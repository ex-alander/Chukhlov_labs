#pragma once
#include <string>
using namespace std;
class GNR
{
public:
    class Pipe
    {
    private:
        bool on;
    public:
        string name, state;
        int len, diam;
        Pipe()
        {
            name = "0";
            len = 0;
            diam = 0;
            state = "0";
        }
        void flick()
        {
            if (on) state = "Under maintenance";
            else state = "Ready for exploitation";
            on = !on;
        }
    };
    class CS
    {

    public:
        string name;
        int wksh_num, active, eff;
        CS()
        {
            name = "0";
            wksh_num = 0;
            active = 0;
            eff = 0;
        }
    };
    void connect(Pipe& a, CS& b)
    {

    }
    void disconnect(Pipe& a, CS& b)
    {

    }

};
class Pipe
{
private:
    bool on;
public:
    string name, state;
    int len, diam;
    Pipe()
    {
        name = "0";
        len = 0;
        diam = 0;
        state = "0";
    }
    void flick()
    {
        if (on) state = "Under maintenance";
        else state = "Ready for exploitation";
        on = !on;
    }
};
class CS
{

public:
    string name;
    int wksh_num, active, eff;
    CS()
    {
        name = "0";
        wksh_num = 0;
        active = 0;
        eff = 0;
    }
};
