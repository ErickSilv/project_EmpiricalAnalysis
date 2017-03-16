#include <iostream>
#include <iterator>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

#include "../include/algorithms.h"

#define MAX_RANGE 18384 //2²⁹


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

	auto arrSz(536870912ul);
	std::chrono::duration<double, std::milli> database[25][8]; 
	int target, count;


	//int *(*func_ptr) (int* first, int* last, int target);
	ptr *fun_ptr[8] = { seqSearch_it, 
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
    auto lower(0), upper(MAX_RANGE); // Range of value
    // Fill it up with random integers.
    randomFill(V, lower, upper, r());

    std::sort(std::begin(V), std::end(V));

    std::cout << "Número a ser buscado : ";
    std::cin >> target;


    for ( auto i(64), count = 0; i <= 4096; i *= 4, count++) {

    	for ( auto j(0); j < 8; ++j ) {

    		std::chrono::duration<double, std::milli> sum_data(0);
    		
    		for ( auto k(0); k < 100; k++) {

    			auto start = std::chrono::steady_clock::now();

    		    fun_ptr[j](&V.front(), &V[i], target);

    			auto end = std::chrono::steady_clock::now();

    			auto diff = end - start;

    			sum_data += diff;

    		}

            database[count][j] = sum_data/100;

    	}

    }


   std::cout.precision(6);
   std::cout << ">>> | ILS | RLS | SLS | RBS | SBS | ITS | RTS | ALL | \n";
   
   for (auto i(64), count=0; i < MAX_RANGE; i*=4, count++) {
        
        std::cout << i << " | ";

        for (auto j(0); j < 8; ++j) {

             std::cout << std::fixed << std::chrono::duration <double, std::milli> (database[count][j]).count() << " | ";

        }

        std::cout << std::endl;

    }
    

    return 0;




}