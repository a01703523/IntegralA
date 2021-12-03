#ifndef SORTS_H
#define SORTS_H 

#include <iostream>
#include <vector>
#include <list>
#include "peliculas.h"

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
public:
	void insertionSort(std::vector<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}  

template <class T>
void Sorts<T>::insertionSort(std::vector<T> &v) {
	for(int i=1; i < v.size(); i++){
		for(int j=i; j>0 && v[j].getDuration() < v[j-1].getDuration(); j--){
			swap(v, j, j-1);
		}
	}
}

#endif