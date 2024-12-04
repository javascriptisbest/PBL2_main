#include "CTDL/Khach_hang.hpp"

void Khach_hang::them(Khach kh){
    khachhang.insert(kh);
}

void Khach_hang::xoa(int index){
    khachhang.remove(index);
}

void Khach_hang::xoa(string ma){
    khachhang.remove2(ma);
}
