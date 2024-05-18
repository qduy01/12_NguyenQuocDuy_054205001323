#include "ChuyenXe.h"

ChuyenXe::ChuyenXe()
{
	maSo = soXe = 0;
	doanhThu = 0.0;
	hoTenTaiXe = "";
}

ChuyenXe::ChuyenXe(int maSo, string hoTenTaiXe, int soXe, float doanhThu)
{
	this->maSo = maSo;
	this->hoTenTaiXe = hoTenTaiXe;
	this->soXe = soXe;
	this->doanhThu = doanhThu;
}

ChuyenXe::~ChuyenXe()
{

}

float ChuyenXe::tongdoanhthu() const
{
	return doanhThu;
}

void ChuyenXe::XuatThongTin() const
{
	cout << maSo;
	cout << hoTenTaiXe;
	cout << soXe;
	cout << doanhThu;
}
