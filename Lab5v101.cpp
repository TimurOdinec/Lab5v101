#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>
//#include <typeinfo.h>
//3.	Написать шаблон класса вектор, 
// который принимает элементы любого типа.
// В классе реализовать методы, например, поиска, сортировки, удаления и т.д.
// При реализации методов использовать динамическую идентификацию типа элементов объекта.



#include <iostream>
#include <vector>

template<class T>
class VectorT {
	T* array;
	int size;
	int numbElements;

public:
	VectorT();										//конструктор
	VectorT(int numbElements);							//конструктор
	VectorT(int numbElements, const T& elementInit);	//конструктор наполняет вектор элементами elementInit
	VectorT(const VectorT<T>& vec);					//конструктор копирования
	~VectorT();										//деструктор

	void viewVectorT();								//выводэлементов вектора в консоль
	void reserve(int numbElements);
	int getSize();
	int getNumbElements();
	T* arrayBegin();								//начало вектора
	T* arrayEnd();									//конец вектора
	void pushBack(const T& value);					//добавляем элемент
	void popBack();									//вытягиваем элемент 
	void clear();									//очистка вектора
	VectorT<T>& operator=(const VectorT<T>& vec);	//перегрузка оператора =
	T& operator[](int index);						//перегрузка оператора []
};
template<class T>
VectorT<T>::VectorT() 
{
	array = NULL;
	size = 0;
	numbElements = 0;
}
template<class T>
VectorT<T>::VectorT(int numbElements) 
{
	size = 0;
	this->numbElements = numbElements;
	array = new T[numbElements];
}
template<class T>
VectorT<T>::VectorT(int numbElements, const T& initial)
{
	this->numbElements = numbElements;
	this->size = numbElements;
	this->array = new T[numbElements];
	for (int i = 0; i < numbElements; i++) 
	{
		array[i] = initial;
	}
}
template<class T>
VectorT<T>::VectorT(const VectorT& vec)
{
	size = vec.size;
	numbElements = vec.numbElements;
	array = new T[size];
	for (int i = 0; i < size; i++) 
	{
		array[i] = vec.array[i];
	}
}
template<class T>
VectorT<T>::~VectorT() 
{
	delete[]array;
}
template<class T>
void VectorT<T>::viewVectorT()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		std::cout << array[i] << "; ";
	}
}

template<class T>
void VectorT<T>::reserve(int numbElements) 
{
	this->numbElements = this->getNumbElements() + numbElements;
	T* newarr = new T[this->numbElements];
	for (int i = 0; i < this->getSize(); i++)
	{
		newarr[i] = array[i];
	}
	delete[]array;
	array = newarr;
}
template<class T>
int VectorT<T>::getSize() 
{
	return size;
}
template<class T>
int VectorT<T>::getNumbElements() 
{
	return numbElements;
}
template<class T>
T* VectorT<T>::arrayBegin() 
{
	return array;
}
template<class T>
T* VectorT<T>::arrayEnd() 
{
	return array + getNumbElements();
}
template<class T>
void VectorT<T>::pushBack(const T& value) 
{
	if (size == numbElements) 
	{
		reserve(1);
	}
	array[size++] = value;
}
template<class T>
void VectorT<T>::popBack() 
{
	if (size > 0) 
	{
		size--;
		T* newarr = new T[numbElements];
		for (int i = 0; i < size; i++)
		{
			newarr[i] = array[i];
		}
		delete[]array;
		array = newarr;
	}
	else 
	{
		std::cout << "You cant delete! Vector is empty" << std::endl;
	}
}
template<class T>
void VectorT<T>::clear()
{
	delete[] array;
	array = NULL;
	size = 0;
	numbElements = 0;
}
template<class T>
VectorT<T>& VectorT<T>::operator=(const VectorT<T>& vec) 
{
	delete[]array;
	size = vec.size;
	numbElements = vec.numbElements;
	array = new T[size];
	for (int i = 0; i < size; i++) 
	{
		array[i] = vec.array[i];
	}

	return *this;
}
template<class T>
T& VectorT<T>::operator[](int index) 
{
	if (index < 0 || (index >= size)) index = 0;      // контроль за выходом из вектора 
	return array[index];
}


int main() 
{

	VectorT<double> vec(3, 1.33);
	vec.viewVectorT();
	std::cout << std::endl;
	vec.pushBack(2.6);
	vec.viewVectorT();
	std::cout << std::endl;
	vec.popBack();
	vec.viewVectorT();
	std::cout << std::endl;
	
	VectorT<double> vec1(6, 12);
	vec1.viewVectorT();
	std::cout << std::endl;

	vec1 = vec;
	vec1.viewVectorT();
	std::cout << std::endl;

	vec.popBack();
	vec.viewVectorT();	

	return 0;
}
