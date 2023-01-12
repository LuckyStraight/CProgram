#include <stdio.h>

void whatdayisIt(); //function prototype 
void whatistomorrow();
int favnum();
double favdoubs();
char favlet();

int main()
{
    whatdayisIt(); //function call to user defined function

    int num = favnum();

    printf("In the main function the number is %d\n", num);

    double doubs = favdoubs();
    printf("In the main function the doubs is %lf\n", doubs);

    char let = favlet();
    printf("In the main function the letter is %f\n", let);
    

    return 0;
}

void whatdayisIt() // function definition
{
    printf("its friday\n");
    whatistomorrow();
}

void whatistomorrow()
{
    printf("its saturday\n");
}

int favnum()
{
    printf("sending back your fav number\n");

    int num = 10;

    return num;
}

double favdoubs()
{
    double doubs = 12.0;

    return doubs;

}

char favlet()
{
    char let = "what";

    return let;

}