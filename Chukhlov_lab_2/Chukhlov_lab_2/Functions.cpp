using namespace std;
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define NOMINMAX
#include <Windows.h>
#include <iterator>
#include "Checking tools.h"
#include "classes.h"
//#include "structs.h"
ostream& operator << (ostream& out, Pipe& a)
{
    out << "Name:                      " << a.name << endl
        << "Length:                    " << a.len << endl
        << "Diameter:                  " << a.diam << endl
        << "State:                     " << a.state << endl;
    return out;
}
ostream& operator << (ostream& out, CS& b)
{
    out << "Name:                      " << b.name << endl
        << "Workshops number:          " << b.wksh_num << endl
        << "Active workshops number:   " << b.active << endl
        << "Efficiency (0-5):          " << b.eff << endl;
    return out;
}

/*overloading cin for pipes & css*/
//istream& operator >> (istream& in, Pipe& a)
//{
//    out << "Name:                      " << a.name << endl
//        << "Length:                    " << a.len << endl
//        << "Diameter:                  " << a.diam << endl
//        << "State:                     " << a.maint << endl;
//    return out;
//}
//istream& operator >> (istream& out, CS& b)
//{
//    out << "Name:                      " << b.name << endl
//        << "Workshops number:          " << b.wksh_num << endl
//        << "Active workshops number:   " << b.act_wksh_num << endl
//        << "Efficiency (0-5):          " << b.eff << endl;
//    return out;
//}

