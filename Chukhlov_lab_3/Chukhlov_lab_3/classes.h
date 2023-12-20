#pragma once
#include <string>

using namespace std;

class net
{
public:
    class CS
    {

    public:
        bool operator == (const net::CS& cs2)
        {
            return this->name == cs2.name
                and this->wksh_num == cs2.wksh_num
                and this->active == cs2.active
                and this->eff == cs2.eff;
        }
        string name;
        int wksh_num, active, eff;
        CS()
        {
            name = "0";
            wksh_num = 0;
            active = 0;
            eff = 0;
        }
        bool exist()
        {
            return this->name[0] - '0';
        }
    };
    class Pipe
    {
    private:
        bool on = true;

    public:
        bool operator == (const net::Pipe& pipe2)
        {
            return this->name == pipe2.name
                and this->len == pipe2.len
                and this->diam == pipe2.diam
                and this->state == pipe2.state
                and this->start == pipe2.start
                and this->end == pipe2.end;
        }

        string name, state;
        int len, diam;
        net::CS start;
        net::CS end;
        const net::CS nullCS;
        Pipe()
        {
            name = "0";
            len = 0;
            diam = 0;
            state = "0";
            start = nullCS;
            end = nullCS;
        }
        bool exist()
        {
            return this->name[0] - '0';
        }
        void flick()
        {
            if (state == "Ready for exploitation") state = "Under maintenance";
            else state = "Ready for exploitation";
        }
        void connect(net::CS a, net::CS b)
        {
            if (!a.exist() or !b.exist())
            {
                cout << "ERROR: object(s) not found\n";
                return;
            }
            if (a == b)
            {
                cout << "Connecting a CS to iteslf? Genius. \n";
            }
            else
            {
                start = a;
                end = b;
                cout << "CS's connected successfully\n";
                cout << "the start of the new edge is " << this->start.name << '\n'
                    << "and the end of it is " << this->end.name << '\n';
            }
        }
        void disconnect()
        {
            start = end = nullCS;
        }
        Pipe& operator=(Pipe& A)
        {
            A.name = this->name;
            A.len = this->len;
            A.diam = this->diam;
            A.state = this->state;
            A.start = this->start;
            A.end = this->end;
            return A;
        }
    };
    map<int, net::Pipe> PipesSearch(map<int, net::Pipe>a);
    map<int, net::CS> CSSearch(map<int, net::CS > b);
    void SetPipe(int x, net::Pipe& A);
    void SetCS(int x, net::CS& B);
    void AddPipe(int& id_pipe, map<int, net::Pipe>& pipes);
    void AddCS(int& id_cs, map<int, net::CS>& css);
    void EditOnePipe(map<int, net::Pipe>& pipes);
    void EditOneCS(map<int, net::CS>& css);
    void BatchEditPipes(map<int, net::Pipe>& a, string isfilter);
    void BatchEditCSs(map<int, net::CS>& b, string isfilter);
    void DeletePipes(map<int, net::Pipe>& pipes);
    void DeleteCS(map<int, net::CS>& css);
    void ViewPipes(map<int, net::Pipe>& pipes);
    void ViewCS(map<int, net::CS>& css);
    void PipesSettings(int& id_pipe, map<int, net::Pipe>& pipes);
    void CSSettings(int& id_cs, map<int, net::CS>& css);
    void SaveAll(map<int, net::Pipe>& A, map<int, net::CS>& B);
    void LoadInfo(map<int, net::Pipe>& A, map<int, net::CS>& B, int& id_cs, int& id_pipe);
    void topsort_action(vector<CS>& visited, net::CS cs);
    void topsort(map<int, CS>& css);
    stack<net::CS>to_print;
    vector<net::CS>visited;
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
    bool exist()
    {
        return this->name[0] - '0';
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
    bool exist()
    {
        return this->name[0] - '0';
    }
};
