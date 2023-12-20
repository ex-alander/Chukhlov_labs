#pragma once
#include <string>
#include "classes.h"
#include <vector>
#include <map>
//#include "structs.h"
using namespace std;
string slice(string x, int start, int end);
void Divider();
void PDivider();
int SpellCheck(string x);
int IntCheck(string x);
int lenCheck(string x);
int number();
int number_big();
int number_big_n_negative();
template<typename T>
void PrintMap(map <int, T> a)
{
    PDivider();
    string typenamie = typeid(a[0]).name();
    typenamie = slice(typenamie, 11, typenamie.length() - 1);
    for (auto itr = a.begin();itr != a.end();itr++)
    {
        cout << "\t\t" << typenamie << " #" << itr->first << endl << itr->second << '\n';
        PDivider();
    }
}