#include "NhanVien.h"
#include <iomanip>
#include <exception>
NhanVien::NhanVien() : NgayNhan() {
	this->MaNhanVien = "";
	this->TenNhanVien = "";
	this->GioiTinh = 1;
	this->Luong = 0;
}

NhanVien::NhanVien(int month, int day, int year, string MaNhanVien, string TenNhanVien, bool GioiTinh, double Luong)
	: NgayNhan(month, day, year), MaNhanVien(MaNhanVien), TenNhanVien(TenNhanVien), GioiTinh(GioiTinh), Luong(Luong)
{
}
NhanVien::~NhanVien() {
//  cout << "Huy NhanVien" <<endl;
}

void NhanVien::scan() {
	bool kt = false;
	while (!kt) {
		try {
			cout << "MaNhanVien: ";
			getline(cin, this->MaNhanVien);
			if (this->MaNhanVien.length() != 8)
				throw invalid_argument("Ma Nhan Vien must 8 characters");
			cout << "TenNhanVien: ";
			getline(cin, this->TenNhanVien);
			this->NgayNhan.scan();
			kt = true;
		}
		catch (invalid_argument& exception) {
			cout << exception.what() << endl;
			kt = false;
		}
	};
	kt = false;
	while (!kt) {
		try {
			int gender;
			cout << "Gioi tinh: "; // 1-nam 0-nu
			cin >> gender;
			if (gender < 0 || gender > 1)
				throw invalid_argument("Gioi tinh must be between 0 and 1");
			this->GioiTinh = gender;
			cin.ignore();
			kt = true;
		} catch (invalid_argument& exception) {
			cout << exception.what() << endl;
			kt = false;
		}
	}
	this->Luong = 0;
}

void NhanVien::read() {
	cout << "MaNhanVien: " << this->MaNhanVien << endl;
	cout << "TenNhanVien: " << this->TenNhanVien << endl;
	this->NgayNhan.showDate();
	cout << "Gioi Tinh: " << ((this->GioiTinh == 1) ? "nam": "nu") << endl;
	cout << "Luong: " << setprecision(3) << fixed << this->Luong << endl;
}

ostream& operator<<(ostream& o, const NhanVien& nv) {
	o << "MaNhanVien: " << nv.MaNhanVien << endl;
	o << "TenNhanVien: " << nv.TenNhanVien << endl;
	o << "Gioi Tinh: " << nv.GioiTinh << endl;
	o << "Luong: " << nv.Luong << endl;
	return o;
}

string NhanVien::getTenNhanVien() const {
	return this->TenNhanVien;
}

string NhanVien::getMaNhanVien() const {
	return this->MaNhanVien;
}

const NhanVien& NhanVien::operator=(const NhanVien& nv) {
	if (this != &nv) {
		return nv;
	}
	return *this;
}

void NhanVien::setMaNhanVien(const string& MaNhanVien) {
	this->MaNhanVien = MaNhanVien;
}

void NhanVien::setTenNhanVien(const string& TenNhanVien) {
	this->TenNhanVien = TenNhanVien;
}

Date& NhanVien::getNgayNhan() {
	return this->NgayNhan;
}

void NhanVien::setLuong(const double& luong) {
	this->Luong = luong;
}