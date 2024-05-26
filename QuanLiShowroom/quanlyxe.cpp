#include "QuanLyXe.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

QuanLyXe::QuanLyXe() {}

QuanLyXe::~QuanLyXe()
{
    for (Xe* xe : danhSachXe)
    {
        delete xe;
    }
}

void QuanLyXe::themXe(Xe* xe) {
    danhSachXe.push_back(xe);
}

int QuanLyXe::demXeThueTruocBaTren200Tr() const
{
    int count = 0;
    for (Xe* xe : danhSachXe)
    {
        if (xe->tinhThue() > 200000000)
        {
            count++;
        }
    }
    return count;
}

vector<Xe*> QuanLyXe::danhSachXeKhachNamX(int nam) const
{
    vector<Xe*> result;
    for (Xe* xe : danhSachXe)
    {
        if (xe->getNamSanXuat() == nam && dynamic_cast<XeKhach*>(xe))
        {
            result.push_back(xe);
        }
    }
    return result;
}

void QuanLyXe::capNhatTriGiaXe(string ma, float triGiaMoi)
{
    for (Xe* xe : danhSachXe)
    {
        if (xe->getMa() == ma)
        {
            xe->setTriGia(triGiaMoi);
            return;
        }
    }
}

vector<Xe*> QuanLyXe::sapXepGiamTheoNamSanXuat() const
{
    vector<Xe*> temp = danhSachXe;
    sort(temp.begin(), temp.end(), [](const Xe* a, const Xe* b)
        {
            return a->getNamSanXuat() > b->getNamSanXuat();
        });
    return temp;
}

void QuanLyXe::them5XeMau()
{
    srand(time(nullptr));
    for (int i = 0; i < 5; i++)
    {
        int type = rand() % 2;
        string ma = "XE" + to_string(i + 1);
        int nam = rand() % 10 + 2010;
        double dungTich = (double)(rand() % 100 + 50);
        double triGia = (double)(rand() % 200 + 100) * 1000000;
        if (type == 0)
        {
            string loaiXe[4] = { "Xe bus", "Xe ban tai", "Xe du lich", "Xe khac" };
            string loai = loaiXe[rand() % 4];
            int soCho = rand() % 49 + 2;
            themXe(new XeKhach(ma, nam, dungTich, triGia, loai, soCho));
        }
        else {
            int taiTrong = (int)(rand() % 5000 + 1000);
            themXe(new XeTai(ma, nam, dungTich, triGia, taiTrong));
        }
    }
}

void QuanLyXe::xuatDanhSachXe() const
{
    cout << setw(10) << left << "Ma"
        << setw(15) << left << "Nam SX"
        << setw(15) << left << "Dung tich"
        << setw(15) << left << "Tri gia"
        << setw(20) << left << "Thue" << endl;
    for (Xe* xe : danhSachXe)
    {
        cout << setw(10) << left << xe->getMa()
            << setw(15) << left << xe->getNamSanXuat()
            << setw(15) << left << xe->getDungTichDongCo()
            << setw(15) << left << xe->getTriGia()
            << setw(20) << left << xe->tinhThue() << endl;
    }
}

void QuanLyXe::menu()
{
    int choice;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Them xe" << endl;
        cout << "2. Dem so luong xe co thue truoc ba > 200.000.000" << endl;
        cout << "3. Lay danh sach cac xe o to khach duoc san xuat trong nam x" << endl;
        cout << "4. Cap nhat tri gia xe moi dua vao ma" << endl;
        cout << "5. Sap xep giam theo nam san xuat" << endl;
        cout << "6. Them vao danh sach 5 xe du loai, xuat ra toan bo danh sach" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Them xe
            themXeMenu();
            break;
        case 2:
            // Dem so luong xe co thue truoc ba tren 200.000.000
            cout << "So luong xe co thue truoc ba tren 200.000.000: " << demXeThueTruocBaTren200Tr() << endl;
            break;
        case 3:
            // Lay danh sach cac xe o to khach duoc san xuat trong nam x
            danhSachXeNamXMenu();
            break;
        case 4:
            // Cap nhat tri gia xe moi dua vao ma
            capNhatTriGiaXeMenu();
            break;
        case 5:
            // Sap xep giam theo nam san xuat
            xuatDanhSachXeSapXepMenu();
            break;
        case 6:
            // Them vao danh sach 5 xe du loai, xuat ra toan bo danh sach
            them5XeMau();
            xuatDanhSachXe();
            break;
        case 7:
            // Thoat
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
        }
    } while (choice != 7);
}

