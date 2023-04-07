/* Name: Joshua Khooba
Program Number: 8
Title: stats
Date:3/21/23
*/

#include <stdio.h>
#include <math.h>

#define NUM_INTERVALS 21 // The number of intervals in the histogram
#define INTERVAL_SIZE 5 // The size of each interval in the histogram

void readGrades(double grades[], int *n); // Reads in grades from the user
void frequency(double grades[], int n); // Computes and prints a histogram of the grades
int maximum(double grades[], int n); // Returns the index of the maximum grade
int minimum(double grades[], int n); // Returns the index of the minimum grade
void deleteElement(double grades[], int *n, int loc); // Deletes an element from an array
double mean(double grades[], int n); // Computes the mean of the grades
double standardDeviation(double grades[], int n); // Computes the standard deviation of the grades

int main()
{
    double grades[100] = {0}; // The array to hold the grades
    int n = 0;

    readGrades(grades, &n);

    int min_loc = minimum(grades, n); // Find the index of the minimum grade
    printf("The data has been adjusted by removing the minimum %.2f.\n", grades[min_loc]); // Print a message indicating that the minimum grade has been removed

    deleteElement(grades, &n, min_loc);

    int max_loc = maximum(grades, n); // Find the index of the maximum grade
    printf("The data has been adjusted by removing the maximum %.2f.\n", grades[max_loc]); // Print a message indicating that the maximum grade has been removed

    deleteElement(grades, &n, max_loc);

    double avg = mean(grades, n); // Compute the mean of the adjusted grades
    double std_dev = standardDeviation(grades, n); // Compute the standard deviation of the adjusted grades

    printf("The adjusted mean is %.2f\n", avg); // Print the adjusted mean
    printf("The adjusted standard deviation is %.2f\n\n", std_dev); // Print the adjusted standard deviation

    frequency(grades, n);

    return 0; 
}

void readGrades(double grades[], int *n)
{
    double grade;

    printf("Enter in grades (-999 to stop the algorithm): "); // Prompt the user to enter grades
    scanf("%lf", &grade); // Read in the first grade

    while (grade != -999 && *n < 100) // Continue reading grades until the user enters -999 or the array is full
    { 
        grades[*n] = grade; // Store the grade in the array

        (*n)++; // Increment the number of grades

        printf("Enter in grades (-999 to stop the algorithm): "); // Prompt the user to enter more grades
        scanf("%lf", &grade);
    }

    printf("\n");
}

void frequency(double grades[], int n)
{
    int freq[NUM_INTERVALS] = {0}; // initialize an array to hold the frequency of grades in each interval

    // Iterate over the grades and update the frequency array
    for (int i = 0; i < n; i++)
    {
        int interval = (int) (grades[i] / INTERVAL_SIZE); // compute the interval that the grade falls into

        if (interval == NUM_INTERVALS - 1) // check if the grade is outside the range of the histogram
        {
            freq[interval]++; // increment the frequency count for the last interval
        }
        else
        {
            freq[interval]++; // increment the frequency count for the interval that the grade falls into
        }
    }

    printf("Here is a histogram of the adjusted data:\n");

    for (int i = 0; i < NUM_INTERVALS - 1; i++) // Iterate over the intervals and print the frequency counts for each interval
    {
        int lower = i * INTERVAL_SIZE;
        int upper = lower + INTERVAL_SIZE - 1;

        printf("%2d-%2d: ", lower, upper); // print the range of grades for the current interval

        for (int j = 0; j < freq[i]; j++) // print the frequency count for the current interval as asterisks
        {
            printf("*");
        }

        printf("\n");
    }

    printf("  %2d: ", 100); // print the last interval separately

    for (int j = 0; j < freq[NUM_INTERVALS - 1]; j++) // print the frequency count for the last interval as asterisks
    {
        printf("*");
    }

    printf("\n");
}

int maximum(double grades[], int n)
{
    int max_loc = 0; // assume the first grade is the maximum

    for (int i = 1; i < n; i++) // Iterate over the grades and find the index of the maximum grade
    {
        if (grades[i] > grades[max_loc])
        {
            max_loc = i;
        }
    }

    return max_loc; // return the index of the maximum grade
}

int minimum(double grades[], int n)
{
    int min_loc = 0; // assume the first grade is the minimum

    for (int i = 1; i < n; i++) // Iterate over the grades and find the index of the minimum grade
    {
        if (grades[i] < grades[min_loc])
        {
            min_loc = i;
        }
    }

    return min_loc; // return the index of the minimum grade
}

void deleteElement(double grades[], int *n, int loc)
{
    for (int i = loc; i < *n - 1; i++) // Shift all the elements after the index to be deleted one position to the left
    {
        grades[i] = grades[i + 1];
    }

    (*n)--; // Decrease the size of the array by one
}

double mean(double grades[], int n)
{
    double sum = 0; // Initialize the sum to zero

    for (int i = 0; i < n; i++) // Iterate over the grades and add them to the sum
    {
        sum += grades[i];
    }

    return sum / n; // Compute and return the mean of the grades
}

double standardDeviation(double grades[], int n) 
{
    double sum = 0.0, mean_value, variance = 0.0;

    // Compute the mean
    mean_value = mean(grades, n);

    // Compute the variance
    for (int i = 0; i < n; ++i) 
    {
        variance += pow(grades[i] - mean_value, 2);
    }

    variance /= n;

    // Compute the standard deviation
    double standardDeviation = sqrt(variance);

    return standardDeviation;
}

