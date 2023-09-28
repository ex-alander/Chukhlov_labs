#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Pipe
{
    string name;
    int len = 0;
    int diam = 0;
    string maint;
};
struct CS
{
    string name;
    int wksh_num = 0;
    int act_wksh_num = 0; // <=workshop_num!
    float eff = 0; // from 1 to 10
};
//void one(string x, int y, int z, bool w) // <-- that'd work if we were allowed to use global variables
//{
//    int i;
//    string g;
//    cout << "\nSo you wanna add a new pipe, huh? Write, one after another, the following details:";
//    cout << "\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n" << endl;
//    i = 1;
//    cout << i << ". ";
//    cin >> x;
//    i++;
//    cout << i << ". ";
//    cin >> g;
//    if (stoi(g)) y = stoi(g);  
//    else y = 0;
//    i++;
//    cout << i << ". ";
//    cin >> g;
//    if (stoi(g)) z = stoi(g);
//    else z = 0;
//    i++;
//    cout << i << ". ";
//    while (0 != 1)
//    {
//        cin >> g;
//        try {
//            if (stoi(g)) w = 1;
//            else w = 0;
//            break;
//        }
//        catch (...) {
//            cout << "Wrong.\n";
//        }
//    }
//}


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
        cout << "You did't even try.\n";
    }
    else if (a == 3)
    {
        cout << "Changes were saved temporarily (to save them permamently, press '6').\n";
    }
    else if (a == 4)
    {
        cout << "You can't edit an object that doesn't exist\n";
    }
    else if (a == 5)
    {
        cout << "You can't call it like that, sorry.\n";
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
        cout << "\nEdit pipe info.\nChoose what detail to edit:\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Everything at once\n0. Exit\n";
    }
    else if (a == 50)
    {
        cout << "\nEdit CS info.\nChoose what detail to edit:\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n5. Everything at once\n0. Exit\n";
    }
}


int IntCheck(string x)
{
    try
    {
        if (stoi(x))1 < 2;
        return 1;
    }
    catch (...)
    {
        MenuCall(2);
        return 0;
    }
}


