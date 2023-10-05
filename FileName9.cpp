#include<iostream>
using namespace std;

class Person
{
protected: 
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) : age(a) // инициализатор
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void Print()
	{
		cout << "Name: " << name << "\nAge: " << age << endl;
	}
	void Input()
	{
		char buff[20];
		cout << "Enter Name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
};

class Student : public Person
{
	char* University;
public:
	Student() = default;
	Student(const char* n, int a, const char* univ) : /* <-делегирование */  Person(n, a) // вызов конструктора базового класса
	{
		University = new char[strlen(univ) + 1];
		strcpy_s(University, strlen(univ) + 1, univ);
		cout << "Student has been created\n";
	}
	void Print() // переопределение
	{
		Person::Print();
		cout << "Univ.: " << University << endl;
	}
	void Input(const char* univ) // замещение!!! - метод базового класса Ќ≈ замещаетс€!!!
	{
		delete[] University;
		University = new char[strlen(univ) + 1];
		strcpy_s(University, strlen(univ) + 1, univ);

		Person::Input();
	}
	~Student()
	{
		delete[]University;
		cout << "Student has been destroyed\n";
	}
};

int main()
{
	Student obj("Irina", 18, "ItStep");
	obj.Print();
	obj.Input("Academy IT");
	obj.Print();
}