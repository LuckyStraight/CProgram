//joshua Khooba
// Professor Ting Tang
//COP3223C Section 1 lab
//lab 1

#include <stdio.h>

int main(void)
{
    printf("Hello world!\n");

    /* created two arrays with size of 50 to store the strings.*/
    char update1[50] = "How are you doing my friends!";
    char update2[50]= "C you late.";

    printf("Hello world! %s\n", update1); // prints the first update to the Hello World
    printf("Hello world!\n%s\n \t %s\n", update1, update2); // prints the second update to the Hello World

    return 0;

}