#include "ParTime.h"
#include"Employee.h"
ParTime::ParTime() :TienLuong()
{
	this->soGioLamTuan = 0;
	this->mucLuongMoiGio = 0;
}
ParTime::ParTime(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int tongLuong, int soGioLamTuan, int mucLuongMoiGio) :TienLuong(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, tongLuong)
{
	this->soGioLamTuan = soGioLamTuan;
	this->mucLuongMoiGio = mucLuongMoiGio;
}

void ParTime::thongTinTienLuong() const
{
	cout << setfill(' ');
	cout << setw(12) << getMaNhanVien() << setw(15) << getHoTenNhanVien() << setw(15) << getNgayVaoLam();
	cout << setw(16) << getSoDienThoai() << setw(18) << soGioLamTuan << setw(22) << mucLuongMoiGio;
	cout << setw(12) << getTongLuong() << endl;
}
bool ParTime::isTienLuongGi() const
{
	return false;
}
