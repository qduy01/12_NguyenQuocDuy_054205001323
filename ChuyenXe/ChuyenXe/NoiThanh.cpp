#include "NoiThanh.h"

XeNoiThanh::XeNoiThanh(int maSo, string hoTenTaiXe, int soXe, float doanhThu, int soTuyen, int soKm) : ChuyenXe(maSo, hoTenTaiXe, soXe, doanhThu) {
	this->soTuyen = soTuyen;
	this->soKm = soKm;
}

void XeNoiThanh::XuatThongTin() const
{
	ChuyenXe::XuatThongTin();
	cout << soTuyen;
	cout << soKm;
}

float XeNoiThanh::tongdoanhthu() const
{
	return doanhThu;
}