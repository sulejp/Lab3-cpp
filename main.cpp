#include <iostream>
#include <limits>
#include "Adding.h"
#include "Student.h"
#include "Array.h"

using namespace std;

void example1(){
    Adding<int> a1(5);
    a1.add(6);
    a1.show();
    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();
}

void example2(){
    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();
}

template <typename T> void showAll(T* tab[], int n)
{
    for(int i=0;i<n;i++)
        tab[i]->show();
}

void example3(){

    Adding<int>* arrAdd[3];
    for(int i=0;i<3;i++) {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);
    Student<string>* arrStu[2];
    for(int i=0;i<3;i++) {
        arrStu[i]=new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);
    for(int i=0; i<3; i++)
        delete arrAdd[i];
    for(int i=0; i<2; i++)
        delete arrStu[i];
}

template <typename T> void checkType(T a)
{
    // numeric_limits udostępnia specjalizacje dla wszystkich typów podstawowych
    T val=numeric_limits<T>::max();
    cout<<val<<endl;
}

void example4(){
    checkType<int>(3);
}

template <typename T> T functionExercise1(T *array, int size){
    T min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

void exercise2(){
    int intArray[5] = {10,3,223,2,12212};
    string stringArray[5] = {"wyrewolwerowany","awokado","oko","baklazan","onomatopeja"};
    char charArray[5] = {'g','b','a','d','e'};
    cout << "elementy tablicy int: ";
    for(int i=0;i<5;i++) cout << intArray[i] << " ";
    cout << endl << "najmniejszy element to: " << functionExercise1(intArray,5) << endl << endl;
    cout << "elementy tablicy string: ";
    for(int i=0;i<5;i++) cout << stringArray[i] << " ";
    cout << endl << "najmniejszy element to: " << functionExercise1(stringArray,5) << endl << endl;
    cout << "elementy tablicy char: ";
    for(int i=0;i<5;i++) cout << charArray[i] << " ";
    cout << endl << "najmniejszy element to: " << functionExercise1(charArray,5);
}

void exercise3(){
    int intExample[5] = {10,3,223,2,12212};
    string stringExample[5] = {"wyrewolwerowany","pilka","konstantynopolitanczykowianeczka","oko","ul"};

    Array<int> intArray(5);;
    for(int i=0;i<5;i++) intArray.addArray(intExample[i]);
    cout << "(int)";
    intArray.showArray();
    cout << "zwrocony index(2): " << intArray.getElement(2) << endl;
    cout << "maksymalny element: ";
    cout << intArray.maxElement() << endl;
    cout << "po sortowaniu ";
    intArray.sortAscending();
    intArray.showArray();

    Array<string> stringArray(5);
    for(int i=0;i<5;i++) stringArray.addArray(stringExample[i]);
    cout << endl << "(string)";
    stringArray.showArray();
    cout << "najdluzszy element: " << stringArray.maxElement()<<endl;
    cout << "po sortowaniu ";
    stringArray.sortAscending();
    stringArray.showArray();
}

int main()
{
    //example1();
    //example2();
    //example3();
    //example4();
    //exercise2();
    exercise3();

    return 0;
}