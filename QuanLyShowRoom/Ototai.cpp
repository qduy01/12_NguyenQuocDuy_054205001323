#include "Ototai.h"
#include <sstream>
#include <stdexcept>

Ototai::Ototai() : Oto(), taiTrong(0) {}

Ototai::Ototai(string ma, int namSanXuat, double dungTichDongCo, int triGiaXe, int taiTrong)
    : Oto(ma, namSanXuat, dungTichDongCo, triGiaXe) {
    setTaiTrong(taiTrong);
}

void Ototai::setTaiTrong(int taiTrong) {
    if (taiTrong < 0) throw invalid_argument("Tai trong phai >= 0");
    this->taiTrong = taiTrong;
}

int Ototai::getTaiTrong() const {
    return taiTrong;
}

int Ototai::tinhThue() const {
    double VAT = 0.1 * getTriGiaXe();
    double thueTruocBa = (taiTrong < 950) ? 0.02 * getTriGiaXe() : 0.05 * getTriGiaXe();
    return VAT + thueTruocBa;
}
string Ototai::toString() const {
    stringstream ss;
    ss << setw(5) << getMa() << setw(8) << getNamSanXuat() << setw(19) << getDungTichDongCo()
        << setw(9) << getTriGiaXe() << setw(41) << getTaiTrong()
        << setw(25) << tinhThue();
    return ss.str();
}