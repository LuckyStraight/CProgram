#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 10

void wordFreq();

int main() 
{
    int n, threshold, i;

    printf("Input a list of integers. (input 100 to exit.): ");
    scanf("%d", &n);  // Get the number of integers

    int num_list[n];  // Create an array of size n

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &num_list[i]);  // Get the integers
    }

    scanf("%d", &threshold);  // Get the threshold value

    for (i = 0; i < n; i++) 
    {
        if (num_list[i] <= threshold) 
        {
            printf("%d, ", num_list[i]);  // Print integers that are less than or equal to the threshold

        }
    }
    
    printf("\n");

    wordFreq();

    return 0;
}

void wordFreq()
{
   int num_words, i, j, freq;
    char words[MAX_WORDS][MAX_WORD_LEN+1];
    int frequencies[MAX_WORDS];
    int counted[MAX_WORDS] = {0};

    // Read number of words
    printf("input a list of words: ");
    scanf("%d", &num_words);

    // Read words and initialize frequencies and counted to zero
    for (i = 0; i < num_words; i++) 
    {
        scanf("%s", words[i]);
        frequencies[i] = 0;
        counted[i] = 0;
    }

    // Calculate frequencies
    for (i = 0; i < num_words; i++) 
    {
        freq = 1;
        for (j = i+1; j < num_words; j++) 
        {
            if (strcmp(words[i], words[j]) == 0) 
            {
                freq++;
                // Mark subsequent occurrences as counted
                counted[j] = 1;
            }
        }

        if (!counted[i]) 
        {
            frequencies[i] = freq;
        }
    }

    // Output results
    for (i = 0; i < num_words; i++) 
    {
        if (frequencies[i] != 0) 
        {
            printf("%s - %d\n", words[i], frequencies[i]);
        }
    }


}
