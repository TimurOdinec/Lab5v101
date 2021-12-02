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
	T* arr;
	int size;
	int capacity;

public:
	VectorT();									//конструктор
	VectorT(int capacity);
	VectorT(int capacity, const T& initial);
	VectorT(const VectorT<T>& vec);
	~VectorT();
	void reserve(int capacity);
	bool is_empty();
	int my_size();
	int my_capacity();
	T* begin();
	T* end();
	void push_back(const T& value);
	void pop_back();
	void clear();
	VectorT<T>& operator=(const VectorT<T>& vec);
	T& operator[](int index);
};
template<class T>
VectorT<T>::VectorT() {
	arr = NULL;
	size = 0;
	capacity = 0;
}
template<class T>
VectorT<T>::VectorT(int capacity) {
	size = 0;
	this->capacity = capacity;
	arr = new T[capacity];
}
template<class T>
VectorT<T>::VectorT(int capacity, const T& initial) {
	this->capacity = capacity;
	size = capacity;
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = initial;
	}
}
template<class T>
VectorT<T>::VectorT(const VectorT& vec) {
	size = vec.size;
	capacity = vec.capacity;
	arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = vec.arr[i];
	}
}
template<class T>
VectorT<T>::~VectorT() {
	delete[]arr;
}
template<class T>
void VectorT<T>::reserve(int capacity) {
	this->capacity = this->capacity + capacity;
	T* newarr = new T[this->capacity];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	delete[]arr;
	arr = newarr;
}
template<class T>
bool VectorT<T>::is_empty() {
	if (arr == NULL)
		return true;
	return false;
}
template<class T>
int VectorT<T>::my_size() {
	return size;
}
template<class T>
int VectorT<T>::my_capacity() {
	return capacity;
}
template<class T>
T* VectorT<T>::begin() {
	return arr;
}
template<class T>
T* VectorT<T>::end() {
	return arr + my_capacity();
}
template<class T>
void VectorT<T>::push_back(const T& value) {

	if (size == capacity) {
		reserve(5);
	}
	arr[size++] = value;
}
template<class T>
void VectorT<T>::pop_back() {
	if (size > 0) {
		size--;
		T* newarr = new T[capacity];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		delete[]arr;
		arr = newarr;
	}
	else {
		std::cout << "You cant delete! Vector is empty" << std::endl;
	}
}
template<class T>
void VectorT<T>::clear() {
	delete[] arr;
	arr = NULL;
	size = 0;
	capacity = 0;
}
template<class T>
VectorT<T>& VectorT<T>::operator=(const VectorT<T>& vec) {
	delete[]arr;
	size = vec.size;
	capacity = vec.capacity;
	arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = vec.arr[i];
	}

	return *this;
}
template<class T>
T& VectorT<T>::operator[](int index) {
	return arr[index];
}






int main() {

	VectorT<double> vec(10, 1);

	VectorT<double> vec1(15, 12);
	vec1 = vec;
	vec.pop_back();
	for (int i = 0; i < vec1.my_size(); i++) {
		std::cout << vec1[i] << " ";
	}

	return 0;
}
