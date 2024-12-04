
#include "app/Nhap_xuat.hpp"
string* split2(string str, char delim, int size = 20){
    string* arr = new string[size];
    int j = 0;
    for(int i = 0; j <= size;i++){
        if(str[i] == delim){
            j++;
        }
        else arr[j] += str[i];
        if(str[i] == '\0') break;
        
    }
    return arr;
}

void Nhap_xuat::nhap_button(Hanghoa &hanghoa, int index) {
    hanghoa.hang()[index].soLuong += stoi(SL);
    hanghoa.Money() -= hanghoa.hang()[index].giaNhap * stoi(SL);
    Hang hang;
    struct hoa_don hd;
    split2(date1, '/', 3);
    if(date1.length() != 3) ;
    else
    hd.date = Date(date1[0], date1[1], date1[2]);
    hd.hang = hanghoa.hang()[index];
    
    hd.ten = hanghoa.hang()[index].ten;

    hd.gia = hanghoa.hang()[index].gia;
    if(SL == "") hd.soLuong = 0;
    else hd.soLuong = stoi(SL);
    hanghoa.getHoaDon().insert(hd);

}

void Nhap_xuat::ban_button(Hanghoa &hanghoa, int index) {
    hanghoa.hang()[index].soLuong -= stoi(SL);
    hanghoa.Money() += hanghoa.hang()[index].gia * stoi(SL);
    Hang hang;
    struct hoa_don hd;
    // split2(date1, '/', 3);
    // if(date1.length() != 3) ;
    // else
    // hd.date = Date(date1[0], date1[1], date1[2]);
    hd.hang = hanghoa.hang()[index];
    if(SL == "") hd.soLuong = 0;
    else hd.soLuong = stoi(SL);
    hanghoa.getHoaDon().insert(hd);
}

void Nhap_xuat::nhap_xuat(Hanghoa &hanghoa, int index, int select) {
    int i = hanghoa.getMang()[index];
    
    auto screen = ScreenInteractive::TerminalOutput();
    auto inputoption = InputOption::Spacious();
    auto text1 = text(hanghoa.hang()[index].ten);
    auto text2 = text(to_string(hanghoa.hang()[index].gia));
    
    auto text0 = text(hanghoa.hang()[i].key);
    auto input = Input(&SL, "Nhap so luong", inputoption);

    auto date = Input(&date1, "Nhap ngay", inputoption);
    Component button;
    if (select) button = Button("OK", [&] { ban_button(hanghoa, i); screen.Exit(); }, ButtonOption::Animated(Color::Red));
    else button = Button("OK", [&] { nhap_button(hanghoa, i); screen.Exit(); }, ButtonOption::Animated(Color::Red));

    auto render = Container::Vertical({
        input,
        button,
    });
    auto renderer = Renderer(render, [&] {
        return vbox({
            hbox({
                text0 | center | size(WIDTH, EQUAL, 10),
                text1 | center | size(WIDTH, EQUAL, 30),
                text2 | center | size(WIDTH, EQUAL, 10),
                input->Render() | center,
                date->Render() | center,
            }),
            separatorEmpty() | size(HEIGHT, EQUAL, 10),
            hbox({ separatorEmpty() | size(WIDTH, EQUAL, 10), button->Render() | center }),
        });
    });
    screen.Loop(renderer);
}
