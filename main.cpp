/*
 * The driver function to demonstrate various operations with pointers
 * and passing and returning data by reference
 */

#include "main.h"

int main() {
    srand(time(NULL));
    
    // this is a static allocation of an array of pointers to struct Data
    Data *array1[SIZE];

    /* 
     * this is a dynamic allocation of an array of pointers to struct Data
     * you can use it just like array1, just replace all the "array1" below
     * with "array2" and uncomment the last line that deallocates array2
     */
    Data **array2;
    array2 = new Data*[SIZE];

    // fill array1 with pointers to dynamically allocated struct Data
    for(int i = 0; i<SIZE; i++){
        // this creates a struct data and puts the pointer to it in the array
        array1[i] = new Data;
        array1[i]->id = rand_between(MIN,MAX);
        array1[i]->information = "info " + std::to_string(i+1);
    }
    
    // prove it
    for(int i = 0; i<SIZE; i++){
        cout << "[" << i << "] " << "id: " << array1[i]->id << " with \"" << array1[i]->information << "\"" << endl;;
    }
    cout << endl;

    // sort the array
    sort(array1, SIZE);
    
    // prove it
    for(int i = 0; i<SIZE; i++){
        cout << "[" << i << "] " << "id: " << array1[i]->id << " with \"" << array1[i]->information << "\"" << endl;
    }
    cout << endl;
   
    // randomly look for ids
    int found;
    int findit;
    for(int i = 0; i<SIZE; i++){
        findit = rand_between(MIN,MAX);
        found = search(array1, findit, SIZE);
        if(found != -1){
            cout << "found " << findit << " at location " << found << endl;
        } else {
            cout << "did not find " << findit << endl;
        }
        found = -1;
    }
    cout << endl;
    
    // delete the allocated memory
    for(int i = 0; i<SIZE; i++){
        delete array1[i];
    }
    
    // this deletes array2.
    // array1 does not need to be deleted because it is static
    delete [] array2;
    
    return 0;
}
