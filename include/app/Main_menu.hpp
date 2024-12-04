#pragma once
#include "eins/tui_support.h"

using namespace std;


class MainMenu {
    private:
        vector<string> tab = {"SẢN PHẨM ", "KHÁCH HÀNG", "ĐƠN HÀNG", "NHÂN VIÊN"};
        int selected = 0;
        vector<string> tab1 = {"THÊM SẢN PHẨM", "CHỈNH SỬA SẢN PHẨM"};
        int selected1 = 0;
        vector<string> tab2 = {"THÊM KHÁCH HÀNG", "CHỈNH SỬA KHÁCH HÀNG", "THỐNG KÊ KHÁCH HÀNG"};
        int selected2 = 0;
        vector<string> tab3 = { "THÊM ĐƠN HÀNG","THÔNG TIN ĐƠN HÀNG", "THỐNG KÊ ĐƠN HÀNG"};
        int selected3 = 0;
        vector<string> tab4 = {"THÊM NHÂN VIÊN", "CHỈNH SỬA NHÂN VIÊN", "THỐNG KÊ NHÂN VIÊN"};
        int selected4 = 0;

        ScreenInteractive screen = ScreenInteractive::TerminalOutput();
        Component menu;
    public:
        ButtonOption optional(Color color, int &selected);
        ButtonOption optional1(Color color, int &selected);
        void enter(Hanghoa &hanghoa, Khach_hang &khachhang);
        void create(Hanghoa &hanghoa, Khach_hang &khachhang);
        void run(bool i);
        void exitmain(Hanghoa hanghoa, Khach_hang khachhang);
        void trans(Hanghoa &hanghoa, Khach_hang &khachhang);
};