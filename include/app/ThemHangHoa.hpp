#pragma once
#include "eins/tui_support.h"
using namespace std;

class ThemHangHoa {
    private:
        int selected = 0;
        ScreenInteractive screen = ScreenInteractive::TerminalOutput();
        Component menu;
        string ten;
        string ma_hang_hoa;
        string SL;
        string ten_cu;
        string gia;
        string giaNhap;
        string text_errror = "";
    public:
        void sua(int index, Hanghoa &hanghoa);
        void insert(Hanghoa &hanghoa);
        void sua(Hanghoa &hanghoa);
        void create(bool co, Hanghoa &hanghoa);
};
