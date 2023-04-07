#include <stdio.h>

// function declaration for the grades function
void grades();

int main(void)
{
    int a = 5, b = 4, c = 3, d = 2;

    // if statement to check if (a <= b + 1) is true
    if ( a <= b + 1 ) 
    {
        printf("(a <= b + 1) is True\n");
    } 
    else 
    {
        printf("(a <= b + 1) is False\n");
    }

    // if statement to check if (a < b && c > b) is true
    if ( a < b && c > b ) 
    {
        printf("(a < b && c > b) is True\n");
    } 
    else 
    {
        printf("(a < b && c > b) is False\n");
    }

    // if statement to check if (a >= c || d >= 5) is true
    if ( a >= c || d >= 5 ) 
    {
        printf("(a >= c || d >= 5) is True\n");
    } 
    else 
    {
        printf("(a >= c || d >= 5) is False\n");
    }

    // if statement to check if (!(a > b)) is true
    if ( !( a > b) ) 
    {
        printf("(!(a > b)) is True\n");
    } 
    else 
    {
        printf("(!(a > b)) is False\n");
    }

    // if statement to check if (b >= a && !(d < b)) is true
    if ( b >= a && !(d < b) ) 
    {
        printf("(b >= a && !(d < b)) is True\n");
    } 
    else 
    {
        printf("(b >= a && !(d < b)) is False\n");
    }

    // call to the grades function
    grades();

    return 0;
}

void grades()
{
    int grade, count = 0, total = 0;

    // prompt for input
    printf("Enter grades (enter -1 to stop):\n");
    scanf("%d", &grade);

    // loop until grade is -1
    while (grade != -1) 
    {
        // if grade is within the valid range
        if (grade >= 0 && grade <= 100) 
        {
            // increment the total number of grades
            total++;

            // if grade is >= 70, increment the count of passing grades
            if (grade >= 70) 
            {
                count++;
            }
        } 
        else 
        {
            // print error message for invalid grades
            printf("That is not a valid grade!\n");
        }
        scanf("%d", &grade);
    }

    // if any grades were entered
    if (total > 0) 
    {
        printf("You entered %d passing grades.\n", count);
        printf("%.1f%% of the valid grades entered are passing grades.\n", (float) count / total * 100);
    } 
    else 
    {
        printf("No grades were entered.\n");
    }
}
