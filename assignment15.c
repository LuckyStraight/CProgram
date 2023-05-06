#include <stdio.h>
#include <stdlib.h>

// Prints the elements of an array
void PrintArray(int* array, int size) {
    for (int j = 0; j < size; ++j) {
        printf("%d ", array[j]);
    }
}

// Returns the first n Fibonacci numbers
// fibonacci(0) = 0, fibonacci(1) = 1, fibonacci(2) = 1
// Ex: n = 5, seq = 0 1 1 2 3
int* Fibonacci(int n) {
    int* seq = (int*) malloc(n * sizeof(int)); // Allocate memory for the sequence
    seq[0] = 0; // The first Fibonacci number is always 0
    if (n > 1) {
        seq[1] = 1; // The second Fibonacci number is always 1
        for (int i = 2; i < n; ++i) { // Calculate the remaining numbers in the sequence
            seq[i] = seq[i-1] + seq[i-2];
        }
    }
    return seq; // Return the sequence
}

// Returns sequence of squares for 1..n (inclusive)
// Ex: sqrn = 3, seq = 1 4 9
int* Squares(int n) {
    int* seq = (int*) malloc(n * sizeof(int)); // Allocate memory for the sequence
    for (int i = 1; i <= n; ++i) { // Calculate the squares
        seq[i-1] = i*i;
    }
    return seq; // Return the sequence
}

// Returns an array that is a copy of array1 followed by
// the elements of array2
int* Concatenate(int* array1, int size1, int* array2, int size2) {
    int* seq = (int*) malloc((size1 + size2) * sizeof(int)); // Allocate memory for the concatenated sequence
    for (int i = 0; i < size1; ++i) { // Copy the elements of array1
        seq[i] = array1[i];
    }
    for (int i = 0; i < size2; ++i) { // Copy the elements of array2
        seq[i+size1] = array2[i];
    }
    return seq; // Return the concatenated sequence
}

int main(void) {
    int fibn; // seq of first fibn Fibonacci numbers
    // Ex: fibn = 5, seq = 0 1 1 2 3
    int sqrn; // number of squares starting with 1
    // Ex: sqrn = 3, seq = 1 4 9
    scanf("%d %d", &fibn, &sqrn); // Read in the values of fibn and sqrn

    int* fibs = Fibonacci(fibn); // Generate the Fibonacci sequence
    PrintArray(fibs, fibn); // Print the Fibonacci sequence
    printf("\n");
    
    int* sqrs = Squares(sqrn); // Generate the squares sequence
    PrintArray(sqrs, sqrn); // Print the squares sequence
    printf("\n");

    int* conc = Concatenate(fibs, fibn, sqrs, sqrn); // Concatenate the two sequences
    PrintArray(conc, fibn + sqrn); // Print the concatenated sequence
    printf("\n");

    // Free dynamically allocated memory
    free(fibs); // Free the memory used by the Fibonacci

    free(sqrs);
    free(conc);

    return 0;
}
