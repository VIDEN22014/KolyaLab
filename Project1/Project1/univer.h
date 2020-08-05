#ifndef UNIVER_H
#define UNIVER_H
#include <string>
#include <iostream>
using namespace std;
class univer {
    string name_facultet;
    string name_decan;
    int count_group;
    string name_group[15];
    int count_stud;
public:
    void add_group();
    void del_group();
    void input();
    void view();
    void calc_stud();
};
#endif