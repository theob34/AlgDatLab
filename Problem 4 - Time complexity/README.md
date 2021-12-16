### Problem 4 - Time complexity

## 4.1

# Pseudo-code algorithm
function calculateComplexity(n) {
    // Variables
    int complexity = 0
    int n

    //If n = 1, then T(1) = 1
    if (n = 1) {
        complexity = 1
    }
    //Else, we use the recursive expression to calculate T(n)
    else {
        complexity = calculateComplexity(n - 1) + calculateComplexity(ceil(n/2)) + n
    }

    return complexity
}

## 4.2