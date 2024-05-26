#include "Otokhach.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <iomanip>

Otokhach::Otokhach() : Oto(), loaiXe("#####"), soCho(0) {}

Otokhach::Otokhach(string ma, int namSanXuat, double dungTichDongCo, int triGiaXe, string loaiXe, int soCho)
    : Oto(ma, namSanXuat, dungTichDongCo, triGiaXe) {
    setLoaiXe(loaiXe);
    setSoCho(soCho);
}

void Otokhach::setLoaiXe(string loaiXe) {
    vector<string> loaiXeHopLe = { "xe bus", "xe ban tai", "xe du lich", "xe khac" };
    if (find(loaiXeHopLe.begin(), loaiXeHopLe.end(), loaiXe) == loaiXeHopLe.end()) {
        throw invalid_argument("Loai xe khong hop le.");
    }
    this->loaiXe = loaiXe;
}

void Otokhach::setSoCho(int soCho) {
    if (soCho < 2 || soCho > 50) throw invalid_argument("So cho phai >= 2 va <= 50.");
    this->soCho = soCho;
}

string Otokhach::getLoaiXe() const {
    return this->loaiXe;
}

int Otokhach::getSoCho() const {
    return this->soCho;
}

int Otokhach::tinhThue() const {
    double triGia = getTriGiaXe(); // S? d?ng getter
    double VAT = 0.1 * triGia;
    double thueTTDB = (soCho >= 5) ? 0.3 * triGia : 0.5 * triGia;
    double thueTruocBa;
    if (soCho <= 9) {
        thueTruocBa = 0.1 * triGia;
    }
    else if (loaiXe == "xe ban tai") {
        thueTruocBa = 0.06 * triGia;
    }
    else {
        thueTruocBa = 0.02 * triGia;
    }
    return VAT + thueTTDB + thueTruocBa;
}
string Otokhach::toString() const {
    stringstream ss;
    ss << setw(5) << getMa() << setw(8) << getNamSanXuat() << setw(19) << getDungTichDongCo()
        << setw(9) << getTriGiaXe() << setw(16) << loaiXe << setw(25) << soCho
        << setw(25) << tinhThue();
    return ss.str();
}