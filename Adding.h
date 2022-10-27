//
// Created by psulej on 27.10.2022.
//

#ifndef LAB3_CPP_ADDING_H
#define LAB3_CPP_ADDING_H
#include <iostream>
using namespace std;

template <typename T>
class Adding {
private:
    T element;
public:
    Adding(T value);
    void add(T value);
    void show();
};

template <typename T> Adding<T>::Adding(T value) {
    element=value;
}

template <typename T> void Adding<T>::add(T value) {
    element=element+value;
}

template <typename T> void Adding<T>::show() {
    cout<<"Element: "<<element<<endl;
}

#endif //LAB3_CPP_ADDING_H
