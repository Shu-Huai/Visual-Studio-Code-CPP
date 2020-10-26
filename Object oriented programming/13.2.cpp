#include <iostream>
using namespace std;
class Animal
{
protected:
    string kind;

public:
    Animal(const string &KIND)
    {
        kind = KIND;
    }
    void Sound() const;
};
class Cat : public Animal
{
public:
    Cat();
};
class Dog : public Animal
{
public:
    Dog();
};
class Rooster : public Animal
{
public:
    Rooster();
};
class Cattle : public Animal
{
public:
    Cattle();
};
class Horse : public Animal
{
public:
    Horse();
};
void Animal::Sound() const
{
    if (kind == "Cat")
    {
        cout << "miaow ...";
    }
    else if (kind == "Dog")
    {
        cout << "wang ...";
    }
    else if (kind == "Rooster")
    {
        cout << "crow ...";
    }
    else if (kind == "Cattle")
    {
        cout << "moo ...";
    }
    else if (kind == "Horse")
    {
        cout << "neigh ...";
    }
    else
    {
        return;
    }
    cout << endl;
}
Cat::Cat() : Animal("Cat")
{
}
Dog::Dog() : Animal("Dog")
{
}
Rooster::Rooster() : Animal("Rooster")
{
}
Cattle::Cattle() : Animal("Cattle")
{
}
Horse::Horse() : Animal("Horse")
{
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