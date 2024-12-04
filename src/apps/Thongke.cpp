#include "app/Thongke.hpp"
#include "app/ThemHangHoa.hpp"
#include "app/Nhap_xuat.hpp"
#include "eins/db.hpp"
#include "CTDL/Date.cpp"

void Hoa_don::xoa(int index, Hanghoa &hanghoa) {
    
}

void Hoa_don::sua(int index, Hanghoa &hanghoa) {
   
}

void Hoa_don::nhap1(int index, Hanghoa &hanghoa) {
    
}

void Hoa_don::mua1(int index, Hanghoa &hanghoa) {
    Nhap_xuat nhap_xuat;
    nhap_xuat.nhap_xuat(hanghoa, index, 1);
}

void Hoa_don::capnhat(Hanghoa &hanghoa) {
    infos->DetachAllChildren();
    hanghoa.getMang().clear();
    for (int c = 0; c < hanghoa.getHoaDon().length(); c++) {
        if (hanghoa.getHoaDon()[c].hang.ten.find(da_nhap) != std::string::npos) {
            infos->Add(Button("hihi", []() {}, info(Color::Black, c, hanghoa)));
            hanghoa.getMang().insert(c);
        }
        
    }
}

ButtonOption Hoa_don::info(Color color, int e, Hanghoa &hanghoa) {
    auto option = ButtonOption::Animated(color);
    Date date = hanghoa.getHoaDon()[e].date;
    string date1 = to_string(date.getNgay()) + '/' + to_string( date.getThang()) + '/' +to_string(date.getNam());
    option.transform = [=](EntryState state) {
        return hbox({
            hbox({text(hanghoa.getHoaDon()[e].ten) | size(WIDTH, EQUAL, 30) | center,
                    text(to_string(hanghoa.getHoaDon()[e].gia)) | size(WIDTH, EQUAL, 10) | center,
                  text(to_string( hanghoa.getHoaDon()[e].soLuong)) | size(WIDTH, EQUAL, 10) | center,
                  
                  text(date1) | size(WIDTH, EQUAL, 30) | center,

                
            })| size(HEIGHT, EQUAL, 3) | center,
        });
    };
    return option;
}

void Hoa_don::create(Hanghoa &hanghoa, int select) {
    auto screen = ScreenInteractive::TerminalOutput();
    
    auto inputoption = InputOption::Spacious();

    // button
    Component button1[4];
    Component button_thoat = Button("Thoat", [&] { screen.Exit(); }, ButtonOption::Animated(Color::Red));    

    auto option = MenuOption::HorizontalAnimated();
    option.underline.SetAnimationFunction(animation::easing::BackOut);
    option.underline.SetAnimationDuration(350ms);
    option.entries_option.transform = [&](EntryState state) {
        auto e = text(tab_values[state.index]) | center;
        switch (state.index) {
            case 0:
                e = e | size(WIDTH, EQUAL, 29) | center;
                break;
            case 1:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
            case 2:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
            case 3:
                e = e | size(WIDTH, EQUAL, 29) | center;
                break;
        }
        return e;
    };

    inputoption.on_change = [&] {
        infos->DetachAllChildren();
        hanghoa.getMang().clear();
        capnhat(hanghoa);
    };
    auto input = Input(&da_nhap, "Nhap", inputoption);

    option.on_change = [&] {
        switch (tab_selected) {
            case 0:
                hanghoa.getHoaDon().sort(compareBytenAsc);
                break;
            case 1:
                hanghoa.getHoaDon().sort(compareBygiaAsc);
                break;
            case 2:
                hanghoa.getHoaDon().sort(compareBysoLuongAsc);
                break;
            case 3:
                hanghoa.getHoaDon().sort(compareByDateAsc);
                break;

        }
        capnhat(hanghoa);
    };
    auto menu = Menu(&tab_values, &tab_selected, option);
    hanghoa.getMang().clear();
    for (int c = 0; c < hanghoa.getHoaDon().length(); c++) {
        
        infos->Add(Button("hihi", [this, c]() { this->selecinfo = c; }, info(Color::Black, c, hanghoa)));
        hanghoa.getMang().insert(c);
    }

    auto layout = Container::Vertical({
        input,
        menu,
        infos,
        button_thoat,
    });
   
    
   

    auto layouts = Renderer(layout, [&] {
        return hbox({
            vbox({
                input->Render() | center | borderRounded,
                menu->Render(),
                infos->Render() | vscroll_indicator | frame|size(HEIGHT, EQUAL, 28),
                hbox({button_thoat->Render() | center}),
            }) | center | borderRounded,
        });
    });

    screen.Loop(layouts);
}
