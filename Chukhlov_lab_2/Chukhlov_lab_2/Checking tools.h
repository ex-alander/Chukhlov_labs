#pragma once
#include <string>
#include "classes.h"
#include <vector>
//#include "structs.h"
using namespace std;
string slice(string x, int start, int end);
void Divider();
void PDivider();
int SpellCheck(string x);
int NumCheck(string x);
int IntCheck(string x);
int lenCheck(string x);
int number();
int number_big();
int number_big_n_negative();
template <typename T>
bool exist(T t)
{
	if (t.name[0] - '0') return 1;
	else
	{
        cout << "Error: object(s) not found" << '\n';
		return 0;
	}
}
template<typename T>
void PrintMap(map <int, T> a)
{
    PDivider();
    string typenamie = typeid(a[0]).name();
    typenamie = slice(typenamie, 6, typenamie.length() - 1);
    for (auto itr = a.begin();itr != a.end();itr++)
    {
        cout << "\t\t" << typenamie << " #" << itr->first << endl << itr->second << '\n';
        PDivider();
    }
}