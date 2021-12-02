#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INFINITE 10000000


void printArray (int * array, int size) {
    printf("[");
    for (int i = 0; i < (size-1); i++) {
        printf("%d, ", (*(array+i)));
    }
    printf("%d]\n", (*(array+size-1)));
}

int * sort(int * v, int size) {

    //Search for the greatest element k in v
    int k = -INFINITE;
    for (int i = 0; i < size; i++) {
        if ((*(v+i)) > k) {
            k = *(v+i) ;
        }
    }

    //Create a new vector w and initialize all values at 0
    int * w = malloc((k+1)*sizeof(int)) ;
    for (int i = 0; i < (k+1); i++) {
        (*(w+i)) = 0;
    }

    //Iterate and update the vector w
    for (int i = 0; i < size; i++) {
        (*(w + (*(v+i))))++ ;
    }

    printArray(w, k+1);

    //Write out vector v
    int i = 0;
    for (int j = 0; j < k+1; j++) {
        if ((*(w+j)) != 0) {
            for (int t = 0; t < (*(w+j)); t++) {
                (*(v+i)) = j;
                i++;
            }
        }
    }
}


int main() {

    int size = 10;
    int * v = malloc(size*sizeof(int));

    for (int i = 0; i < size; i++) {
        (*(v + i)) = rand()%20;
    }

    printf("Array before sort\n") ;
    printArray(v, size) ;

    sort(v, size) ;

    printf("Array after sort\n") ;
    printArray(v, size );


    return 1;
}