#ifndef INSERTION_HPP_
#define INSERTION_HPP_

#include <vector>

template<typename T>
void insertionSort(std::vector<T> &v) {
	int i, j;
	int n = v.size();
	T aux;
	for (i = 1; i < n; i++) {
		aux = v[i];
		j = i - 1;
		while (j >= 0 && aux.montadora < v[j].montadora) {
			v[j + 1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
}

#endif
