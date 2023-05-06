#include <stdio.h>

int main() 
{
    int num, count = 0; // Declare integer variables to store input and count of input
    double sum = 0, max = 0; // Declare double variables to store sum of input and max input

    while (1) 
    {
        printf("Enter integers (enter -1 to stop): ");
        scanf("%d", &num); // Read input and store in num
        if (num < 0) 
        {
            break; // If input is negative, break out of the loop
        }
        count++; // Increment count for each positive input
        sum += num; // Add input to sum
        if (num > max) 
        {
            max = num; // Update max if the current input is greater than the previous max
        }
    }
    
    printf("%.0lf %0.2lf\n", max, sum / count); // Print max and average with 2 decimal places, followed by a newline
    
    return 0; // Return success
}
