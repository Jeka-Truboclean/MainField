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
		cout << "\t<Student>\n";
		University = new char[strlen(univ) + 1];
		strcpy_s(University, strlen(univ) + 1, univ);
		//cout << "Student has been created\n";
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
		//cout << "Student has been destroyed\n";
	}
};

class Teacher : public Person 
{
	char* University;
	int salary;
	char* tool;
public:
	Teacher() = default;
	Teacher(const char* n, int a, const char* univ, int sala, const char* TOOL) : Person(n, a), salary(sala)
	{
		cout << "\t<Teacher>\n";
		University = new char[strlen(univ) + 1];
		strcpy_s(University, strlen(univ) + 1, univ);
		tool = new char[strlen(TOOL) + 1];
		strcpy_s(tool, strlen(TOOL) + 1, TOOL);
	}
	void Print()
	{
		Person::Print();
		cout << "Univ.: " << University << "\nSalary: " << salary << " UAH" << "\nTools: " << tool << endl;
	}
	~Teacher()
	{
		delete[] University;
		delete[] tool;
	}

};

class Driver : public Person
{
	char* Auto;
	char* ID;
public:
	Driver() = default;
	Driver(const char* n, int a, const char* AUTO, const char* id) : Person(n, a)
	{
		cout << "\t<Driver>\n";
		Auto = new char[strlen(AUTO) + 1];
		strcpy_s(Auto, strlen(AUTO) + 1, AUTO);
		ID = new char[strlen(id) + 1];
		strcpy_s(ID, strlen(id) + 1, id);
	}
	void Print()
	{
		Person::Print();
		cout << "Car: " << Auto << "\nID licence: " << ID << endl;
	}
	~Driver()
	{
		delete[] Auto;
		delete[] ID;
	}
};

class Doctor : public Person
{
	char* special;
	char* hospital;
	short exp;
public:
	Doctor() = default;
	Doctor(const char* n, int a, const char* spec, const char* hosp, short EXP) : Person(n, a), exp(EXP)
	{
		cout << "\t<Doctor>\n";
		special = new char[strlen(spec) + 1];
		strcpy_s(special, strlen(spec) + 1, spec);
		hospital = new char[strlen(spec) + 1];
		strcpy_s(hospital, strlen(hosp) + 1, hosp);
	}
	void Print()
	{
		Person::Print();
		cout << "Speciality: " << special << "\nHospital: " << hospital << "\nExp.: " << exp << endl;
	}
};

int main()
{
	Student obj("Irina", 18, "ItStep");
	obj.Print();
	Teacher obj1("Alexei", 37, "Medical Univ.", 30000, "Document, Pen, Pencils, Notebook, Laptop");
	obj1.Print();
	Driver obj2("Nikolai", 28, "Porche 911", "G459-947-174-906");
	obj2.Print();
	Doctor obj3("Fedor", 35, "Surgeon", "Central", 6);
	obj3.Print();
}