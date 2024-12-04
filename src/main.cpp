
#include "eins/tui_support.h"
#include "app/Main_menu.hpp"
#include "eins/db.cpp"
#include "app/Them_KH.hpp"
#include "app/QLKH.hpp"

ButtonOption Style() {
  auto option = ButtonOption::Animated();
  option.transform = [](const EntryState& s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
}


// int main(){
//     int value = 50;
 
//   // clang-format off
//   auto btn_dec_01 = Button("-1", [&] { value -= 1; }, Style());
//   auto btn_inc_01 = Button("+1", [&] { value += 1; }, Style());
//   auto btn_dec_10 = Button("-10", [&] { value -= 10; }, Style());
//   auto btn_inc_10 = Button("+10", [&] { value += 10; }, Style());
//   // clang-format on
 
//   // The tree of components. This defines how to navigate using the keyboard.
//   // The selected `row` is shared to get a grid layout.
//   int row = 0;
//   auto buttons = Container::Vertical({
//       Container::Horizontal({btn_dec_01, btn_inc_01}, &row) | flex,
//       Container::Horizontal({btn_dec_10, btn_inc_10}, &row) | flex,
//   });
 
//   // Modify the way to render them on screen:
//   auto component = Renderer(buttons, [&] {
//     return vbox({
//                text("value = " + std::to_string(value)),
//                separator(),
//                buttons->Render() | flex,
//            }) |
//            flex | border;
//   });
 
//   auto screen = ScreenInteractive::FitComponent();
//   screen.Loop(component);
//   return 0;
// }

int main() {
    Hanghoa hanghoa;
    Khach_hang khachhang;
    read_file(hanghoa);
    read_hoadon(hanghoa);
    read_file(khachhang);

    
    MainMenu main_menu;
    main_menu.create(hanghoa, khachhang);
    write_file(hanghoa);
    write_hoadon(hanghoa);
     Them_KH them_kh;
    return 0;
} 