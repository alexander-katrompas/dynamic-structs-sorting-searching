/*
 * the supporting demo functions
 */

#include "functions.h"

void swap(int *n1, int *n2) {
    // swaps two integers
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int rand_between(int n1, int n2) {
    // Generates a random number between n1 and n2, order does not matter
    int n = 0;

    if (n1 > n2) {
        swap(&n1, &n2);
    }

    if (n1 >= 0 && n2 >= 0 && n1 != n2) {
        n = (rand() % (n2 - n1)) + n1;
    }

    return n;
}

void swap(Data **d1, Data **d2) {
    // this swaps pointers to structs
    Data *temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

void sort(Data **a, const int size) {
    // bubble sort for pointers to structs
    int i, j;
    Data *temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (a[j]->id > a[j + 1]->id) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                // you can use this function instead of the 3 previous lines
                //swap(&a[j], &a[j + 1]);
            }
        }
    }

}

int search(Data **haystack, int needle, const int size){
    // linear search
    int found = -1;
    for (int i = 0; i < size && found == -1; i++) {
        if(haystack[i]->id == needle){
            found = i;
        }
    }
    return found;
}