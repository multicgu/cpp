#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<cassert>

template <class T>
class array {
	private:
		T * list;
		int size;
	public:
		array(int sz=50);
		array(array<T> & arr);
		~array();
		int getsize();
		void resize(int sz);
		array<T> & operator =(T & arr);
		T & operator [](int n);
		//const T & operator [](int n) const;
		operator T * ();
		//operator const T * () const;
};
template <class T>
array<T>::array(int sz) {
	size = sz;
	list = new T[size];
}
template <class T>
array<T>::array(array<T> & arr) {
	size = arr.size;
	list = new T[size];
	for(int i=0;i<size;i++)
		list[i] = arr.list[i];
}
template <class T>
array<T>::~array() {
	delete [] list;
}
template <class T>
array<T> & array<T>::operator = (T & arr) {
	if(&arr != this) {
		if(size!=arr.size) {
			delete [] list;
			size = arr.size;
			list = new T[size];
		}
		for(int i = 0; i < size; i++)
			list[i] = arr.list[i];
	}
}
template <class T>
T & array<T>::operator [] (int n) {
	assert(n>=0 && n<size);
	return list[n];
}
template <class T>
array<T>::operator T * () {
	return list;
}
template <class T>
int array<T>::getsize() {
	return size;
}
template <class T>
void array<T>::resize(int sz) {
	if(sz==size) return;
	int n = (size>sz)?sz:size;
	T * templist = new T[n];
	for(int i=0;i<n;i++)
		templist[i] = list[i];
	delete [] list;
	list = templist;
	size=n;
}
#endif
