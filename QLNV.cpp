#include "QLNV.h"
#include <exception>
#include <ctime>
template<class T>
QLNV<T>* QLNV<T>::instance = nullptr;

template<class T>
QLNV<T>* QLNV<T>::getInstance() {
	if (instance == nullptr) instance = new QLNV();
	return instance;
}

template<class T>
QLNV<T>::QLNV() {
	this->size = 0;
	this->data = new T*[this->size];
}

template<class T>
QLNV<T>::QLNV(const QLNV& list) {
	for (int i = 0; i < this->size; ++i) {
		this->data[i] = *(list.data + i);
	}
	this->size = list.size;
}

template<class T>
QLNV<T>::~QLNV() {
	// for (int i = 0; i < this->size; ++i) {
	// 	delete *(this->data + i);
	// }
	delete[] this->data;
}

template<class T>
void QLNV<T>::addEmploye() {
	int choose;
	bool success = false;
	//do {
		cout << "Add Nhan Vien Bien Che/ Hop Dong(1/0): "; //Nhan vien bien che-1, nhan vien hop dong-0
		cin >> choose;
		cin.ignore();
		//if (choose > 1 && choose < 0) throw invalid_argument("Select isvalid");
		//	else success = true;
	//} while (success == false);
	T *nv;
	switch (choose) {
        case 0:
        {
			nv = new NVHD();
            nv->scan();
            this->pushBack(nv);
            break;
        }
        case 1:
        {
            nv = new NVBC();
            nv->scan();
            this->pushBack(nv);
            break;
        }
	};
}

template<class T>
void QLNV<T>::copyArrayNhanVien(T**& nv1, T**& nv2) {
	for (int i = 0; i < this->size; ++i) {
		nv2[i] = nv1[i];
	}
}

template<class T>
void QLNV<T>::pushBack(T *nhanvien) {
	if (this->size == 0) {
        this->data = new T*[this->size + 1];
        this->data[0] = nhanvien;
		// nhanvien = nullptr;
        this->size++;
	}
	else {
		T** temp = new T*[this->size];
		this->copyArrayNhanVien(this->data, temp);
		// for (int i = 0; i < this->size; ++i) {
		// 	*(temp + i) = *(this->data + i);
		// }
		this->data = new T*[this->size + 1];
		// for (int i = 0; i < this->size; ++i) {
		// 	*(this->data + i) = *(temp + i);
		// }
		this->copyArrayNhanVien(temp, this->data);
		this->data[this->size] = nhanvien;
		// for (int i = 0; i < this->size; ++i) {
		// 	delete *(temp + i);
		// }
		// nhanvien = nullptr;
		delete[] temp;
		this->size++;
	}
}

template<class T>
void QLNV<T>::readAllDetailEmploye() {
	for (int i = 0; i < this->size; ++i) {
		// (*(this->data + i))->read();
		// ((*this)[i])->read();
		T *nv = ((*this)[i]);
		nv->read();
		delete nv;
	}
}

template<class T>
int QLNV<T>::getLength() const {
	return this->size;
}

template<class T>
T* QLNV<T>::operator[](const int& index) {
	static T *error = nullptr;
	return (index >= 0 && index < this->size) ? *(this->data + index) : error;
}

template<class T>
QLNV<T>& QLNV<T>::operator=(QLNV<T>& ql) {
	if (this != &ql) {
		this->data = new T*[ql.size];
		for (int i = 0; i < ql.size; ++i) {
			this->data[i] = ql.data[i];
		}
		this->size = ql.size;
	}
	return *this;
}

template<class T>
string QLNV<T>::split(string str, string delimiter) {
    // string token, str = s;
    int pos = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
		// token = str.substr(0, pos);
		// cout << token << endl;
		str.erase(0, pos + delimiter.length());
	}
    return str;
}

template<class T>
bool QLNV<T>::compare(T* nv1,T* nv2) {
	string s1 = this->split(nv1->getTenNhanVien(), " ");
	string s2 = this->split(nv2->getTenNhanVien(), " ");
	return (s1 > s2) ? true : false;
}

template<class T>
void QLNV<T>::swap(T*& nv1, T*& nv2) {
	T** t = new T*[1];
	t[0] = nv1;
	nv1 = nv2;
	nv2 = t[0];
	delete [] t;
}

template<class T>
void QLNV<T>::sortNameEmploye(bool(QLNV<T>::*selectionSort)(T*, T*)) {
	for (int i = 0; i < this->size - 1; ++i) {
		for (int j = i + 1; j < this->size; ++j) {
			if ((this->*selectionSort)(*(this->data + i), *(this->data + j))) {
				this->swap(*(this->data + i), *(this->data + j));
			}
		}
	}
}

template<class T>
bool QLNV<T>::down(T* nv1, T*nv2) {
	return (this->compare(nv1, nv2) == false) ? true : false;
}

template<class T>
bool QLNV<T>::up(T* nv1, T* nv2) {
	return (this->compare(nv1, nv2) == true) ? true : false;
}

template<class T>
void QLNV<T>::selectionSort() {
	cout << "\t\t1. Sort tang dan\n";
	cout << "\t\t2. Sort giam dan\n";
	cout << "\t\t0. Back come\n";
	int choice;
	bool success = false;
	while (!success) {
		cout << "\tSelect: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1:
				this->sortNameEmploye(up);
				success = true;
				break;
			case 2:
				this->sortNameEmploye(down);
				success = true;
				break;
			case 0: 
				success = true;
				break;
			default:
				cout << "\t\tError:: Select invalid value" << endl;
		}
	}
}

