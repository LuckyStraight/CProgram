#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    char title[30];
}movie_t;

typedef struct{
    int year;
    char *title;
    char *author;
}book_t;


int main()
{
    char titlesample[] = "Avatar";
    movie_t *movie = (movie_t *) malloc(sizeof(movie_t)); // gives movie assigned space.

    movie -> year = 2022;
    strcpy(movie -> title, titlesample);

    printf("%d\n", movie -> year);
    printf("%s\n", movie -> title);

    free(movie);

    book_t *book = (book_t *) malloc(sizeof(book_t)); // gives book an assigned space.

    book -> title = (char *) malloc(sizeof(char)* 30); // gives title a size, if 30 is characters has been reached then it multiplies 30 more.
    book -> author = (char *) malloc(sizeof(char)* 30); // gives author a size, if 30 is characters has been reached then it multiplies 30 more.

    char titlesample2[] = "Harry Potter and the Chamber of Secrets";
    char authorsample[] = "Stephen King";

    book -> year = 2022;
    strcpy(book -> title, titlesample2);
    strcpy(book -> author, authorsample);

    printf("%d\n", book -> year);
    printf("%s\n", book -> title);
    printf("%s\n", book -> author);

    /*when making free calls it must match the malloc calls in order.*/
    free(book -> title);
    free(book -> author);
    free(book);

    return 0;
}