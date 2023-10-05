#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/* Внимание!Программа завершается аварийно! Для этого
 примера это нормально.*/
template <typename T>
class DynArray
{
	T* arr;
	int size;
	int* arr1;
	double* arr2;
	char* arr3;
public:
	DynArray(T sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object)
		: arr{ object.arr }, size{ object.size }
	{
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	int getElem(int idx) { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	T print();
	T randomize();
	T Sum();
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
T DynArray<T>::Sum()
{
	T sum = 0;
	for (int i{ 0 }; i < size; ++i)
	{
		sum += arr[i];
	}
	return sum;
}
template <typename T>
int main()
{
	DynArray ar1{ 10 };
	ar1.randomize();
	std::cout << "ar1 elements: ";
	ar1.print();
	cout << "Sum: " << ar1.Sum() << endl;
	
	DynArray ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();
	//DynArray ar3{ 5 };
	return 0;
}