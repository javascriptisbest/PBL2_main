#pragma once
using namespace std;
#include <string>

template <typename T>
using CompareFunc = bool (*)(const T&, const T&);



template <typename T>
void insertionSort(T arr[], int left, int right, CompareFunc<T> comp) {
  for (int i = left + 1; i <= right; i++) {
    T temp = arr[i];
    int j = i - 1;
    while (j >= left && comp(temp, arr[j])) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

template <typename T>
void merge(T arr[], int left, int mid, int right, CompareFunc<T> comp) {
  int len1 = mid - left + 1, len2 = right - mid;
  T* leftArr = new T[len1];
  T* rightArr = new T[len2];

  for (int i = 0; i < len1; i++)
    leftArr[i] = arr[left + i];
  for (int i = 0; i < len2; i++)
    rightArr[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;
  while (i < len1 && j < len2) {
    if (comp(leftArr[i], rightArr[j])) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < len1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < len2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }

  delete[] leftArr;
  delete[] rightArr;
}

template <typename T>
void timSort(T arr[], int n, CompareFunc<T> comp) {
  const int RUN = 32;
  for (int i = 0; i < n; i += RUN)
    insertionSort(arr, i, min((i + RUN - 1), (n - 1)), comp);

  for (int size = RUN; size < n; size = 2 * size) {
    for (int left = 0; left < n; left += 2 * size) {
      int mid = left + size - 1;
      int right = min((left + 2 * size - 1), (n - 1));
      if (mid < right)
        merge(arr, left, mid, right, comp);
    }
  }
}

template <typename T>
class Vector {
private:
    int size;
    T* arr;
    int soLuong;

public:
    Vector(int size = 100);
    ~Vector();
    Vector(const Vector<T>& v);

    T* array() { return arr; }
    int length() { return soLuong; }
    
    void insert(T node);
    void remove(int i);
    void remove2(string key);
    bool find(string key);

    void print();
    void nhandoi();
    void sort(CompareFunc<T> comp);
    void clear() { soLuong = 0; }
    void change(int index, string value);

    T& operator[](int index) { return arr[index]; };
    T  operator[](int index) const { return arr[index]; }
    Vector<T>& operator=(const Vector<T>& v);

    
};
