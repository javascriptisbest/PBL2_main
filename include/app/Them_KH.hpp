#pragma once

#include "eins/tui_support.h"
using namespace std;


class Them_KH {
    private:
        int selected = 0;
        ScreenInteractive screen = ScreenInteractive::TerminalOutput();
        Component menu;
        string ten;
        string mk;
        string sdt;
        string diachi;
        string email;
        string gioitinh;
        string maThe;
        string hanThe;
        string diem;
        string soLanMua;
        string text_errror = "";
    public:
       // void sua(int index, Khach_hang &khachhang);
        void insert(Khach_hang &khachhang);
        void sua(Khach_hang &khachhang);
        void sua(Khach_hang &khachhang,int index);
        void create(bool co, Khach_hang &khachhang);
        InputOption style(string nhapgi);
};
