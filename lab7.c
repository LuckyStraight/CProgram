#include <stdio.h>

void reverse();

int main() 
{
    int lst[9]; // assuming maximum length of list is 9
    int num, i, middle_index;

    for (i = 0; i < 9; i++) 
    { // read input into array
        printf("Enter integers(Enter -1 to stop input: ");
        scanf("%d", &num);
        if (num < 0) break; // exit loop if negative number is entered
        lst[i] = num; // add number to array
    }

    if (i > 9) 
    { // check if too many numbers
        printf("Too many numbers\n");
    } 
    else 
    {
        middle_index = i / 2; // find middle index
        printf("Middle item: %d\n", lst[middle_index]); // output middle item
    }

    reverse(); // call function to reverse input integers

    return 0;
}

void reverse()
{
    int n, lst[20], i;

    printf("Enter integers: ");
    scanf("%d", &n); // read number of integers
    
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &lst[i]); // read integers into array
    }

    for (i = n - 1; i >= 0; i--) 
    {
        printf("%d,", lst[i]); // output integers in reverse
    }

}
