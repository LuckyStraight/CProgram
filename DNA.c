#include <stdio.h>
#include <string.h>

// Function to calculate the DNA matching score between a sample and a candidate
int score_dna_match(char sample[], char candidate[]);

// Function to match a sample DNA string with a set of candidate DNA strings
void dna_matching(char sample[], char candidates[][50], int num_candidates);

int main() 
{
    // Declare variables to hold the sample, candidate DNA strings, and number of candidates
    char sample[50];
    char candidates[100][50];
    int num_candidates;
    
    // Open the input file for reading
    FILE *fp = fopen("input1.txt", "r");
    
    // Read the sample DNA string from the input file
    fgets(sample, 50, fp);
    sample[strcspn(sample, "\n")] = 0;
    
    // Read the number of candidate DNA strings from the input file
    fscanf(fp, "%d", &num_candidates);
    
    // Read the candidate DNA strings from the input file and store them in an array
    for (int i = 0; i < num_candidates; i++) 
    {
        fscanf(fp, "%s", candidates[i]);
    }
    
    // Call the function to match the sample DNA string with the candidate DNA strings
    dna_matching(sample, candidates, num_candidates);
    
    // Close the input file
    fclose(fp);
    
    return 0;
}

// Function to calculate the DNA matching score between a sample and a candidate
int score_dna_match(char sample[], char candidate[]) 
{
    // Initialize the score to zero
    int score = 0;
    
    // Determine the length of the shorter DNA string
    int shorter_len = strlen(sample) < strlen(candidate) ? strlen(sample) : strlen(candidate);

    // Loop through each position in the DNA strings and update the score accordingly
    for (int i = 0; i < shorter_len; i++) 
    {
        if (sample[i] == candidate[i]) 
        {
            score += 3;
        }
        else if ((sample[i] == 'A' && candidate[i] == 'T') || (sample[i] == 'T' && candidate[i] == 'A') \
            || (sample[i] == 'C' && candidate[i] == 'G') || (sample[i] == 'G' && candidate[i] == 'C')) 
        {
            score += 1;
        }
    }
    
    // Normalize the score based on the length of the shorter DNA string
    return score * 100 / (3 * shorter_len);
}

// Function to match a sample DNA string with a set of candidate DNA strings
void dna_matching(char sample[], char candidates[][50], int num_candidates) 
{
    // Initialize variables to hold the index of the perfect match, the best score, and the index of the best candidate
    int perfect_match = -1;
    int best_score = -1;
    int best_candidate = -1;
    
    // Loop through each candidate DNA string and update the perfect match and best candidate variables
    for (int i = 0; i < num_candidates; i++) 
    {
        // Check if the candidate DNA string is a perfect match with the sample DNA string
        if (strcmp(sample, candidates[i]) == 0) 
        {
            perfect_match = i;
        }
        else 
        {
            // Calculate the DNA matching score between the sample and the candidate DNA strings
            int score = score_dna_match(sample, candidates[i]);
            
            // Update the best score and best candidate variables if the score for this candidate is better
            if (score > best_score) 
            {
                best_score = score;
                best_candidate = i;
            }
        }
    }
    
    if (perfect_match != -1) 
    {
        printf("Candidate %d is a perfect match.\n", perfect_match+1);
    }
    else 
    {
        printf("The best match is Candidate %d, with a score of %d.\n", best_candidate+1, best_score);
    }
}
