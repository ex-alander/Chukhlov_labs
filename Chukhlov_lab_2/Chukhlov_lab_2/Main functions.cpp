#include <iostream>
#include <fstream>
#include <string>
#include "Checking tools.h"
#include "structs.h"
using namespace std;
ostream& operator << (ostream& out, Pipe& a)
{
    out << "Name:                      " << a.name << endl
        << "Length:                    " << a.len << endl
        << "Diameter:                  " << a.diam << endl
        << "State:                     " << a.maint << endl;
    return out;
}

ostream& operator << (ostream& out, CS& b)
{
    out << "Name:                      " << b.name << endl
        << "Workshops number:          " << b.wksh_num << endl
        << "Active workshops number:   " << b.act_wksh_num << endl
        << "Efficiency (0-5):          " << b.eff << endl;
    return out;
}
void Divider()
{
    cout << "-------------------------------------------------------------------------------------";
}
void MenuCall(int a) {
    if (a == 0)
    {
        cout << "Welcome to the pipeline description module!";
    }
    else if (a == 1)
    {
        cout << "\nHere's what you can do:\n1. Add a pipe & describe it\n2. Add a CS & describe it\n3. View all described objects\n4. Edit existing pipe\n5. Edit existing CS\n6. Save\n7. Load\n0. Exit\n" << endl;
        cout << "\nEnter operation number:" << endl;
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
        cout << "\nYou can't edit an object that doesn't exist\n";
    }
    else if (a == 5)
    {
        cout << "\nYou can't call it like that, sorry.\n";
    }
    else if (a == 6)
    {
        cout << "Hey, hey! One at a time!\n";
    }
    else if (a == 10)
    {
        cout << "\nSo you wanna add a new pipe, huh? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n" << endl;
    }
    else if (a == 20)
    {
        cout << "\nWanna add a new CS? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n" << endl;
    }
    else if (a == 40)
    {
        cout << "\nEdit pipe info.\nChoose what detail to edit:\n0. Everything at once\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Exit\n";
    }
    else if (a == 50)
    {
        cout << "\nEdit CS info.\nChoose what detail to edit:\n0. Everything at once\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n5. Exit\n";
    }
}
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
int NumCheck(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] - '0' >= 0 and x[i] - '0' <= 9) continue;
        else return 0;
    }
    return 1;
}
int IntCheck(string x)
{
    try
    {
        if (stoi(x) or !stoi(x)) 1 < 2;
        return 1;
    }
    catch (...)
    {
        return 0;
    }
}
int lenCheck(string x)
{
    if (x.length() == 1) return 1;
    else return 0;
}
int number(string& x)
{
    int c;
    while (1) // number check
    {
        getline(cin, x);
        if (IntCheck(x) and lenCheck(x))
        {
            c = stoi(x);
            break;
        }
        MenuCall(2);
    }
    return c;
}
void PipeAdd(int x, Pipe& A)
{
    int switcher = 1;
    switch (x)
    {
    case 0:
    {
        switcher = 0;
    }
    case 1:
    {
        while (0 != 1) // making name
        {
            cout << 1 << ". ";
            getline(cin, A.name);
            if (SpellCheck(A.name)) break;
            else cout << "You can't call it like that, sorry.\n";
        }
        if (switcher) break;
    }
    case 2:
    {
        string g;
        while (0 != 1) // making length
        {
            cout << 2 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (IntCheck(g) and NumCheck(g)) {

                if (stoi(g) > 0)
                {
                    A.len = stoi(g);
                    break;
                }
                else
                {
                    cout << "Wrong length data.\n---------\nHint: the length must be bigger than 0\n---------\n";
                }
            }
        }
        if (switcher) break;
    }
    case 3:
    {
        string g;
        while (0 != 1) // making diameter
        {
            cout << 3 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (IntCheck(g) and NumCheck(g))
            {
                if (stoi(g) > 0)
                {
                    A.diam = stoi(g);
                    break;
                }
                else
                {
                    cout << "Wrong diameter data.\n---------\nHint: the diameter must be bigger than 0\n---------\n";
                }
            }
        }
        if (switcher) break;
    }
    case 4:
    {
        string g;
        cout << "Is the pipe under maintenance?\n"; // making maintenance
        while (0 != 1)
        {
            cout << 4 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
            {
                A.maint = "Under maintenance";
                break;
            }
            else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
            {
                A.maint = "Ready for exploitation";
                break;
            }
            else cout << "YES OR NO (please)\n";
        }
        switcher = 1;
        break;
    }
    case 5:
    {
        break;
    }
    default:
    {
        cout << "There's no such detail, change it before it's too late\n";
    }
    }
}

