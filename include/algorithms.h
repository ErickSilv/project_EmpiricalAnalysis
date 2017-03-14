#ifndef _ALGORITHMS_
#define _ALGORITHMS_

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


#endif