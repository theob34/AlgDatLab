###Problem 1 - Sorting

##Pseudo-code solution
//v is the vector to be sorted
//Search for the greatest element k in v
k = -INFINITE
for all element in v
    if element > k
        k = element

//Create a new vector w and initialize all values at 0
w[k+1] = 0 for all element

//Iterate and update the vector w
for i between 0 and size of v
    w[v[i]]++

//Write out vector v
i = 0
for j between 0 and size of w
    if (w[j] != 0)
        for t between 0 and w[j]
            v[i] = j
            i++