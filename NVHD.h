#pragma once
#include "NhanVien.h"
// Nhan vien hop dong
class NVHD: public NhanVien
{
	double LuongDate; // luong theo ngay
public:
	NVHD(int = 1, int = 1, int = 2000, string = "", string = "", bool = 1, double = 0, double = 0);
	virtual ~NVHD();
	double TinhLuong();
	void setLuongDate(double);
public:
	void create();
	void read();
	void scan();
	void update();
	void Delete();
	friend ostream& operator<<(ostream&, const NVHD&);
};

