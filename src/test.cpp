#include <cassert>
#include <iostream>

#include "algorithms.h"

// Uso da função:
// g++ test.cpp -o test -Wall -std=c++11 -D FUNCTION=nome_da_funcao

int main () {
	#ifndef FUNCTION
		std::cout << "===== ERROR =====" << std::endl;
		std::cout << "Compile a função conforme esperado:" << std::endl;
		std::cout << "g++ test.cpp -o test -Wall -std=c++11 -D FUNCTION=nome_da_funcao" << std::endl;
		std::cout << std::endl;
	#endif

	// Declaração do ponteiro da função
	int (*funcao)(int*, long unsigned int, long unsigned int, int) = FUNCTION;

	// Declaração dos vetores
	// WARNING: vetores em ordem não decrescente
	int V_1[] = { 10 , 20, 30, 40, 50, 60, 80, 90, 100 }; // Diferentes
	int V_2[] = { 10 , 10, 10, 10, 10, 10, 10, 10, 10  }; // Iguais
	int V_3[] = { 10 , 20, 20, 30, 40, 40, 50, 60, 60  }; // Com repetição
	int V_4[] = { -10,  0,  0,  0,  0,  0,  0, 10, 20  }; // Com negativos
	int V_5[] = { 2  ,  3,  5,  7, 11, 13, 17, 19, 23  }; // Números Primos

	// Tamanhos do vetor (deprecated)
	int size = 9;

	// Declaração dos testes
	// 1. Primeira ocorrência do último elemento [ANALISAR VETOR]
	// 2. Elemento maior que o último
    // 3. Elemento menor que o primeiro
	// 4. Primeira ocorrência de elemento central [ANALISAR VETOR]
	// 5. Primeiro elemento
	// 6. Elemento dentro do intervalo, porém fora do vetor [ANALISAR VETOR]

	// Primeiro vetor
	std::cout << funcao(V_1, 0, size, V_1[8]     ) << std::endl;
	assert( funcao(V_1, 0, size, V_1[8]     ) == 8 );
	assert( funcao(V_1, 0, size, V_1[8] + 10) == -1);
	assert( funcao(V_1, 0, size, V_1[0] - 10) == -1);
	assert( funcao(V_1, 0, size, V_1[4]     ) == 4 );
	assert( funcao(V_1, 0, size, V_1[0]     ) == 0 );
	assert( funcao(V_1, 0, size, V_1[4] + 5 ) == -1 );

	// Segundo vetor
	assert( funcao(V_2, 0, size, V_2[8]     ) == 0 );
	assert( funcao(V_2, 0, size, V_2[8] + 10) == -1);
	assert( funcao(V_2, 0, size, V_2[0] - 10) == -1);
	assert( funcao(V_2, 0, size, V_2[4]     ) == 0 );
	assert( funcao(V_2, 0, size, V_2[0]     ) == 0 );
	assert( funcao(V_2, 0, size, V_2[4] + 5 ) == -1 );

	// Terceiro vetor
	assert( funcao(V_3, 0, size, V_3[8]     ) == 8 );
	assert( funcao(V_3, 0, size, V_3[8] + 10) == -1);
	assert( funcao(V_3, 0, size, V_3[0] - 10) == -1);
	assert( funcao(V_3, 0, size, V_3[4]     ) == 4 );
	assert( funcao(V_3, 0, size, V_3[0]     ) == 0 );
	assert( funcao(V_3, 0, size, V_3[4] + 5 ) == -1 );

	// Quarto vetor
	assert( funcao(V_4, 0, size, V_4[8]     ) == 8 );
	assert( funcao(V_4, 0, size, V_4[8] + 10) == -1);
	assert( funcao(V_4, 0, size, V_4[0] - 10) == -1);
	assert( funcao(V_4, 0, size, V_4[4]     ) == 1 );
	assert( funcao(V_4, 0, size, V_4[0]     ) == 0 );
	assert( funcao(V_4, 0, size, V_4[4] + 5 ) == -1 );

	// Cinco vetor
	assert( funcao(V_5, 0, size, V_5[8]     ) == 8 );
	assert( funcao(V_5, 0, size, V_5[8] + 10) == -1);
	assert( funcao(V_5, 0, size, V_5[0] - 10) == -1);
	assert( funcao(V_5, 0, size, V_5[4]     ) == 4 );
	assert( funcao(V_5, 0, size, V_5[0]     ) == 0 );
	assert( funcao(V_5, 0, size, V_5[4] + 1 ) == -1 );

	std::cout << std::endl;
	std::cout << ">>>>>> A função funcionou corretamente. =D" << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}