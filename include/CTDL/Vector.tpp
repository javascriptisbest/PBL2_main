#include "CTDL/Vector.hpp"


template <typename T>
Vector<T>::Vector(int size): size(size), soLuong(0) {
    arr = new T[size];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v): size(v.size), soLuong(v.soLuong) {
    arr = new T[size];
    for (int i = 0; i < soLuong; i++) {
        arr[i] = v.arr[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this == &v) {
        return *this;
    }
    delete[] arr;
    size = v.size;
    soLuong = v.soLuong;
    arr = new T[size];
    for (int i = 0; i < soLuong; i++) {
        arr[i] = v.arr[i];
    }
    return *this;
}

template <typename T>
void Vector<T>::insert(T node) {
    if (soLuong >= size-1) {
        nhandoi();
    }
    arr[soLuong] = node;
    soLuong++;
}

template <typename T>
void Vector<T>::remove(int i) {
    for (int j = i; j < soLuong - 1; j++) {
        arr[j] = arr[j + 1];
    }
    soLuong--;
    return;
}

template <typename T>
void Vector<T>::remove2(string key) {
    for (int i = 0; i < soLuong; i++) {
        if (arr[i].ten == key) {
            for (int j = i; j < soLuong - 1; j++) {
                arr[j] = arr[j + 1];
            }
            soLuong--;
            return;
        }
    }
}

template <typename T>
void Vector<T>::sort(CompareFunc<T> comp) {
    timSort(arr, soLuong, comp);
}

template <typename T>
bool Vector<T>::find(string key) {
    
    for (int i = 0; i < soLuong; i++) {
        if (arr[i].key.find(key) != std::string::npos) {
            return true;
        }
    }
    return false;
}


template <typename T>
void Vector<T>::print() {
    for (int i = 0; i < soLuong; i++) {
        std::cout << arr[i].key << " " << arr[i].value << " " << arr[i].soLuong << "->";
    }
    std::cout << "NULL" << std::endl;
}

template <typename T>
void Vector<T>::nhandoi() {
    T* temp = new T[size * 2];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size *= 2;
}

template <typename T>
void Vector<T>::change(int index, string value) {
    switch (index) {
        case 0:
            arr[index].key = value;
            break;
        case 1:
            arr[index].ten = value;
            break;
        case 2:
            arr[index].gia = stoi(value);
            break;
        case 3:
            arr[index].soLuong = stoi(value);
            break;
    }
}
