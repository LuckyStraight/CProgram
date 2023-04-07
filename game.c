//Joshua Khooba
// Professor Ting Tang
// COP3223C Section 1
// Arithmetic game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the constants to make code more readable
#define ADD 1
#define MULT 2

//Declare function prototypes
double arithGame(int max, int quantity, int op);
double guessGame(int max);
int numDigits(int number);
int numPoints(double timesec);

//main function
int main()
{
    srand(time(0)); //Seed random number generator with current time
    int choice, max, quantity, op;
    double score = 0, time, total_time = 0;
    int total_questions = 0;

    printf("Welcome to the arithmetic and guessing game program!\n");

    // Show menu until user quits program
    do {
        printf("\nPlease choose one of the following options:\n");
        printf("1. Play Arithmetic Game\n");
        printf("2. Play Guessing Game\n");
        printf("3. Print Score\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch (choice) 
        {
            case 1:
                printf("\nWhich type of arithmetic game would you like to play?\n");
                printf("1. Addition\n");
                printf("2. Multiplication\n");
                scanf("%d", &op);

                printf("\nWhat is the maximum value for the operands?\n");
                scanf("%d", &max);

                printf("\nHow many questions would you like to answer?\n");
                scanf("%d", &quantity);

                time = arithGame(max, quantity, op); // Play arithmetic game
                total_time += time;
                total_questions += quantity;
                score += numPoints(time);
                printf("\nYour score for this round is: %d\n", numPoints(time));
                break;

            case 2:
                printf("\nWhat is the maximum value for the guessing game?\n");
                scanf("%d", &max);

                time = guessGame(max); // Play guessing game
                total_time += time;
                total_questions++;
                score += numPoints(time);
                printf("\nYour score for this round is: %d\n", numPoints(time));
                break;

            case 3:
                if (total_questions > 0) 
                {
                    double avg_time_per_question = total_time / total_questions;
                    printf("\nYour total score is: %.2f\n", score);
                    printf("Average time per question: %.2f seconds\n", avg_time_per_question);
                } 
                else 
                {
                    printf("\nYou have not played any games yet.\n");
                }
                break;

            case 4:
                printf("\nThank You for Playing!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

// This function generates an arithmetic game with randomly generated questions
// and prompts the user to answer them. It returns the average time taken to answer
// each question correctly.
double arithGame(int max, int quantity, int op)
{
    // Variable declarations
    int i, a, b, ans, correct = 0;
    double elapsed_time = 0;

    // Start the timer
    time_t start_time = time(NULL);

    // Loop for the number of questions specified
    for (i = 0; i < quantity; i++) 
    {
        // Generate two random numbers between 1 and max
        a = 1 + rand() % max;
        b = 1 + rand() % max;

        // Print the appropriate question based on the selected operation
        switch (op) 
        {
            case ADD:
                printf("\nQuestion %d: %d + %d = ", i+1, a, b);
                break;
            case MULT:
                printf("\nQuestion %d: %d * %d = ", i+1, a, b);
                break;
            default:
                printf("Invalid operation.\n");
                return 0;
        }

        // Get the user's answer
        if (scanf("%d", &ans) != 1) 
        {
            // Clear input buffer if invalid input is entered
            while (getchar() != '\n');
        }

        // Check if the user's answer is correct and update the correct count and timer
        if ((op == ADD && ans == a + b) || (op == MULT && ans == a * b)) 
        {
            printf("Great job!\n");
            correct++;
        } 
        else 
        {
            printf("Sorry, that's incorrect, the answer is %d\n", (op == ADD ? a + b : a * b));
            elapsed_time += difftime(time(NULL), start_time);
        }
    }

    // Stop the timer and calculate elapsed time
    elapsed_time = difftime(time(NULL), start_time);

    // Print the number of correct answers and elapsed time
    printf("\nYou answered %d out of %d questions correctly in %f seconds.\n", correct, quantity, elapsed_time);

    // If no questions were answered correctly, return 0
    if (correct == 0) 
    {
        return 0;
    } 
    else 
    {
        // Return the average time taken to answer each question correctly
        return elapsed_time / correct;
    }
}

// This function plays a guessing game where the user tries to guess a random number
// between 1 and max, inclusive. It returns the average time per guess.
double guessGame(int max)
{
    int number, guess, num_digits, count = 0;
    double elapsed_time = 0;

    // Generate a random number between 1 and max, inclusive.
    number = 1 + rand() % max;

    // Count the number of digits in the random number.
    num_digits = numDigits(number);

    // Record the start time of the game.
    time_t start_time = time(NULL);

    // Loop until the user guesses the number.
    do {
        // Prompt the user to enter a guess and record the guess.
        printf("\nGuess the number (it has %d digits): ", num_digits);
        scanf("%d", &guess);
        count++;

        // Check if the guess is too low, too high, or correct.
        if (guess < number) 
        {
            printf("Too low. Guess again.\n");
        } 
        else if (guess > number) 
        {
            printf("Too high. Guess again.\n");
        } 
        else 
        {
            // The guess is correct, so congratulate the user and record the elapsed time.
            printf("Congratulations, you guessed the number in %d tries!\n", count);
            elapsed_time += difftime(time(NULL), start_time);
        }
    } while (guess != number);

    // Print the elapsed time and return the average time per guess.
    printf("It took you %.2f seconds to guess the number.\n", elapsed_time);
    return elapsed_time / count;
}

// This function counts the number of digits in a given number.
int numDigits(int number) 
{
    int digits = 0;

    // If the number is 0, it has 1 digit.
    if (number == 0) 
    {
        digits = 1;
    } 
    else 
    {
        // Count the number of digits in the number.
        while (number != 0) 
        {
            digits++;
            number /= 10;
        }
    }

    return digits;
}

// This function calculates the number of points a user earns based on their completion time.
int numPoints(double timesec) 
{
    // If the completion time is less than or equal to 5 seconds, return 10 points.
    if (timesec <= 5) 
    {
        return 10;
    } 
    // If the completion time is less than or equal to 10 seconds, return 8 points.
    else if (timesec <= 10) 
    {
        return 8;
    } 
    // If the completion time is less than or equal to 15 seconds, return 6 points.
    else if (timesec <= 15) 
    {
        return 6;
    } 
    // If the completion time is less than or equal to 20 seconds, return 4 points.
    else if (timesec <= 20) 
    {
        return 4;
    } 
    // If the completion time is less than or equal to 25 seconds, return 2 points.
    else if (timesec <= 25) 
    {
        return 2;
    } 
    // If the completion time is greater than 25 seconds, return 1 point.
    else 
    {
        return 1;
    }
}


