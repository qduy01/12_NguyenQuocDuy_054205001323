#ifndef XE_H
#define XE_H

#include <string>
using namespace std;

class Xe
{
protected:
    string ma;
    int namSanXuat;
    double dungTichDongCo;
    double triGia;

public:
    Xe(string ma, int namSanXuat, double dungTichDongCo, double triGia);
    void setMa(string ma);
    string getMa() const;
    void setNamSanXuat(int namSanXuat);
    int getNamSanXuat() const;
    void setDungTichDongCo(double dungTichDongCo);
    double getDungTichDongCo() const;
    void setTriGia(double triGia);
    double getTriGia() const;
    virtual double tinhThue() const = 0;
    virtual string toString() const = 0;
};

#endif