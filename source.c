#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void init_array(Vector* vector){
    vector->size = 0;
    vector->capacity = 1;
    vector->m_array = (int *)calloc(vector->capacity, sizeof(int));
}

//----------------------------------------------------
//unsigned int ceilLog2(Vector* vector) {
//    unsigned int n = (unsigned int) vector->size;
//    unsigned int count = 0;
//    n--;
//    while (n > 0) {
//        n >>= 1;
//        count++;
//    }
//    return count;
//}
//unsigned int next_power_of_two(Vector* vector){
//    return 1u << ceilLog2(vector);
//}
//---------------------------------------------------

void resize(size_t new_size, Vector* vector){
    int* tmp = (int*)malloc((new_size * sizeof(int)));
    if (tmp == NULL){
        printf("Allocation failed");
        exit(1);
    }
    //Copy elements to the new array
    //size_t copy_size = (vector->capacity < new_size) ? vector->capacity : new_size;
    for (int i = 0; i < vector->capacity; ++i) {
        tmp[i] = vector->m_array[i];
    }

    //Free the old array
    free(vector->m_array);

    //Update the vector with new array and size
    vector->m_array = tmp;
    tmp = NULL;
}

void push_back(int val, Vector* vector){
   if (vector->size >= vector->capacity){
       vector->capacity *= 2;
       resize(vector->capacity, vector);
   }

   vector->m_array[vector->size++] = val;
}

void pop_back(Vector* vector){
    if (vector->size <= 0) { printf("Undefined behaviour"); }
    vector->size--;
}

//return functions
int at(Vector* vector, int pos){
    int position = -1;
    for (int i = 0; i < vector->size; ++i){
        if (pos == vector->m_array[i]){
            position = i;
            break;
        }
    }
    if (position == -1) { printf("There is no element with the given position in the vector\n"); }
    return position;
}

int empty(Vector* vector){
    if (vector->size > 0) { return 1;}
    return 0;
}

int front(Vector* vector){
    if (vector->size >= 1)
        return vector->m_array[0];

    return 0;
}

int back(Vector* vector){
    if (vector->size >= 1)
        return vector->m_array[vector->size];
    return 0;
}

int size(Vector* vector){
    return (int) vector->size+1;
}

int capacity(Vector* vector){
    return (int) vector->capacity;
}

void insert(Vector* vector, int pos, int val){

    if (pos < 0 || pos > vector->size){
        printf("Invalid position");
        return;
    }

    // checking new element will fit in capacity if won't multiply capacity by 2
    if (vector->size == vector->capacity) { vector->capacity *= 2;}
    for(int i = (int) vector->size; i > pos; --i){
        vector->m_array[i] = vector->m_array[i-1];
    }

    vector->size++;
    vector->m_array[pos] = val;
}

void erase(Vector* vector, int pos){

    if (pos < 0 || pos >= vector->size){
        printf("Invalid position");
        return;
    }

    for(int i = pos; i < vector->size - 1; ++i){
        vector->m_array[i] = vector->m_array[i+1];
    }
    vector->size--;
}

void shrink_to_fit(Vector* vector) {

    if ( vector->size == vector->capacity) {
        printf("You can't change vector's capacity");
        return;
    }

    vector->capacity = vector->size;
    resize((int) vector->capacity, vector);
}

// destructor
void clear(Vector* vector){
    vector->size = 0;
    vector->capacity = 1;

    if (vector->m_array){
        free(vector->m_array);
        vector->m_array = NULL;
    }
    vector->m_array = (int *)calloc(vector->capacity, sizeof(int));
}

void destruct(Vector* vector) { clear(vector); }

