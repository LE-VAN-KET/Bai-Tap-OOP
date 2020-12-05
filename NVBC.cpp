#include "NVBC.h"
#include <iostream>
#include <exception>
using namespace std;

NVBC::NVBC(int month, int day, int year, string MaNhanVien, string TenNhanVien, bool GioiTinh, double Luong, double HeLuong, double ThamNien)
	: NhanVien(month, day, year, MaNhanVien, TenNhanVien, GioiTinh, Luong)
{
	this->HeLuong = HeLuong;
	this->ThamNien = ThamNien;
}

NVBC::~NVBC() {

}

void NVBC::isValid() {
	if (this->HeLuong < 2.34 && this->HeLuong > 10.0) throw invalid_argument("He so luong is invalid");
}

void NVBC::setThamNien(double ThamNien) {
	this->ThamNien = ThamNien;
}

void NVBC::setHeLuong(double HeLuong) {
	this->HeLuong = HeLuong;
}

double NVBC::TinhLuong() {
	return (this->HeLuong * 1390.000) * (1 + this->ThamNien);
}

void NVBC::scan() {
	NhanVien::scan();
	bool check = false;
	while(!check) {
		try {
			cout << "He Luong: ";
			cin >> this->HeLuong;
			if (this->HeLuong < 2.34 || this->HeLuong > 10.0)
				throw invalid_argument("He so luong must value 2.34 to 10!");
			check = true;
		} catch (invalid_argument &exception) {
			cout << exception.what() << endl;
			check = false;
		}
	}
    cin.ignore();
	this->ThamNien = 0;
}

void NVBC::read() {
	cout << "\t\t====Nhan Vien Bien Che===\n";
	NhanVien::read();
	cout << "He So Luong: " << this->HeLuong << endl;
	cout << "So Nam Tham Nien: " << this->ThamNien << endl;
	cout << "--------------------------------" << endl;
}

ostream& operator<<(ostream& o, const NVBC& nv) {
	o << "\t\t====Nhan Vien Bien Che===\n";
	o << "He So Luong: " << nv.HeLuong << endl;
	o << "So Nam Tham Nien: " << nv.ThamNien << endl;
	o << "--------------------------------" << endl;
	return o;
}