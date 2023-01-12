#include <stdio.h>
#include <string.h>

int main()
{
    char word[] = "birds";

    printf(" word before = %s\n", word);

    strcpy(word, "Dog"); //strcpy(destination, source)

    printf("word after = %s\n", word);

    for(int x = 0; x < 5; x++)
    {
        printf("word[%d] = %c",x, word[x]);
    }

    char word2[] = "Super Mario Movie";

    strncpy(word, word2, sizeof(word) - 2);
    word[sizeof(word) - 2] = '\0';

    printf("After the strncpy word = %s\n", word);



    return 0;
}