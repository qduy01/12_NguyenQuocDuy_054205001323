#ifndef XEKHACH_H
#define XEKHACH_H

#include "Xe.h"

class XeKhach : public Xe
{
private:
    string loaiXe;
    int soCho;

public:
    XeKhach(string ma, int namSanXuat, double dungTichDongCo, double triGia, string loaiXe, int soCho);
    void setLoaiXe(string loaiXe);
    string getLoaiXe() const;
    void setSoCho(int soCho);
    int getSoCho() const;
    double tinhThue() const override;
    string toString() const override;
};

#endif
