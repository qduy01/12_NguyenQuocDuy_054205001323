#ifndef XETAI_H
#define XETAI_H

#include "Xe.h"

class XeTai : public Xe
{
private:
    int taiTrong;

public:
    XeTai(string ma, int namSanXuat, double dungTichDongCo, double triGia, int taiTrong);
    void setTaiTrong(double taiTrong);
    int getTaiTrong() const;
    double tinhThue() const override;
    string toString() const override;
};

#endif
