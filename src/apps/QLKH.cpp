#include "app/QLKH.hpp"



void QLKH::capnhat(Khach_hang &khachhang) {
    switch (tab_selected) {
            case 0:
                khachhang.getKhachHang().sort(compareBymaTheAsc<Khach>);
                break;
            case 1:
                khachhang.getKhachHang().sort(compareByTenAsc<Khach>);
                break;
            case 2:
                khachhang.getKhachHang().sort(compareByemailAsc<Khach>);
                break;
        }
    infos->DetachAllChildren();
    khachhang.getMang().clear();
    for (int c = 0; c < khachhang.getKhachHang().length(); c++) {
        if (khachhang.getKhachHang()[c].ten.find(da_nhap) != std::string::npos) {
            infos->Add(Button(to_string(c), [this, c]() { this->selecinfo = c; }, info(Color::Black, c, khachhang)));
            khachhang.getMang().insert(c);
        }
    } 
       
    
}

ButtonOption QLKH::info(Color color, int e, Khach_hang &khachhang) {
    auto option = ButtonOption::Animated(color);
    option.transform = [=](EntryState state) {
        return hbox({
            hbox({text(khachhang[e].maThe) | size(WIDTH, EQUAL, 15) | center,
                  text(khachhang[e].ten) | size(WIDTH, EQUAL, 30) | center,
                  text(khachhang[e].email)| size(WIDTH, EQUAL, 15) | center, 
                  text(to_string(khachhang[e].diem)) | size(WIDTH, EQUAL, 10) | center,
                
            })| size(HEIGHT, EQUAL, 3) | center,
        });
    };
    return option;
}

// DropdownOption QLKH::dropdown_ma() {
//     auto option = DropdownOption();
//     option.radiobox.entries = &ma_hanghoa;
//     option.radiobox.selected = &selected_ma;
//     option.radiobox.transform = [&](const EntryState& s) {
//         auto t = text(s.label) | borderEmpty;
//         if (s.active) {
//             t |= bold;
            

//         }
//         if (s.focused) {
//             t |= inverted;
//         }
//         return t;
//     };
//     option.radiobox.on_change = [&] {
//         ma_hang = ma_hanghoa[selected_ma];
//         capnhat(k);
        
//     };
//     option.transform = [&](bool open, Element checkbox, Element radiobox) {
//         checkbox |= borderEmpty;
//         if (open) {
//             return vbox({
//                 checkbox | inverted,
//                 radiobox | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, 20) | bgcolor(Color::Red),
//                 filler(),
//             });
//         }
//         return vbox({
//             checkbox | bgcolor(Color::Red),
//             filler(),
//         });
//     };
//     return option;
// }

void QLKH::xoa(int index, Khach_hang &khachhang) {
    khachhang.xoa(khachhang.getMang()[index]);
    capnhat(khachhang);
}


void add(Khach_hang &khachhang,int index){
    
}

InputOption style(string nhapgi) {
    auto style_4 = InputOption::Spacious();
  style_4.transform = [=](InputState state) {
    state.element = hbox({
        text(nhapgi) | center | borderEmpty | bgcolor(Color::Red),
        separatorEmpty(),
        separator() | color(Color::White),
        separatorEmpty(),
        std::move(state.element),
    });
 
    state.element |= borderEmpty;
    if (state.is_placeholder) {
      state.element |= color(Color::Grey70);
    }
 
    if (state.focused) {
      state.element |= bgcolor(Color::Black);
    } else {
      state.element |= bgcolor(Color::Grey23); }
 
    if (state.hovered) {
      state.element |= bgcolor(Color::GrayDark);
    }
 
    return vbox({state.element, separatorEmpty()});
  };
    return style_4;
};


void QLKH::create(Khach_hang &khachhang, int select) {
   


    auto screen = ScreenInteractive::TerminalOutput();
    
    auto inputoption = InputOption::Spacious();

    // button
    Component button1[4];
    Component button_cancel = Button("Xoa", [&] {xoa(selecinfo,khachhang);}, ButtonOption::Animated(Color::Red));
    Component button1_sua = Button("Sua", [&] { }, ButtonOption::Animated(Color::Red));
    

    Component but = Button("Thoat", [&] { }, ButtonOption::Animated(Color::Red));    
    



    


    auto option = MenuOption::HorizontalAnimated();
    option.underline.SetAnimationFunction(animation::easing::BackOut);
    option.underline.SetAnimationDuration(350ms);
    option.entries_option.transform = [&](EntryState state) {

        auto e = text(tab_values[state.index]) | center;
        switch (state.index) {
            case 0:
                e = e | size(WIDTH, EQUAL, 14) | center;
                break;
            case 1:
                e = e | size(WIDTH, EQUAL, 29) | center;
                break;
            case 2:
                e = e | size(WIDTH, EQUAL, 14) | center;
                break;
            case 3:
                e = e | size(WIDTH, EQUAL, 9) | center;
                break;
        }
        return e;
    };

    inputoption.on_change = [&] {
        capnhat(khachhang);
    };
    auto input = Input(&da_nhap, "Nhap", inputoption);

    option.on_change = [&] {
        
        capnhat(khachhang);
    

    };
    auto menu = Menu(&tab_values, &tab_selected, option);
    //hanghoa.getMang().clear();
    khachhang.getMang().clear();
    for (int c = 0; c < khachhang.getKhachHang().length(); c++) {
        
        infos->Add(Button("", [this, c]() { this->selecinfo = c; }, info(Color::Black, c, khachhang)));
        khachhang.getMang().insert(c);
    }

    auto layout = Container::Vertical({
        input,
        menu,
        infos,
    });

    

    auto layout_choice = Container::Horizontal({
        layout,

    });
    
        button1[0] = button_cancel;
        button1[1] = button1_sua;
   
    layout->Add(button1[0]);
    layout->Add(button1[1]);
    layout->Add(but);

    auto layouts = Renderer(layout_choice, [&] {
        return hbox({
            vbox({
                input->Render() | center | borderRounded,
                menu->Render(),
                infos->Render() | vscroll_indicator | frame|size(HEIGHT, EQUAL, 28),
                hbox({button1[0]->Render() | center, button1[1]->Render() | center, but->Render() | center}) | center | borderRounded,
            })
        });
    });


  
    

    screen.Loop(layouts);
}
