#include <stdio.h>

int main()
{
    char string [30]; //declaration in memory
    printf("sizeof(string) = %ld\n", sizeof(string));
    
    char string2 [30] = "Strings are Fun!"; //declaration and initializing
    char word [] = {'C', 'a', 't', '\0'};

    printf("Word = %s\n", word);

    int x = 3;

    for(int x = 0; x < 2; ++x)
    {
        string[x] = 'A';
    }

    string[5] = '\0';

    printf("%s\n", string);


    char class[30];

    printf("Enter the course: ");
    scanf("%s\n", class);

    printf("The class is %s\n", class);
    
    puts(class);


    
    return 0;
}