#pragma once

#include "CTDL/Hanghoa.hpp"
#include "CTDL/Khach_hang.hpp"
#include <fstream>
void read_hoadon(Hanghoa &hanghoa);
void read_file(Hanghoa &hanghoa);
string* split(string str, char delim, int size );
string trimspace(string str );
void write_file(Hanghoa &hanghoa);
void write_hoadon(Hanghoa &hanghoa);
void write_file(Khach_hang &khachhang);
void read_file(Khach_hang &khachhang);
