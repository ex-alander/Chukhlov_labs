#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <vector>
#define NOMINMAX
#include <Windows.h>
#include <iterator>
#include "Checking tools.h"
#include "classes.h"
using namespace std;

ostream& operator << (ostream& out, net::Pipe& a)
{
    out << "Name:                      " << a.name << endl
        << "Length:                    " << a.len << endl
        << "Diameter:                  " << a.diam << endl
        << "State:                     " << a.state << endl;
    return out;
}
ostream& operator << (ostream& out, net::CS& b)
{
    out << "Name:                      " << b.name << endl
        << "Workshops number:          " << b.wksh_num << endl
        << "Active workshops number:   " << b.active << endl
        << "Efficiency (0-5):          " << b.eff << endl;
    return out;
}
ostream& operator << (ostream& out, stack<CS>& st)
{
    while(st.size())
    {
        out << st.top().name << ' ';
        st.pop();
    }
    out << '\n';
    return out;
}

/*DESIGN STUFF*/
string slice(string x, int start, int end)
{
    string slicie = "";
    for (int i = start; i <= end; i++)
    {
        slicie += x[i];
    }
    return slicie;
}
void Divider()
{
    cout << "----------------------------------------------------------------------------------\n";
}
void PDivider()
{
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . .\n";
}

/*LOGGING*/
void Record(const string logout)
{
    // time & writing the log
    ofstream out; // opening the file (writing mode)
    time_t result = time(NULL);
    char str[26];
    ctime_s(str, sizeof str, &result);
    out.open("LoggingTrashbin.txt", ios_base::app);
    if (out.is_open())
    {
        out << logout << "::\t" << str << endl;
    }
    out.close(); // closing the file
}
void LogsStash(int a) {
    Divider();
    string logout = "0";
    if (a == 0)
    {
        cout << "Welcome to the pipeline description module!\n";
    }
    else if (a == 1)
    {
        cout << "Here's what you can do:\n"
            << "1. Pipes settings\n"
            << "2. CS settings\n"
            << "3. Save\n"
            << "4. Load\n"
            << "/*Temporary controls*/\n"
            << "5. Connect compressor stations\n"
            << "6. Disconnect compressor stations\n"
            << "0. Exit\n"
            << "\nEnter operation number : \n";
    }
    else if (a == 2)
    {
        cout << "You did't even try to type what was asked.\n";
    }
    else if (a == 3)
    {
        cout << "Changes were saved temporarily (to save them permamently, press '6').\n";
    }
    else if (a == 4)
    {
        cout << "wrong ID.\n";
    }
    else if (a == 5)
    {
        cout << "You can't call your object some fiddle-faddle like this.\n";
    }
    else if (a == 6)
    {
        cout << "Hey, hey! One at a time!\n";
    }
    else if (a == 7)
    {
        cout << "Thou shall chooseth:" << '\n'
            << "1. Add a new one" << '\n'
            << "2. Edit" << '\n'
            << "3. Delete" << '\n'
            << "4. View" << '\n';
    }
    else if (a == 10)
    {
        cout << "So you wanna add a new pipe, huh? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n" << endl;
    }
    else if (a == 20)
    {
        cout << "Wanna add a new CS? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n" << endl;
    }
    else if (a == 40)
    {
        cout << "Edit pipe info.\nChoose what detail to edit:\n0. Everything at once\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Exit\n";
    }
    else if (a == 50)
    {
        cout << "Edit CS info.\nChoose what detail to edit:\n0. Everything at once\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n5. Exit\n";
    }
    Divider();
    if (abs(logout[0] - '0'))
    {
        // time & writing the log
        ofstream out; // opening the file (writing mode)
        time_t result = time(NULL);
        char str[26];
        ctime_s(str, sizeof str, &result);
        out.open("LoggingTrashbin.txt");
        if (out.is_open())
        {
            out << logout << "::\t" << str;
        }
        out.close(); // closing the file
    }
}
void buf(const string logout)
{
    ofstream logfile("log.txt");
    streambuf* oldbuf = cout.rdbuf();
    cout.rdbuf(logfile.rdbuf());
    cout << logout << '\n';
    cout.rdbuf(oldbuf);

    logfile.close();
}

/*CHECKERS*/
int SpellCheck(string x)
{
    if (x[0] != '0'
        and x[0] != '-'
        and x[0] != ':'
        and x[0] != ','
        and x[0] != '.'
        and x[0] != '/'
        and x[0] != '|'
        and x[0] != ';'
        and x[0]) return 1;
    else return 0;
}
int IntCheck(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if ((int)x[i] < 48 or 57 < (int)x[i]) return 0;
    }
    return 1;
}
int lenCheck(string x)
{
    if (x.length() == 1) return 1;
    else return 0;
}

/*NUMBER-GETTERS*/
int number()
{
    int c;
    string c_0;
    while (1) // number check
    {
        getline(cin, c_0);
        if (IntCheck(c_0) and lenCheck(c_0))
        {
            c = stoi(c_0);
            break;
        }
        LogsStash(2);
    }
    return c;
}
int number_big()
{
    int c;
    string c_0;
    while (1) // number check
    {
        getline(cin, c_0);
        if (c_0 != "")
        {
            if (IntCheck(c_0))
            {
                c = stoi(c_0);
                break;
            }
        }
        LogsStash(2);
    }
    return c;
}
int number_big_n_negative()
{
    int c;
    string c_0;
    while (1) // number check
    {
        getline(cin, c_0);
        if (IntCheck(c_0))
        {
            c = stoi(c_0);
            break;
        }
        else if (c_0 == "-1")
        {
            return -1;
        }
        LogsStash(2);
    }
    return c;
}

/*BOYER MOORE SEARCH FOR NAMES*/
const int ALPHABET_SIZE = 256;
void computeBadCharShift(const string& pattern, vector<int>& badCharShift) {
    int m = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharShift[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badCharShift[(int)pattern[i]] = i;
    }
}
bool BoyerMoore_bool(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    std::vector<int> badCharShift(ALPHABET_SIZE, 0);
    computeBadCharShift(pattern, badCharShift);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            //std::cout << "Pattern found at index " << s << std::endl;
            return true;
            if (s + m < n) {
                s += m - badCharShift[text[s + m]];
            }
            else {
                s += 1;
            }
        }
        else {
            s += std::max(1, j - badCharShift[text[s + j]]);
        }
    }
    return false;
}