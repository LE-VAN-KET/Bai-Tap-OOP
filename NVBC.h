#pragma once
#include "NhanVien.h"
// Nhan vien bien che
class NVBC : public NhanVien
{
	double HeLuong; // he so luong
	double ThamNien;
public:
	NVBC(int = 1, int = 1 , int = 2000, string = "", string = "", bool = 1, double = 0, double = 0, double = 0);
	virtual ~NVBC();
	void isValid();
	double TinhLuong();
	void setThamNien(double);
	void setHeLuong(double);
public:
	void scan();
	void read();
	void update();
	void Delete();
	friend ostream& operator<<(ostream&, const NVBC&);
};

