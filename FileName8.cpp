#include <iostream>
using namespace std;
//����� "�������"
class Student {
protected:
	string name;
	int age;
public:
	Student() {
		name = "Sasha";
		age = 15;
	}
	//��������� name
	string& GetName() {
		return name;
	}
	//��������� age
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
	//��������� ���������� ������
	int& GetTech() {
		return technologies;
	}
	//��������� ������� ������� �������
	string& GetOwn() {
		return own;
	}
	//����� �� �����
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
	//�������� �������
	StepStudent Stud;
	Stud.Show();
}
