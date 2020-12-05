#pragma once
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
class NhanVien
{
protected:
	string MaNhanVien, TenNhanVien;
	Date NgayNhan; // date of employment
	bool GioiTinh; // Gender true-male false-female
	double Luong;
public:
	NhanVien();
	NhanVien(int, int, int, string , string, bool, double = 0);
	virtual ~NhanVien();

	virtual void scan();
	virtual void read();
	friend ostream& operator<<(ostream&, const NhanVien&);
	virtual double TinhLuong() = 0;

	string getTenNhanVien() const;
	string getMaNhanVien() const;
	void setTenNhanVien(const string&);
	void setMaNhanVien(const string&);
	void setLuong(const double&);
	Date& getNgayNhan();
	const NhanVien& operator=(const NhanVien&);
};
