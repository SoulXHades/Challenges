#include <iostream>
#include "animal.h"

using namespace std;

class Dog : public Mammal
{
    private:
        string _owner;

    public:
        Dog() : Mammal()
        {
            _owner = "Unknown_Owner";
            cout << "Constructing Dog object " << Animal::getName() << endl;
        }

        Dog(string n, COLOR c, string owner) : Mammal(n, c)
        {
            _owner = owner;
            cout << "Constructing Dog object " << Animal::getName() << " with color of ";

            switch(Animal::getColor())
            {
                case Green:
                    cout << "Green" << endl;
                    break;

                case Blue:
                    cout << "Blue" << endl;
                    break;

                case White:
                    cout << "White" << endl;
                    break;

                case Black:
                    cout << "Black" << endl;
                    break;

                case Brown:
                    cout <<"Brown" << endl;
                    break;
            }
        }

        ~Dog()
        {
            cout << "destructing Dog object " << Animal::getName() << endl;
        }

    void speak();
    void move();
    void eat();
};

class Cat : public Mammal
{
    private:
        string _owner;

    public:
        Cat() : Mammal()
        {
            _owner = "Unknown_Owner";
            cout << "Constructing Cat object " << Animal::getName() << endl;
        }

        Cat(string n, COLOR c, string owner) : Mammal(n, c)
        {
            _owner = owner;
            cout << "Constructing Cat object " << Animal::getName() << " with color of ";

            switch(Animal::getColor())
            {
                case Green:
                    cout << "Green" << endl;
                    break;

                case Blue:
                    cout << "Blue" << endl;
                    break;

                case White:
                    cout << "White" << endl;
                    break;

                case Black:
                    cout << "Black" << endl;
                    break;

                case Brown:
                    cout <<"Brown" << endl;
                    break;
            }
        }

        ~Cat()
        {
            cout << "destructing Cat object " << Animal::getName() << endl;
        }

    void speak();
    void move();
    void eat();
};

class Lion : public Mammal
{
    private:
        string _owner;

    public:
        Lion() : Mammal()
        {
            _owner = "Unknown_Owner";
            cout << "Constructing Lion object " << Animal::getName() << endl;
        }

        Lion(string n, COLOR c, string owner) : Mammal(n, c)
        {
            _owner = owner;
            cout << "Constructing Lion object " << Animal::getName() << " with color of ";

            switch(Animal::getColor())
            {
                case Green:
                    cout << "Green" << endl;
                    break;

                case Blue:
                    cout << "Blue" << endl;
                    break;

                case White:
                    cout << "White" << endl;
                    break;

                case Black:
                    cout << "Black" << endl;
                    break;

                case Brown:
                    cout <<"Brown" << endl;
                    break;
            }
        }

        ~Lion()
        {
            cout << "destructing Lion object " << Animal::getName() << endl;
        }

    void speak();
    void move();
    void eat();
};