void CSAdd(int x, CS& B)
{
    int switcher = 1;
    switch (x)
    {
    case 0:
    {
        switcher = 0;
    }
    case 1:
    {
        while (0 != 1) // making name
        {
            cout << 1 << ". ";
            getline(cin, B.name);
            if (SpellCheck(B.name)) break;
            else cout << "You can't call it like that, sorry.\n";
        }
        if (switcher) break;
    }
    case 2:
    {
        string g;
        while (0 != 1) // making workshops number
        {
            cout << 2 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (IntCheck(g) and NumCheck(g))
            {
                if (stoi(g) > 0)
                {
                    B.wksh_num = stoi(g);
                    break;
                }
                else
                {
                    cout << "Wrong workshops number.\n---------\nHint: the workshops number must be bigger than 0\n---------\n";
                }
            }
        }
        if (switcher) break;
    }
    case 3:
    {
        string g;
        while (0 != 1) // making active workshops number
        {
            cout << 3 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (IntCheck(g) and NumCheck(g)) {
                if (stoi(g) >= 0)
                {
                    if (stoi(g) <= B.wksh_num)
                    {
                        B.act_wksh_num = stoi(g);
                        break;
                    }
                    else cout << "You can't use more workshops than you have, genius.\n";
                }
                else
                {
                    cout << "Wrong active workshops number.\n---------\nHint: you can't use a negative number of workshops\n---------\n";
                }
            }
        }
        if (switcher) break;
    }
    case 4:
    {
        string g;
        while (0 != 1) // making efficiency
        {
            cout << 4 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            getline(cin, g);
            if (IntCheck(g) and lenCheck(g))
            {
                int f = stoi(g);
                if (f >= 0 and f <= 5)
                {
                    B.eff = f;
                    break;
                }
                else
                {
                    cout << "Wrong efficiency data.\n---------\nHint: the number must be between 0 and 5\n---------\n";
                }
            }
        }
        switcher = 1;
        break;
    }
    case 5:
    {
        break;
    }
    default:
    {
        cout << "There's no such detail, change it before it's too late\n";
    }
    }
}
void ViewPipe(Pipe A)
{
    cout << "\nPipe info:\n";
    cout << A;
}
void ViewCS(CS B)
{
    cout << "\nCS info:\n";
    cout << B;
}
void ViewAll(Pipe A, CS B)
{
    Divider();
    if (A.len and B.wksh_num)
    {
        ViewPipe(A);
        ViewCS(B);
    }
    else if (A.len and !B.wksh_num)
    {
        ViewPipe(A);
        cout << "\nNo CS data to show here.\n";
    }
    else if (!A.len and B.wksh_num)
    {
        cout << "\nNo pipe data to show here.\n";
        ViewCS(B);
    }
    else
    {
        cout << "\nNo data to show here.\n";
    }
    Divider();
}

void SaveAll(Pipe A, CS B)
{
    ofstream out; // opening the file (writing mode)
    out.open("hello.txt");
    if (out.is_open())
    {
        out << A.name << endl
            << A.len << endl
            << A.diam << endl
            << A.maint << endl
            << B.name << endl
            << B.wksh_num << endl
            << B.act_wksh_num << endl
            << B.eff << endl;
    }
    out.close(); // closing the file
}
void LoadInfo(Pipe& A, CS& B)
{
    int kl = 0;
    string line;
    ifstream in("hello.txt"); // opening the file (reading mode)
    if (in.is_open())
    {
        getline(in, A.name);
        getline(in, line);
        A.len = stoi(line);
        getline(in, line);
        A.diam = stoi(line);
        getline(in, A.maint);
        getline(in, B.name);
        in >> B.wksh_num;
        in >> B.act_wksh_num;
        in >> B.eff;
    }
    in.close();     // closing the file
}