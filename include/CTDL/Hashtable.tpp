#include "Hashtable.hpp"
#include "Vector.hpp"
template <typename T>
HashTable<T>::HashTable() {
    table = new LinkedList<T>[10];
    size = 10;
    numElements = 0;
}

template <typename T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < size; i++) {
        table[i].~LinkedList();
    }
    delete[] table;
}

template <typename T>
int HashTable<T>::hashCode(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash += key[i];
    }
    return hash;
}

template <typename T>
void HashTable<T>::insert(string key, T value) {
    int index = abs(hashCode(key)) % size;
    table[index].insert(value);
    numElements++;
    if(numElements > size*0.75) {
        rehashing();
    }
}

template <typename T>
void HashTable<T>::remove(string key) {
    int index = abs(hashCode(key)) % size;
    table[index].remove(key);
    numElements--;
}

template <typename T>
T* HashTable<T>::find(string key) {
    int index = abs(hashCode(key)) % size;
    return table[index].find(key);
}

template <typename T>
T* HashTable<T>::find2(string key) {
    int index = abs(hashCode(key)) % size;
    return table[index].find2(key);
}

template <typename T>
void HashTable<T>::rehashing() {
    LinkedList<T>* oldTable = table;
    int oldSize = size;
    
    size *= 2;
    table = new LinkedList<T>[size];
    numElements = 0;
    
    for (int i = 0; i < oldSize; i++) {
        T* current = oldTable[i].head;
        while (current != NULL) {
            insert(current->data.key, current->data);
            current = current->next;
        }
    }
}

template <typename T>
void HashTable<T>::sort(Vector<T> &sapxep, bool (*comp)(const T&, const T&)) {
    for (int i = 0; i < size; i++) {
        T* current = table[i].head;
        while (current != NULL) {
            sapxep.insert(current->data.key, current->data.value, current->data.soLuong, current->data.daBan);
            current = current->next;
        }
    }
    sapxep.sort(comp);
    sapxep.print();
}

template <typename T>
void HashTable<T>::suakey(string key, string keyMoi) {
    T* hangHoa = find(key);
    if (hangHoa != NULL) {
        insert(keyMoi, hangHoa->data);
        remove(key);
    }
}

template <typename T>
void HashTable<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "Bucket " << i << ": ";
        table[i].print();
        cout << "NULL" << endl;
    }
}

