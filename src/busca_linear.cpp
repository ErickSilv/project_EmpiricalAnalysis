#include <iostream>
#include <cassert> //std::assert()

using namespace std;
using param_type = int; //typedef int param_type


int linear_search_interactive(param_type* V, size_t l, size_t r, param_type key);
int linear_search_recursive(param_type* V, size_t l, size_t r, param_type key);

int binary_search_interactive(param_type* V, size_t l, size_t r, param_type key);
int binary_search_recursive(param_type* V, size_t l, size_t r, param_type key);

int ternary_search_interactive(param_type* V, size_t l, size_t r, param_type key);
int ternary_search_recursive(param_type* V, size_t l, size_t r, param_type key);



int main() {

	int A[] = {10, 20, 30, 40, 50, 60, 70, 80};
	int size_a = sizeof(A)/sizeof(int);

	
	for (auto i(0); i < size_a; i++) {
		auto result = linear_search_interactive(A, 0, size_a-1, A[i]);
		cout << result << endl;
		assert(result == i);
	}	


	return 	EXIT_SUCCESS;


}

/*!
 *Busca a primeira ocorrência de um elemento em um arranjo
 * A função realiza a busca de 'd' nos indices [b;c] de 'A'.
 *
 * \param V Vetor ara realização de busca.
 * \param l Indice do vetor que define o inicio do intervao de busca no vetor.
 * \param r Indice do vetor que define o fim do intervalo de busca no vetor
 * \param key Elemento a ser procurado no vetor.
 *
 * return 0 indice de 'key' em 'V', se encontrar, ou -1, caso contrário.
 */


int linear_search_interactive(param_type* V, size_t l, size_t r, param_type key) {

	for (auto i(l); i <= r; ++i) {
		
		if (V[i] == key) {
		
			return i;
		
		}

	}

	return -1;
}

int linear_search_recursive(param_type* V, size_t l, size_t r, param_type key) {

	if ( key == V [ l ] ) {
		return l;
	} else if ( l <= r ) {
		linear_search_recursive(V, l+1, r, key);
	} else {
		return -1;
	}

	//return -1;
}

int binary_search_interactive(param_type* V, size_t l, size_t r, param_type key) {

	if (key < V[l] || key > V[r]) {

		return -1;

	}
	
	while (r > l) {

		if (key < V[ (l+r)/2 ]) {

			r = (l+r)/2 - 1;
		
		} else if (key > V[ (l+r)/2]) {
		
			l = (l+r)/2 + 1;
		
		} else {
		//	std::cout << (l+r)/2 << std::endl;
			return (l+r)/2;
		
		}

	}

	//return -1;
	

}


int binary_search_recursive(param_type* V, size_t l, size_t r, param_type key) {

	if (key < V[l] || key > V[r]){

		return -1; 

	} else if ( r - l == 1 ) {

		if ( V[r] == key ) {
			return r;
		} else {
			return l;
		}

	} else {	

		if (key < V[ (l+r)/2 ]) {
			
			r = (l+r)/2;
			binary_search_recursive(V, l, r-1, key);

		} else if (key > V[ (l+r)/2 ]){ 

			l = (l+r)/2;
			binary_search_recursive(V, l+1, r, key);

		} else {

			return (r/2);

		} 

	}

	//return -1;
}

int ternary_search_interactive(param_type* V, size_t l, size_t r, param_type key) {



} 

int ternary_search_recursive(param_type* V, size_t l, size_t r, param_type key) {

	int first_divide = (l+r)/3;
	int second_divide = ((l+r)/3)*2;

	if ( r < l ) {

		return -1;

	} else if ( r - l == 1 or r == l) {

		if ( V[r] == key ) {
			return r;
		} else if ( V[l] == key ){
			return l;
		} else {
			return -1;
		}

	} else if ( r - l == 2 ) {

		if ( V[r] == key ) {
			return r;
		} else if ( V[r+1] == key ) {
			return r+1;
		} else if ( V[l]==key ) {
			return l;
		} else {
			return -1;
		}

	} else {

		if (key > V[l] && key < V[first_divide]) {

			ternary_search_recursive(V, l, first_divide-1, key);

		} else if (key > V[first_divide] && key < V[second_divide]) {

			ternary_search_recursive(V, first_divide+1, second_divide-1, key);

		} else if (key > V[second_divide] && key < V[r]) {

			ternary_search_recursive(V, second_divide, r, key);

		} else {


			if(key == V[l]) {

				return l;
			
			} else if(key == V[first_divide]) {
			
				return first_divide;
			
			} else if(key == V[second_divide]) {
			
				return second_divide;
			
			} else if (key == V[r]) {

				return r;

			} else {

				return -1;

			}

		
		}

	}
	//return -1;
}