void QuanLyXe::themXeMenu()
{
    int choice;
    do
    {
        cout << "\n===== MENU THEM XE =====" << endl;
        cout << "1. Them xe o to khach" << endl;
        cout << "2. Them xe o to tai" << endl;
        cout << "3. Quay lai" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Them xe o to khach
            themXeKhachMenu();
            break;
        case 2:
            // Them xe o to tai
            themXeTaiMenu();
            break;
        case 3:
            // Quay lai
            return;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
        }
    } while (choice != 3);
}

void QuanLyXe::themXeKhachMenu()
{
    string ma, loaiXe;
    int namSanXuat, soCho;
    float dungTichDongCo, triGia;

    cout << "Nhap ma xe: ";
    cin >> ma;
    cout << "Nhap nam san xuat: ";
    cin >> namSanXuat;
    cout << "Nhap dung tich dong co: ";
    cin >> dungTichDongCo;
    cout << "Nhap tri gia: ";
    cin >> triGia;
    cout << "Nhap loai xe: ";
    cin.ignore();
    getline(cin, loaiXe);
    cout << "Nhap so cho: ";
    cin >> soCho;

    themXe(new XeKhach(ma, namSanXuat, dungTichDongCo, triGia, loaiXe, soCho));
}

void QuanLyXe::themXeTaiMenu() {
    string ma;
    int namSanXuat, taiTrong;
    double dungTichDongCo, triGia;

    cout << "Nhap ma xe: ";
    cin >> ma;
    cout << "Nhap nam san xuat: ";
    cin >> namSanXuat;
    cout << "Nhap dung tich dong co: ";
    cin >> dungTichDongCo;
    cout << "Nhap tri gia: ";
    cin >> triGia;
    cout << "Nhap tai trong: ";
    cin >> taiTrong;
    themXe(new XeTai(ma, namSanXuat, dungTichDongCo, triGia, taiTrong));
}

void QuanLyXe::danhSachXeNamXMenu()
{
    int nam;
    cout << "Nhap nam san xuat can tim: ";
    cin >> nam;
    vector<Xe*> danhSachXeNamX = danhSachXeKhachNamX(nam);
    if (!danhSachXeNamX.empty())
    {
        cout << "Danh sach xe o to khach san xuat trong nam " << nam << ":" << endl;
        for (Xe* xe : danhSachXeNamX) {
            cout << xe->toString() << endl;
        }
    }
    else
    {
        cout << "Khong co xe o to khach nao duoc san xuat trong nam " << nam << endl;
    }
}

void QuanLyXe::capNhatTriGiaXeMenu()
{
    string ma;
    double triGiaMoi;
    cout << "Nhap ma xe can cap nhat tri gia moi: ";
    cin >> ma;
    cout << "Nhap tri gia moi: ";
    cin >> triGiaMoi;
    capNhatTriGiaXe(ma, triGiaMoi);

    cout << "Danh sach sau khi cap nhat tri gia:" << endl;
    xuatDanhSachXe();
}

void QuanLyXe::xuatDanhSachXeSapXepMenu()
{
    cout << "Danh sach sau khi sap xep giam dan theo nam san xuat:" << endl;
    vector<Xe*> danhSachSapXep = sapXepGiamTheoNamSanXuat();
    for (Xe* xe : danhSachSapXep) {
        cout << xe->toString() << endl;
    }
}