template<class T>
int QLNV<T>::searchNameEmploye(const string &TenNhanVien) {
	static int error = -1;
	for (int i = 0; i < this->size; ++i) {
		if (((*this)[i])->getTenNhanVien() == TenNhanVien) return i;
	}
	return error;
}

template<class T>
int QLNV<T>::searchMaNhanVien(const string &MaNhanVien) {
	static int error = -1;
	for (int i = 0; i < this->size; ++i) {
		if (((*this)[i])->getMaNhanVien() == MaNhanVien) return i;
	}
	return error;
}

template<class T>
T* QLNV<T>::selectionSearch() {
	cout << "\t\t1. Tim kiem ten nhan vien\n";
	cout << "\t\t2. Tim kiem ma nhan vien\n";
	int choice;
	string key;
	bool success = false;
	while (!success) {
		cout << "\tSelect: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1:
			{
				cout << "Nhap Ten Nhan Vien: ";
				getline(cin, key);
				int check = this->searchNameEmploye(key);
				if (check != -1) return ((*this)[check]);
				else {
					cout << "\t\tError: Is not employe invalid!" << endl;
					return NULL;
				}
				success = true;
				break;
			}
			case 2:
			{
				cout << "Nhap Ma Nhan Vien: ";
				getline(cin, key);
				int check = this->searchMaNhanVien(key);
				if (check != -1) return ((*this)[check]);
				else {
					cout << "\t\tError: Is not employe invalid!" << endl;
					return NULL;
				}
				success = true;
				break;
			}
			default:
				cout << "\t\tError:: Select invalid value" << endl;
		}
	}
	return NULL;
}

template<class T>
void QLNV<T>::updateEmploye() {
	bool flash = false;
	T* nv = this->selectionSearch();
	if (nv == NULL) return;
	cout << "\t\t1. Update ten nhan vien\n";
	cout << "\t\t2. Update ma nhan vien\n";
	if (NVBC *kt = dynamic_cast<NVBC*>(nv)) {
		cout << "\t\t3. Update He Luong\n";
		cout << "\t\t4. Update nam tham nien\n";
	} else {
		cout << "\t\t3. Update luong theo ngay\n";
	}
	int selection;
	string key;
	do {
		cout << "\tSelect update: ";
		cin >> selection;
		cin.ignore();
		switch (selection) {
			case 1:
			{
				cout << "\t\tTen Nhan Vien: ";
				getline(cin, key);
				nv->setTenNhanVien(key);
				flash = true;
				break;
			}
			case 2:
			{
				cout << "\t\tMa Nhan Vien: ";
				getline(cin, key);
				nv->setMaNhanVien(key);
				flash = true;
				break;
			}
			case 3:
			{
				if (NVBC *kt = dynamic_cast<NVBC*>(nv)) {
					NVBC *nhanvien = static_cast<NVBC*>(nv);
					double heluong;
					cout << "\t\tHe Luong: ";
					cin >> heluong; cin.ignore();
					nhanvien->setHeLuong(heluong);
					flash = true;
					break;
				} else {
					NVHD *nhanvien = static_cast<NVHD*>(nv);
					double luongdate;
					cout << "\t\tLuong date: ";
					cin >> luongdate; cin.ignore();
					nhanvien->setLuongDate(luongdate);
					flash = true;
					break;
				}
			}
			case 4:
			{
				if (NVBC *kt = dynamic_cast<NVBC*>(nv)) {
					double heluong = 0;
					NVBC *nhanvien = static_cast<NVBC*>(nv);
					time_t now = time(0);
					tm *ltm = localtime(&now);
					int yearWorkings = (1900 + ltm->tm_year) - nhanvien->getNgayNhan().getYear();
					if (yearWorkings >= 5) heluong = yearWorkings*1.0/100;
					nhanvien->setThamNien(heluong);
					flash = true;
					break;
				} else {
					cout << "\t\tError:: Select invalid value" << endl;
					break;
				}
			}
			default:
				cout << "\t\tError:: Select invalid value" << endl;
		}
	} while (!flash);
}

template<class T>
void QLNV<T>::deleteEmploye() {
	T* _nv = this->selectionSearch();
	if (_nv != NULL) {
		int position = this->searchNameEmploye(_nv->getTenNhanVien());
		for (int i = position, j = i + 1; i < this->size - 1; ++i) {
			*(this->data + i) = *(this->data + j);
		}
		this->size--;
	}
}

template<class T>
void QLNV<T>::selectionSalary() {
	for (int i = 0; i < this->size; ++i) {
		if (NVBC* kt = dynamic_cast<NVBC*>(this->data[i])) {
			double heluong = 0;
			NVBC* nhanvien = static_cast<NVBC*>(this->data[i]);
			time_t now = time(0);
			tm ltm;
			localtime_s(&ltm, &now);
			//tm* ltm = localtime(&now);
			int yearWorkings = (1900 + ltm.tm_year) - nhanvien->getNgayNhan().getYear();
			if (yearWorkings >= 5) heluong = yearWorkings * 1.0 / 100;
			nhanvien->setThamNien(heluong);
		}
	}
	T* _nv = this->selectionSearch();
	if (_nv == NULL) return;
	double luong = _nv->TinhLuong();
	_nv->setLuong(luong);
}
