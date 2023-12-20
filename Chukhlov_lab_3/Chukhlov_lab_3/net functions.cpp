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
#include "Main functions.h"
#include "classes.h"
using namespace std;

/*SEARCHING*/
map<int, net::Pipe> net::PipesSearch(map<int, net::Pipe>a)
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
    map<int, net::Pipe> ibwmap;

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
                ibwmap.insert(pair<int, net::Pipe>(itr->first, a[itr->first]));
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
                ibwmap.insert(pair<int,net::Pipe>(itr->first,a[itr->first]));
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
map<int, net::CS> net::CSSearch(map<int, net::CS > b)
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
    map<int, net::CS>ibwmap;
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
                ibwmap.insert(pair<int, net::CS>(itr->first, b[itr->first]));
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
                    ibwmap.insert(pair<int, net::CS>(itr->first, b[itr->first]));
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
                    ibwmap.insert(pair<int, net::CS>(itr->first, b[itr->first]));
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
                    ibwmap.insert(pair<int, net::CS>(itr->first, b[itr->first]));
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

/*SETTING OBJECTS*/
void net::SetPipe(int x, net::Pipe& A)
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
        while (0 != 1)
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
void net::SetCS(int x, net::CS& B)
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
        while (0 != 1)
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
            else if (g > 0)
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

/*ADD OBJECTS*/
void net::AddPipe(int& id_pipe, map<int, net::Pipe>& pipes)
{
    net::Pipe pipe;
    LogsStash(10);
    SetPipe(0, pipe);
    Record("A new pipe was added");
    pipes.insert(pair<int, net::Pipe&>(id_pipe, pipe));
    id_pipe++;
}
void net::AddCS(int& id_cs, map<int, net::CS>& css)
{
    net::CS cs;
    LogsStash(20);
    SetCS(0, cs);
    Record("A new CS was added");
    css.insert(pair<int, net::CS>(id_cs, cs));
    id_cs++;
}

/*EDIT OBJECTS*/
void net::EditOnePipe(map<int, net::Pipe>& pipes)
{
    cout << "Enter pipe ID:" << endl;
    int g = number_big();
    if (pipes[g].exist())
    {
        LogsStash(40);
        int c = number();
        SetPipe(c, pipes[g]);
    }
    else cout << "no such pipe!\n";
}
void net::EditOneCS(map<int, net::CS>& css)
{
    cout << "Enter CS ID:" << '\n';
    int g = number_big();
    if (css[g].exist())// check if there even is one
    {
        LogsStash(50);
        int c = number();
        SetCS(c, css[g]);
    }
    else cout << "no such CS!\n";
}

/*VECTOR OF ID's FOR BATCH EDIT*/
template <typename T>
vector <int> IDs_vector(map<int, T>& b)
{
    vector <int> vec = {};
    net::CS ibwCS;
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
void net::BatchEditPipes(map<int, net::Pipe>& a, string isfilter)
{
    vector<int> vec;
    if (isfilter == "notfilter")
    {
        vec = IDs_vector(a);
    }
    bool switcher = false;
    net::Pipe ibwPipe;
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
void net::BatchEditCSs(map<int, net::CS>& b, string isfilter)
{
    net::CS ibwCS;
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
void net::DeletePipes(map<int, net::Pipe>& pipes)
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
void net::DeleteCS(map<int, net::CS>& css)
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
void net::ViewPipes(map<int, net::Pipe>& pipes)
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
        map<int, net::Pipe>found = PipesSearch(pipes);
        PrintMap(found);
        cout << "Choose what to do with what you've found:" << '\n'
            << "1. Edit" << '\n'
            << "2. Delete" << '\n';
        c = number();
        switch (c)
        {
        case 1:
        {
            BatchEditPipes(found, "filter");
            for (auto itr = found.begin(); itr != found.end(); itr++)
            {
                pipes[itr->first] = found[itr->first];
            }
            break;
        }
        case 2:
        {
            for (auto itr = found.begin(); itr != found.end(); itr++)
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
void net::ViewCS(map<int, net::CS>& css)
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
        map<int, net::CS>found = CSSearch(css);
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
void net::PipesSettings(int& id_pipe, map<int, net::Pipe>& pipes) {
    int c;
    LogsStash(7);
    c = number();
    switch (c)
    {
    case 1: // add pipes
    {
        AddPipe(id_pipe, pipes);
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
void net::CSSettings(int& id_cs, map<int, net::CS>& css)
{
    net::CS cs;
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

/*SAVE & LOAD*/
void net::SaveAll(map<int, net::Pipe>& A, map<int, net::CS>& B)
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
        if (!A.empty())
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
void net::LoadInfo(map<int, net::Pipe >& A, map<int, net::CS>& B, int& id_pipe, int& id_cs)
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
        string str_temp_id, prev_id = "/";
        int temp_id;
        bool switcher = false;
        do
        {
            getline(in, str_temp_id);
            //cout << "Here it is: " << str_temp_id << endl;
            if (str_temp_id[0] - '0' >= 0)
            {
                temp_id = stoi(str_temp_id);
            }
            else break;
            if ((str_temp_id.size() > prev_id.size() or str_temp_id[str_temp_id.size() - 1] - '0' > prev_id[prev_id.size() - 1] - '0') and !switcher)
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
        id_pipe = (--A.end())->first + 1;
        id_cs = (--B.end())->first + 1;
    }
    in.close();     // closing the file
}
/*TOP SORT*/
void net::topsort_action(vector<CS>&visited, net::CS cs)
{
    visited.push_back(cs);
    
    topsort_action(visited, cs);
}
void net::topsort(map<int,net::CS>& css)
{
    this->visited; // to talk to visited thingies
    for (auto itr = css.begin(); itr != css.end(); itr++)
    {
        if (inVector(this->visited, itr->second)) continue;
        topsort_action(this->visited,itr->second);
    }
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