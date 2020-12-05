#include "NVHD.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

NVHD::NVHD(int month, int day, int year, string MaNhanVien, string TenNhanVien, bool GioiTinh, double Luong, double LuongDate)
	: NhanVien(month, day, year, MaNhanVien, TenNhanVien, GioiTinh, Luong)
{
	this->LuongDate = LuongDate;
}

NVHD::~NVHD() {
}

double NVHD::TinhLuong() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int dayCurrent = ltm->tm_mday;
	int maxday = (this->NgayNhan).dayofmonth(ltm->tm_mon + 1);
	int minday_current = dayCurrent % 7;
	int minthu_began = ltm->tm_wday - (minday_current - 1);
	int sum_day_workings;
	switch (minthu_began) {
		case 0:
			sum_day_workings = maxday - (maxday*2/7 + 1);
			break;
		case 6:
			sum_day_workings = maxday - (maxday*2/7 + 2);
			break;
		default:
			sum_day_workings = maxday - (maxday*2/7);
	}
	return this->LuongDate * sum_day_workings;
}

void NVHD::read() {
	cout << "\t\t====Nhan Vien Hop Dong===\n";
	NhanVien::read();
	cout << "Luong/date: " << setprecision(3) << fixed << this->LuongDate << endl;
	cout << "--------------------------------" << endl;
}

ostream& operator<<(ostream& o, const NVHD& nv) {
	o << "\t\t====Nhan Vien Hop Dong===\n";
	o << "Luong/date: " << nv.LuongDate << endl;
	o << "--------------------------------" << endl;
	return o;
}

void NVHD::scan() {
	NhanVien::scan();
	cout << "Luong theo ngay: ";
	cin >> this->LuongDate;
	cin.ignore();
}

void NVHD::setLuongDate(double LuongDate) {
	this->LuongDate = LuongDate;
}