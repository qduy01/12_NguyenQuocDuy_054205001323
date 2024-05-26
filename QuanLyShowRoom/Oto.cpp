#include "Oto.h"
#include <ctime>

Oto::Oto() : ma("####"), namSanXuat(0), dungTichDongCo(0.0), triGiaXe(0.0) {}

Oto::Oto(string ma, int namSanXuat, double dungTichDongCo, int triGiaXe) {
    setMa(ma);
    setNamSanXuat(namSanXuat);
    setDungTichDongCo(dungTichDongCo);
    setTriGiaXe(triGiaXe);
}

void Oto::setMa(string ma) {
    if (ma.empty()) throw invalid_argument("Ma xe khong duoc rong.");
    this->ma = ma;
}

void Oto::setNamSanXuat(int namSanXuat) {
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);
    int currentYear = now.tm_year + 1900;
    if (namSanXuat > currentYear) {
        throw std::invalid_argument("Nam san xuat phai nho hon hoac bang nam hien tai.");
    }
    this->namSanXuat = namSanXuat;
}


void Oto::setDungTichDongCo(double dungTichDongCo) {
    if (dungTichDongCo < 0) throw invalid_argument("Dung tich dong co phai >= 0.");
    this->dungTichDongCo = dungTichDongCo;
}

void Oto::setTriGiaXe(int triGiaXe) {
    if (triGiaXe < 0) throw invalid_argument("Tri gia xe phai >= 0.");
    this->triGiaXe = triGiaXe;
}

string Oto::getMa() const {
    return this->ma;
}

int Oto::getNamSanXuat() const {
    return this->namSanXuat;
}

double Oto::getDungTichDongCo() const {
    return this->dungTichDongCo;
}

int Oto::getTriGiaXe() const {
    return this->triGiaXe;
}

