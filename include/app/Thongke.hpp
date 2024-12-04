#pragma once

#include "eins/tui_support.h"

using namespace std;
class Hoa_don {
public:
    string da_nhap;
    int selecinfo;
    Component infos = Container::Vertical({}, &selecinfo);
    void capnhat(Hanghoa &hanghoa);

    vector<string> tab_values = {"Ten san pham", "Gia tien", "So luong", "ngay dang ky"};
    int tab_selected = 3;
    int selected = 0;

    void xoa(int index, Hanghoa &hh);
    ButtonOption info(Color color, int e, Hanghoa &hh);
    ButtonOption hangmua(Color color, int &selected);
    void sua(int index, Hanghoa &hanghoa);
    void create(Hanghoa &hanghoa, int select);
    void nhap1(int index, Hanghoa &hanghoa);
    void mua1(int index, Hanghoa &hanghoa);
};