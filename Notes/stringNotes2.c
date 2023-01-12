#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[30] = "The Magic School Bus";
    char word2[30] = "Ms.Frizzle";

    strncpy(word, word2, 5);

    printf("word = %s\n", word);

    char word3[100] = "Agatha Coven of Chaos";
    int size = strlen(word);

    printf("%s contains %d characters\n", word3, size);


    char s1[30] =  "agatha";
    char s2[30] = "agatha";
    char s3[30] = "cagatha";
    char s4[30] = "bgatha";

    int result = strcmp(s1, s2);
    printf("strcmp(%s, %s) = %d\n", s1, s2, result);

    result = strcmp(s1, s3);
    printf("strcmp(%s, %s) = %d\n", s1, s3, result);

    result = strcmp(s1, s4);
    printf("strcmp(%s, %s) = %d\n", s1, s4, result);

    result = strcmp(s3, s4);
    printf("strcmp(%s, %s) = %d\n", s3, s4, result);

    char string[] = "asd31;";

    string[0] = toupper(string[0]);

    printf("%s\n", string);

    return 0;
}