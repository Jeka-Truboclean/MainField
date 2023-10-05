#include<iostream>

#include<stdio.h>

#include<string>

using namespace std;



class Cond

{

    string name;

public:

    Cond()

    {

        name = "Midea";

    }

    Cond(const char* N)

    {

        name = N;

    }

    Cond(Cond& obj)

    {

        name = obj.name;

    }

    void Show()

    {

        cout << name << endl;

    }

};

class Engine

{

    double w;

public:

    Engine()

    {

        w = 10000;

    }

    Engine(double d)

    {

        w = d;

    }

    void Show()

    {

        cout << "Engine w = " << w << endl;

    }

};

class GearBox
{
    int numGear;
public:
    GearBox()
    {
        numGear = 5;
    }
    GearBox(int a)
    {
        numGear = a;
    }
    void Show()

    {

        cout << "Number of gear = " << numGear << endl;

    }
};


class Radio
{
    string magnitola;
public:
    Radio()

    {

        magnitola = "Magnit";

    }

    Radio(string d)

    {

        magnitola = d;

    }

    void Show()

    {

        cout << "Mugnitola = " << magnitola << endl;

    }
};



class Car

{

    Cond* obj;   // не уничтожается при удалении объекта класса Car!!!  Агрегирование!

    int year;

    Engine a; // удаляется при уничтожении объекта класса Car!!! Композиция!
    GearBox b;
    Radio* c;

public:

    Car(Cond* x, double d, int y, int z, Radio* v) : obj(x), a(d), b(z), c(v)

    {

        year = y;



    }

    void Show()

    {

        cout << year << endl;

        obj->Show();

        a.Show();

    }

    ~Car()

    {

        cout << "Destruct\n";

    }

};





int main()

{

    Cond obj{ "Samsung" };
    Radio rad{ "Yamaha" };

    Car* ptr = new Car(&obj, 20000, 2018, 5, &rad);

    ptr->Show();

    delete ptr;

    cout << "\n---- obj2 -------------------\n";

    Car new_obj(&obj, 12000, 1999, 3, &rad);

    new_obj.Show();

}

