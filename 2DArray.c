#include <stdio.h>

#define NUM_STUDENTS 4
#define NUM_QUIZZES 5

int main() 
{
    int scores[NUM_STUDENTS][NUM_QUIZZES];
    int i, j;

    // Populate scores array
    for (i = 0; i < NUM_STUDENTS; i++) 
    {
        printf("Enter scores for student %d:\n", i+1);

        for (j = 0; j < NUM_QUIZZES; j++) 
        {
            printf("Quiz %d: ", j+1);
            scanf("%d", &scores[i][j]);
        }
    }

    // Calculate average score for each student
    for (i = 0; i < NUM_STUDENTS; i++) 
    {
        int sum = 0;
        for (j = 0; j < NUM_QUIZZES; j++) 
        {
            sum += scores[i][j];
        }

        printf("Average score for student %d: %.2f\n", i+1, (float)sum / NUM_QUIZZES);
    }

    // Calculate average score for each quiz
    for (i = 0; i < NUM_QUIZZES; i++) 
    {
        int sum = 0;

        for (j = 0; j < NUM_STUDENTS; j++) 
        {
            sum += scores[j][i];
        }

        printf("Average score for quiz %d: %.2f\n", i+1, (float)sum / NUM_STUDENTS);
    }

    // Calculate average score for all students in all quizzes
    int sum = 0;

    for (i = 0; i < NUM_STUDENTS; i++) 
    {
        for (j = 0; j < NUM_QUIZZES; j++) 
        {
            sum += scores[i][j];
        }
    }
    
    printf("Average score for all students in all quizzes: %.2f\n", (float)sum / (NUM_STUDENTS * NUM_QUIZZES));

    return 0;
}
