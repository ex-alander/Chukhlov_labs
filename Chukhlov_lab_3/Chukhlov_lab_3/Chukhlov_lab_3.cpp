#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <map>
#include <iterator>
#include <vector>
#include "Main functions.h"
#include "Checking tools.h"
//#include "structs.h"
#include <time.h>
using namespace std;
int main()
{
    int i = 0, id_cs = 0, id_pipe = 0;
    // setting up the console so that it looks cool
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    map <int, Pipe> pipes;
    map <int, CS> css;
    LogsStash(0);
    while (true)
    {
        int counter = 0;
        LogsStash(1);
        int c = number();

        switch (c) // control panel
        {
        case 1: // pipes settings
        {
            PipesSettings(id_pipe, pipes);
            break;
        }
        case 2: // css settings
        {
            CSSettings(id_cs, css);
            break;
        }
        case 3: // save
        {
            Divider();
            if (!pipes.empty() or !pipes.empty())
            {
                SaveAll(pipes, css);
                cout << "\nSaved.\n";
                Record("Saved current info");
            }
            else cout << "\nError saving data. Check if you even have any pipes or compressor stations.\n";
            Divider();
            break;
        }
        case 4: // load
        {
            Divider();
            LoadInfo(pipes, css, id_pipe, id_cs);
            cout << "\ninfo loaded.\n";
            Record("info loaded");
            Divider();
            break;
        }
        case 0: // close
        {
            cout << "c ya";
            return 0;
        }
        case 8: // Russia
        {
            {
                SetConsoleTextAttribute(hConsole, 255);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl;
                SetConsoleTextAttribute(hConsole, 153);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl;
                SetConsoleTextAttribute(hConsole, 68);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl << endl;
                SetConsoleTextAttribute(hConsole, 11);
                Record("user viewed the Russian flag!");
            }
            break;
        }
        default:
        {
            cout << "There's no such operation, why don't you try again\n";
        }
        }
    }
    return 0;
}
