#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class TienLuong {
private:
    string maNhanVien;
    string hoTenNhanVien;
    string ngayVaoLam;
    string soDienThoai;
    int tongLuong;

public:
    TienLuong();
    TienLuong(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int tongLuong);

    void setMaNhanVien(string maNhanVien);
    void setHoTenNhanVien(string hoTenNhanVien);
    void setNgayVaoLam(string ngayVaoLam);
    void setSoDienThoai(string soDienThoai);
    void setTongLuong(int tongLuong);

    string getMaNhanVien() const;
    string getHoTenNhanVien() const;
    string getNgayVaoLam() const;
    string getSoDienThoai() const;
    int getTongLuong() const;

    virtual void thongTinTienLuong() const = 0;
    virtual bool isTienLuongGi() const = 0;
};



