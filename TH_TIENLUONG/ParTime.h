#pragma once
#include"Employee.h"
class ParTime :public TienLuong
{
private:
	int soGioLamTuan;
	int mucLuongMoiGio;
public:
	ParTime();
	ParTime(string, string, string, string, int, int, int);
	void  thongTinTienLuong() const;
	bool isTienLuongGi() const;
};


