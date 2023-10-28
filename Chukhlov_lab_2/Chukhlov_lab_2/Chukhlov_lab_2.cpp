#include <iostream>
#include <string>
#include <fstream>
#include "Main functions.h"
#include "Checking tools.h"
#include "structs.h"
using namespace std;

int main()
{
    string c_0 = "1000";
    int c;
    int i = 0;
    Pipe A;
    CS B;
    MenuCall(0);
    while (1)
    {
        int counter = 0;
        MenuCall(1);
        c=number(c_0);

        switch (c) // control panel
        {
        case 1:
        {
            MenuCall(10);
            PipeAdd(0,A);
            break;
        }
        case 2:
        {
            MenuCall(20);
            CSAdd(0,B);
            break;
        }
        case 3:
        {
            ViewAll(A,B);
            break;
        }
        case 4:
        {
            if (A.name[0] - '0')
            {
                MenuCall(40);
                int detnum;
                string det_string = "10";
                detnum = number(det_string);
                PipeAdd(detnum, A);
            }
            else
            {
                Divider();
                MenuCall(4);
                Divider();
            }
            break;
        }
        case 5:
        {
            MenuCall(50);
            if (B.name[0] - '0')
            {
                int detnum;
                string det_string = "10";
                detnum = number(det_string);
                CSAdd(detnum, B);
            }
            else
            {
                Divider();
                MenuCall(4);
                Divider();
            }
            break;
        }
        case 6:
        {
            Divider();
            if (A.name[0]-'0' and B.name[0]-'0')
            {
                SaveAll(A, B);
                cout << "\nSaved.\n";
            }
            else cout << "\nError saving data. Check if you even have any pipes or compressor stations.\n";
            Divider();
            break;
        }
        case 7:
        {
            Divider();
            try
            {
                LoadInfo(A, B);
                cout << "\ninfo loaded.\n";
            }
            catch (...)
            {
                cout << "\nno data to load.\n";
            }
            Divider();
            break;
        }
        case 0:
        {
            cout << "c ya";
            return 0;
        }
        default:
        {
            cout << "There's no such operation, why don't you try again\n";
        }
        }
    }
    return 0;
}
