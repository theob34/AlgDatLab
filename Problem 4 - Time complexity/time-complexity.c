#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SIZE 15
#define VALUE 1200

double divideAndCeil (int n) {
    //if the number is even, then no need to ceil
    if (n%2 == 0) {
        return (double)(n/2);
    }
    //if the number is odd, then we need to ceil with adding 1 after an euclidean division
    else {
        return (double)(n/2 + 1);
    }
}

void testDivideAndCeil() {
    for (int i = 0; i < 10; i++) {
        printf("i = %i and ceil(%i/2) = %f\n", i, i, divideAndCeil(i));
    }
}

double calculateComplexity(int n) {
    // Variables
    double complexity;

    //If n = 1, then T(1) = 1
    if (n == 1) {
        complexity = 1 ;
    }
    //Else, we use the recursive expression to calculate T(n)
    else {
        complexity = calculateComplexity(n - 1) + calculateComplexity(divideAndCeil(n)) + n ;
    }
    return complexity ;
}

void calculateComplexityDynamicly(double * complexity, int n) {
    //If the value is not yet in our array, we calculate it
    if(complexity[n] <= 0.5) {
        //If n = 1, then T(1) = 1   
        if (n == 1) {
            complexity[n] = 1.0 ;
        }
        //Else, we use the recursive expression to calculate T(n)
        else {
            calculateComplexityDynamicly(complexity, n-1);
            calculateComplexityDynamicly(complexity, divideAndCeil(n));
            int nOver2 = divideAndCeil(n);
            complexity[n] = complexity[n-1] + complexity[nOver2] + n;
        }
    }
}

void initializedArray(double * array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0.0 ;
    }
}

int main() {
    
    // -- It calculate values for i between 1 and SIZE but without any link between them -- 
    //Variables and initialization
    double complexity[SIZE] ;
    double complexityDynamic[SIZE+1] ;
    initializedArray(complexityDynamic, SIZE+1);
    //Calculation loop for each value
    for (int i = 1; i <= SIZE; i++) {
        //Version without dynamic programming
        complexity[i] = calculateComplexity(i) ;
        printf("Without dynamic : n = %i : T(n) = %f\n", i, complexity[i]);

        //Version with dynamic programming
        calculateComplexityDynamicly(complexityDynamic, i);
        printf("With dynamic : n = %i : T(n) = %f\n", i, complexityDynamic[i]);
        //Reboot it with 0.0 for each cell
        initializedArray(complexityDynamic, SIZE+1);
    }

    // -- It calculate for the value specify --
    //Variables and initialization
    double complexityDynamicValue[VALUE] ;
    initializedArray(complexityDynamicValue, VALUE+1);
    //Calculation for the value
    calculateComplexityDynamicly(complexityDynamicValue, VALUE);
    printf("With dynamic : n = %i : T(n) = %f\n", VALUE, complexityDynamicValue[VALUE]);
    
}