#include <iostream>
#include <string>

using namespace std ;

enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal {
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
        COLOR getColor()
        {
            return _color;
        }

        string getName()
        {
            return _name;
        }

        virtual void speak() {
            cout << "Animal speaks "<< endl ;
        }
        virtual void move() = 0;
    private :
        string _name;
        COLOR _color ;
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
        virtual void eat()
        {
            cout << "Mammal eat " << endl;
        }

        virtual void move()
        {
            cout << "Mammal moves" << endl;
        }
};

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

    void speak()
    {
        cout << "Woof" << endl;
    }

    void move()
    {
        cout << "Dog move" << endl;
    }

    void eat()
    {
        cout << "Dog eat" << endl;
    }
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

    void speak()
    {
        cout << "Cat meow" << endl;
    }

    void move()
    {
        cout << "Cat move" << endl;
    }

    void eat()
    {
        cout << "Cat eat" << endl;
    }
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

    void speak()
    {
        cout << "Lion" << endl;
    }

    void move()
    {
        cout << "Lion move" << endl;
    }

    void eat()
    {
        cout << "Lion eat" << endl;
    }
};

int main() {
    //Animal a;                             //for 3.1
    //Animal a1("Testing", Black);          //for 3.1
    //a.speak();                            //for 3.1
    //a1.speak();                           //for 3.1

    //Mammal m("Testing", Green);             //for 3.2
    //m.speak();                              //for 3.2

    //Dog d("Testing", Blue, "Testing_Owner");    //for 3.2
    //d.speak();                                  //for 3.2

    //d.move();                                   //for 3.2

    //Animal *animalPtr = new Dog("Lassie", White, "Andy");   //for 3.3
    //animalPtr->speak();                                     //for 3.3
    //animalPtr->move();                                      //for 3.3
    //delete animalPtr;                                       //for 3.3

    /*Dog dogi("Lassie", White, "Andy");              //for 3.3
    Mammal *aniPtr = &dogi;                         //for 3.3
    Mammal &aniRef = dogi;                          //for 3.3
    Mammal aniVal = dogi;                           //for 3.3
    aniPtr->speak();                                //for 3.3
    aniRef.speak();                                 //for 3.3
    aniVal.speak();*/                                 //for 3.3

    //for 3.3
    int choice = 0;
    Mammal **mammal = new Mammal*[3];
    mammal[0] = new Dog();
    mammal[1] = new Cat();
    mammal[2] = new Lion();

    do
    {
        cout << "Select the animal to send to Zoo :" << endl;
        cout << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                mammal[0]->move();
                mammal[0]->speak();
                mammal[0]->eat();
                break;

            case 2:
                mammal[1]->move();
                mammal[1]->speak();
                mammal[1]->eat();
                break;

            case 3:
                mammal[2]->move();
                mammal[2]->speak();
                mammal[2]->eat();
                break;

            case 4:
                for(int i=0; i<3; i++)
                {
                    mammal[i]->move();
                    mammal[i]->speak();
                    mammal[i]->eat();
                }
                break;
        }
    }while(choice != 5);

    //free memory
    for(int i=0; i<3; i++)
        delete mammal[i];
    delete [] mammal;

    cout << "Program exiting …. "<< endl ;

    return 0;
}

