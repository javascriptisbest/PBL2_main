#include "app/Main_menu.hpp"
#include "app/Everything.hpp"
#include "CTDL/Hanghoa.hpp"
#include "app/ThemHangHoa.hpp"
#include "app/Nhap_xuat.hpp"
#include "app/Title.hpp"
#include "app/Thongke.hpp"
#include "app/Them_KH.hpp"




ButtonOption MainMenu::optional(Color color, int &selected) {
    auto option = ButtonOption::Animated(color);
    option.transform = [&](EntryState state) {
        if (state.focused) {
            selected = state.index;
        }
        return hbox({text(state.label) | center}) | center;
    };
    return option;
}

ButtonOption MainMenu::optional1(Color color, int &selected) {
    auto option = ButtonOption::Animated(color);
    option.transform = [&](EntryState state) {
        if (state.focused) {
            selected = state.index;
        }
        return hbox({text(state.label) | center})  |size(WIDTH,EQUAL,25)| center;
    };
    return option;
}

void MainMenu::enter(Hanghoa &hanghoa, Khach_hang &khachhang) {
    screen.Exit();
    trans(hanghoa, khachhang);
}

void MainMenu::create(Hanghoa &hanghoa, Khach_hang &khachhang) {
    Text title;
    Component title_1 = title.create("nghenhan.txt");

    auto tab1_menu = Container::Vertical(
        {
            Button(tab1[0], [&]{enter(hanghoa, khachhang);}, optional(Color::Red, selected1)),
            Button(tab1[1], [&]{enter(hanghoa, khachhang);}, optional(Color::Red, selected1)),
        },
        &selected1);

    auto tab2_menu = Container::Vertical(
        {
            Button(tab2[0], [&]{enter(hanghoa, khachhang);}, optional(Color::Blue, selected2)),
            Button(tab2[1], [&]{enter(hanghoa, khachhang);}, optional(Color::Blue, selected2)),
            Button(tab2[2], [&]{enter(hanghoa, khachhang);}, optional(Color::Blue, selected2)),
        },
        &selected2);

    auto tab3_menu = Container::Vertical(
        {
            Button(tab3[0], [&]{enter(hanghoa, khachhang);}, optional(Color::Green, selected3)),
            Button(tab3[1], [&]{enter(hanghoa, khachhang);}, optional(Color::Green, selected3)),
            Button(tab3[2], [&]{enter(hanghoa, khachhang);}, optional(Color::Green, selected3)),
        },
        &selected3);

    auto tab4_menu = Container::Vertical(
        {
            Button(tab4[0], [&]{enter(hanghoa, khachhang);}, optional(Color::Orange1, selected4)),
            Button(tab4[1], [&]{enter(hanghoa, khachhang);}, optional(Color::Orange1, selected4)),
            Button(tab4[2], [&]{enter(hanghoa, khachhang);}, optional(Color::Orange1, selected4)),
        },
        &selected4);

    auto button_sanpham = Button("SẢN PHẨM", [&] { selected = 0; }, optional(Color::Red, selected));
    auto button_khachhang = Button("KHÁCH HÀNG", [&] { selected = 1; }, optional(Color::Blue, selected));
    auto button_donhang = Button("ĐƠN HÀNG", [&] { selected = 2; }, optional(Color::Green, selected));
    auto button_nhanvien = Button("NHÂN VIÊN", [&] { selected = 3; }, optional(Color::Orange1, selected));
    auto tab_menu = Container::Horizontal(
        {
            button_sanpham,
            button_khachhang,
            button_donhang,
            button_nhanvien,
        },
        &selected);
    
    auto tab_menu_render = Renderer(tab_menu, [&] {
        return hbox({
            button_sanpham->Render()|size(WIDTH,EQUAL,25),
            button_khachhang->Render()|size(WIDTH,EQUAL,25),
            button_donhang->Render()|size(WIDTH,EQUAL,25),
            button_nhanvien->Render()| size(WIDTH,EQUAL,25),
        }) | size(HEIGHT, EQUAL, 3) | center| xflex;
    });

    auto tab_container = Container::Tab(
        {
            tab1_menu,
            tab2_menu,
            tab3_menu,
            tab4_menu,
        }, &selected);

    auto container = Container::Horizontal({
        tab_menu_render,
        tab_container ,
    });


    menu = Renderer(container, [&] {
        return vbox({
            title_1->Render() | center,
            separatorEmpty() | size(WIDTH, EQUAL, 10),
            
            separatorEmpty() | size(WIDTH, EQUAL, 20),
            tab_menu_render->Render(),
            separatorEmpty() | size(WIDTH, EQUAL, 5),
            tab_container->Render(),
        
        });
    });

    // menu |= CatchEvent([&](Event event) {
    //     switch (selected) {
    //         case 0:
    //             text_tab = "Giúp thêm, xóa , sua, tim kiem hang hoa";
    //             break;
    //         case 1:
    //             text_tab = "Giúp thêm, xóa , sua, tim kiem nhan vien";
    //             break;
    //         case 2:
    //             text_tab = "Giúp thêm, xóa , sua, tim kiem hoa don";
    //             break;
    //     }
    //     return false;
    // });

    screen.Loop(menu);
}

void MainMenu::run(bool i) {
    screen.ExitLoopClosure();
}

void MainMenu::exitmain(Hanghoa hanghoa, Khach_hang khachhang) {
    //write_file(hanghoa);
    screen.Exit();
}

void MainMenu::trans(Hanghoa &hanghoa, Khach_hang &khachhang) {
    system("cls");

    Everything everything;
    ThemHangHoa them_hang_hoa;
    Hoa_don hoa_don;
    Them_KH them_kh;
    switch (selected) {
        case 0:
            switch (selected1) {
                case 0:
                    them_hang_hoa.create(0, hanghoa);
                    break;
                case 1:
                    everything.create(hanghoa, 0);
                    break;
                case 2:
                    everything.create(hanghoa, 1);
                    break;
            }
        
            create(hanghoa, khachhang);
            break;
        case 1:
            switch (selected2) {
                case 0:
                    hoa_don.create(hanghoa, 0);
                    break;
                case 1:
                    them_kh.create(0, khachhang);
                    
                    break;
                case 2:
                    them_kh.create(1, khachhang);
                    break;
                
            }
            create(hanghoa, khachhang);
            break;
        case 3:
            exitmain(hanghoa, khachhang);
    }
}





