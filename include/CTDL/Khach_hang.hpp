#pragma once
#include <string>
#include "CTDL/Vector.hpp"
#include "CTDL/Date.hpp"
using namespace std;


template <typename T>
bool compareByTenAsc(const T& a, const T& b) {
  return a.ten < b.ten;
}

template <typename T>
bool compareByTenDesc(const T& a, const T& b) {
  return a.ten > b.ten;
}

template <typename T>
bool compareBymaTheAsc(const T& a, const T& b) {
  return a.maThe < b.maThe;
}

template <typename T>
bool compareBymaTheDesc(const T& a, const T& b) {
  return a.maThe > b.maThe;
}

template <typename T>
bool compareBydiemAsc(const T& a, const T& b) {
  return a.diem < b.diem;
}

template <typename T>
bool compareBydiemDesc(const T& a, const T& b) {
  return a.diem > b.diem;
}

template <typename T>
bool compareByemailAsc(const T& a, const T& b) {
  return a.email < b.email;
}

template <typename T>
bool compareByemailDesc(const T& a, const T& b) {
  return a.email > b.email;
}
struct Khach{
    string ten;
    string sdt;
    string diachi;
    string mk;
    string email;
    bool gioitinh;
    string maThe;
    Date hanThe;
    int diem;
    int soLanMua;
};

class Khach_hang{
    private:
        Vector<Khach> khachhang ;
        Vector<int> mang;
    public:
        void them(Khach kh);
        void xoa(int index);
        void xoa(string ma);
        Vector<Khach>& getKhachHang(){
            return khachhang;
        };
        Khach& operator[](int index){
            return khachhang[index];
        }
        Khach operator[](int index) const{
            return khachhang[index];
        }
        Vector<int>& getMang(){
            return mang;
        }
        Vector<int> getMang() const{
            return mang;
        }
};
