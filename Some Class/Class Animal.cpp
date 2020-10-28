#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void Sound() const=0;
};
class Cat : public Animal
{
public:
    void Sound() const;
};
class Dog : public Animal
{
public:
    void Sound() const;
};
class Rooster : public Animal
{
public:
    void Sound() const;
};
class Cattle : public Animal
{
public:
    void Sound() const;
};
class Horse : public Animal
{
public:
    void Sound() const;
};
void Cat::Sound() const
{
    cout << "miaow ..." << endl;
}
void Dog::Sound() const
{
    cout << "wang ..." << endl;
}
void Rooster::Sound() const
{
    cout << "crow ..." << endl;
}
void Cattle::Sound() const
{
    cout << "moo ..." << endl;
}
void Horse::Sound() const
{
    cout << "neigh ..." << endl;
}
void Speaker(const Animal &a)
{
    a.Sound();
}
void Speaker(const Animal *a)
{
    a->Sound();
}
int main()
{
    Cat c;
    Dog d;
    Rooster r;
    Cattle ca;
    Horse h;
    cout << "Use void Sound();" << endl;
    c.Sound();
    d.Sound();
    r.Sound();
    ca.Sound();
    h.Sound();
    cout << "Use void Speaker(const Animal &a);" << endl;
    Speaker(c);
    Speaker(d);
    Speaker(r);
    Speaker(ca);
    Speaker(h);
    cout << "Use void Sound(const Animal *a);" << endl;
    Speaker(c);
    Speaker(d);
    Speaker(r);
    Speaker(ca);
    Speaker(h);
    return 0;
}