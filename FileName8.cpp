#include <iostream>
using namespace std;
//Класс "студент"
class Student {
protected:
	string name;
	int age;
public:
	Student() {
		name = "Sasha";
		age = 15;
	}
	//получение name
	string& GetName() {
		return name;
	}
	//получение age
	int& GetAge() {
		return age;
	}
};
class StepStudent : public Student {
	int technologies;
	string own;
public:
	StepStudent() {
		technologies = 5;
		own = "C++";
	}
	//получение количество языков
	int& GetTech() {
		return technologies;
	}
	//получение сколько владеет языками
	string& GetOwn() {
		return own;
	}
	//показ на экран
	void Show() {
		cout << "--------------\n";
		cout << "Name: " << name << "\n";
		cout << "Age: " << age << "\n";
		cout << "Technologies: " << technologies << "\n";
		cout << "Own: " << own << "\n";
		cout << "--------------\n";
	}
};
void main() {
	//создание объекта
	StepStudent Stud;
	Stud.Show();
}
