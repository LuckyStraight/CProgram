#include <stdio.h>
#include <string.h>

int score_dna_match(char sample[], char candidate[]) {
    int score = 0;
    int shorter_len = strlen(sample) < strlen(candidate) ? strlen(sample) : strlen(candidate);

    for (int i = 0; i < shorter_len; i++) {
        if (sample[i] == candidate[i]) {
            score += 3;
        }
        else if ((sample[i] == 'A' && candidate[i] == 'T') || (sample[i] == 'T' && candidate[i] == 'A') \
            || (sample[i] == 'C' && candidate[i] == 'G') || (sample[i] == 'G' && candidate[i] == 'C')) {
            score += 1;
        }
    }
    
    return score * 100 / (3 * shorter_len);
}

void dna_matching(char sample[], char candidates[][50], int num_candidates) {
    int perfect_match = -1;
    int best_score = -1;
    int best_candidate = -1;
    
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(sample, candidates[i]) == 0) {
            perfect_match = i;
        }
        else {
            int score = score_dna_match(sample, candidates[i]);
            if (score > best_score) {
                best_score = score;
                best_candidate = i;
            }
        }
    }
    
    if (perfect_match != -1) {
        printf("Candidate %d is a perfect match.\n", perfect_match);
    }
    else {
        printf("The best match is Candidate %d, with a score of %d.\n", best_candidate, best_score);
    }
}

int main() {
    char sample[50];
    char candidates[100][50];
    int num_candidates;
    
    FILE *fp = fopen("input1.txt", "r");
    fgets(sample, 50, fp);
    sample[strcspn(sample, "\n")] = 0;
    fscanf(fp, "%d", &num_candidates);
    
    for (int i = 0; i < num_candidates; i++) {
        fscanf(fp, "%s", candidates[i]);
    }
    
    dna_matching(sample, candidates, num_candidates);
    fclose(fp);
    
    return 0;
}