#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class ChuyenXe
{
private:
	int maSo;
	string hoTenTaiXe;
	int soXe;
protected:
	float doanhThu;
public:
	ChuyenXe();
	ChuyenXe(int maSo, string hoTenTaiXe, int soXe, float doanhThu);
	~ChuyenXe();
	virtual float tongdoanhthu() const;
	virtual void XuatThongTin() const;
};
