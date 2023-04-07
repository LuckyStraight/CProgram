#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() 
{
    char user_input[MAX_LENGTH + 1];
    int i, j, string_length;

    while (1) 
    {
        // Allow user to enter a string with up to 100 letters
        printf("Enter a string with up to 100 letters (or 'q' to quit): ");
        fgets(user_input, MAX_LENGTH, stdin);

        // Remove newline character from input
        if (user_input[strlen(user_input) - 1] == '\n') 
        {
            user_input[strlen(user_input) - 1] = '\0';
        }

        if (strcmp(user_input, "q") == 0) 
        {
            break;
        }

        // Display the string forward
        printf("Forward: %s\n", user_input);

        // Display the string backward
        string_length = strlen(user_input);
        printf("Backward: ");
        for (i = string_length - 1; i >= 0; i--) 
        {
            printf("%c", user_input[i]);
        }
        printf("\n");

        // Display the string vertically
        printf("Vertical:\n");
        for (i = 0; i < string_length; i++) 
        {
            printf("%c\n", user_input[i]);
        }

        // Display the string as a triangle
        printf("Triangle:\n");
        for (i = 0; i < string_length; i++) 
        {
            for (j = 0; j <= i; j++) 
            {
                printf("%c", user_input[j]);
            }
            printf("\n");
        }

        // Display the number of letters in the string
        printf("Number of letters: %d\n", string_length);
    }

    return 0;
}

