/*
 * shellsort.hpp
 *
 *  Created on: 30 de ago. de 2023
 *      Author: arsrc
 */

#ifndef SHELLSORT_HPP_
#define SHELLSORT_HPP_

#include <vector>

template<typename T>
void shell_sort(std::vector<T> &v) {

	int h = 1;
	int i, j;
	int rep = 0;

	while (h < v.size()) {
		h = h * 3 + 1;
	}

	while (h > 1) {
		h /= 3;

		for (i = h; i < v.size(); i++) {
			T aux = v[i];
			j = i;

			while (j >= h && aux < v[j - h]) {
				v[j] = v[j - h];
				j -= h;
				rep++;
			}

			v[j] = aux;
		}
	}
}



#endif /* SHELLSORT_HPP_ */
