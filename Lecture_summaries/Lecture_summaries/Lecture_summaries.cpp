#include <iostream>
/*Classes*/
// can't use global variables in lab 2
/*
classes are structures, but all fields are private by default

classes have a special method "constructor" that's called the same as the class itself

if you make 2 consequential global variables, there's no guarantee one will be created after another
*/
class Pipe
{
public:
    //int l; <-- putting variables in public is generally bad
    int l; 
    Pipe() // <-- there's only one default constructor for the class
    {
        l = 9;
    }
    Pipe(int len) // <-- you can make many constructors with arguments for the class
    {
        l = len*1000;
    }
    //tilda Pipe()
    //{
    //    std::cout << "tilda Pipe()\n";// there can only be 1 destructor
    //}
    int getl() const
    {
        return l;
    }
    Pipe(Pipe& p) // <-- конструктор копирования
    {
        std::cout << "something\n";
        this->l = p.l; // <-- this isn't needed, because the constructor of copying already does this
                       // it's like "self" in python
    }
private:
    //int l = 11;
protected:
};

std::ostream& operator << (std::ostream& out, const Pipe& p)
{
    out << "Pipe's length is " << p.getl() << std::endl;
}
int main()
{
    std::cout << "Hello World!\n";
    
}

