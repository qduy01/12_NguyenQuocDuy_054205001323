#include "FullTime.h"
#include"Employee.h"
FullTime::FullTime() :TienLuong()
{
	this->heSoLuong = 0;
	this->soNamKinhNghiem = 0;
}
FullTime::FullTime(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int tongLuong, double heSoLuong, int soNamKinhNghiem) : TienLuong(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, tongLuong)
{
	this->heSoLuong = heSoLuong;
	this->soNamKinhNghiem = soNamKinhNghiem;
}
void FullTime::thongTinTienLuong() const
{
	cout << setfill(' ');
	cout << setw(12) << getMaNhanVien() << setw(15) << getHoTenNhanVien() << setw(15) << getNgayVaoLam();
	cout << setw(15) << getSoDienThoai() << setw(13) << heSoLuong << setw(20) << soNamKinhNghiem;
	cout << setw(12) << getTongLuong() << endl;
}
bool FullTime::isTienLuongGi() const
{
	return true;
}

