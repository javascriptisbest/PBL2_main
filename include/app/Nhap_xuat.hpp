#pragma once
#include "eins/tui_support.h"
using namespace std;
class Nhap_xuat {
private:
    string SL;
    string date1;
public:
    void nhap_button(Hanghoa &hanghoa, int index);
    void ban_button(Hanghoa &hanghoa, int index);
    void nhap_xuat(Hanghoa &hanghoa, int index, int select);
};