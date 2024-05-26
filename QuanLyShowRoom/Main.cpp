#include "Otokhach.h"
#include "Ototai.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class QuanLyShowroom {
private:
    vector<Oto*> danhSachXe;

public:
    ~QuanLyShowroom() {
        for (Oto* xe : danhSachXe) {
            delete xe;
        }
    }

    void themXe(Oto* xe) {
        for (Oto* x : danhSachXe) {
            if (x->getMa() == xe->getMa()) {
                cout << "Xe voi ma " << xe->getMa() << " da ton tai." << endl;
                return;
            }
        }
        danhSachXe.push_back(xe);
    }

    int demXeThueTruocBaLonHon(double mucThue) const {
        int count = 0;
        for (Oto* xe : danhSachXe) {
            if (xe->tinhThue() > mucThue) {
                count++;
            }
        }
        return count;
    }
    // NAM
    vector<Otokhach*> layDanhSachXeKhachTheoNam(int nam) const {
        vector<Otokhach*> result;
        for (Oto* xe : danhSachXe) {
            Otokhach* khach = dynamic_cast<Otokhach*>(xe);
            if (khach && khach->getNamSanXuat() == nam) {
                result.push_back(khach);
            }
        }
        return result;
    }

    void capNhatTriGiaXe(string ma, double triGiaMoi) {
        for (Oto* xe : danhSachXe) {
            if (xe->getMa() == ma) {
                xe->setTriGiaXe(triGiaMoi);
                return;
            }
        }
        cout << "Khong tim thay xe voi ma " << ma << "." << endl;
    }
    // SAP XEP THEO NAM SAN XUAT
    vector<Oto*> sapXepTheoNamSanXuatGiamDan() const {
        vector<Oto*> result = danhSachXe;
        sort(result.begin(), result.end(), [](Oto* a, Oto* b) {
            return a->getNamSanXuat() > b->getNamSanXuat();
            });
        return result;
    }

    void nhapCungDuLieu() {
        themXe(new Otokhach("K001", 2022, 2.5, 50000000, "xe du lich", 4));
        themXe(new Otokhach("K002", 2020, 3.0, 70000000, "xe bus", 30));
        themXe(new Ototai("T001", 2021, 3.5, 60000000, 1000));
        themXe(new Ototai("T002", 2019, 2.0, 40000000, 800));
        themXe(new Otokhach("K003", 2023, 1.8, 30000000, "xe ban tai", 2));
    }

    void xuatDanhSachXe() const {
        cout << setw(5) << "Ma" << setw(8) << "Nam SX" << setw(19) << "Dung tich dong co"
            << setw(9) << "Tri gia" << setw(16) << "Loai" << setw(25) << "So cho/Tai trong(kg)"
            << setw(25) << "Thue" << endl;

        for (Oto* xe : danhSachXe) {
            cout << xe->toString() << endl;
        }
    }
};

void Menu() {
    cout << "===================MENU=================\n";
    cout << "1. Them xe\n";
    cout << "2. In danh sach xe\n";
    cout << "3. Cap nhat tri gia xe\n";
    cout << "4. Dem xe co thue truoc ba > 200.000.000\n";
    cout << "5. Lay danh sach xe khach theo nam san xuat\n";
    cout << "6. Sap xep danh sach theo nam san xuat giam dan\n";
    cout << "0. Thoat\n";
    cout << "=======================================\n";
}

int main() {
    QuanLyShowroom ql;
    int luaChon;

    ql.nhapCungDuLieu();

    do {
        Menu();
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            int loaiXe;
            cout << "Nhap loai xe (1: Oto khach, 2: Oto tai): ";
            cin >> loaiXe;

            if (loaiXe == 1) {
                string ma, loaiXe;
                int namSanXuat, soCho;
                double dungTichDongCo, triGiaXe;
                cout << "Nhap ma xe: ";
                cin >> ma;
                cout << "Nhap nam san xuat: ";
                cin >> namSanXuat;
                cout << "Nhap dung tich dong co: ";
                cin >> dungTichDongCo;
                cout << "Nhap tri gia xe: ";
                cin >> triGiaXe;
                cout << "Nhap loai xe (xe bus, xe ban tai, xe du lich, xe khac): ";
                cin >> loaiXe;
                cout << "Nhap so cho: ";
                cin >> soCho;

                try {
                    ql.themXe(new Otokhach(ma, namSanXuat, dungTichDongCo, triGiaXe, loaiXe, soCho));
                }
                catch (const exception& e) {
                    cout << "Loi: " << e.what() << endl;
                }
            }
            else if (loaiXe == 2) {
                string ma;
                int namSanXuat;
                double dungTichDongCo, triGiaXe, taiTrong;
                cout << "Nhap ma xe: ";
                cin >> ma;
                cout << "Nhap nam san xuat: ";
                cin >> namSanXuat;
                cout << "Nhap dung tich dong co: ";
                cin >> dungTichDongCo;
                cout << "Nhap tri gia xe: ";
                cin >> triGiaXe;
                cout << "Nhap tai trong: ";
                cin >> taiTrong;

                try {
                    ql.themXe(new Ototai(ma, namSanXuat, dungTichDongCo, triGiaXe, taiTrong));
                }
                catch (const exception& e) {
                    cout << "Loi: " << e.what() << endl;
                }
            }
            else {
                cout << "Loai xe khong hop le." << endl;
            }
            break;
        }
        case 2:
            cout << "Danh sach xe:\n";
            ql.xuatDanhSachXe();
            break;
        case 3: {
            string ma;
            double triGiaMoi;
            cout << "Nhap ma xe can cap nhat tri gia: ";
            cin >> ma;
            cout << "Nhap tri gia moi: ";
            cin >> triGiaMoi;
            ql.capNhatTriGiaXe(ma, triGiaMoi);
            break;
        }
        case 4:
            cout << "So luong xe co thue truoc ba > 200.000.000: " << ql.demXeThueTruocBaLonHon(200000000) << endl;
            break;
        case 5: {
            int nam;
            cout << "Nhap nam san xuat can lay danh sach xe khach: ";
            cin >> nam;
            vector<Otokhach*> ds = ql.layDanhSachXeKhachTheoNam(nam);
            cout << "Danh sach xe khach san xuat nam " << nam << ":\n";
            for (Otokhach* khach : ds) {
                cout << khach->toString() << endl;
            }
            break;
        }
        case 6: {
            vector<Oto*> ds = ql.sapXepTheoNamSanXuatGiamDan();
            cout << "Danh sach xe sap xep theo nam san xuat giam dan:\n";
            for (Oto* xe : ds) {
                cout << xe->toString() << endl;
            }
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (luaChon != 0);

    return 0;
}
