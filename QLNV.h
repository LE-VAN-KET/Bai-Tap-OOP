#pragma once
#include <string>
#include <iostream>
#include "NhanVien.h"
#include "NVBC.h"
#include "NVHD.h"
using namespace std;
template<class T>
class QLNV
{
	T** data;
	int size;
	static QLNV* instance;
	QLNV();
public:
	static QLNV* getInstance();
public:
	QLNV(const QLNV&);
	~QLNV();
	int getLength() const;
	string split(string, string);
	bool compare(T*, T*);
	void swap(T*&, T*&);
	bool down(T*, T*);
	bool up(T*, T*);

	void addEmploye();
	void pushBack(T*);
	void readAllDetailEmploye();
	void updateEmploye();
	void deleteEmploye();
	int searchNameEmploye(const string&);
	int searchMaNhanVien(const string&);
	T* selectionSearch();
	void selectionSort();
	void sortNameEmploye(bool(QLNV<T>::*selection)(T*, T*));
	friend ostream& operator<<(ostream& o,QLNV<T>& nv) {
		for (int i = 0; i < nv.size; ++i) {
			// o << **(nv.data + i);
			(*(nv.data + i))->read();
		}
		// nv->readAllDetailEmploye();
		return o;
	};
	friend istream& operator>>(istream& in,QLNV<T>& nv) {
		nv.addEmploye();
		return in;
	}
	T* operator[](const int&);
	QLNV<T>& operator=(QLNV<T>&);
	void copyArrayNhanVien(T**&, T**&);
	void selectionSalary();
};

