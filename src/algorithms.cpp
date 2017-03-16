#include <iostream> // Temporary
#include <algorithm>

#include "../include/algorithms.h"

// List of all possible flags
// | ILS | RLS | SLS | RBS | SBS | ITS | RTS | ALL |

// Iterative Linear Search [ILS]
/*!
 * Busca a primeira ocorrência de um elemento em um arranjo
 * A função realiza a busca de 'd' no intervalo de memória [first, last).
 * // INSERIR AQUI DESCRIÇÃO DO ALGORITMO
 *
 * \param first Primeiro endereço de memória a ser procurado
 * \param last Primeiro endereço de memória APÓS o último endereço a ser procurando
 * \param target Elemento a ser procurando dentro do intervalo
 *
 * return Caso o target seja encontrado no intervalo, retorna o índice. Caso contrário, retorna -1.
 */
int seqSearch_it  ( int* first, int* last, int target ) {

    for ( auto aux(first) ; aux < last ; aux++ ) {
        if ( *aux==target ) {
            return (aux - first); // Calculating the index
        }
    }
    
    return -1;
}

// Recursive Linear Search [RLS]
int seqSearch_rc ( int* first, int* last, int target ) {
    
    // Caso base - não encontrado
    if (first >= last) {
        return -1;
    } 

    // Caso base - encontrado
    if (*first==target) {
        return (first - first);
    } else {
        // Caso recursivo
        int value = seqSearch_rc( first+1 , last , target );

        if (value==-1) { // Retorna -1 sem incrementar
            return value;
        } else { // Incrementa o valor retornado no número de vezes em que ocorre a recursão
            return value+1;
        }
    }

    //{ 10 , 20, 30, 40, 50, 60, 80, 90, 100 }
    // FIRST : 0 1 2 3 4 5 6 7 8
    // LAST  : 9 9 9 9 9 9 9 9 9 
    // RETURN: X X X X X X X X 0
}

// Standard Linear Search [SLS]
int seqSearch_std ( int* first, int* last, int target ) {

    int* pointer = std::find( first , last , target );

    if (pointer == last) {
        return -1;
    } else {
        return (pointer - first);
    }
}

// Iterative Binary Search [IBS]
int binarySearch_it  ( int* first, int* last, int target ) {

    auto auxF(first);
    auto auxL(last);
    int* midPointer;

    while( first <= last ) {

        midPointer = first + (last - first) / 2;

        if (*midPointer == target) {
            int* position = std::lower_bound( auxF , auxL , target );
            return (position - auxF);
        } else if (*midPointer > target) {
            last = midPointer - 1;
        } else if (*midPointer < target) {
            first = midPointer + 1;
        } 
    }

    return -1;
}

// Recursive Binary Search [RBS]
int binarySearch_rc  ( int* first, int* last, int target ) {
    if (first > last) {
        return -1;
    }

    int* midPointer = first + (last - first) / 2;

    if (*midPointer == target) {
        return (midPointer - first);
    } else if (*midPointer > target) {
        return binarySearch_rc( first , midPointer - 1 , target );
    } else if (*midPointer < target) {
        return binarySearch_rc( midPointer + 1 , last , target );
    }
}

// Standard Binary Search [SBS]
int binarySearch_std ( int* first, int* last, int target ) {

    bool isThere = std::binary_search( first , last , target );
    if (isThere) {
        int* position = std::lower_bound( first , last , target );
        return (position - first);
    } else {
        return -1;
    }

}

//
int ternarySearch_it( int* first, int* last, int target ) {
    int index = ternarySearch_rc( first , last , target );
    if (index!=-1) {
        int* position = std::lower_bound( first , last , target );
        return (position - first);
    } else {
        return -1;
    }
}

// Recursive Ternary Search [RTS]
int ternarySearch_rc( int* first, int* last, int target ) {

    if (first > last) {
        return -1;
    }

    int* t1 = first + (last - first) / 2;
    int* t2 = first + ((last - first)/3)*2;

    if (*t1 == target) {
        return t1 - first;
    } else if (*t2 == target) {
        return t2 - first;
    } else if ( target < *t1 ) {
        return ternarySearch_rc( first , t1 - 1 , target );
    } else if ( target < *t2 ) {
        int value = ternarySearch_rc( t1 + 1 , t2 - 1 , target );
        if (value != -1) {
            return value + ( (t1 + 1) - first ); 
        } else {
            return -1;
        }
    } else if ( target > *t2 ) {
        int value = ternarySearch_rc( t2 + 1 , last , target );
        if (value != -1) {
            return value + ( (t2 + 1) - first ); 
        } else {
            return -1;
        }
    } 

}