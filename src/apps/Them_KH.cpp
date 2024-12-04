#include "app/Them_KH.hpp"
#include "CTDL/Khach_hang.cpp"


void Them_KH::insert(Khach_hang &khachhang) {
    Khach kh;
    kh.ten = ten;
    kh.sdt = sdt;
    kh.diachi = diachi;
    kh.email = email;
    if(gioitinh == "Nam") kh.gioitinh = 1;
    else kh.gioitinh = 0;
    kh.maThe = maThe;
    kh.hanThe = hanThe;
    kh.diem = stoi(diem);
    kh.soLanMua = stoi(soLanMua);
    khachhang.them(kh);

    
}

void Them_KH::sua(Khach_hang &khachhang) {
    Khach kh;
    kh.ten = ten;
    kh.sdt = sdt;
    kh.diachi = diachi;
    kh.email = email;
    if(gioitinh == "Nam") kh.gioitinh = 1;
    else kh.gioitinh = 0;
    kh.maThe = maThe;
    kh.hanThe = hanThe;
    kh.diem = stoi(diem);
    kh.soLanMua = stoi(soLanMua);
    khachhang.them(kh);
    khachhang.xoa(ten);
}
void Them_KH::sua(Khach_hang &khachhang,int index){
  diachi = khachhang.getKhachHang()[index].diachi;
  ten = khachhang.getKhachHang()[index].ten;
  sdt = khachhang.getKhachHang()[index].sdt;
  mk = khachhang.getKhachHang()[index].mk;

}


InputOption Them_KH::style(string nhapgi) {
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


void Them_KH::create(bool co, Khach_hang &khachhang) {
    vector<string> gioitinh = {"Nam", "Nu"};
    int selected = 0;
    InputOption style_2 = InputOption::Spacious();
    Component input_ten = Input(&ten, "Ten khach hang", style("Họ và tên"));
    Component input_sdt = Input(&sdt, "So dien thoai", style("Số điện thoại"));
    Component input_diachi = Input(&diachi, "Dia chi", style("Địa chỉ"));
    Component input_email = Input(&email, "Email", style("Email"));
    Component input_gioitinh = Dropdown(&gioitinh, &selected);
    Component input_maThe = Input(&maThe, "Ma the", style_2);
    Component input_hanThe = Input(&hanThe, "Han the", style_2);
    Component input_diem = Input(&diem, "Diem", style_2);
    Component input_soLanMua = Input(&soLanMua, "So lan mua", style_2);
    auto error = text(text_errror);
    auto button = Button("Them", [&] {insert(khachhang);}, ButtonOption::Border());
    menu = Container::Vertical({
        input_ten,
        input_sdt,
        input_diachi,
        input_email,
        input_gioitinh,
        input_maThe,
        input_hanThe,
        input_diem,
        input_soLanMua,
        button,
    });

    auto renderer = Renderer(menu, [&] {
        return vbox({
            hbox({    input_ten->Render() | size(WIDTH, EQUAL, 35),
                      separatorEmpty() | size(WIDTH, EQUAL, 10),
                      input_sdt->Render() | size(WIDTH, EQUAL, 35) }),
            hbox({    input_diachi->Render() | size(WIDTH, EQUAL, 35) | center,
                      separatorEmpty() | size(WIDTH, EQUAL, 10),
                      input_email->Render() | size(WIDTH, EQUAL, 35) | center}),
            
            hbox({    input_maThe->Render() | size(WIDTH, EQUAL, 15) | center, 
                        separatorEmpty() | size(WIDTH, EQUAL, 20),
                       input_gioitinh->Render() | size(WIDTH, EQUAL, 15) | center}),
        
        
    });
    });


    screen.Loop(renderer);
}


