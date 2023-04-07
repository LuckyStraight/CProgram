#include <stdio.h>

int main()
{
    // Task 1: Create a loop that will output all the multiples of 5 that are greater than zero and less than 60 (do not include 60)
    for (int i = 5; i < 60; i += 5)
    {
        printf("%d\n", i);
    }

    // Task 2: Create a loop that will output all the numbers less than 200 that are evenly divisible by both 2 and 7.
    for (int i = 2; i < 200; i += 2)
    {
        if (i % 7 == 0)
        {
            printf("%d\n", i);
        }
    }

    // Task 3: Create a loop that will calculate the sum of the multiples of 8 that are between 100 and 500. Output the sum only.
    int sum_of_multiples = 0;
    for (int i = 100; i < 500; i += 8)
    {
        sum_of_multiples += i;
    }
    printf("Sum of multiples of 8 between 100 and 500: %d\n", sum_of_multiples);

    // Task 4: Create a loop that will output the sum of all odd numbers between 20 and 100.
    int sum_of_odd_numbers = 0;
    for (int i = 21; i < 100; i += 2)
    {
        sum_of_odd_numbers += i;
    }
    printf("Sum of all odd numbers between 20 and 100: %d\n", sum_of_odd_numbers);

    return 0;
}
