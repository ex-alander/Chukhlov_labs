#pragma once
using namespace std;
#include "classes.h"
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include "Checking tools.h"
ostream& operator << (ostream& out, net::Pipe& a);
ostream& operator << (ostream& out, net::CS& b);
ostream& operator << (ostream& out, stack<CS>& st);
//design
string slice(string x, int start, int end);
void Divider();
void PDivider();
//logging
void Record(const string logout);
void LogsStash(int a);
//string search
const int ALPHABET_SIZE = 256;
bool BoyerMoore_bool(const string& text, const string& pattern);
//vector search
template <typename T>
bool inVector(vector<T>vec, T a)
{
    for (int i = 0;i < vec.size();i++)
    {
        if (vec[i] == a) return true;
    }
    return false;
}

