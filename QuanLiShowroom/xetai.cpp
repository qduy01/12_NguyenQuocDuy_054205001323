#include "XeTai.h"

XeTai::XeTai(string ma, int namSanXuat, double dungTichDongCo, double triGia, int taiTrong)
    : Xe(ma, namSanXuat, dungTichDongCo, triGia), taiTrong(taiTrong) {}

void XeTai::setTaiTrong(double taiTrong) { this->taiTrong = taiTrong; }
int XeTai::getTaiTrong() const { return taiTrong; }

double XeTai::tinhThue() const {
    double vat = triGia * 0.1;
    double thueTruocBa = (taiTrong < 950) ? triGia * 0.02 : triGia * 0.05;
    return vat + thueTruocBa;
}

string XeTai::toString() const {
    return "Xe O to tai\nMa: " + ma + "\nNam san xuat: " + to_string(namSanXuat) + "\nDung tich dong co: " + to_string(dungTichDongCo)
        + "\nTri gia: " + to_string(triGia) + "\nTai trong: " + to_string(taiTrong);
}