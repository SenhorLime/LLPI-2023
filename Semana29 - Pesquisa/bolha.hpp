#ifndef _BOLHA_HPP_
#define _BOLHA_HPP_

template<typename T>
void Bolha(T* v, int n){
	int i, j;
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

#endif //_BOLHA_HPP_
