//
// Created by psulej on 27.10.2022.
//

#ifndef LAB3_CPP_STUDENT_H
#define LAB3_CPP_STUDENT_H
#include<iostream>
using namespace std;
template <typename T>

class Student {
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark = mark;
        this->name = name;
    }

    Student(){
    }

    void show(){
        cout << "imie: "<<name<<" ocena "<<mark<<endl;
    }

    void showMark() {
        cout <<mark<<endl;
    }
};

template<> void Student<int>::showMark() {
    cout <<"Twoja ocena to: "<<mark<<endl;
}

template<> class Student<string> {
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark = mark;
        this->name = name;
    }

    Student() {
    }

    void show() {
        cout <<"imie: "<<name<<" ocena "<<mark<<endl;
    }

    int showMark() {
        string word [6]= {"jedynka","dwojka","trojka","czworka","piatka","szostka"};
        cout <<"Twoja ocena to: "<<word[mark-1]<<endl;
        return mark;
    }
};

#endif //LAB3_CPP_STUDENT_H
