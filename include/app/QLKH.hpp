#pragma once
#include "eins/tui_support.h"


using namespace std;
class QLKH {
public:
    string da_nhap;
    int selecinfo;
    MenuOption option1;
    Component infos = Container::Vertical({}, &selecinfo);
    void capnhat(Khach_hang &khachhang);

    vector<string> tab_values = {"Ma the", "Ten", "Email", "Diem"};
    vector<string> ma_hanghoa = {"Tat ca", "BC", "BD", "VT","QA" };
    string ma_hang = "Tat ca";
    int selected_ma = 0;
    int tab_selected = 3;
    int selected = 0;


    void xoa(int index, Khach_hang &khachhang);
    ButtonOption info(Color color, int e, Khach_hang &khachhang);
    void create(Khach_hang &khachhang, int select);
    
};