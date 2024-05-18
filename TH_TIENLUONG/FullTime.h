#pragma once
#include "Employee.h"

class FullTime : public TienLuong {
private:
    double heSoLuong;
    int soNamKinhNghiem;

public:
    FullTime();
    FullTime(string, string, string, string, int, double, int);

    void thongTinTienLuong() const;
    bool isTienLuongGi() const;
};



