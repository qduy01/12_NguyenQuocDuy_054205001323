#pragma once
#include "ChuyenXe.h"
class XeNoiThanh : public ChuyenXe
{
private:
	int soTuyen;
	int soKm;
public:
	XeNoiThanh(int maSo, string hoTenTaiXe, int soXe, float doanhThu, int soTuyen, int soKm);
	void XuatThongTin() const override;
	float tongdoanhthu() const override;
};
