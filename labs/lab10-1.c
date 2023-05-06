#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_TITLE_LENGTH 100

int main(void) 
{
    FILE *fp;
    char line[100];
    char prev_title[MAX_TITLE_LENGTH] = "";
    char prev_rating[10] = "";
    char title[MAX_TITLE_LENGTH];
    char rating[10];
    char time[10];
    int i = 0;

    fp = fopen("movies.csv", "r");
    if (fp == NULL) 
    {
        perror("Error opening file");
        exit(1);
    }

    printf("%-44s|%-6s|%-15s\n", "Title", "Rating", "Showtimes");
    printf("------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        sscanf(line, "%[^,],%[^,],%s", time, title, rating);
        if (strcmp(title, prev_title) != 0) 
        {
            if (prev_title[0] != '\0') 
            {
                printf("%-44s|%-6s|", prev_title, prev_rating);
                for (int j = 0; j < i - 1; j++)
                {
                    printf("%s ", time);
                    fgets(line, sizeof(line), fp);
                    sscanf(line, "%*[^,],%*[^,],%s", time);
                }
                
                printf("%s\n", time);
            }
            strcpy(prev_title, title);
            strcpy(prev_rating, rating);
            i = 0;
        } 

        else 
        {
            i++;
        }
    }

    printf("%-44s|%-6s|", prev_title, prev_rating);
    for (int j = 0; j < i - 1; j++) 
    {
        printf("%s ", time);
        fgets(line, sizeof(line), fp);
        sscanf(line, "%*[^,],%*[^,],%s", time);
    }

    printf("%s\n", time);

    fclose(fp);

    return 0;
}
