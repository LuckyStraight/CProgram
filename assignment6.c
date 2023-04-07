#include <stdio.h>

int main() 
{
    int num, count = 0, sum = 0;
    int lowest, highest;

    // loop until the user enters a number less than or equal to zero
    while (1) 
    {
        printf("Enter a positive number (or 0 to stop): ");
        scanf("%d", &num);

        // exit the loop if the user entered a number less than or equal to zero
        if (num <= 0) 
        {
            break;
        }

        // update the lowest and highest numbers
        if (count == 0) 
        {
            // first number entered
            lowest = highest = num;
        } 
        else 
        {
            if (num < lowest) 
            {
                lowest = num;
            }
            if (num > highest) 
            {
                highest = num;
            }
        }

        // increment the count and add the number to the sum
        count++;
        sum += num;
    }

    // calculate the average of the numbers
    float average = (float)sum / count;

    // display the results
    printf("The lowest number was: %d\n", lowest);
    printf("The highest number was: %d\n", highest);
    printf("The number of values entered was: %d\n", count);
    printf("The average of the numbers was: %.2f\n", average);

    return 0;
}
