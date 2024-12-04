#pragma once
#include <string>
#include "Vector.hpp"
using namespace std;

template <typename T>
class HashTable {
public:
    HashTable();
    ~HashTable();
    void insert(string key, T value);
    void remove(string key);
    T* find(string key);
    void rehashing();
    int hashCode(string key);
    void sort(Vector<T> &table, CompareFunc<T> comp);
    void print();

    T* find2(string key);
    void suakey(string key, string keyMoi);
    int getnum(){
        return numElements;
    }
    LinkedList<T>* gettable(){
        return table;
    }
private:
    LinkedList<T>* table;
    int size;
    int numElements;
};
