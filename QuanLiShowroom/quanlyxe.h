#pragma once
#ifndef QUANLYXE_H
#define QUANLYXE_H

#include <vector>
#include "Xe.h"
#include "XeKhach.h"
#include "XeTai.h"

class QuanLyXe
{
private:
    vector<Xe*> danhSachXe;
public:
    QuanLyXe();
    ~QuanLyXe();
    void themXe(Xe* xe);
    int demXeThueTruocBaTren200Tr() const;
    vector<Xe*> danhSachXeKhachNamX(int nam) const;
    void capNhatTriGiaXe(string ma, float triGiaMoi);
    vector<Xe*> sapXepGiamTheoNamSanXuat() const;
    void them5XeMau();
    void xuatDanhSachXe() const;
    void menu();
    void themXeMenu();
    void themXeKhachMenu();
    void themXeTaiMenu();
    void danhSachXeNamXMenu();
    void capNhatTriGiaXeMenu();
    void xuatDanhSachXeSapXepMenu();
};

#endif