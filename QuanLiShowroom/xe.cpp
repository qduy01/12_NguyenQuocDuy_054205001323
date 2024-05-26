#include "Xe.h"

Xe::Xe(string ma, int namSanXuat, double dungTichDongCo, double triGia)
    : ma(ma), namSanXuat(namSanXuat), dungTichDongCo(dungTichDongCo), triGia(triGia) {}

void Xe::setMa(string ma) { this->ma = ma; }
string Xe::getMa() const { return ma; }

void Xe::setNamSanXuat(int namSanXuat) { this->namSanXuat = namSanXuat; }
int Xe::getNamSanXuat() const { return namSanXuat; }

void Xe::setDungTichDongCo(double dungTichDongCo) { this->dungTichDongCo = dungTichDongCo; }
double Xe::getDungTichDongCo() const { return dungTichDongCo; }

void Xe::setTriGia(double triGia) { this->triGia = triGia; }
double Xe::getTriGia() const { return triGia; }