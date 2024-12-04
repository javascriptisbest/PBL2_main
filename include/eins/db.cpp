#include "eins/db.hpp"





string* split(string str, char delim, int size = 20){
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

string trimspace(string str ){
    string arr;
    int i = 0;
    while(arr[i] == ' '){
        i++;
    }
    arr = str.substr(i);
    i = str.length() - 1;
    while(str[i] == ' '){
        i--;
    }
    arr= arr.substr(0, i + 1);
    return arr;
}
void read_file(Hanghoa &hanghoa){
    ifstream input("D:/edge ngu/ppl2/PBL2-main/src/hanghoa.csv");
    string str;
    string* arr;
    int i = 0;
    getline(input, str);
    while(!input.eof()){
        Hang hang;
        getline(input, str);
        arr = split(str, ',');
        hang.key = arr[0];
        hang.ten = arr[1];
        if(arr[2] == "" || arr[2] == " "|| arr[2] == "\0" || arr[2] == "\n") arr[2] = "0";
        else   hang.gia = stoi(arr[2]);
        if(arr[3] == "" || arr[3] == " "|| arr[3] == "\0" || arr[3] == "\n") arr[3] = "0";
        else hang.soLuong = stoi(arr[3]);
        
        if(arr[4] == "" || arr[4] == " "|| arr[4] == "\0" || arr[4] == "\n") arr[4] = "0";
        else hang.giaNhap = stoi(arr[4]);
        hanghoa.hang().insert(hang);
    }
    
    input.close();
}
void write_file(Hanghoa &hanghoa){
    ofstream output;
    output.open("D:\\edge ngu\\ppl2\\PBL2-main\\src\\hanghoa.csv", ios::trunc);
    string str;
    output << "Ma,Ten,Gia,So luong,giaNhap\n";
    

    for(int i = 0; i < hanghoa.hang().length(); i++){
        str = hanghoa.hang()[i].key + "," + hanghoa.hang()[i].ten + "," + to_string(hanghoa.hang()[i].gia) + "," + to_string(hanghoa.hang()[i].soLuong) + "," + to_string(hanghoa.hang()[i].giaNhap) + "\n";
        output << str;
    }
    output.close();
}





void read_hoadon(Hanghoa &hanghoa){
    ifstream input("D:\\edge ngu\\ppl2\\PBL2-main\\src\\hoadon.csv");
    string str;
    string* arr;
    string* arrdate;
    int i = 0;
    getline(input, str);
    while(!input.eof()){
        Hang hang;
        hoa_don hd;
        getline(input, str);
        arr = split(str, ',');
        if(arr[0] == "" || arr[0] == " "|| arr[0] == "\0" || arr[0] == "\n") arr[0] = "0";
        else hd.ten = arr[0];
        if(arr[1] == "" || arr[1] == " "|| arr[1] == "\0" || arr[1] == "\n") arr[1] = "0";
        else hd.gia = stoi(arr[1]);
        if(arr[2] == "" || arr[2] == " "|| arr[2] == "\0" || arr[2] == "\n") arr[2] = "0";
        else hd.soLuong = stoi(arr[2]);
        
        if(arr[3] == "" || arr[3] == " "|| arr[3] == "\0" || arr[3] == "\n") arr[3] = "0";

        arrdate = split(arr[3], '-');
        if(arrdate->length() != 3) cout << "loi";
        else{
        Date date = Date(stoi(arrdate[0]), stoi(arrdate[1]), stoi(arrdate[2]));
        hd.date = date;
        }
        
        hanghoa.getHoaDon().insert(hd);

        }
    
    input.close();
}
void write_hoadon(Hanghoa &hanghoa){
    ofstream output;
    output.open("D:\\edge ngu\\ppl2\\PBL2-main\\src\\hoadon.csv", ios::trunc);
    string str;
    string date1;
    output << "Ten, Gia, So_luong,Ngay,Khach_hang\n";
    date1 = to_string(hanghoa.getHoaDon()[0].date.getNgay()) + '/' + to_string(hanghoa.getHoaDon()[0].date.getThang()) + '/' + to_string(hanghoa.getHoaDon()[0].date.getNam());
    

    for(int i = 0; i < hanghoa.hang().length(); i++){
        str = hanghoa.getHoaDon()[i].ten+ "," + to_string(hanghoa.getHoaDon()[i].gia) + "," + to_string(hanghoa.getHoaDon()[i].soLuong) +  + "," + date1 + "\n";
        output << str;
    }
    output.close();
}

void read_file(Khach_hang &kh){
    ifstream input("D:\\edge ngu\\ppl2\\PBL2-main\\src\\khachhang.csv");
    string str;
    string* arr;
    string* arrdate;
    int i = 0;
    getline(input, str);
    while(!input.eof()){
        //Mathe,Ten,mk,Email,SDT,diachi,diem,hanthe
        Khach khach;
        getline(input, str);
        arr = split(str, ',');
        if(arr[0] == "" || arr[0] == " "|| arr[0] == "\0" || arr[0] == "\n") arr[0] = " ";
        else khach.maThe = arr[0];
        if(arr[1] == "" || arr[1] == " "|| arr[1] == "\0" || arr[1] == "\n") arr[1] = " ";
        else khach.ten = arr[1];
        if(arr[2] == "" || arr[2] == " "|| arr[2] == "\0" || arr[2] == "\n") arr[2] =  " ";
        else khach.mk = arr[2];
        
        if(arr[3] == "" || arr[3] == " "|| arr[3] == "\0" || arr[3] == "\n") arr[3] = " ";
        else khach.email = arr[3];
        if(arr[4] == "" || arr[4] == " "|| arr[4] == "\0" || arr[4] == "\n") arr[4] = " ";
        else khach.sdt = arr[4];
        if(arr[5] == "" || arr[5] == " "|| arr[5] == "\0" || arr[5] == "\n") arr[5] = " ";
        else khach.diachi = arr[5];
        if(arr[6] == "" || arr[6] == " "|| arr[6] == "\0" || arr[6] == "\n") arr[6] = "0";
         else khach.diem = 0;
        arrdate = split(arr[7], '-') ;
        // if(arrdate->length() != 3) ;
        // else{
        // Date date = Date(stoi(arrdate[0]), stoi(arrdate[1]), stoi(arrdate[2]));
        // khach.hanThe = date;}
        
        
        kh.them(khach);

        }
    
    input.close();
}