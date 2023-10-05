#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string.h>
#include <initializer_list>
using namespace std;


class string_
{
private:
	//Строка
	char* S;
	//Длина строки
	int len;
public:
	//Конструктор по умолчанию
	//без параметров
	string_();
	//Перегруженный конструктор
	//с параметром
	string_(char* s);
	//Конструктор копирования
	string_(const string_& s);
	//Деструктор
	~string_() {
		delete[] S;
	}
	//Метод сортировки
	void Sort(string_ s[], int n);
	//Константный метод
	//возвращающий содержимое
	//строки
	const char* GetStr()const
	{
		return S;
	}
	//метод позволяющий изменить содержимое
	//с помощью пользователя
	void SetStr()
	{
		//если строка не пустая - очистить
		if (S != NULL)
			delete[]S;
		//создаем массив
		//и запрашиваем у пользователя данные
		char a[256];
		cin.getline(a, 256);
		//просчитываем размер
		len = strlen(a) + 1;
		//выделяем память
		S = new char[len];
		//переписываем в объект
		//введенную строку
		strcpy(S, a);
	}
	//метод позволяющий изменить содержимое
 //с помощью параметра
	void SetStr2(char* str)
	{
		//если строка не пустая - очистить
		if (S != NULL)
			delete[]S;
		//просчитываем размер
		len = strlen(str) + 1;
		//выделяем память
		S = new char[len];
		//переписываем в объект
		//введенную строку
		strcpy(S, str);
	}
};
string_::string_()
{
	//Начальная инициализация
	S = NULL;
	len = 0;
}
string_::string_(const std::initializer_list<int>& s) : string_(s.size())
{
	int i = 0;
	for (auto& element : s)
	{
		S[i] = element;
		i++;
	}
}
//string_::string_(const string_& s)
//{
//	len = s.len;
//	//Безопасное копирование 
//	S = new char[len + 1];
//	strcpy(S, s.S);
//}
void string_::Sort(string_ s[], int n)
{
	//Сортировка строк
	//Методом пузырька
	string_ temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			//сравнение двух строк
			if (strcmp(s[j].S, s[j - 1].S) < 0)
			{
				//запись строки s[j] в temp
				temp.SetStr2(s[j].S);
				//запись строки s[j-1] в s[j] 
				s[j].SetStr2(s[j - 1].S);
				//запись строки temp в s[j-1]
				s[j - 1].SetStr2(temp.S);
			}
		}
	}
}
void main()
{
	int n, i;
	//Вводим количество строк
	cout << "Input the number of string s: ";
	cin >> n;
	if (n < 0)
	{
		cout << "Error number:\t" << n << endl;
		return;
	}
	//Забираем из потока символ Enter ("\n")
	char c[2];
	cin.getline(c, 2);
	//Создаем массив из n строк
	string_* s = new string_[n];
	//Ввод строк c клавиатуры
	for (i = 0; i < n; i++)
		s[i].SetStr();
	//Сортировка строк
	//Вызов через указатель,
	//так как функция работает
	//для группы объектов,
	//а не для одного конкретного
	s->Sort(s, n);
	//Вывод отсортированных строк
	for (i = 0; i < n; i++)
		cout << "\n" << s[i].GetStr() << "\n";
	//Удаление массива строк
	delete[] s;
}
