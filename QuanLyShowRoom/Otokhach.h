#pragma once
#include "Oto.h"

class Otokhach : public Oto {
private:
    string loaiXe;
    int soCho;

public:
    Otokhach();
    Otokhach(string, int, double, int, string, int);

    void setLoaiXe(string loaiXe);
    void setSoCho(int soCho);

    string getLoaiXe() const;
    int getSoCho() const;

    int tinhThue() const override;
    string toString() const override;
};


