#include <iostream>
#include "univer.h"
using namespace std;
void univer::input() {
    cout << "Enter facultet name : ";
    cin >> name_facultet;
    cout << "Enter decan name : ";
    cin >> name_decan;
    cout << "Enter count groups : ";
    cin >> count_group;
    for (int i = 0; i < count_group; i++) {
        cout << "Name of [" << i << "] : ";
        cin >> name_group[i];
    }
    cout << "Enter count stud : ";
    cin >> count_stud;
}
void univer::view() {
    cout << "Facultet name : " << name_facultet << endl;
    cout << "Decan name : " << name_decan << endl;
    cout << "Count groups : " << count_group << endl;
    for (int i = 0; i < count_group; i++)
        cout << "Name of [" << i << "] : " << name_group[i] << endl;
    cout << "Count stud : " << count_stud << endl;
}
void univer::add_group() {
    cout << "How much add : ";
    int add_group2;
    cin >> add_group2;
    for (int i = count_group + 1; i < count_group + add_group2; i++) {
        cout << "Name of [" << i << "] : ";
        cin >> name_group[i];
    }
}
void univer::del_group() {
    cout << "What delete : ";
    int k;
    cin >> k;
    for (int i = k; i < count_group; ++i)
    {
        name_group[i] = name_group[i + 1];
    }
    --count_group;
}
void univer::calc_stud() {
    cout << "Count stud : " << count_stud << endl;
}