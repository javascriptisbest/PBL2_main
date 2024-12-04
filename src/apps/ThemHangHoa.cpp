#include "app/ThemHangHoa.hpp"
#include "CTDL/Hanghoa.hpp"

void ThemHangHoa::sua(int index, Hanghoa &hanghoa) {
    ten = hanghoa.hang()[index].ten;
    ten_cu = ten;
    ma_hang_hoa = hanghoa.hang()[index].key;
    SL = std::to_string(hanghoa.hang()[index].soLuong);
    gia = std::to_string(hanghoa.hang()[index].gia);
    giaNhap = std::to_string(hanghoa.hang()[index].giaNhap);
}

void ThemHangHoa::insert(Hanghoa &hanghoa) {
    Hang hang;
    hang.ten = ten;
    hang.key = ma_hang_hoa;
    if (gia == "") gia = "0";
    else hang.gia = stoi(gia);
    if (SL == "") SL = "0";
    else hang.soLuong = stoi(SL);
    if (giaNhap == "") giaNhap = "0";
    else hang.giaNhap = stoi(giaNhap);
    hanghoa.hang().insert(hang);
}

void ThemHangHoa::sua(Hanghoa &hanghoa) {
    Hang hang;
    hang.ten = ten;
    hang.key = ma_hang_hoa;
    if (gia == "") gia = "0";
    else hang.gia = stoi(gia);
    if (SL == "") SL = "0";
    else hang.soLuong = stoi(SL);
    if (giaNhap == "") giaNhap = "0";
    else hang.giaNhap = stoi(giaNhap);
    hanghoa.hang().insert(hang);
    hanghoa.hang().remove2(ten_cu);
}
Component text_convert(string text1,int width){
    return Renderer([=]{return hbox({text(text1)|center })| center| size(WIDTH, EQUAL,width ) | borderStyled(Color::Red) |center| size(HEIGHT, EQUAL, 4) ;});
}

void ThemHangHoa::create(bool co, Hanghoa &hanghoa) {

    Component input_ten = Input(&ten, "Ten hang hoa");
    Component input_ma = Input(&ma_hang_hoa, "Ma hang hoa");
    Component text_muc = Renderer([&]{
        return hbox({text("Ma SP")| size(WIDTH, EQUAL, 10)|borderStyled(Color::Red)| size(HEIGHT,EQUAL, 4)|center,
                     text("Ten san pham")| size(WIDTH, EQUAL, 30)|borderStyled(Color::Red)| size(HEIGHT,EQUAL, 4)|center,
        });
    });
    input_ma |= CatchEvent([&](Event event) {
        if (event.is_character() && !std::isdigit(event.character()[0])) {

            text_errror = " Ma hang hoa khong duoc chua chu ";
            return true;
        }
        else return false;
    });
    input_ma |= CatchEvent([&](Event event) {
        if (event.is_character() && ma_hang_hoa.size() >= 4) {
            text_errror = "Ma hang hoa khong duoc qua 4 ky tu";
            return true;
        }
        else return false;
    });
    auto error = text(text_errror) | color(Color::Red);

    Component input_gia = Input(&gia, "Gia ban");
    input_gia |= CatchEvent([&](Event event) {
        if (event.is_character() && !std::isdigit(event.character()[0])) {
            text_errror = "Gia tien khong duoc chua chu";
            return true;
        }
        else if (event.is_character() && (gia.size() == 2 || (gia.size() % 3 == 0 && gia.size() != 0 && gia.size() != 3))) {
            event.character() = event.character() + ".";
        }
        return false;
    });
    

        Component input_gianhap = Input(&giaNhap, "Gia nhap");
    input_gianhap |= CatchEvent([&](Event event) {
        if (event.is_character() && !std::isdigit(event.character()[0])) {
            text_errror = "Gia tien khong duoc chua chu";
            return true;
        }
        else if (event.is_character() && (gia.size() == 2 || (gia.size() % 3 == 0 && gia.size() != 0 && gia.size() != 3))) {
            event.character() = event.character() + ".";
        }
        return false;
    });

    Component input_SL = Input(&SL, "So luong");
    input_SL |= CatchEvent([&](Event event) {
        if (event.is_character() && !std::isdigit(event.character()[0])) {
            text_errror = "So luong khong duoc chua chu";
            return true;
        }
        else return false;
    });
    Component button;
    if (co) {
        button = Button("Sửa", [&] { sua(hanghoa); screen.Exit(); }, ButtonOption::Animated(Color::Blue));
    }
    else {
        button = Button("Thêm", [&] { insert(hanghoa); screen.Exit(); }, ButtonOption::Animated(Color::Blue));
    }

    auto component = Container::Horizontal({
        input_ma,
        input_ten,
        input_gia,
        input_gianhap,
        input_SL,
        
    });

    auto renderer = Renderer( [&] {
        return vbox({
                separatorEmpty() | size(HEIGHT, EQUAL, 6),
                hbox({text_convert("Mã", 10)->Render(),
                      text("ten sp")|center|borderStyled(Color::Red)| size(WIDTH, EQUAL, 30)|center|size(HEIGHT,EQUAL,6),})|size(HEIGHT, EQUAL, 6)|center,
                
            
            separatorEmpty() | size(HEIGHT, EQUAL, 10),
        })| size(HEIGHT, EQUAL, 20)|center;
    });
    auto renderer1 = Container::Vertical({
        renderer,
    });

    auto renderer2 = Container::Vertical({
        renderer1,
        button
    });
    auto render = Renderer(renderer2, [&] {
        return vbox({
            text(text_errror),
            renderer1->Render() | size(HEIGHT, EQUAL, 25) | vscroll_indicator | frame | xflex,
            vbox({ separatorEmpty() | size(WIDTH, EQUAL, 30), button->Render() | center }),
        });
    });

    screen.Loop(renderer);
}