#include <stdio.h>

struct book_s{
    int numpages;
    char author[30];
    char title[30];
    int year;
};

typedef struct{
    int time;
    char title[30];

} movie_t;

void printStruct(movie_t mymovie);
void anotherprintStruct(movie_t *mymovie);
int createInt();

movie_t createMovie();


int main()
{
    int x;
    double y;
    char ltr;
    float num;

    x = 2022;

    struct book_s book1; //declaration of a struct

    book1.numpages = 123;

    printf("Enter the author last name: ");
    scanf("%s", book1.author);

    printf("Enter a title: ");
    scanf("%s", book1.title);

    printf("Enter the publish year: ");
    scanf("%d", &book1.year);

    

    printf("book1.numpages = %d\n", book1.numpages);
    printf("book1.author = %c\n", book1.author);
    printf("book1.title = %c\n", book1.title);
    printf("book1.year = %d\n", book1.year);

    movie_t movie1 = createMovie(); //declaration of a typedef

    printStruct(movie1);

    anotherprintStruct(&movie1);

    movie_t library[5];

    printf("Populate the Array Struct of Movies\n");

    printf("Enter the 1st Movie title: ");
    scanf("%s", library[0].title);

    printf("Enter %s length: ", library[0].title);
    scanf("%d", library[0].time);

    printf("Enter the 2nd Movie title: ");
    scanf("%s", library[1].title);

    printf("Enter %s length: ", library[1].title);
    scanf("%d", library[1].time);

    printf("Enter the 3rd Movie title: ");
    scanf("%s", library[2].title);

    printf("Enter %s length: ", library[2].title);
    scanf("%d", library[2].time);

    printf("Enter the 4th Movie title: ");
    scanf("%s", library[3].title);

    printf("Enter %s length: ", library[3].title);
    scanf("%d", library[3].time);

    printf("Enter the 5th Movie title: ");
    scanf("%s", library[4].title);

    printf("Enter %s length: ", library[4].title);
    scanf("%d", library[4].time);

    printf("Displaying the values stored in the array.\n");
    for(int x = 0; x < 5; ++x)
    {
        printf("library[%d].title = %s\n", x, library[x].title);
        printf("library[%d].time = %d\n", x, library[x].time);
    }

    int structSize = sizeof(movie_t);
    printf("movie_t takes about %d bytes of memory\n", structSize);
    

    return 0;
}

void printStruct(movie_t mymovie)
{
    printf("Inside the printStruct function");
    printf("movie1.title = %S\n", mymovie.title);
    printf("movie1.time = %d\n", mymovie.time);
}

void anotherprintStruct(movie_t *mymovie)
{
    printf("(mymoive).title = %s\n", (*mymovie).title);
    printf("(mymovie).time = %s\n", (*mymovie).time);

    printf("Inside the printStruct function");
    printf("movie1.title = %S\n", mymovie->title);
    printf("movie1.time = %d\n", mymovie->time);
}

movie_t createMovie()
{
    movie_t movie1;

    printf("Creating movie for you now!\n");
    printf("Enter the movie title: ");
    scanf("%s", movie1.title);

    printf("Enter the movie length: ");
    scanf("%d", &movie1.time);

    printfStruct(movie1);
    anotherprintStruct(&movie1);

    printf("Done creating the movie for you!\n");

    return movie1;
}

int createInt() // samething as the createMovie function
{
    int val;
    printf("Enter in a value: ");
    scanf("%d", &val);

    return val;
}