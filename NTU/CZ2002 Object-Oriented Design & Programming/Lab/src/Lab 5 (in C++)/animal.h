#include <iostream>
#include <string>

using namespace std;

enum COLOR { Green, Blue, White, Black, Brown };

class Animal {
    private :
        string _name;
        COLOR _color ;

    public :
        Animal() : _name("unknown") {
            cout << "constructing Animal object "<< _name << endl ;
        }

        Animal(string n, COLOR c) : _name(n), _color(c)
        {
            cout << "constructing Animal object " << _name << " with color of ";

            switch(c)
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
        ~Animal() {
            cout << "destructing Animal object " << _name << endl ;
        }

        COLOR getColor();
        string getName();
        virtual void speak();
        virtual void move() = 0;
};


class Mammal : public Animal
{
    public :
        Mammal() : Animal()
        {
            cout << "Constructing Mammal object " << Animal::getName() << endl;
        }

        Mammal(string n, COLOR c) : Animal(n, c)
        {
            cout << "Constructing Mammal object " << Animal::getName() << " with color of ";

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

        ~Mammal()
        {
            cout << "destructing Mammal object " << Animal::getName() << endl;
        }

        //prevents object from modification when using this function
        virtual void eat();

        virtual void move();
};

