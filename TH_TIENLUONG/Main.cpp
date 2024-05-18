#include<iostream>
#include"Employee.h"
#include"ParTime.h"
#include"FullTime.h"
#include<string>
using namespace std;
// chuan hoa ten
string chuanHoaTen2(string& ten)
{
	ten[0] = toupper(ten[0]);
	for (int i = 1; i < ten.size(); i++)
	{
		ten[i] = tolower(ten[i]);
	}
	return ten;
}
void chuanHoaTen1(string& hoTenNhanVien)
{
	string tenTamThoi; string ten = "";
	vector<string> chuoiTen;
	while (hoTenNhanVien[0] == ' ')
	{
		hoTenNhanVien.erase(hoTenNhanVien.begin() + 0);
	}
	for (int i = 0; i < hoTenNhanVien.size(); i++)
	{
		if (hoTenNhanVien[i] != 0)
		{
			tenTamThoi = "";
			int j = i;
			while (j < hoTenNhanVien.size())
			{
				if (hoTenNhanVien[j] == ' ')
				{
					break;
				}
				else
				{
					tenTamThoi = tenTamThoi + hoTenNhanVien[j];
					j++;
				}
			}
			chuoiTen.push_back(tenTamThoi);
			i = j;
		}
	}
	for (int i = 0; i < chuoiTen.size(); i++)
	{
		ten = ten + " " + chuanHoaTen2(chuoiTen[i]);
	}
	ten.erase(ten.begin() + 0);
	hoTenNhanVien = ten;
}
// nhap cung
void nhapCung(vector<TienLuong*>& danhSachLuong)
{
	danhSachLuong.push_back(new FullTime("2005A", "Nguyen A", "5/12/2014", "0123456789", 27500000, 5.0, 10));
	danhSachLuong.push_back(new FullTime("2005B", "Nguyen B", "5/11/2014", "0012345678", 22440000, 5.1, 10));
	danhSachLuong.push_back(new FullTime("2005C", "Nguyen C", "5/10/2015", "0023456789", 22236000, 5.1, 9));
	danhSachLuong.push_back(new ParTime("2904D", "Nguyen D", "5/3/2019", "0102345678", 22000000, 36, 500000));
	danhSachLuong.push_back(new ParTime("2904E", "Nguyen E", "5/3/2019", "0201345678", 18200000, 33, 400000));
}
// nhap danh sach
void nhapdanhSachTienLuong(vector<TienLuong*>& danhSachLuong) {
	int luongFullTime, luongParTime, tongLuong;
	string hoTenNhanVien, ngayVaoLam, soDienThoai, maNhanVien;
	double heSoLuong = 0; // FullTime
	int soNamKinhNghiem; // FullTime
	int soGioLamTuan; // ParTime
	int mucLuongMoiGio; // ParTime

	cout << "Nhap so luong nhan vien Fulltime: ";
	cin >> luongFullTime;
	cout << "Nhap so luong nhan vien Partime: ";
	cin >> luongParTime;
	// FullTime
	cout << "* Tien luong Fulltime *" << endl;
	for (int i = 0; i < luongFullTime; i++) {
		cout << "______________________________________" << endl;
		cin.ignore();
		cout << "Ma so nhan vien: ";
		getline(cin, maNhanVien);
		cout << "Ho ten nhan vien: ";
		getline(cin, hoTenNhanVien);
		chuanHoaTen1(hoTenNhanVien);
		cout << "Ngay vao lam: ";
		getline(cin, ngayVaoLam);
		cout << "So dien thoai: ";
		getline(cin, soDienThoai);
		cout << "He so luong :";
		cin >> heSoLuong;
		if (heSoLuong >= 1.65 && heSoLuong <= 8) {
			cout << "So nam kinh nghiem: ";
			cin >> soNamKinhNghiem;
		}
		else cout << "Nhap lai :";
		cout << "Tong Luong: ";
		cin >> tongLuong;
		danhSachLuong.push_back(new FullTime(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, tongLuong, heSoLuong, soNamKinhNghiem));
	}
	cout << endl;
	// PartTime
	cout << "* Tien luong Partime *" << endl;
	for (int i = 0; i < luongParTime; i++) {
		cout << "_________________________________" << endl;
		cin.ignore();
		cout << "Ma so nhan vien: ";
		getline(cin, maNhanVien);
		cout << "Ho ten nhan vien: ";
		getline(cin, hoTenNhanVien);
		chuanHoaTen1(hoTenNhanVien);
		cout << "	Ngay vao lam: ";
		getline(cin, ngayVaoLam);
		cout << "So dien thoai: ";
		getline(cin, soDienThoai);
		cout << "So gio lam / tuan: ";
		cin >> soGioLamTuan;
		cout << "Muc luong moi gio: ";
		cin >> mucLuongMoiGio;
		cout << "Tong Luong: ";
		cin >> tongLuong;
		danhSachLuong.push_back(new ParTime(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, tongLuong, soGioLamTuan, mucLuongMoiGio));
	}
}
// tinh tong luong fulltime
int  sumFullTime(vector<TienLuong*> danhSachLuong)
{
	int sum = 0;
	for (int i = 0; i < danhSachLuong.size(); i++)
	{
		if (danhSachLuong[i]->isTienLuongGi())
		{
			sum = sum + danhSachLuong[i]->getTongLuong();
		}
	}
	return sum;
}
//   sap xep ngay
bool comparengayVaoLam(const std::string& ngayVaoLam1, const std::string& ngayVaoLam2) {
	return ngayVaoLam1 > ngayVaoLam2;
}
// tong luong partime
int  sumParTime(vector<TienLuong*> danhSachLuong)
{
	int sum = 0;
	for (int i = 0; i < danhSachLuong.size(); i++)
	{
		if (!(danhSachLuong[i]->isTienLuongGi()))
		{
			sum = sum + danhSachLuong[i]->getTongLuong();
		}
	}
	return sum;
}
// Xuat danh sach
void xuatDanhSach(vector<TienLuong*> danhSachLuong)
{
	cout << setfill('=') << setw(30) << "=" << "* Tien luong FullTime *" << setw(30) << "=" << endl;
	cout << setfill(' ');
	cout << setw(12) << "Ma nhan vien" << setw(15) << "Ho ten" << setw(15) << "Ngay lam";
	cout << setw(15) << "So dien thoai" << setw(13) << "he so luong" << setw(20) << "So nam kinh nghiem";
	cout << setw(12) << "Tong Luong" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachLuong.size(); i++)
	{
		if (danhSachLuong[i]->isTienLuongGi())
		{
			danhSachLuong[i]->thongTinTienLuong();
		}
	}
	cout << endl;
	cout << "Tong tien luong cua Fulltime: " << sumFullTime(danhSachLuong) << endl;
	cout << endl;
	cout << setfill('=') << setw(30) << "=" << "* Tien luong Partime *" << setw(30) << "=" << endl;
	cout << setfill(' ');
	cout << setw(12) << "Ma nhan vien" << setw(15) << "Ho ten" << setw(16) << "Ngay lam";
	cout << setw(15) << "So dien thoai" << setw(18) << "so gio lam/tuan" << setw(22) << "muc luong moi gio";
	cout << setw(12) << "Tong Luong" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachLuong.size(); i++)
	{
		if (!(danhSachLuong[i]->isTienLuongGi()))
		{
			danhSachLuong[i]->thongTinTienLuong();
		}
	}
	cout << endl;
	cout << "Tong tien luong cua Partime: " << sumParTime(danhSachLuong) << endl;
	cout << "\n\n\n";
	cout << "\t\t\t\t Tong luong cua Fulltime va Partime: " << sumFullTime(danhSachLuong) + sumParTime(danhSachLuong) << endl;
}
void menu()
{
	cout << "===========================*Menu *========================= " << endl;
	cout << "1. Nhap cung                                               *\n";
	cout << "2. Nhap mem                                                *\n";
	cout << "3. Xuat danh sach nhan vien                                *\n";
	cout << "0. Thoat                                                   *\n";
	cout << "============================================================" << endl;
}
int main()
{
	vector<TienLuong*> danhSachLuong;

	int luaChon;
	do
	{
		system("cls");
		menu();

		int chon;
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			nhapCung(danhSachLuong);
			break;
		}
		case 2:
		{
			nhapdanhSachTienLuong(danhSachLuong);
			break;
		}
		case 3:
		{
			xuatDanhSach(danhSachLuong);
			break;
		}

		default:
		{
			luaChon = 0;
		}
		}
		cout << "------------------------------------------" << endl;
		cout << "1. Tiep tuc    0.Thoat" << endl;
		cout << "Chon:";
		cin >> luaChon;
	} while (luaChon != 0);


}
