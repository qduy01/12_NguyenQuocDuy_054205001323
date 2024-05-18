#include "ChuyenXe.h";
#include "NoiThanh.h";
#include "NgoaiThanh.h";
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    vector<ChuyenXe*> dsChuyenXe;
    dsChuyenXe.push_back(new XeNoiThanh(1, "Nguyen Minh Duc ", 123, 500000, 12, 100));
    dsChuyenXe.push_back(new XeNgoaiThanh(2, "Tran Tuan Tai", 456, 700000, "Ha Noi", 2));
    dsChuyenXe.push_back(new XeNgoaiThanh(3, "Nguyen Minh Son ", 789, 233000, "TP.HCM", 9));


    cout << "Danh sach chuyen xe Noi Thanh:" << endl;
    cout << left << setw(20) << "Ma so" << setw(20) << "Ho ten tai xe" << setw(20) << "So xe" << setw(20) << "Doanh thu" << setw(20) << "So tuyen" << setw(20) << "So km" << endl;
    for (auto xe : dsChuyenXe)
    {
        if (dynamic_cast<XeNoiThanh*>(xe)) {
            xe->XuatThongTin();
        }
    }

    cout << "\nDanh sach chuyen xe Ngoai Thanh:" << endl;
    cout << left << setw(20) << "Ma so" << setw(20) << "Ho ten tai xe" << setw(20) << "So xe" << setw(20) << "Doanh thu" << setw(20) << "Noi den" << setw(20) << "So ngay" << endl;
    for (auto xe : dsChuyenXe)
    {
        if (dynamic_cast<XeNgoaiThanh*>(xe)) {
            xe->XuatThongTin();
        }
    }



    float ngoaithanh = 0;
    float noithanh = 0;
    float doanhthu = 0;
    for (const auto& xe : dsChuyenXe) {
        doanhthu += xe->tongdoanhthu();
        if (dynamic_cast<XeNoiThanh*>(xe)) {
            noithanh += xe->tongdoanhthu();
        }
        else if (dynamic_cast<XeNgoaiThanh*>(xe)) {
            ngoaithanh += xe->tongdoanhthu();
        }
    }
    cout << endl;
    cout << "Tong doanh thu cua ca chuyen xe: " << doanhthu << endl;
    cout << "Tong doanh thu cua xe noi thanh: " << noithanh << endl;
    cout << "Tong doanh thu cua xe ngoai thanh: " << ngoaithanh << endl;

    for (auto xe : dsChuyenXe) {
        delete xe;
    }
    return 0;
}
