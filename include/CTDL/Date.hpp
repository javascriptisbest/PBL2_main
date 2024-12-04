
#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Date {
    private:
        int ngay;
        int thang;
        int nam;
        int dayOfWeek;

        bool namNhuan(int nam) const;
        int soNgayTrongThang(int thang, int nam) const;
        bool kiemTraNgayThangNam(int ngay, int thang, int nam) const;

    public:
       Date(int nam, int thang, int ngay);
       Date(string date);
        Date():ngay(1), thang(1), nam(1), dayOfWeek(0){};
        string getDatestring() const;
         int getNgay() const;
         int getThang() const;
         int getNam() const; 
        int getDayOfWeek() const;

         bool setNgay(int ngay);
         bool setThang(int thang);
         bool setNam(int nam);
         void setDaystring(string day);

           bool operator==(const Date& other) const;
           bool operator!=(const Date& other) const;
           bool operator<(const Date& other) const;
           bool operator<=(const Date& other) const;
           bool operator>(const Date& other) const;
           bool operator>=(const Date& other) const;
           Date operator+(int days) const;
           Date operator-(int days) const;
           Date& operator-(const Date& other);

       friend ostream& operator<<(ostream& os, const Date& date);
       int thuDauTienTrongThang() ;
};