/*DESIGN STUFF*/
string slice(string x, int start, int end)
{
    string slicie="";
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
    string logout="0";
    if (a == 0)
    {
        cout << "Welcome to the pipeline description module!\n";
    }
    else if (a == 1)
    {
        cout << "Here's what you can do:\n1. Pipes settings\n2. CS settings\n3. Save\n4. Load\n0. Exit\n\nEnter operation number:\n";
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
    if (abs(logout[0]-'0'))
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
        if (c_0!="")
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

/*reading , and - in pipe sequences*/
//bool FirstRangeCheck(string x)
//{
//    for (int i = 0; i < x.length(); i++)
//    {
//        if (x[i] - '0' >= 0 and x[i] - '0' <= 9 or x[i] - '0' == -3 or x[i] - '0' == -4)
//            continue;
//        else return 0;
//    }
//    return 1; 
//}
//bool SecondRangeCheck(string x)
//{
//    int token=0;
//    for (int i = 0; i < x.length(); i++)
//    {
//        if (x[i] - '0' == -3 or x[i] - '0' == -4)
//        {
//            i++;
//            if (x[i] - '0' == -3 or x[i] - '0' == -4)
//            {
//                return 0;
//            }
//        }
//        else continue;
//    }
//    return 1;
//}
//bool rangecheck(string r)
//{
//    if (FirstRangeCheck(r) and SecondRangeCheck(r) and r[0]-'0'>=0 and r[0]-'0'<=9)
//    {
//        return 1;
//    }
//    else return 0;
//}
//int NumConstruct (vector<int> n)
//{
//    int len=0, sum=0;
//    for (int i = 0; i < 5; i++)
//    {
//        if (n[i] == -1)
//        {
//            if (i == 0) return 0;
//            else len = i;
//            break;
//        }
//    }
//    if (!len)
//    { 
//        len = 5;
//    }
//    for (int i = 0; i < len; i++)
//    {
//        sum += n[i] * pow(10, (len - i - 1));
//    }
//    return sum;
//}
//vector<int> CDR_pipes(map<int,Pipe>pipes) // comma dash range
//{
//    int c[50];
//    for (int i = 0; i < 50; i++)
//    {
//        c[i] = -1;
//    }
//    int num = 0, // counter of ID's for c
//        a = 0, // beginning of the cycle for this ^^^ 
//        b = 0; // ending of the cycle
//    vector<int> n{ -1, -1, -1, -1, -1 }; //array that helps convert a sequence of char digits to int
//    bool dashtoggle = 0;
//    string c_0;
//    while (1) // number check
//    {
//        getline(cin, c_0);
//        if (c_0 == "all")
//        {
//            for (auto itr = pipes.begin();itr != pipes.end();itr++)
//            {
//                c[num] = itr->first;
//                num++;
//            }
//            break;
//        }
//        else if (rangecheck(c_0))
//        {
//            for (int i = 0; i <= c_0.length(); i++)
//            {
//                if (c_0[i] == ',' or c_0[i] == 0) // comma or end case
//                {
//                    if (!dashtoggle) // no dash prior to the last number
//                    {
//                        c[num] = NumConstruct(n);
//                        num++;
//                        fill_n(n.begin(), 5, -1);
//                    }
//                    else // if E dash
//                    {
//                        b = NumConstruct(n);
//                        fill_n(n.begin(), 5, -1);
//                        if (a < b)
//                        {
//                            for (int i = a; i <= b; i++)
//                            {
//                                c[num] = i;
//                                num++;
//                            }
//                            a = 0;
//                            b = 0;
//                            dashtoggle = 0;
//                        }
//                        else break;
//                    }
//                }
//                else if (c_0[i] == '-') // dash case
//                {
//                    dashtoggle = 1;
//                    a = NumConstruct(n); // set the start of the upcoming cycle
//                    fill_n(n.begin(), 5, -1);
//                }
//            else n[i] = c_0[i]; // if it's a number, just set n[i] to it, the rest
//                                // will be done by "if's"
//            }
//            break;
//        }
//        LogsStash(2);
//    }
//    return c;
//}
/*SETTING OBJECTS*/
void SetPipe(int x, Pipe& A)
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
        while(0!=1)
        {
            cout << 2 << ". ";
            A.len = number_big();
            if (A.len > 0)
            {
                break;
            }
            else
            {
                cout << "Wrong length data.\n---------\nHint: it must be bigger than 0\n---------\n";
            }
        }
        if (switcher) break;
    }
    case 3:
    {
        while (0 != 1) // making diameter
        {
            cout << 3 << ". ";
            A.diam = number_big();
            if (A.diam > 0)
            {
                break;
            }
            else
            {
                cout << "Wrong diameter data.\n---------\nHint: it must be bigger than 0\n---------\n";
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
                A.state = "Under maintenance";
                break;
            }
            else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
            {
                A.state = "Ready for exploitation";
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
        cout << "There's no such option.\n";
    }
    }
}
void SetCS(int x, CS& B)
{
    int switcher = 1;
    switch (x)
    {
    case 0:
    {
        switcher = 0;
    }
    case 1: // make name
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
    case 2: // make wksh num
    {
        while(0!=1)
        {
            cout << 2 << ". ";
            B.wksh_num = number_big();
            if (B.wksh_num > 0)
            {
                break;
            }
            else
            {
                cout << "Wrong workshops number.\n---------\nHint: it must be bigger than 0\n---------\n";
            }
        }
        if (switcher) break;
    }
    case 3: // make act wksh num
    {
        while (0 != 1) // making active workshops number
        {
            cout << 3 << ". ";
            int g = number_big();

            if (g > B.wksh_num)
            {
                cout << "You can't use more workshops than you have" << '\n';
                continue;
            }
            else if (g>0)
            {
                B.active = g;
                break;
            }
            else cout << "Wrong active workshops number.\n-------- - \nHint: it must be bigger than 0\n-------- - \n";
        }
        if (switcher) break;
    }
    case 4:
    {
        while (0 != 1) // making efficiency
        {
            cout << 4 << ". ";
            //cin.ignore(); // this was making things worse (first symbol couldn't get read)
            int f = number_big();
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
        switcher = 1;
        break;
    }
    case 5:
    {
        break;
    }
    default:
    {
        cout << "There's no such detail\n";
    }
    }
}

/*BOYER MOORE SEARCH FOR NAMES*/
const int ALPHABET_SIZE = 256;
void computeBadCharShift(const std::string& pattern, std::vector<int>& badCharShift) {
    int m = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharShift[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badCharShift[(int)pattern[i]] = i;
    }
}
bool BoyerMoore_bool(const std::string& text, const std::string& pattern) {
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

/*SEARCHING*/
map<int, Pipe> PipesSearch(map<int, Pipe>a)
{
    if (a.empty())
    {
        cout << "no data to show." << '\n';
        return a;
    }
    cout << "Choose what to search by:" << '\n'
        << "1. Name" << '\n'
        << "2. State" << '\n';
    int x;
    map<int, Pipe>ibwmap;
    string search_name;
    x = number();
    switch (x)
    {
    case 1: // by name
    {
        cout << "Enter the symbols sequence that the name must contain:" << '\n';
        getline(cin, search_name);
        for (auto itr = a.begin();itr != a.end();itr++)
        {
            if (BoyerMoore_bool(a[itr->first].name, search_name))
            {
                ibwmap[itr->first] = a[itr->first];
            }
        }
        break;
    }
    case 2: // by state
    {
        cout << "Choose what pipes to show: (type number)" << '\n'
            << "1. Under maintenance" << '\n'
            << "2. Ready for exploitation" << '\n';
        int state;
        bool switcher = false;
        while (true)
        {
            state = number();
            switch (state)
            {
            case 1:
            {
                search_name = "Under maintenance";
                break;
            }
            case 2:
            {
                search_name = "Ready for exploitation";
                break;
            }
            default:
            {
                cout << "That was NOT an option" << '\n';
                switcher = true;
            }
            }
            if (!switcher) break;
        }
        for (auto itr = a.begin();itr != a.end();itr++)
        {
            if (a[itr->first].state == search_name)
            {
                ibwmap[itr->first] = a[itr->first];
            }
        }
        break;
    }
    default:
    {
        cout << "wrong" << '\n';
    }
    }
    return ibwmap;
}
map<int, CS> CSSearch(map<int, CS>b)
{
    if (b.empty())
    {
        cout << "no data to show." << '\n';
        return b;
    }
    cout << "Choose what to search by:" << '\n'
        << "1. Name" << '\n'
        << "2. Percentage of inactive worshops" << '\n';
    int x = number();
    map<int, CS>ibwmap;
    switch (x)
    {
    case 1: // search by name
    {
        cout << "Enter the symbols sequence that the name must contain:" << '\n';
        string search_name;
        getline(cin, search_name);
        for (auto itr = b.begin();itr != b.end();itr++)
        {
            if (BoyerMoore_bool(b[itr->first].name, search_name))
            {
                ibwmap[itr->first] = b[itr->first];
            }
        }
        break;
    }
    case 2: // search by percentage
    {
        cout << "Enter desired persentage of inactive workshops:" << '\n';
        int inact_desire;
        while (true)
        {
            inact_desire = number_big();
            if (100 < inact_desire or inact_desire < 0)
            {
                cout << "Wrong\n";
                continue;
            }
            else break;
        }
        cout << '\n' << "Choose what compressor stations to show:" << '\n'
            << "1. the ones that have bigger percentage of inactive workshops" << '\n'
            << "2. the ones that have smaller percentage of inactive workshops" << '\n'
            << "3. those having percentage equal to desired" << '\n';
        int chooser = number();
        switch (chooser)
        {
        case 1:
        {
            for (auto itr = b.begin();itr != b.end();itr++)
            {
                float inact_percent = (b[itr->first].wksh_num - b[itr->first].active) * 100 / b[itr->first].wksh_num;
                if (inact_percent >= inact_desire)
                {
                    ibwmap[itr->first] = b[itr->first];
                }
            }
            break;
        }
        case 2:
        {
            for (auto itr = b.begin();itr != b.end();itr++)
            {
                float inact_percent = (b[itr->first].wksh_num - b[itr->first].active) * 100 / b[itr->first].wksh_num;
                if (inact_percent <= inact_desire)
                {
                    ibwmap[itr->first] = b[itr->first];
                }
            }
            break;
        }
        case 3:
        {
            for (auto itr = b.begin();itr != b.end();itr++)
            {
                float inact_percent = (b[itr->first].wksh_num - b[itr->first].active) * 100 / b[itr->first].wksh_num;
                if (inact_percent == inact_desire)
                {
                    ibwmap[itr->first] = b[itr->first];
                }
            }
            break;
        }
        default:
        {
            cout << "wrong" << '\n';
        }
        }
        break;
    }
    default: // if wrong
    {
        cout << "wrong" << '\n';
    }
    }
    return ibwmap;
}

/*ADD OBJECTS*/
void AddPipe(int& id_pipe,map<int, Pipe>& pipes)
{
    Pipe pipe;
    LogsStash(10);
    SetPipe(0, pipe);
    Record("A new pipe was added");
    pipes.insert(pair<int, Pipe&>(id_pipe, pipe));
    id_pipe++;
}
void AddCS(int& id_cs, map<int, CS>& css)
{
    CS cs;
    LogsStash(20);
    SetCS(0, cs);
    Record("A new CS was added");
    css.insert(pair<int, CS>(id_cs, cs));
    id_cs++;
}

/*EDIT OBJECTS*/
void EditOnePipe(map<int, Pipe>& pipes)
{
    cout << "Enter pipe ID:" << endl;
    int g = number_big();
    if (exist(pipes[g]))
    {
        LogsStash(40);
        int c = number();
        SetPipe(c, pipes[g]);
    }
}
void EditOneCS(map<int, CS>& css)
{
    cout << "Enter CS ID:" << '\n';
    int g = number_big();
    if (exist(css[g]))// check if there even is one
    {
        LogsStash(50);
        int c = number();
        SetCS(c, css[g]);
    }
}

/*VECTOR OF ID's FOR BATCH EDIT*/
template <typename T>
vector <int> IDs_vector(map<int, T>& b)
{
    vector <int> vec = {};
    CS ibwCS;
    int g;
    cout << "Enter ID's of all objects you want edit:" << '\n'
        << "(press 'Enter' after each ID)" << '\n';
    if (b.empty())
    {
        cout << "No objects to edit\n";
        return vec;
    }
    cout << "[to exit, type -1]" << endl;
    //getting ID's
    while (0 != 1)
    {
        g = number_big_n_negative();
        if (g >= 0)
        {
            if (b[g].name[0] - '0')
            {
                vec.push_back(g);
            }
            else
            {
                b.erase(g);
                cout << "Try another one, you fopdoodle\n";
            }
        }
        else if (g == -1)
        {
            if (vec.size())
            {
                cout << "ID input successful\n";
            }
            else cout << "Batch editing exitted successfully\n";
            break;
        }
    }
    return vec;
}
/*BATCH EDIT*/
void BatchEditPipes(map<int, Pipe>& a, string isfilter)
{
    vector<int> vec;
    if (isfilter == "notfilter")
    {
        vec = IDs_vector(a);
    }
    bool switcher = false;
    Pipe ibwPipe;
    /*ALTERNATE BATCH EDIT*/ //[CAN EDIT EVERYTHING]
    //cout << "Choose what detail to edit:\n0. Everything at once\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Exit\n";
    //g = number();  
    ////batch edit
    //while(true)
    //{
    //switch (g)
    //    {
    //        case 5:
    //        {
    //            return;
    //        }
    //        case 0:
    //        {
    //            PipeAdd(g, ibwPipe);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]] = ibwPipe;
    //            }
    //            break;
    //        }
    //        case 1:
    //        {
    //            PipeAdd(g, ibwPipe);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].name = ibwPipe.name;
    //            }
    //            break;
    //        }
    //        case 2:
    //        {
    //            PipeAdd(g, ibwPipe);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].len = ibwPipe.len;
    //            }
    //            break;
    //        }
    //        case 3:
    //        {
    //            PipeAdd(g, ibwPipe);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].diam = ibwPipe.diam;
    //            }
    //            break;
    //        }
    //        case 4:
    //        {
    //            PipeAdd(g, ibwPipe);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].state = ibwPipe.state;
    //            }
    //            break;
    //        }
    //        default:
    //        {
    //            cout << "Try again" << endl;
    //            switcher = true;
    //        }
    //    }
    //if (!switcher) break;
    //}
    /*making changes*/
    cout << "Are the pipes under maintenance?" << "\n";
    while (0 != 1)
    {
        string g;
        //cin.ignore(); // this was making things worse (first symbol couldn't get read)
        getline(cin, g);
        if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
        {
            ibwPipe.state = "Under maintenance";
            break;
        }
        else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
        {
            ibwPipe.state = "Ready for exploitation";
            break;
        }
        else cout << "YES OR NO (please)\n";
    }
    // applying changes
    if (isfilter == "notfilter")
    {
        for (int i = 0; i < vec.size();i++)
        {
            a[vec[i]].state = ibwPipe.state;
        }
    }
    else
    {
        for (auto itr = a.begin(); itr != a.end(); itr++)
        {
            a[itr->first].state = ibwPipe.state;
        }
    }
    Record("Batch edited pipes");
}
void BatchEditCSs(map<int, CS>& b, string isfilter)
{
    CS ibwCS;
    bool switcher = false;
    vector<int> vec;
    if (isfilter == "notfilter")
    {
        vec = IDs_vector(b);
        cout << "Enter new active workshops number:" << '\n';
        /*making changes*/
        while (true)
        {
            ibwCS.active = number_big();
            for (auto i = 0; i < vec.size();i++)
            {
                if (ibwCS.active > b[vec[i]].active)
                {
                    cout << "You can't use more workshops than you have, genius.\n";
                    switcher = true;
                    break;
                }
                else switcher = false;
            }
            if (switcher) continue;
            else break;
        }
    }
    else
    {
        cout << "Enter new active workshops number:" << '\n';
        while (true)
        {
            ibwCS.active = number_big();
            for (auto itr = b.begin(); itr != b.end(); itr++)
            {
                if (ibwCS.active > b[itr->first].active)
                {
                    cout << "You can't use more workshops than you have, genius.\n";
                    switcher = true;
                    break;
                }
                else switcher = false;
            }
            if (switcher) continue;
            else break;
        }
    }
    /*ALTERNATE BATCH EDIT*/ //[CAN EDIT EVERYTHING]
    //cout << "Choose what detail to edit:\n0. Everything at once\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Exit\n";
    //g = number();
    ////batch edit
    //while(true)
    //{
    //    switch (g)
    //    {
    //        case 5:
    //        {
    //            return;
    //        }
    //        case 0:
    //        {
    //            CSAdd(g, ibwCS);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]] = ibwCS;
    //            }
    //            break;
    //        }
    //        case 1:
    //        {
    //            CSAdd(g, ibwCS);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].name = ibwCS.name;
    //            }
    //            break;
    //        }
    //        case 2:
    //        {
    //            CSAdd(g, ibwCS);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].wksh_num = ibwCS.wksh_num;
    //            }
    //            break;
    //        }
    //        case 3:
    //        {
    //            CSAdd(g, ibwCS);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].active = ibwCS.active;
    //            }
    //            break;
    //        }
    //        case 4:
    //        {
    //            CSAdd(g, ibwCS);
    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                a[vec[i]].eff = ibwCS.eff;
    //            }
    //            break;
    //        }
    //        default:
    //        {
    //            cout << "Try again" << endl;
    //            switcher = true;
    //        }
    //    }
    //    if (!switcher) break;
    //}
    /**/
    // applying changes
    if (isfilter == "notfilter")
    {
        for (int i = 0; i < vec.size(); i++)
        {
            b[vec[i]].active = ibwCS.active;
        }
    }
    else
    {
        for (auto itr = b.begin(); itr != b.end(); itr++)
        {
            b[itr->first].active = ibwCS.active;
        }
    }
    Record("Batch edited CS");
}

/*DELETE OBJECTS*/
void DeletePipes(map<int,Pipe>& pipes)
{
    cout << "Choose action:" << endl
            << "1. Proceed with blowing stuff up" << endl
            << "2. Show all pipes" << endl
            << "3. Leave demolition operations" << endl;
    int c = number_big();
    switch (c)
    {
        case 3:
        {
            break;
        }
        case 2:
        {
            PrintMap(pipes);
        }
        case 1:
        {
            cout << "Choose target" << endl;
            c = number_big();
            if (pipes[c].len)
            {
                pipes.erase(c);
                cout << "Pipe #" << c << " has been erased" << '\n';
            }
            else
            {
                pipes.erase(c);
                cout << "you can't blow up something that exists only in your head." << endl;
            }
            break;
        }
        default:
        {
            cout << "Codswallop! " << endl;
        }
    }
}
void DeleteCS(map<int, CS>& css)
{
    cout << "Choose action:" << endl
        << "1. Proceed with blowing stuff up" << endl
        << "2. Show all compressor stations" << endl
        << "3. Leave demolition operations" << endl;
    int c = number_big();
    switch (c)
    {
    case 3:
    {
        break;
    }
    case 2:
    {
        PrintMap(css);
    }
    case 1:
    {
        cout << "Choose target" << endl;
        c = number_big();
        if (css[c].wksh_num)
        {
            css.erase(c);
            cout << "CS #" << c << " has been erased" << '\n';
        }
        else
        {
            css.erase(c);
            cout << "you can't blow up something that exists only in your head." << endl;
        }
        break;
    }
    default:
    {
        cout << "No such operation. " << endl;
        break;
    }
    }
}

/*VIEW OBJECTS*/
void ViewPipes(map<int, Pipe>& pipes)
{
    cout << "Choose one of the following: " << '\n'
        << "1. View all pipes" << '\n'
        << "2. Use a filter" << '\n';
    int c = number();
    switch (c)
    {
    case 1: // view all
    {
        if (!pipes.empty())
        {
            PrintMap(pipes);
        }
        else cout << "nothing to show here." << '\n';
        break;
    }
    case 2: // filtered view
    {
        map<int, Pipe>found = PipesSearch(pipes);
        PrintMap(found);
        cout << "Choose what to do with what you've found:" << '\n'
            << "1. Edit" << '\n'
            << "2. Delete" << '\n';
        c = number();
        switch (c)
        {
        case 1:
        {
            BatchEditPipes(found,"filter");
            for (auto itr = found.begin(); itr != found.end(); itr++)
            {
                pipes[itr->first] = found[itr->first];
            }
            break;
        }
        case 2:
        {
            for (auto itr = found.end(); itr != found.begin(); itr--)
            {
                pipes.erase(itr->first);
            }
            break;
        }
        default:
        {
            cout << "you have to read more carefully" << '\n';
        }
        }
        break;
    }
    default:
    {
        cout << "nope. can't do that" << '\n';
    }
    }
}
void ViewCS(map<int, CS>& css)
{
    cout << "Choose one of the following: " << '\n'
        << "1. View all CSs" << '\n'
        << "2. Use a filter" << '\n';
    int c = number();
    switch (c)
    {
    case 1: // view all
    {
        if (!css.empty())
        {
            PrintMap(css);
        }
        else cout << "nothing to show here." << '\n';
        break;
    }
    case 2: // use filter
    {
        map<int,CS>found=CSSearch(css);
        PrintMap(found);
        cout << "Choose what to do with what you've found:" << '\n'
            << "1. Edit" << '\n'
            << "2. Delete" << '\n';
        c = number();
        switch (c)
        {
        case 1:
        {
            BatchEditCSs(found, "filter");
            for (auto itr = found.begin(); itr != found.end(); itr++)
            {
                css[itr->first] = found[itr->first];
            }
            break;
        }
        case 2:
        {
            for (auto itr = found.begin(); itr != found.end(); itr++)
            {
                css.erase(itr->first);
            }
            break;
        }
        }
        break;
    }
    default:
    {
        cout << "that wasn't an option" << '\n';
    }
    }
}

/*WHOLE SETTINGS*/
void PipesSettings(int& id_pipe, map<int,Pipe>& pipes){
    int c;
    LogsStash(7);
    c = number();
    switch (c)
    {
    case 1: // add pipes
    {
        AddPipe(id_pipe,pipes);
        break;
    }
    case 2: // edit pipes
    {
        cout << "Choose one of the following:" << endl
            << "1. Edit a specific pipe" << endl
            << "2. Edit multiple pipes" << endl;
        c = number();
        switch (c)
        {
        case 1:
        {
            EditOnePipe(pipes);
            break;
        }
        case 2:
        {
            BatchEditPipes(pipes, "notfilter");
            break;
        }
        default:
        {
            cout << "no such operation";
            break;
        }
        }
        break;
    }
    case 3: // delete pipes
    {
        DeletePipes(pipes);
        break;
    }
    case 4: // view pipes
    {
        ViewPipes(pipes);
        break;
    }
    default: // if wrong
    {
        cout << "that wasn't an option." << '\n';
    }
    }
}
void CSSettings(int& id_cs,map<int, CS>& css)
{
    CS cs;
    LogsStash(7);
    int c = number();
    switch (c)
    {
    case 1: // add css
    {
        AddCS(id_cs, css);
        break;
    }
    case 2: // edit css
    {
        cout << "Choose one of the following:" << '\n'
            << "1. Choose a specific CS" << '\n'
            << "2. Choose multiple CS's" << '\n';
        c = number();
        switch (c)
        {
        case 1:
        {
            EditOneCS(css);
            break;
        }
        case 2:
        {
            BatchEditCSs(css, "notfilter");
            break;
        }
        default:
        {
            cout << "no such action." << '\n';
            break;
        }
        }
        break;
    }
    case 3: // delete css
    {
        DeleteCS(css);
        break;
    }
    case 4: // view css
    {
        ViewCS(css);
        break;
    }
    default:
    {
        cout << "you just can't read right can you" << '\n';
    }
    }
}

/*VIEWING*/
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

/*SAVE & LOAD*/
void SaveAll(map<int,Pipe>& A, map<int,CS>& B)
{
    ofstream out_db; // opening the file (writing mode)
    string filename;
    cout << "Enter the name of the file you want to save your data to:" << '\n';
    getline(cin, filename);
    out_db.open("filenames_db.txt");
    if (out_db.is_open())
    {
        out_db << filename << endl;
    }
    out_db.close();
    ofstream out;
    out.open(filename);
    if (out.is_open())
    {
        if(!A.empty())
        {
            for (auto itr = A.begin(); itr != A.end(); itr++)
            {
                out << itr->first << endl;
                out << A[itr->first].name << endl
                    << A[itr->first].len << endl
                    << A[itr->first].diam << endl
                    << A[itr->first].state << endl;
            }
        }
        if (!B.empty())
        {
            for (auto itr = B.begin(); itr != B.end(); itr++)
            {
                out << itr->first << endl;
                out << B[itr->first].name << endl
                    << B[itr->first].wksh_num << endl
                    << B[itr->first].active << endl
                    << B[itr->first].eff << endl;
            }
        }
    }
    out.close(); // closing the file
}
bool VectorStringSearch(vector<string>vec_str, string a)
{
    for (int i = 0;i < vec_str.size();i++)
    {
        if (vec_str[i] == a) return true;
    }
    return false;
}
void LoadInfo(map<int,Pipe>& A, map<int,CS>& B, int& id_pipe, int& id_cs)
{
    cout << "\nEnter file name: \n";
    int kl = 0;
    string filename;
    string line;
    vector<string>filenames_db;
    getline(cin, filename);
    //checking if the chosen file exists
    /*ifstream in_check("filenames_db.txt");
    if (in_check.is_open())
    {
        string temp_name;
        getline(in_check, temp_name);
        for (string i : filenames_db)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    in_check.close();
    if (!VectorStringSearch(filenames_db, filename))
    {
        cout << filename << ":    No such file" << '\n';
        return;
    }*/
    ifstream in(filename); // opening the file (reading mode)
    if (in.is_open())
    {
        string str_temp_id, prev_id="/";
        int temp_id;
        bool switcher = false;
        do
        {
        getline(in,str_temp_id);
        cout << "Here it is: " << str_temp_id << endl;
        if (str_temp_id[0]-'0'>=0)
        {
            temp_id = stoi(str_temp_id);
        }
        else break;
        if ((str_temp_id.size()>prev_id.size() or str_temp_id[str_temp_id.size()-1] - '0' > prev_id[prev_id.size()-1] - '0') and !switcher)
        {
            getline(in, A[temp_id].name);
            getline(in, line);
            A[temp_id].len = stoi(line);
            getline(in, line);
            A[temp_id].diam = stoi(line);
            getline(in, A[temp_id].state);
        }
        else
        {
            getline(in, B[temp_id].name);
            getline(in, line);
            B[temp_id].wksh_num = stoi(line);
            getline(in, line);
            B[temp_id].active = stoi(line);
            getline(in, line);
            B[temp_id].eff = stoi(line);
            switcher = true;
        }
        prev_id = str_temp_id;
        } while (str_temp_id[0] - '0' >= 0);
        if (B.empty())
        {
            A.erase(-48);
        }
        else B.erase(-48);
        id_pipe = (--A.end())->first+1;
        id_cs = (--B.end())->first+1;
    }
    in.close();     // closing the file
}