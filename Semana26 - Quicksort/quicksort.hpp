/*
 * quicksort.hpp
 *
 *  Created on: 30 de ago. de 2023
 *      Author: arsrc
 */

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <vector>

//Chamado do main.
template<typename T>
void quicksort(std::vector<T> &v) {
	quicksort<T>(v, 0, v.size() - 1);
}

//Chamada interna e chamadas recursivas.
template<typename T>
void quicksort(std::vector<T> &X, int IniVet, int FimVet) {
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

		quicksort(X, IniVet, j);
		quicksort(X, i, FimVet);
	}
}

#endif  //QUICKSORT_HPP_
