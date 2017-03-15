#include <iostream>
#include <cassert> //std::assert()
#include <iterator>

using namespace std;
using param_type = int; //typedef int param_type


int linear_search_interactive(param_type* first, param_type* last, param_type key);
int linear_search_recursive(param_type* first, param_type* last, param_type key);

int binary_search_interactive(param_type* first, param_type* last, param_type key);
int binary_search_recursive(param_type* first, param_type* last, param_type key);

int ternary_search_interactive(param_type* first, param_type* last, param_type key);
int ternary_search_recursive(param_type* first, param_type* last, param_type key);



int main() {

	int A[] = {1 ,5 ,10, 15, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
	int size_a = sizeof(A)/sizeof(int);
		
		auto result = binary_search_recursive(begin(A), end(A), 0);
		cout << 0 << " >>> " << result <<  endl;
		assert(result == -1);
	
	for (auto i(0); i < size_a; i++) {
		result = ternary_search_recursive(begin(A), end(A), A[i]);
		cout << result << " >>> " << A[i] << " >>> " << &A[i] << endl;
		assert(result == i);
	}	

		result = ternary_search_recursive(begin(A), end(A), 110);
		cout << 110 << " >>> "<< result <<  endl;
		assert(result == -1);


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


int linear_search_interactive(param_type* first, param_type* last, param_type key) {

	auto aux(first);
	for (; first != last ; ++first) {
		
		if (*first == key) {
		
			return (first-aux);
		
		}

	}

	return -1;
}

int linear_search_recursive(param_type* first, param_type* last, param_type key) {

	if ( first == last ) {
		
		return -1;

	} else {	

		if (*first == key) {
		
			return *first;

		} else {

			++first;
			linear_search_recursive(first, last, key);

		} 
	}

	return -1;
}

int binary_search_interactive(param_type* first, param_type* last, param_type key) {

	auto aux(first);

	if (key < *first || key > *(last-1)) {

		return -1;

	}
	
	auto size_a(last - first);

	while (first < last) {


		if ( key < *(first + (size_a/2)) ) {

			last = first + size_a/2;
		
		} else if ( key > *(first + (size_a/2)) ) {
		
			first += size_a/2;

		
		} else {
			
			return first + (size_a/2) - aux;
		
		}
		size_a = last - first;
	}
}


int binary_search_recursive(param_type* first, param_type* last, param_type key) {

	if (key < *first or key > *(last-1) or first == last) {

		return -1; 

	} else if ( (last-1) - first == 1 ) {

		if ( *first == key ) {
			return *first;
		} else if (*(first+1) == key) {
			return *(first+1);
		} else {
			return -1;
		}

	} else {	

		auto size_a(last-first);

		if ( key < *( first + (size_a/2) ) ) {
			
			last = first + (size_a/2);
			binary_search_recursive(first, last, key);

		} else if ( key > *( first + (size_a/2) ) ){ 

			first += size_a/2;
			binary_search_recursive(first, last, key);

		} else {

			return *(first + size_a/2);

		} 

	}

	//return -1;
}

int ternary_search_interactive(param_type* V, size_t l, size_t 	r, param_type key) {



} 

int ternary_search_recursive(param_type* first, param_type* last, param_type key) {

	auto size_a(last-first);

	int first_divide = 	size_a/3;
	int second_divide = (size_a/3)*2 - 1;

	if ( first - last > 0 ) {
	
		return -1;
	
	} else {


		if(key == *(first + first_divide)) {

			return first_divide;
			
		} else if(key == *(first + second_divide)) {
			
			return second_divide;
			
		} else if ( key > *first && key < *(first + first_divide) ) {

			ternary_search_recursive(first, first + first_divide, key);

		} else if (key > *(first + first_divide) && key < *( first + second_divide)) {

			ternary_search_recursive(first + first_divide + 1, first + second_divide, key);

		} else if (key > *(first + second_divide) && key < *(last-1)) {

			ternary_search_recursive(first + second_divide + 1, last, key);

		} else {

			return -1;

		}	
	}
}