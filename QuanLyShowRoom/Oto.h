#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Oto {
protected:
    string ma;
    int namSanXuat;
    double dungTichDongCo;
    int triGiaXe;

public:
    Oto();
    Oto(string, int, double, int);

    void setMa(string ma);
    void setNamSanXuat(int namSanXuat);
    void setDungTichDongCo(double dungTichDongCo);
    void setTriGiaXe(int triGiaXe);

    string getMa() const;
    int getNamSanXuat() const;
    double getDungTichDongCo() const;
    int getTriGiaXe() const;

    virtual int tinhThue() const = 0;
    virtual string toString() const = 0;
};