int main()
{
    string c_0 = "1";
    int c = stoi(c_0);
    int i = 0;
    Pipe A;
    CS B;
    MenuCall(0);
    MenuCall(1);
    while (c != 0) {
        while (0 != 1) // number check
        {
            cin >> c_0;
            if (IntCheck(c_0))
            {
                c = stoi(c_0);
                break;
            }
        }

        /*PIPE ADDING*/

        if (c == 1) {
            //one(A.name, A.len, A.diam, A.maint); // <--that'd work if we were allowed to use global variables 
            string g;
            MenuCall(10);

            i = 1;
            while (0 != 1)
            {
                cout << i << ". ";
                cin.ignore();
                getline(cin, A.name);
                if (SpellCheck(A.name)) break;
                else cout << "You can't call it like that, sorry.\n";
            }
            i++;

            while (0 != 1) // making length
            {
                cout << i << ". ";
                cin >> g;
                if (IntCheck(g)) {
                    if (stoi(g)>0)
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
            i++;

            while (0 != 1) // making diameter
            {
                cout << i << ". ";
                cin >> g;
                if (IntCheck(g))
                {
                    if (stoi(g)>0)
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
            i++;
            cout << "Is the pipe under maintenance?\n";

            while (0 != 1) // making maintenance
            {
                cout << i << ". ";
                cin >> g;
                if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
                {
                    A.maint = "Maintenance";
                    break;
                }
                else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
                {
                    A.maint = "Ready_for_exploitation";
                    break;
                }
                else cout << "YES OR NO (please)\n";
            }

        }

        /*CS ADDING*/

        else if (c == 2) {
            MenuCall(20);
            string g;

            i = 1;
            while (0 != 1) // making name
            {
                cout << i << ". ";
                cin.ignore();
                getline(cin,B.name);
                if (SpellCheck(B.name)) break;
                else cout << "You can't call it like that, sorry.\n";
            }
            i++;

            while (0 != 1) // making workshops number
            {
                cout << i << ". ";
                cin >> g;
                if (IntCheck(g))
                {
                    if (stoi(g)>0)
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
            i++;

            while (0 != 1) // making active workshops number
            {
                cout << i << ". ";
                cin >> g;
                if (IntCheck(g)) {
                    if (stoi(g)>=0)
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
            i++;

            while (0 != 1) // making efficiency
            {
                cout << i << ". ";
                if (IntCheck(g))
                {
                    cin >> g;
                    float f = stof(g);
                    if (f >= 0 and f <= 10)
                    {
                        B.eff = f;
                        break;
                    }
                    else
                    {
                        cout << "Wrong efficiency data.\n---------\nHint: the number must be between 0 and 10\n---------\n";
                    }
                }
            }
        }

        /*VIEW ALL DATA*/

        else if (c == 3) {
            if (A.len and B.wksh_num)
            {
                cout << "\nPipe info:\n";
                cout << "1. " << A.name << endl
                    << "2. " << A.len << endl
                    << "3. " << A.diam << endl
                    << "4. " << A.maint << endl;
                cout << "\nCS info:\n";
                cout << "1. " << B.name << endl
                    << "2. " << B.wksh_num << endl
                    << "3. " << B.act_wksh_num << endl
                    << "4. " << B.eff << endl;
                MenuCall(1);
            }
            else if (A.len and !B.wksh_num)
            {
                cout << "\nPipe info:\n";
                cout << "1. " << A.name << endl
                    << "2. " << A.len << endl
                    << "3. " << A.diam << endl
                    << "4. " << A.maint << endl;
                cout << "\nNo CS data to show here.\n";
                MenuCall(1);
            }
            else if (!A.len and B.wksh_num)
            {
                cout << "\nNo pipe data to show here.\n";
                cout << "\nCS info:\n";
                cout << "1. " << B.name << endl
                    << "2. " << B.wksh_num << endl
                    << "3. " << B.act_wksh_num << endl
                    << "4. " << B.eff << endl;
                MenuCall(1);
            }
            else
            {
                cout << "\nNo data to show here.\n";
                MenuCall(1);
            }
        }

        /*EDIT PIPE*/

        else if (c == 4) {
            if (!A.name[0]) // check if you can
            {
                MenuCall(4);
                continue;
            }
            string a, g;
            int pipedet;
            MenuCall(40);
            while (1 < 2)
            {
                while (0 != 1) // number check
                {
                    cin >> a;
                    if (IntCheck(a))
                    {
                        pipedet = stoi(a);
                        break;
                    }
                }
                if (pipedet == 1) // editing name
                {
                    while (0 != 1) // making name
                    {
                        cout << pipedet << ". ";
                        cin >> A.name;
                        if (SpellCheck(A.name)) break;
                        else cout << "You can't call it like that, sorry.\n";
                    }
                    MenuCall(3);
                    break;
                }
                else if (pipedet == 2) // editing length
                {
                    while (0 != 1) // making length
                    {
                        cout << pipedet << ". ";
                        cin >> g;
                        if (IntCheck(g)) {
                            A.len = stoi(g);
                            break;
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (pipedet == 3) // editing diameter
                {
                    while (0 != 1) // making diameter
                    {
                        cout << pipedet << ". ";
                        cin >> g;
                        if (IntCheck(g))
                        {
                            A.diam = stoi(g);
                            break;
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (pipedet == 4) // editing maintenance
                {
                    cout << "Is the pipe under maintenance?\n";
                    while (0 != 1) // making maintenance
                    {
                        cout << pipedet << ". ";
                        cin >> g;
                        if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
                        {
                            A.maint = "Maintenance";
                            break;
                        }
                        else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
                        {
                            A.maint = "Ready for exploitation";
                            break;
                        }
                        else cout << "YES OR NO DUMMY (please)\n";
                    }
                    MenuCall(3);
                    break;
                }
                else if (pipedet == 5) // editing everything
                {
                    MenuCall(10);

                    i = 1;
                    while (0 != 1) // making name
                    {
                        cout << i << ". ";
                        cin >> A.name;
                        if (SpellCheck(A.name)) break;
                        else cout << "You can't call it like that, sorry.\n";
                    }
                    i++;

                    while (0 != 1) // making length
                    {
                        cout << i << ". ";
                        cin >> g;
                        if (IntCheck(g)) {
                            A.len = stoi(g);
                            break;
                        }
                    }
                    i++;

                    while (0 != 1) // making diameter
                    {
                        cout << i << ". ";
                        cin >> g;
                        if (IntCheck(g))
                        {
                            A.diam = stoi(g);
                            break;
                        }
                    }
                    i++;
                    cout << "Is the pipe under maintenance?\n";

                    while (0 != 1) // making maintenance
                    {
                        cout << i << ". ";
                        cin >> g;
                        if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
                        {
                            A.maint = "Maintenance";
                            break;
                        }
                        else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
                        {
                            A.maint = "Ready_for_exploitation";
                            break;
                        }
                        else cout << "YES OR NO DUMMY (please)\n";
                    }

                }
                else if (pipedet == 0)
                {
                    cout << "Exit to main menu.\n";
                    break;
                }
                else cout << "Incorrect detail number. Try again:\n";
            }
        }

        /*EDIT CS*/

        else if (c == 5) {
            if (!B.name[0]) // check if you can
            {
                MenuCall(4);
                continue;
            }
            string a, g;
            int csdet;
            MenuCall(50);
            while (1 < 2)
            {
                while (0 != 1) // number check
                {
                    cin >> a;
                    if (IntCheck(a))
                    {
                        csdet = stoi(a);
                        break;
                    }
                }
                if (csdet == 1)
                {
                    while (0 != 1) // making name
                    {
                        cout << csdet << ". ";
                        cin >> B.name;
                        if (SpellCheck(B.name)) break;
                        else cout << "You can't call it like that, sorry.\n";
                    }
                    MenuCall(3);
                    break;
                }
                else if (csdet == 2)
                {
                    while (0 != 1) // making workshops number
                    {
                        cout << csdet << ". ";
                        cin >> g;
                        if (IntCheck(g))
                        {
                            B.wksh_num = stoi(g);
                            break;
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (csdet == 3)
                {
                    while (0 != 1) // making active workshops number
                    {
                        cout << csdet << ". ";
                        cin >> g;
                        if (IntCheck(g)) {
                            if (stoi(g) <= B.wksh_num)
                            {
                                B.act_wksh_num = stoi(g);
                                break;
                            }
                            else cout << "You can't use more workshops than you have, genius.\n";
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (csdet == 4)
                {
                    while (0 != 1) // making efficiency
                    {
                        cout << csdet << ". ";
                        if (IntCheck(g))
                        {
                            cin >> g;
                            float f = stof(g);
                            if (f >= 0 and f <= 10)
                            {
                                B.eff = f;
                                break;
                            }
                            else
                            {
                                cout << "Wrong efficiency data.\n---------\nHint: the number must be between 0 and 10\n---------\n";
                            }
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (csdet == 5)
                {

                    i = 1;
                    while (0 != 1) // making name
                    {
                        cout << i << ". ";
                        cin >> B.name;
                        if (SpellCheck(B.name)) break;
                        else cout << "You can't call it like that, sorry.\n";
                    }
                    i++;

                    while (0 != 1) // making workshops number
                    {
                        cout << i << ". ";
                        cin >> g;
                        if (IntCheck(g))
                        {
                            B.wksh_num = stoi(g);
                            break;
                        }
                    }
                    i++;

                    while (0 != 1) // making active workshops number
                    {
                        cout << i << ". ";
                        cin >> g;
                        if (IntCheck(g)) {
                            if (stoi(g) <= B.wksh_num)
                            {
                                B.act_wksh_num = stoi(g);
                                break;
                            }
                            else cout << "You can't use more workshops than you have, genius.\n";
                        }
                    }
                    i++;

                    while (0 != 1) // making efficiency
                    {
                        cout << i << ". ";
                        if (IntCheck(g))
                        {
                            cin >> g;
                            float f = stof(g);
                            if (f >= 0 and f <= 10)
                            {
                                B.eff = f;
                                break;
                            }
                            else
                            {
                                cout << "Wrong efficiency data.\n---------\nHint: the number must be between 0 and 10\n---------\n";
                            }
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (csdet == 0)
                {
                    cout << "Exit to main menu.\n";
                    break;
                }
                else cout << "Incorrect detail number. Try again:\n";
            }
        }

        /*SAVING SYSTEM*/

        else if (c == 6) {
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
            cout << "Saved." << endl;
        }

        /*LOADING SYSTEM*/

        else if (c == 7) {
            int kl = 0;
            string line;
            ifstream in("hello.txt"); // opening the file (reading mode)
            if (in.is_open())
            {
                getline(in,A.name);
                in >> A.len;
                in >> A.diam;
                getline(in,A.maint);
                getline(in,B.name);
                in >> B.wksh_num;
                in >> B.act_wksh_num;
                in >> B.eff;
            }
            in.close();     // closing the file
            cout << "info loaded.\n";
        }

        /*EXIT*/

        else if (c == 0) {
            cout << "c ya\n";
            break;
        }
    }
    return 0;
}