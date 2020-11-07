/*
 * The header file for the supporting demo functions
 */

#ifndef DEMO_FUNCTIONS_H
#define DEMO_FUNCTIONS_H

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;

void swap(int*, int*);
void swap(Data*, Data*);
int rand_between(int, int);
void sort(Data**, const int);
int search(Data**, int, const int);


#endif /* DEMO_FUNCTIONS_H */
