#include "XeKhach.h"

XeKhach::XeKhach(string ma, int namSanXuat, double dungTichDongCo, double triGia, string loaiXe, int soCho)
    : Xe(ma, namSanXuat, dungTichDongCo, triGia), loaiXe(loaiXe), soCho(soCho) {}

void XeKhach::setLoaiXe(string loaiXe) { this->loaiXe = loaiXe; }
string XeKhach::getLoaiXe() const { return loaiXe; }

void XeKhach::setSoCho(int soCho) { this->soCho = soCho; }
int XeKhach::getSoCho() const { return soCho; }

double XeKhach::tinhThue() const
{
    double vat = triGia * 0.1;
    double thueTieuThuDacBiet = soCho >= 5 ? triGia * 0.3 : triGia * 0.5;
    double thueTruocBa = (soCho <= 9) ? triGia * 0.1 : (soCho == 0) ? triGia * 0.06 : triGia * 0.02;
    return vat + thueTieuThuDacBiet + thueTruocBa;
}

string XeKhach::toString() const
{
    return "Xe O to khach\nMa: " + ma + "\nNam san xuat: " + to_string(namSanXuat) + "\nDung tich dong co: " + to_string(dungTichDongCo)
        + "\nTri gia: " + to_string(triGia) + "\nLoai xe: " + loaiXe + "\nSo cho: " + to_string(soCho);
}