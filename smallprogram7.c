//COP3223C Section 1
//Small Program 7

#include <stdio.h>
#include <string.h>

void deblank(char *input, char *output);
void pluralize(char *plural);
void fact(char *string);
void substring(char *word, char *subword);

int main()
{
    /*declaring size of the string.*/
    char input[20];
    char output[20];

    printf("Enter a string: ");
    fgets(input, 19, stdin); // like scanf, but for strings only

    deblank(input,output); // calls deblank function.

    printf("Output String with no blanks: %s", output);

    char plural[20]; // size of the string.

    /*asks user for input.*/
    printf("Enter string to be pluralize: ");
    scanf("%s", plural);

    pluralize(plural); // call the plural function to main.
    printf("Word pluralize: %s\n", plural); // prints the plural value that was stored in the function call.

    char string[20]; // size of the string

    /*asks user to input any type of string*/
    printf("Enter a string with no spaces: ");
    scanf("%s", string);

    printf("%s has\n", string); // reprints the string.
    fact(string);

    char word[20], subword[20]; // size of the string.

    /*asks user for input for the string.*/
    printf("Enter the string: ");
    scanf("%s", word);

    /*asks user for input for the substring.*/
    printf("Enter the substring you would like to look for: ");
    scanf("%s", subword);

    substring(word, subword); // calls the substring function to main.

    return 0;
}

void deblank(char *input, char *output)
{
    int y = 0;

    for(int x = 0; input[x] != '\0'; x++) // starts when null value isn't detected.
    {
        if(input[x] != ' ') //if space is detected then it will run.
        {
            output[y++] = input[x]; //removes the spaces in string.
        }

        output[y] = '\0'; // stops the function when null value is satisfied.
    }

}

void pluralize(char *plural)
{
    int size = strlen(plural); //stores the length of the string in size.
    
    /*if the string ends in 'y'. Then it pluralizes it to 'ies'.*/
    if(plural[size - 1] == 'y')
    {
        plural[size - 1] = '\0';
        plural[size - 1] = 'i';
        plural[size] = 'e';
        plural[size + 1] = 's';
        plural[size + 2] = '\0';
    }
    /*if the string ends in 'sh' or 'ch'. Then it pluralizes it to 'es'.*/
    else if(plural[size - 2] == 's' && plural[size - 1] == 'h'|| (plural[size - 2] == 'c' && plural[size - 1] == 'h'))
    {
        plural[size] = 'e';
        plural[size + 1] = 's';
        plural[size + 2] = '\0';
    }
    /*if the string ends in anything else. Then it pluralizes it to 's'.*/
    else
    {
        plural[size] = 's';
        plural[size + 1] = '\0';
    }
}

void fact(char *string)
{
    /*variable declaration*/
    int letters = 0;
    int digits = 0;
    int punct = 0;

    for(int s = 0; s < strlen(string); s++) //iterates over the length of the length of the string inputed.
    {
        if((string[s]>='a' && string[s]<='z') || (string[s]>='A' && string[s]<='Z')) //checking if the string is using letters.
        {
            letters++; //increases the value of letters for the amount of letters in the string.
        }
        else if(string[s]>='0' && string[s]<='9') // checking if the string uses any numbers.
        {
            digits++; //increases the value of digits for the amount of numbers in the string.
        }
        else // everything else is consider a punctutation character.
        {
            punct++; // increases the value of punct for the amount of punctutation characters in the string.
        }
    }

    printf("%d letters\n %d digits\n %d punctuation characters\n",letters ,digits ,punct);
}

void substring(char *word, char *subword)
{
    char *p1, *p2, *p3; // pointer variable declaration.
    int j = 0, flag = 0; // random value declaration.

  p1 = word;
  p2 = subword;

  for(int x = 0; x < strlen(word); x++) // allows the loop to check the word inputted.
  {
    if(*p1 == *p2) // checks if the word and subword have the same letters.
    {
        p3 = p1; // p3 now holds the word value.
        for(j = 0; j < strlen(subword); j++) // allows the loop to check the subword inputted.
        {
            /*checks if the suboword is in the word.*/
            if(*p3 == *p2)
            {
                p3++; 
                p2++;
            } 
            else // when done it breaks.
            {
                break;
            }
            
        }

        p2 = subword;
        if( j == strlen(subword)) // if the subword is in the word then it prints the value.
        {
            flag = 1; // sets flag to 1 so the 'if' statement on line 171 doesn't run.
            printf("Substring %s exists!\n", subword);
        }
        

    }

    p1++; // counter for word.
    
  }
    if(flag == 0) // if the 'if' on line 159 doesn't run then this function runs.
    {
        printf("Substring %s doesn't exist!\n", subword);
    }
}