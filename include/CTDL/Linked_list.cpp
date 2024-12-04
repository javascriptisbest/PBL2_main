#include "Linked_list.hpp"
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    T* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::remove(T data) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

template <typename T>
T* LinkedList<T>::find(T data) {
    T* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::print() {
    T* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}
