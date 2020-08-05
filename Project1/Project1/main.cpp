#include <iostream>
#include "univer.h"
using namespace std;
int count_facultet;
int main()
{
    int menu;
    cout << "Enter count facultet : ";
    cin >> count_facultet;
    univer* array = new univer[count_facultet];
    do {
        cout << "1.Input" << endl;
        cout << "2.Show" << endl;
        cout << "3.Add group" << endl;
        cout << "4.Delete group" << endl;
        cout << "5.Calc group" << endl;
        cin >> menu;
        switch (menu) {
        case 1:
            for (int i = 0; i < count_facultet; i++) {
                cout << "===============================================" << endl;
                array[i].input();
                cout << "===============================================" << endl;
            }
            break;
        case 2:
            for (int i = 0; i < count_facultet; i++) {
                cout << "===============================================" << endl;
                array[i].view();
                cout << "===============================================" << endl;
            }
            break;
        case 3:
            cout << "Faculty of what to add(number) : ";
            int number_fac;
            cin >> number_fac;
            for (int i = number_fac; i == number_fac; i++)
                array[i].add_group();
            break;
        case 4:
            cout << "Faculty of what to delete(number) : ";
            int number_fac1;
            cin >> number_fac1;
            for (int i = number_fac1; i == number_fac1; i++)
                array[i].del_group();
            break;
        case 5:
            for (int i = 0; i < count_facultet; i++)
                array[i].calc_stud();
            break;
        }
    } while (menu < 6);
    return 0;
}