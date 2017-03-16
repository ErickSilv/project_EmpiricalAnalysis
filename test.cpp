#include <iostream>
#include <cassert>
#include <unistd.h>

#include "../include/algorithms.h"
//#include "../include/test.h"

int main( int arg, char* argv[] ) {

	// Declaração dos vetores
	// WARNING: vetores em ordem não decrescente  
	int V_1[] = { 10 , 20, 30, 40, 50, 60, 80, 90, 100 }; // Diferentes
	int V_2[] = { 10 , 10, 10, 10, 10, 10, 10, 10, 10  }; // Iguais
	int V_3[] = { 10 , 20, 20, 30, 40, 40, 50, 60, 60  }; // Com repetição
	int V_4[] = { -10,  0,  0,  0,  0,  0,  0, 10, 20  }; // Com negativos
	int V_5[] = { 2  ,  3,  5,  7, 11, 13, 17, 19, 23  }; // Números Primos

	// Declaração dos testes
	// 1. Primeira ocorrência do último elemento [ANALISAR VETOR]
	// 2. Elemento maior que o último
    // 3. Elemento menor que o primeiro
    // 4. Primeiro elemento
	// 5. Primeira ocorrência de elemento central [ANALISAR VETOR]
	// 6. Elemento dentro do intervalo, porém fora do vetor [ANALISAR VETOR]

    // Declaração do ponteiro da função

	int (*functionVector[])(int*, int*, int) = {
        linearSearch_it  ,
        linearSearch_rc  ,
        linearSearch_std ,
        binarySearch_it  ,
        binarySearch_rc  ,
        binarySearch_std ,
        terciarySearch_it,
        terciarySearch_rc
    } ;

    std::string functionNames[] = {
        "BUSCA LINEAR ITERATIVA"    ,
        "BUSCA LINEAR RECURSIVA"    ,
        "STD::FIND"                 ,
        "BUSCA BINÁRIA ITERATIVA"   ,
        "BUSCA BINÁRIA RECURSIVA"   ,
        "STD::BINARY_SEARCH"        ,
        "BUSCA TERCIÁRIA ITERATIVA" ,
        "BUSCA TERCIÁRIA RECURSIVA"
    };

    for ( auto i(0) ; i < 8 ; i++ ) {
        int (*funcao)(int*, int*, int) = functionVector[i];
        std::cout << ">>>>>> Testando: " << functionNames[i] << std::endl;
        usleep(500000);

        // Primeira ocorrência do último elemento
        assert( funcao( std::begin(V_1) , std::end(V_1) , V_1[8]) == 8);
        assert( funcao( std::begin(V_2) , std::end(V_2) , V_2[8]) == 0);
        assert( funcao( std::begin(V_3) , std::end(V_3) , V_3[8]) == 7);
        assert( funcao( std::begin(V_4) , std::end(V_4) , V_4[8]) == 8);
        assert( funcao( std::begin(V_5) , std::end(V_5) , V_5[8]) == 8);

        // Elemento maior que o último
        assert( funcao( std::begin(V_1) , std::end(V_1) , V_1[8] + 10) == -1);
        assert( funcao( std::begin(V_2) , std::end(V_2) , V_2[8] + 10) == -1);
        assert( funcao( std::begin(V_3) , std::end(V_3) , V_3[8] + 10) == -1);
        assert( funcao( std::begin(V_4) , std::end(V_4) , V_4[8] + 10) == -1);
        assert( funcao( std::begin(V_5) , std::end(V_5) , V_5[8] + 10) == -1);

        // Elemento menos que o primeiro
        assert( funcao( std::begin(V_1) , std::end(V_1) , V_1[0] - 10) == -1);
        assert( funcao( std::begin(V_2) , std::end(V_2) , V_2[0] - 10) == -1);
        assert( funcao( std::begin(V_3) , std::end(V_3) , V_3[0] - 10) == -1);
        assert( funcao( std::begin(V_4) , std::end(V_4) , V_4[0] - 10) == -1);
        assert( funcao( std::begin(V_5) , std::end(V_5) , V_5[0] - 10) == -1);

        // Primeiro elemento
        assert( funcao( std::begin(V_1) , std::end(V_1) , V_1[0]) == 0);
        assert( funcao( std::begin(V_2) , std::end(V_2) , V_2[0]) == 0);
        assert( funcao( std::begin(V_3) , std::end(V_3) , V_3[0]) == 0);
        assert( funcao( std::begin(V_4) , std::end(V_4) , V_4[0]) == 0);
        assert( funcao( std::begin(V_5) , std::end(V_5) , V_5[0]) == 0);

        // Primeira ocorrência do elemento central
        assert( funcao( std::begin(V_1) , std::end(V_1) , V_1[4]) == 4);
        assert( funcao( std::begin(V_2) , std::end(V_2) , V_2[4]) == 0);
        assert( funcao( std::begin(V_3) , std::end(V_3) , V_3[4]) == 4);
        assert( funcao( std::begin(V_4) , std::end(V_4) , V_4[4]) == 1);
        assert( funcao( std::begin(V_5) , std::end(V_5) , V_5[4]) == 4);

        // Elemento dentro do intervalo, porém fora do vetor
        assert( funcao( std::begin(V_1) , std::end(V_1) , 45 ) == -1);
        assert( funcao( std::begin(V_2) , std::end(V_2) , 15 ) == -1);
        assert( funcao( std::begin(V_3) , std::end(V_3) , 35 ) == -1);
        assert( funcao( std::begin(V_4) , std::end(V_4) , 5  ) == -1);
        assert( funcao( std::begin(V_5) , std::end(V_5) , 6  ) == -1);

        std::cout << ">>> A função funcionou corretamente. =D" << std::endl;
        std::cout << std::endl;
        usleep(500000);

    }

	return EXIT_SUCCESS;
}