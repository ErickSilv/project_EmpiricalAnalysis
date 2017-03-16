#ifndef _ALGORITHMS_
#define _ALGORITHMS_


int seqSearch_it(int* first, int* last, int target);
int seqSearch_rc(int* first, int* last,  int target);
int seqSearch_std(int* first, int* last, int target);

int binarySearch_it(int* first, int* last, int target);
int binarySearch_rc(int* first, int* last, int target);
int binarySearch_std(int* first, int* last, int target);


int ternarySearch_it(int* first, int* last, int target);
int ternarySearch_rc(int* first, int* last, int target);


#endif