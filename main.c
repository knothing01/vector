#include <stdio.h>
#include "header.h"

int main(){

    //initialize Vector
    Vector vector;
    init_array(&vector);

    //---------------------------------------------------------------------
    //TEST CASES
    //---------------------------------------------------------------------

    //PUSH_BACK
     push_back(98, &vector);
     push_back(2, &vector);
     push_back(3, &vector);
     push_back(56, &vector);
     push_back(2005, &vector);
     push_back(38, &vector);
     push_back(238, &vector);
     push_back(268, &vector);
     push_back(25238, &vector);

    for(int i = 0; i < vector.size; ++i){
        printf("%d - %d \n", i+1, vector.m_array[i]);
    }

    printf("Capacity - %zu\n", vector.capacity);
    printf("Size - %zu\n", vector.size);

    //POP_BACK
//    pop_back(&vector);
//    printf("--------------------------\n");
//    printf("New array - after deleting element");
//
//    for (int i = 0; i < vector.size; ++i){
//        printf("%d - %d \n", i+1, vector.m_array[i]);
//    }

    printf("Size - %zu\n", vector.size);
    printf("Capacity - %zu\n", vector.capacity);

    //---------------------------------------------------------------------
    //SOME SIMPLE FUNCTIONS OF VECTOR
    //---------------------------------------------------------------------
    printf("%d\n", at(&vector, 38));
    printf("%d\n", empty(&vector));
    printf("%d\n", front(&vector));
    printf("%d\n", back(&vector));
    printf("%d\n", size(&vector));
    printf("%d\n", capacity(&vector));
    printf("--------------------------\n");
    insert(&vector, 3, 46356356);
    erase(&vector, 0);
    printf("New array - after inserting element\n");

    for (int i = 0; i < vector.size; ++i){
        printf("%d - %d \n", i, vector.m_array[i]);
    }

    printf("%zu\n", vector.size);
    printf("%zu\n", vector.capacity);

    //shrink_to_fit testing
    shrink_to_fit(&vector);
    printf("%zu\n", vector.size);
    printf("%zu\n", vector.capacity);

    push_back(345, &vector);

    printf("-------------------\n");
    printf("%zu\n", vector.size);
    printf("%zu\n", vector.capacity);

    printf("-------------------\n");
    shrink_to_fit(&vector);
    printf("%zu\n", vector.size);
    printf("%zu\n", vector.capacity);

    // push_back, have to resize capacity (after shrink_to_fit) with the number that is power of two;
    push_back(345, &vector);
    printf("-------------------\n");
    printf("%zu\n", vector.size);
    printf("%zu\n", vector.capacity);

    //freeing memory
    destruct(&vector);
    return 0;
}

