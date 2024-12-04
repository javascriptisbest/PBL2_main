#include "CTDL/Date.hpp"
#include <string>

Date::Date(int nam, int thang, int ngay) {
    kiemTraNgayThangNam(ngay, thang, nam);
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

bool Date::namNhuan(int nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int Date::soNgayTrongThang(int thang, int nam) const {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return namNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

bool Date::kiemTraNgayThangNam(int ngay, int thang, int nam) const {
    if (nam < 0) {
        return false;
    }
    if (thang < 1 || thang > 12) {
        return false;
    
    }
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam)) {
        return false;
    }
    return true;
}

int Date::getNgay() const {
    return ngay;
}

int Date::getThang() const {
    return thang;
}

int Date::getNam() const {
    return nam;
}



bool Date::setNgay(int ngay) {
    if(kiemTraNgayThangNam(ngay, thang, nam)) {this->ngay = ngay;return true;}
    else return false;
}

bool Date::setThang(int thang) {
    if(kiemTraNgayThangNam(ngay, thang, nam)){this->thang = thang; return true;}
    else return false;
}

bool Date::setNam(int nam) {
    if(kiemTraNgayThangNam(ngay, thang, nam)){this->nam = nam; return true;}
    else return false;
}

bool Date::operator==(const Date& other) const {
    return ngay == other.ngay && thang == other.thang && nam == other.nam;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (nam != other.nam) {
        return nam < other.nam;
    }
    if (thang != other.thang) {
        return thang < other.thang;
    }
    return ngay < other.ngay;
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.ngay << "/" << date.thang << "/" << date.nam;
    return os;
}
int Date::getDayOfWeek() const { 
    int d = ngay, m = thang, y = nam;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int k = y % 100;
    int j = y / 100;
    int f = d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    int dayOfWeek = f % 7;

    return dayOfWeek;
}

Date Date::operator+(int days) const {
    int d = ngay + days;
    int m = thang;
    int y = nam;

    while (d > soNgayTrongThang(m, y)) {
        d -= soNgayTrongThang(m, y);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    return Date(d, m, y);
}

Date Date::operator-(int days) const {
    int d = ngay - days;
    int m = thang;
    int y = nam;

    while (d < 1) {
        m--;
        if (m < 1) {
            m = 12;
            y--;
        }
        d += soNgayTrongThang(m, y);
    }

    return Date(d, m, y);
}

Date& Date::operator-(const Date& other) {
    int d = ngay - other.ngay;
    int m = thang - other.thang;
    int y = nam - other.nam;

    while (d < 1) {
        m--;
        if (m < 1) {
            m = 12;
            y--;
        }
        d += soNgayTrongThang(m, y);
    }

    ngay = d;
    thang = m;
    nam = y;

    return *this;
}

int Date::thuDauTienTrongThang() {
    return Date(1, thang, nam).getDayOfWeek();
}

string Date::getDatestring() const {
   return to_string(nam) + "-" + to_string(thang) + "-" + to_string(ngay);

}

string* split1(string str, char delim, int size = 20){
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

void Date::setDaystring(string day) {
    string* arr = split1(day, '-');
    nam = stoi(arr[0]);
    thang = stoi(arr[1]);
    ngay = stoi(arr[2]);
}

Date::Date(string date) {
    setDaystring(date);
}


