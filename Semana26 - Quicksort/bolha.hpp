/*
 * bolha.hpp
 *
 *  Created on: 30 de ago. de 2023
 *      Author: arsrc
 */

#ifndef BOLHA_HPP_
#define BOLHA_HPP_

#include <vector>

template<typename T>
void bolha(std::vector<T> &v) {
	int i, j;
	int n = v.size();
	T aux;
	for (i = 0; i < n - 1; i++) {
		for (j = 1; j < n - i; j++) {
			if (v[j] < v[j - 1]) {
				aux = v[j];
				v[j] = v[j - 1];
				v[j - 1] = aux;
			}
		}
	}
}

#endif  //BOLHA_HPP_
