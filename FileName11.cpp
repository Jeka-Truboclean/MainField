#include <iostream>
using namespace std;

class Passport
{
	char* Country;
	char* Name;
	char* Surname;
	char* DateBirth;
	char* Issue;
	char* Expiry;
	time_t Num;
public:
	Passport() = default;
	Passport(const char* con, const char* name, const char* surname,
		const char* birth, const char* issue, const char* expiry, time_t num) : Num(num)
	{
		Country = new char[strlen(con) + 1];
		strcpy_s(Country, strlen(con) + 1, con);
		Name = new char[strlen(name) + 1];
		strcpy_s(Name, strlen(name) + 1, name);
		Surname = new char[strlen(surname) + 1];
		strcpy_s(Surname, strlen(surname) + 1, surname);
		DateBirth = new char[strlen(birth) + 1];
		strcpy_s(DateBirth, strlen(birth) + 1, birth);
		Issue = new char[strlen(issue) + 1];
		strcpy_s(Issue, strlen(issue) + 1, issue);
		Issue = new char[strlen(issue) + 1];
		strcpy_s(Issue, strlen(issue) + 1, issue);
		Expiry = new char[strlen(expiry) + 1];
		strcpy_s(Expiry, strlen(expiry) + 1, expiry);
	}
	Passport(const char* con, const char* name, const char* surname,
		const char* birth)
	{
		Country = new char[strlen(con) + 1];
		strcpy_s(Country, strlen(con) + 1, con);
		Name = new char[strlen(name) + 1];
		strcpy_s(Name, strlen(name) + 1, name);
		Surname = new char[strlen(surname) + 1];
		strcpy_s(Surname, strlen(surname) + 1, surname);
		DateBirth = new char[strlen(birth) + 1];
		strcpy_s(DateBirth, strlen(birth) + 1, birth);
	}
	void Print();
	void Print_2();
	~Passport()
	{
		delete[] Country, Name, Surname, DateBirth, Issue, Expiry;
	}
};

void Passport::Print()
{
	cout << "Country: " << Country << "\nName & Surname: " 
		<< Name << " " << Surname << "\nDate of birth: " 
		<< DateBirth << "\nDate of issue: " << Issue 
		<< "\nDate of expiry: " << Expiry << "\nNumber of document: " << Num << endl;
}
void Passport::Print_2()
{
	cout << "Country: " << Country << "\nName & Surname: "
		<< Name << " " << Surname << "\nDate of birth: "
		<< DateBirth << endl;
}

class Foreign_Passport : public Passport
{
	char* Issue;
	char* Expiry;
	time_t num;
public:
	Foreign_Passport() = default;
	Foreign_Passport(const char* con, const char* name, const char* surname,
		const char* birth, const char* issue, const char* expiry, time_t Num) : Passport(con, name, surname, birth), num(Num) 
	{
		Issue = new char[strlen(issue) + 1];
		strcpy_s(Issue, strlen(issue) + 1, issue);
		Expiry = new char[strlen(expiry) + 1];
		strcpy_s(Expiry, strlen(expiry) + 1, expiry);
	}
	void Print()
	{
		Passport::Print_2();
		cout << "Date of issue: " << Issue
			<< "\nDate of expiry: " << Expiry 
			<< "\nNumber of document: " << num << endl;
	}
};

int main()
{
	cout << "\t<Passport>\n";
	Passport passport("Ukraine" , "Yevhenii", "Karaman", "07.12.2006", "08.12.2019", "08.12.2024", 798378782953);
	passport.Print();
	cout << "\t<Foreign Passport>\n";
	Foreign_Passport foreign_passport("Ukraine", "Yevhenii", "Karaman", "07.12.2006", "24.09.2020", "24.09.2026", 63164791234);
	foreign_passport.Print();
}