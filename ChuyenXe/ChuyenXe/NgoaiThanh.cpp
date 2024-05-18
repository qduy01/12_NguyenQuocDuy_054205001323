#include "NgoaiThanh.h"
#include <string>

XeNgoaiThanh::XeNgoaiThanh(int maSo, string hoTenTaiXe, int soXe, float doanhThu, string noiDen, int soNgay) : ChuyenXe(maSo, hoTenTaiXe, soXe, doanhThu)
{
	this->noiDen = noiDen;
	this->soNgay = soNgay;
}

void XeNgoaiThanh::XuatThongTin() const
{
	ChuyenXe::XuatThongTin();
	cout << noiDen;
	cout << soNgay;
}

float XeNgoaiThanh::tongdoanhthu() const
{
	return doanhThu;
}
