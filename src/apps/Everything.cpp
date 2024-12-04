#include "app/Everything.hpp"
#include "app/ThemHangHoa.hpp"
#include "app/Nhap_xuat.hpp"


void Everything::xoa(int index, Hanghoa &hanghoa) {
    hanghoa.hang().remove(hanghoa.getMang()[index]);
}

void Everything::sua(int index, Hanghoa &hanghoa) {
    system("cls");
    ThemHangHoa them_hang_hoa;
    int i = hanghoa.getMang()[index];
    them_hang_hoa.sua(i, hanghoa);
    them_hang_hoa.create(1, hanghoa);
}

void Everything::nhap1(int index, Hanghoa &hanghoa) {
    Nhap_xuat nhap_xuat;
    nhap_xuat.nhap_xuat(hanghoa, index, 0);
}

void Everything::mua1(int index, Hanghoa &hanghoa) {
    Nhap_xuat nhap_xuat;
    nhap_xuat.nhap_xuat(hanghoa, index, 1);
}

void Everything::capnhat(Hanghoa &hanghoa) {
    switch (tab_selected) {
            case 0:
                hanghoa.hang().sort(compareByKeyAsc);
                break;
            case 1:
                hanghoa.hang().sort(compareBytenAsc);
                break;
            case 2:
                hanghoa.hang().sort(compareBygiaAsc);
                break;
        }
    infos->DetachAllChildren();
    hanghoa.getMang().clear();
    for (int c = 0; c < hanghoa.hang().length(); c++) {
        if(ma_hang == "Tat ca") {
            if (hanghoa.hang()[c].ten.find(da_nhap) != std::string::npos) {
                infos->Add(Button(to_string(c), [this, c]() { this->selecinfo = c; }, info(Color::Black, c, hanghoa)));
                hanghoa.getMang().insert(c);
            }
        } 
        else if (hanghoa.hang()[c].key.find(ma_hang) != std::string::npos) {
                if (hanghoa.hang()[c].ten.find(da_nhap) != std::string::npos) {
                infos->Add(Button(to_string(c), []() {}, info(Color::Black, c, hanghoa)));
                hanghoa.getMang().insert(c);
            }
        }
    }
}

ButtonOption Everything::info(Color color, int e, Hanghoa &hanghoa) {
    auto option = ButtonOption::Animated(color);
    option.transform = [=](EntryState state) {
        int i = stoi(state.label);
        return hbox({
            hbox({text(hanghoa.hang()[i].key) | size(WIDTH, EQUAL, 10) | center,
                  text(hanghoa.hang()[i].ten) | size(WIDTH, EQUAL, 30) | center,
                  text(to_string(hanghoa.hang()[i].gia)) | size(WIDTH, EQUAL, 10) | center, 
                  text(to_string(hanghoa.hang()[i].soLuong)) | size(WIDTH, EQUAL, 10) | center,
                  text(to_string(hanghoa.hang()[i].giaNhap)) | size(WIDTH, EQUAL, 10) | center,
                
            })| size(HEIGHT, EQUAL, 3) | center,
        });
    };
    return option;
}

DropdownOption Everything::dropdown_ma(Hanghoa &hanghoa) {
    auto option = DropdownOption();
    option.radiobox.entries = &ma_hanghoa;
    option.radiobox.selected = &selected_ma;
    option.radiobox.transform = [&](const EntryState& s) {
        auto t = text(s.label) | borderEmpty;
        if (s.active) {
            t |= bold;
            

        }
        if (s.focused) {
            t |= inverted;
        }
        return t;
    };
    option.radiobox.on_change = [&] {
        ma_hang = ma_hanghoa[selected_ma];
        capnhat(hanghoa);
        
    };
    option.transform = [&](bool open, Element checkbox, Element radiobox) {
        checkbox |= borderEmpty;
        if (open) {
            return vbox({
                checkbox | inverted,
                radiobox | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, 20) | bgcolor(Color::Red),
                filler(),
            });
        }
        return vbox({
            checkbox | bgcolor(Color::Red),
            filler(),
        });
    };
    return option;
}

void Everything::create(Hanghoa &hanghoa, int select) {
    auto screen = ScreenInteractive::TerminalOutput();
    
    auto inputoption = InputOption::Spacious();

    // button
    Component button1[4];
    Component button_cancel = Button("Xoa", [&] { hanghoa.hang().remove(hanghoa.getMang()[selecinfo]);capnhat(hanghoa);}, ButtonOption::Animated(Color::Red));
    Component button1_sua = Button("Sua", [&] { sua(selecinfo, hanghoa); capnhat(hanghoa); }, ButtonOption::Animated(Color::Red));
    
    Component button_mua = Button("Mua", [&] { mua1(selecinfo, hanghoa); capnhat(hanghoa); }, ButtonOption::Animated(Color::Blue1));
    Component button_ban = Button("Nhap", [&] { nhap1(selecinfo, hanghoa); capnhat(hanghoa); }, ButtonOption::Animated(Color::Blue1));
    Component but = Button("Thoat", [&] { screen.Exit(); }, ButtonOption::Animated(Color::Red));    
    Component dropdown = Dropdown( dropdown_ma(hanghoa));



    


    auto option = MenuOption::HorizontalAnimated();
    option.underline.SetAnimationFunction(animation::easing::BackOut);
    option.underline.SetAnimationDuration(350ms);
    option.entries_option.transform = [&](EntryState state) {
        auto e = text(tab_values[state.index]) | center;
        switch (state.index) {
            case 0:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
            case 1:
                e = e | size(WIDTH, EQUAL, 29) | center;
                break;
            case 2:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
            case 3:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
        }
        return e;
    };

    inputoption.on_change = [&] {
        capnhat(hanghoa);
    };
    auto input = Input(&da_nhap, "Nhap", inputoption);

    option.on_change = [&] {
        
        capnhat(hanghoa);
    };
    auto menu = Menu(&tab_values, &tab_selected, option);
    //hanghoa.getMang().clear();
    for (int c = 0; c < hanghoa.hang().length(); c++) {
        
        infos->Add(Button(to_string(c), [this, c]() { this->selecinfo = c; }, info(Color::Black, c, hanghoa)));
        hanghoa.getMang().insert(c);
    }

    auto layout = Container::Vertical({
        input,
        menu,
        infos,
    });

    auto layout_choice = Container::Horizontal({
        layout,
        dropdown,

    });
    if (select == 0) {
        button1[0] = button_cancel;
        button1[1] = button1_sua;
    } else if (select == 1) {
        button1[0] = button_mua;
        button1[1] = button_ban;
    }
    
    layout->Add(button1[0]);
    layout->Add(button1[1]);
    layout->Add(but);

    auto layouts = Renderer(layout_choice, [&] {
        return hbox({
            vbox({
                input->Render() | center | borderRounded,
                menu->Render(),
                infos->Render() | vscroll_indicator | frame|size(HEIGHT, EQUAL, 28),
                hbox({button1[0]->Render() | center, button1[1]->Render() | center,but->Render()|center}),
            }) | center | borderRounded,
            dropdown->Render()  ,
        });
    });

  
    

    screen.Loop(layouts);
}
