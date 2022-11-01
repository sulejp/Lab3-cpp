//
// Created by psulej on 27.10.2022.
//

#ifndef LAB3_CPP_ARRAY_H
#define LAB3_CPP_ARRAY_H
#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* array;
    int maxSize;
    int firstIndex;
public:
    Array(int maxSize);
    Array();
    ~Array();
    void sortAscending();
    int maxElement();
    void showArray();
    T addArray(T value);
    T getElement(int index);
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }
};

template<typename T>
Array<T>::Array(int size) {
    array = new T[size];
    maxSize = size;
    firstIndex = 0;
}

template<typename T>
Array<T>::Array() {
    array = new T[10];
    maxSize = 10;
    firstIndex = 0;
}

template<typename T>
Array<T>::~Array() {
    delete[] array;
}

template<typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Array<T>::sortAscending() {
    for(int i = 0; i < maxSize-1; i++) {
        for (int j = 0; j < maxSize - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}


template<typename T>
int Array<T>::maxElement() {
    T max = array[0];
    for (int i = 0; i < maxSize; i++) {
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;
}

template<>
void Array<string>::sortAscending(){
    for(int i = 0; i < maxSize-1; i++){
        for(int j =0; j < maxSize-1-i; j++){
            if(array[j].length() > array[j+1].length()){
                swap(array[j], array[j+1]);
            }
        }
    }
}

template<> int Array<string>::maxElement() {
    int max = 0;
    string word = "";
    int foundIndex = 0;
    for(int i = 0; i < maxSize; i++){
        if(array[i].length() > max){
            max = array[i].length();
            foundIndex = i;
        }
    }

    for(int j=foundIndex;j<maxSize - foundIndex;j++)
        word+=array[j];
    cout << word << " dlugosc ";
    return max;
}

template<typename T>
void Array<T>::showArray() {
    cout << "Tablica: ";
    for(int i=0;i<maxSize;i++){
        cout <<  array[i] << " ";
    }
    cout << endl;
}

template<typename T>
T Array<T>::addArray(T value) {
    array[firstIndex] = value;
    firstIndex++;
}

template<typename T>
T Array<T>::getElement(int index) {
    return array[index];
}

#endif //LAB3_CPP_ARRAY_H
