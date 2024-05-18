#include "Employee.h"
using namespace std;

TienLuong::TienLuong()
{
    this->maNhanVien = "####";
    this->hoTenNhanVien = "####";   //gán giá tr? m?c ??nh cho các thành viên d? li?u c?a ??i t??ng.
    this->ngayVaoLam = "####";
    this->soDienThoai = "####";
    this->tongLuong = 0;
}

TienLuong::TienLuong(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int tongLuong)
{
    this->maNhanVien = maNhanVien;
    this->hoTenNhanVien = hoTenNhanVien;
    this->ngayVaoLam = ngayVaoLam;
    this->soDienThoai = soDienThoai;
    this->tongLuong = tongLuong;
}

void TienLuong::setMaNhanVien(string maNhanVien)
{
    this->maNhanVien = maNhanVien;
}

void TienLuong::setHoTenNhanVien(string hoTenNhanVien)
{
    this->hoTenNhanVien = hoTenNhanVien;
}

void TienLuong::setNgayVaoLam(string ngayVaoLam)
{
    this->ngayVaoLam = ngayVaoLam;
}

void TienLuong::setSoDienThoai(string soDienThoai)
{
    this->soDienThoai = soDienThoai;
}

void TienLuong::setTongLuong(int tongLuong)
{
    this->tongLuong = tongLuong;
}

string TienLuong::getMaNhanVien() const
{
    return this->maNhanVien;
}

string TienLuong::getHoTenNhanVien() const
{
    return this->hoTenNhanVien;
}

string TienLuong::getNgayVaoLam() const
{
    return this->ngayVaoLam;
}

string TienLuong::getSoDienThoai() const
{
    return this->soDienThoai;
}

int TienLuong::getTongLuong() const
{
    return this->tongLuong;
}