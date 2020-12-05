#include <iostream>
#include "QLNV.cpp"
using namespace std;

void menu() {
	cout << "\t\t===========MENU===========\n";
	cout << "\t\t1.Add Thong Tin Nhan Vien\n";
	cout << "\t\t2.Tim Kiem Nhan Vien\n";
	cout << "\t\t3.Update Thong Tin Nhan Vien\n";
	cout << "\t\t4.Delete Nhan Vien\n";
	cout << "\t\t5.Show All Nhan Vien\n";
	cout << "\t\t6.Sap Xep Nhan Vien\n";
	cout << "\t\t7.Tinh Luong\n";
	cout << "\t\t0.Exit(0)\n";
	cout << "\t\t============END===========\n";
}

int main() {
	system("cls");
	QLNV<NhanVien> *db = QLNV<NhanVien>::getInstance();
	QLNV<NhanVien> database = database.operator=(*db);
	int select;
	bool success = false;
	while (!success) {
		menu();
		cout << "Select: ";
		cin >> select;
        cin.ignore();
		switch (select) {
		case 1:
		{
			// db->addEmploye();
			cin >> database;
			break;
		}
		case 5:
		{
			// db->readAllDetailEmploye();
			cout << database;
			break;
		}
		case 0:
		{
			success = true;
			break;
		}
		case 6:
		{
			database.selectionSort();
			break;
		}
		case 2:
		{
			NhanVien* temp = database.selectionSearch();
			if (temp != NULL) temp->read();
			break;
		}
		case 3:
		{
			database.updateEmploye();
			break;
		}
		case 4:
		{
			database.deleteEmploye();
			break;
		}
		case 7:
		{
			database.selectionSalary();
			break;
		}
		default:
			cout << "Error: Select invalid!" << endl;
		};
	};
	delete db;
	system("pause");
	return 0;
}