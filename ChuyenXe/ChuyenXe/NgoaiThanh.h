#pragma once
#include "ChuyenXe.h"
class XeNgoaiThanh : public ChuyenXe
{
private:
	string noiDen;
	int soNgay;
public:
	XeNgoaiThanh(int maSo, string hoTenTaiXe, int soXe, float doanhThu, string noiDen, int soNgay);
	void XuatThongTin() const override;
	float tongdoanhthu() const override;
};

