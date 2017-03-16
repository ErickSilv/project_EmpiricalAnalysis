#include <iostream>
#include <iterator>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

#include "../include/algorithms.h"

#define MAX_RANGE 536870912


typedef int ptr(int*, int*, int);

void randomFill( std::vector<int> &V, const int lower, const int upper,
                 const unsigned int seed) {

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V ){
        elem = distr(eng);
    }

}


int main () {

	auto arrSz(32ul);
	double data, sum_data;
	int target;

	//int *(*func_ptr) (int* first, int* last, int target);
	ptr *func_ptr[8] = {seqSearch_it, 
					  	seqSearch_rc,
					    seqSearch_std, 
					  	binarySearch_it, 
					  	binarySearch_rc, 
					    binarySearch_std, 
					    ternarySearch_it, 
					    ternarySearch_rc };


	//V stores the data
	std::vector< int > V( arrSz );
	// Seed with a real random value, if available.
    std::random_device r;
    // Range of possible random values. This might become a user input as well.
    auto lower(0), upper(31); // Range of value
    // Fill it up with random integers.
    randomFill(V, lower, upper, r());

    std::sort(V.begin(), V.end());


    std::cout << "Número a ser buscado : " << std::endl;
    std::cin >> target;


    for ( auto i(32); i < MAX_RANGE; i *= 4 ) {

    	for ( auto j(0); j < 8; ++j ) {

    		sum_data = 0;
    		
    		for ( auto k(0); k < 100; k++) {

    			fun_ptr[j](V.begin(), V.begin()+i, target);

    		}


    	}

    }


    return 0;




}