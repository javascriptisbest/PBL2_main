#pragma once
#include "CTDL/Vector.hpp"
#include "CTDL/Date.hpp"

struct Hang {
    std::string key;
    std::string ten;
    int gia;
    int soLuong = 0;
    int giaNhap;
    string nhaCungCap;
};

struct hoa_don{
        Date date;
        Hang hang;
        int soLuong;
        int songay; 
        string ten;
        int gia;
    

};


template <typename T>
bool compareByKeyAsc(const T& a, const T& b) {
  return a.key < b.key;
}

template <typename T>
bool compareByKeyDesc(const T& a, const T& b) {
  return a.key > b.key;
}

template <typename T>
bool compareBytenAsc(const T& a, const T& b) {
  return a.ten < b.ten;
}

template <typename T>
bool compareBytenDesc(const T& a, const T& b) {
  return a.ten > b.ten;
}

template <typename T>
bool compareBygiaAsc(const T& a, const T& b) {
  return a.gia < b.gia;
}

template <typename T>
bool compareBygiaDesc(const T& a, const T& b) {
  return a.gia > b.gia;
}

template <typename T>
bool compareBysoLuongAsc(const T& a, const T& b) {
  return a.soLuong < b.soLuong;
}

template <typename T>
bool compareBysoLuongDesc(const T& a, const T& b) {
  return a.soLuong > b.soLuong;
}

template <typename T>
bool compareByDateAsc(const T& a, const T& b) {
  return a.date < b.date;
}

template <typename T>
bool compareByDateDesc(const T& a, const T& b) {
  return a.date > b.date;
}


class Hanghoa{
    private:
        Vector<Hang> hh;
        int money;
        Vector<int> mang;
        Vector<hoa_don> hd;

    
    public:
        Vector<Hang>& hang(){ return hh; }
        Vector<Hang>  hang() const{ return hh; }

        int& Money(){ return money; }

        Vector<int>& getMang(){ return mang; }
        Vector<int> getMang() const{ return mang; }
        void clearmang(){ mang.clear(); }

        hoa_don& create(int ngay, int thang , int nam, Hang hang, int soLuong);
        Vector<hoa_don>& getHoaDon(){ return hd; }
        Vector<hoa_don> getHoaDon() const{ return hd; }
        void clearHoaDon(){ hd.clear(); }
        void insertHoaDon(hoa_don hd1){ hd.insert(hd1); }
        void removeHoaDon(int i){ hd.remove(i); }
        void removeHoaDon2(string key){ hd.remove2(key); }
        bool findHoaDon(string key);

        //xu li hoa don
        bool intime(Date date1, Date date2, hoa_don hd);

};