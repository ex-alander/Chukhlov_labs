#pragma once // so that if an .h file is included twice, it only gets included once (also there's ifndef)
#include <iostream> // <-- � ������� ������� ����������� ����������
#define pi 3.14159265358979
#define sqr(x) x*x
// ���������������� headers ����� ���������� ����� �������
// headers are ctrlcctrlv-ed by the preprocessor
using namespace std;
/*Classes (30.09)*/
// can't use global variables in lab 2
/*
classes are structures, but all fields are private by default

classes have a special method "constructor" that's called the same as the class itself

if you make 2 consequential global variables, there's no guarantee one will be created after another
*/

/*Data types, .h files and stuff (06.10)*/
/*
Dynamic (heap)
Automatic (int, char, string stuff)
Static

Pointer = an address in the memory
& = operation of taking the address of a variable
* = operation of getting the value that is pointed to
* 

Ex.1: Pipe p vs. Pipe& p (Pipe& = address of pipe)

*pP = P, &P = pP

Check out topics: the lifetime of variables, linkers, preprocessors

���������� �������������� = private id
id ������� � ������ (������� �����) - � ������
getter setter
stl = standard template library - ��������� ����� ���� ������ (���)
vector is a containter
*/

/*�������� �� ������, �� ��� �������� ����, ��� ���*/
//do
//{
//    cin.clear();
//    cin.ignore(1i64, '\n');
//    if (counter > 1) cout << "You know you can't type this here, right?";
//    cin >> c; // change to some form of input
//    counter++;
//} while (cin.fail() or c < 0 or c > 7);

class Pipe
{
private:
    //int l = 11;

public:
    int id;
    static int NextId; // <-- lives throughout the whole program 
    //int l; <-- putting variables in public is generally bad
    int l, d = 0; 
    Pipe() // <-- there's only one default constructor for the class
    {
        id = NextId++;
    }
    Pipe(int len) // <-- you can make many constructors with arguments for the class
    {
        l = len*1000;
    }
    //~Pipe()
    //{
    //    std::cout << "tilda Pipe()\n";// there can only be 1 destructor
    //}
    int getl() const
    {
        return l;
    }
    void Print()
    {
        cout << "d = " << id << endl;
    }
    Pipe(Pipe& p) // <-- ����������� �����������
    {
        std::cout << "something\n";
        this->l = p.l; // <-- this isn't needed, because the constructor of copying already does this
                       // it's like "self" in python
    }
    static void HelloPipe()
    {
        cout << "Pipe: " << NextId << endl;
    }
    //ostream& operator << (ostream& out, const Pipe& p)
    //{
    //    cout << p.id << " d =" << p.d << endl;
    //}
    //friend istream& operator >> (istream& in, Pipe& p)
protected:
};


int Pipe::NextId = 1;

//std::ostream& operator << (std::ostream& out, const Pipe& p)
//{
//    out << "Pipe's length is " << p.getl() << std::endl;
//}
int main()
{
    { // <--- automatic variable lives within a block (inside this parenthesis
        Pipe P;
        //Pipe* pP = new Pipe();
        //Pipe* pP = nullptr;
        Pipe* pP = &P;
        std::cout << "Hello World!\n";
        cout << &P << endl;
        cout << pP << endl;
        //cout << pP->d << endl;
        //delete pP;
        //cout << P.d << endl; // <-- can't use a field of a variable whose address doesn't exist (deleted by delete function)
    }
    Pipe p;
    p.Print();
    Pipe::HelloPipe();

    int i = 2;
    cout << sqr(i++) << endl;
    //cout << f(2);
    return 0;
}
/* DATA STRUCTURES / CONTAINTERS */
/* 
                            ���������������� 
* ������ - �����������
* ������ - ������ ������� �������� ��������� �� ����� ����������
    1. forward list
    2. list
* ��� - ������ �������

                            ������������� (����� ������ �� �����)
* ��������� (���� = ��������)
    1. set - ��������� � ����������
    ������������?
    ��������� �� ������?
    2. unordered_set = hash-�������?
    3. multiset
    4. unordered_multiset
    5. map (����� ��������� ���� �� ������ ������,
            �� ������ ������� ��������� �� ������)
    6. unordered_map
    7. multimap
    8. unordered_multimap

* ������� [����, ��������]
* 

��������
* ���� (stack)[LIFO]
* ������� (queue)[FIFO]
* ������� � �����������




bool Check (Type-x(custom) x)
template <typename T>
T GetCorrectNumber(T min,T max)
{
T x;
^check edu github repository (until 'using')
------------------------------------------------------------------------------------
Check out:
relocation in vectors
push_back = append ?
.reserve - �������� capacity
.resize - �������� sizeoff, ��������� ������
at(lists)
list sorting
(!) ������ ���� �� ���������� � ����������, �� �������������� ����������
hash-function?
hash-�������
litcode

����������� ����� ����� ������ � �������������� �������
���� ���� ����� �����������, ���������� �� ���������� ������ ������������
*/

