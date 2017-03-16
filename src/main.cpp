#include <iostream>
#include <iterator>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

#include "../include/algorithms.h"

#define MAX_RANGE 536870912 //2²⁹


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

    //Vector size defined in the top of algorithm
	long int arrSz(MAX_RANGE);
    //Declaration of a vector of a vector, the database was bring the values of media times of executions.
	std::chrono::duration<double, std::milli> database[25][9]; 
	int target, count=0;

    //Declaration of a function pointer to all the eight functions.
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
    auto lower(0), upper(10000); // Range of value
    // Fill it up with random integers.
    randomFill(V, lower, upper, r());
    //Reorganize the vector at not descreasing values.
    std::sort(std::begin(V), std::end(V));

    //Receive a value to search in vector V.
    std::cout << "Número a ser buscado : ";
    std::cin >> target;

    //Execute a 'variable' vector, analyse the values at 0 to (i - 1).
    for ( long int i(16), count = 0; i <= MAX_RANGE; i *= 2, count++) {

        //Switch into functions.
    	for ( auto j(0); j < 8; ++j ) {

            //Declaration at a variable of chrono to save the sum of data time.
    		std::chrono::duration<double, std::milli> sum_data(0);
    		
            //Execute one hundred of times to calculate the media of time at execution.
    		for ( auto k(0); k < 100; k++) {

    			auto start = std::chrono::steady_clock::now();

    		    fun_ptr[j](&V.front(), &V[i], target);

    			auto end = std::chrono::steady_clock::now();

    			auto diff = end - start;

    			sum_data += diff;

    		}

            //Save the media in a vector of a vetor 'database'. 
            database[count][j] = sum_data/100;

    	}

    }

    //Calculates the sum of a media times of executions in differents search algorithms. (ALL)
    for (auto i(0); i < 25; i++) {
        
        std::chrono::duration<double, std::milli> sum_row(0);
        
        for (auto j(0); j < 8; j++) {

            sum_row += database[i][j];

        }

        database[i][8] = sum_row;

    }

   //Show the database of values of executions.
   std::cout << ">> |   ILS    |   RLS    |   SLS    |   IBS    |   RBS    |   SBS    |   ITS    |   RTS    |   ALL    | \n";
   
   for (long int i(16), count=0; i <= MAX_RANGE; i*=2, count++) {
            
            std::cout << i << " | ";

        for (auto j(0); j < 9; ++j) {

             //Set the precision of a double values to show.
             std::cout.precision(6);
             std::cout << std::fixed << std::chrono::duration <double, std::milli> (database[count][j]).count() << " | ";

        }

        std::cout << std::endl;

    }
    
    return 0;

}