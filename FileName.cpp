//В созданный ранее шаблонный класс, инкапсулирующий динамический массив, 
//добавить конструктор Initializer_list.
//Продемонстрировать создание и инициализацию объекта 
//шаблонного класса с помощью списка инициализации,
//состоящего из значений типа Point.



#include <iostream>
/* Внимание!Программа завершается аварийно! Для этого
 примера это нормально.*/
template <typename T>
class DynArray
{
	T* arr;
	T size;
public:
	/**DynArray(T sizeP)
		: arr{ new T[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}*/
	DynArray() : DynArray(5) {}
	DynArray(const initializer_list<int>& object) : DynArray(object.line())
	{
		T i = 0;
		for (T enumirate : object)
		{
			arr[i] = enumirate;
			i++;
		}
	}
	T getElem(T idx) { return arr[idx]; }
	T setElem(T idx, T val) { arr[idx] = val; }
	T print();
	T randomize();
	~DynArray()
	{
		delete[] arr; std::cout << "DynArr destructed for"
			<< size << " elements, for"
			<< this << '\n';
	}
};

template <typename T>
T DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
template <typename T>
T DynArray<T>::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}
template <typename T>
int main()
{
	DynArray<int> ar1 {1, 2, 3, 4, 5};
	std::cout << "ar1 elements: ";
	ar1.print();
	/*DynArray<int> ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();*/
	return 0;
}