#ifndef PBL_EVERYTHING_HPP
#define PBL_EVERYTHING_HPP
#include "eins/tui_support.h"

using namespace std;
class Everything {
public:
    string da_nhap;
    int selecinfo;
    Component infos = Container::Vertical({}, &selecinfo);
    void capnhat(Hanghoa &hanghoa);

    vector<string> tab_values = {"Ma", "Ten san pham", "Gia tien", "So luong","Gia nhap"};
    vector<string> ma_hanghoa = {"Tat ca", "BC", "BD", "VT","QA" };
    string ma_hang = "Tat ca";
    int selected_ma = 0;
    int tab_selected = 3;
    int selected = 0;


    void xoa(int index, Hanghoa &hh);
    ButtonOption info(Color color, int e, Hanghoa &hh);
    ButtonOption hangmua(Color color, int &selected);
    DropdownOption dropdown_ma(Hanghoa &hh);
    void sua(int index, Hanghoa &hanghoa);
    void create(Hanghoa &hanghoa, int select);
    void nhap1(int index, Hanghoa &hanghoa);
    void mua1(int index, Hanghoa &hanghoa);
};
#endif // PBL_EVERYTHING_HPP