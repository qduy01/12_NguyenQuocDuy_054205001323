#pragma once
#include "Oto.h"

class Ototai : public Oto {
private:
    int taiTrong;

public:
    Ototai();
    Ototai(string, int, double, int, int);

    void setTaiTrong(int taiTrong);
    int getTaiTrong() const;

    int tinhThue() const override;
    string toString() const override;
};


