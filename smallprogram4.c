//COP3223C Section 1
//Small Program 4

#include <stdio.h>

void perfectSquare();
void elevator();
void pyramid();
double classAvg(int class);

int main()
{
    perfectSquare(); // call the perfectSquare function to main.
    elevator(); // calls the elevator function to main.
    pyramid(); //calls the pyramid function to main.

    int class = 0;

    while(class <= 0) // starts the loop for input processing.
    {
        if(class <= 0) // allows the user to input class value.
        {
            printf("How many students are in the class: ");
            scanf("%d", &class);

            if(class <= 0) //if the input is 0 or lower then it prints the function then asks class input again.
            {
                printf("Invalid input. Please try again.\n");
            }
        }
    }
    double result = classAvg(class); //reassigning the average value to result held by ClassAvg function.
    printf("The class average on the field trip exam was a %.4lf%%\n", result); //displays the class average up to 4 decimal places.

    return 0;
}

void perfectSquare()
{
   int top, sides, square = 0;

    while(square <= 0) //allows the user to input square value.
    {
        printf("How big would you like the square to be?: ");
        scanf("%d", &square);

        if(square <= 0) // if user input is 0 and lower prints function then asks the value again.
        {
            printf("Invalid Input. Please try again.\n");
        }
    }

    if(square >= 1)
    {

        /* Iterate over each row */
        for(top = 1; top <= square; top++)
        {
            /* Iterate over each column */
            for(sides = 1; sides <= square; sides++)
            {
                if(top == 1 || top == square || sides == 1 ||sides == square) //allows to create a square outline.
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }

            printf("\n");
        }
    }
}

void elevator()
{
    printf("Welcome to the Elevator Ride.\n");

    int ride = 0;// 0 value needed for the while loop to start
    int floor;

    while(ride <= 0) // allows the function to start the loop.
    {
        if(ride <= 0) // allows the user input to start for the floor value.
        {
            printf("Which floor would you like to go to? ");
            scanf("%d", &floor);

/*Nested if statements to for each of the 12 senarios*/
            if(floor == 1)
            {
                printf("Welcome to the first floor.\n");
            }
            else if(floor == 2)
            {
                printf("Welcome to the second floor.\n");
            }
            else if(floor == 3)
            {
                printf("Welcome to the third floor.\n");
            }
            else if(floor == 4)
            {
                printf("Welcome to the fourth floor.\n");
            }
            else if(floor == 5) // Stop the loop onece the user inputs 5.
            {
                printf("Elevator door is now open. Please exit now.\n");
                break;
            }
            else if(floor == 6)
            {
                printf("Welcome to the sixth floor.\n");
            }
            else if(floor == 7)
            {
                printf("Welcome to the seventh floor.\n");
            }
            else if(floor == 8)
            {
                printf("Welcome to the eighth floor.\n");
            }
            else if(floor == 9)
            {
                printf("Welcome to the ninth floor.\n");
            }
            else if(floor == 10)
            {
                printf("Welcome to the tenth floor.\n");               
            }
            else if(floor == 11)
            {
                printf("Welcome to the eleventh floor.\n");
            }
            else if(floor == 12)
            {
                printf("Welcome to the twelfth floor.\n");
            }

            if(floor < 0 || floor > 12) // if the input is less than 0 or greater than 12. Allows user to input a new value that is in range.
            {
                printf("That is not a valid option.\n");
            }
        }
    }

}

void pyramid()
{
    int dashes, length, steps = 0;

    while(steps <= 0) // allows the user to input value for the pyramid.
    {
        printf("How many steps would you like in the pyramid? ");
        scanf("%d", &steps);

        if(steps > 0) // if steps greater than 0 runs the function.
        {
/*This loop allows the dashes to increase, but stops at 5 dashes*/
            for (dashes = 2; dashes <= steps; ++dashes) 
            {
                for (length = 2; length <= dashes; ++length) 
                {
                    printf("-");
                }
                printf("\n");
            }
/*This loop starts at 6 dashes then decreases to 1 dash*/ 
            for (dashes = steps; dashes >= 1; --dashes) 
            {
                for (length = 1; length <= dashes; ++length) 
                {
                    printf("-");
                }
                printf("\n");
            }
        }
        
        else if(steps <= 0) // if the user input is less than or equal to 0 then it's invalid. Gives the user more tries for positive value.
        {
            printf("Invalid Input. Please try again.\n");
        }    
    }

}

double classAvg(int class) //calls the class value that was inputed in main function.
{
    int number = 0;
    double scores;
    double total = 0.0;

    while(number < class) // allows the function to start.
    {
        if(number < class)
        {
            printf("Enter the student's test score: ");
            scanf("%lf", &scores);

            if(scores >= 0 && scores <= 100) //when the inputted score value is between 0 and 100 starts the math function.
            {
                total = total + scores;
                number++; // decides how many times the while loop should ask for score depending on the class value.
            }

            if(scores > 100) // if input is greater than 100 then restarts the loop until correct value is inputted.
            {
                printf("Invalid Student Score. Please try again.\n");
            }

            if(scores < 0) // if input is less than 0 then the loop should restart until the correct value is inputted.
            {
                printf("Invalid Student Score. Please try again.\n");
            }

            
        }
      
    }
    
    double average = total / (double) class; // calculates the average of the classes test scores.

    return average; //returns the average value to the main function.
    
}
