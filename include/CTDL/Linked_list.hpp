#pragma once

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(T data);
    void remove(T data);
    T* find(T data);
    void print();

private:
    T* head;
};