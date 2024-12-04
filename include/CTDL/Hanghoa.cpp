#include "CTDL/Hanghoa.hpp"


hoa_don& Hanghoa::create(int ngay, int thang , int nam, Hang hang, int soLuong){
    Date date(ngay, thang, nam);
    hoa_don hd1;
    hd1.date = date;
    hd1.hang = hang;
    hd1.soLuong = soLuong;
    return hd1;
}

bool Hanghoa::intime(Date date1, Date date2, hoa_don hd){
    if(date1 <= hd.date && hd.date <= date2) return true;
    return false;
    
}

