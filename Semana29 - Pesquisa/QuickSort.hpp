#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <vector>

template<typename T>
void quickSort(std::vector<T> &v) {
	quickSort<T>(v, 0, v.size() - 1);
}

template<typename T>
void quickSort(std::vector<T> &X, int IniVet, int FimVet) {
	int i, j;
	T pivo, aux;

	if (IniVet < FimVet) {
		pivo = X[(IniVet + FimVet) / 2];
		i = IniVet;
		j = FimVet;

		while (i <= j) {
			while (X[i] < pivo) {
				i = i + 1;
			}

			while (X[j] > pivo) {
				j = j - 1;
			}

			if (i <= j) {
				aux = X[i];
				X[i] = X[j];
				X[j] = aux;

				i = i + 1;
				j = j -1;
			}
		}

		quickSort(X, IniVet, j);
		quickSort(X, i, FimVet);
	}
}

#endif
