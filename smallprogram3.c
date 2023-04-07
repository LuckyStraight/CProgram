//COP3223C Section 1
//Small Program 3

#include <stdio.h>
#include <ctype.h>


void letters();
void greenlawyer();
void coordinates(double x, double y);
int triangle(int a, int b, int c);

int main()
{
    letters(); // calls the letter function to run

    greenlawyer(); // calls the greenlawyer function to run

    double x, y; 
    printf("Enter the x-coordinate: "); //user input for x
    scanf("%lf", &x);

    printf("Enter the y-coordinate: "); // user input for y
    scanf("%lf", &y);

    coordinates(x,y); // calls the coordinates function to run
    
    int a, b, c;
    printf("Enter three sides separated by a whitespace: "); //user input of a, b, c
    scanf("%d%d%d", &a, &b, &c);

    int result = triangle(a,b,c); // calls triangle function to store returned value in result
    if(result == -1)
        printf("Not Triangle!\n");
    else
        printf("Triangle!\n");

    return 0;
}

void letters()
{
    char ltr;

    printf("Enter a key from the keyboard: ");
    scanf("%c", &ltr);

    if(islower(ltr)) // if the letter is lower case
        printf("Lower!\n");
    else if(isupper(ltr)) // if the letter is upper case
        printf("Upper!\n");
    else
        printf("Not a letter!\n");

}

void greenlawyer()
{
    int options;
 //different options the user can choose from
    printf("Hi! Thank you for calling the Superhuman Law Division at GLK&H!\n");
    printf("Our associates are currently working hard for super people like you.\n");
    printf("Please listen carefully to the options of who you would like to speak to in regards to your situation.\n");
    printf("Option 1: Fined for thousands of dollars worth of damage to the city you were trying to protect.\n");
    printf("Option 2: Accidentally create a sentient robot who got the feels and tried to destroy the world.\n");
    printf("Option 3: You are an Asgardian god who unintentionally leaves a giant burning imprint on private\nproperty every time you visit Earth.\n");
    printf("Option 4: You just gained new superhero strength that is not recognized by the department of\ndamage control, and they are chasing you down after you performed a good deed.\n");
    printf("Option 5: Your secret identity was revealed by a notorious person and now your personal life\nis no longer the same.\n");
    printf("Option 6: Another super being issue that was not mentioned previously in the options given.\n");

    printf("Selection: ");
    scanf("%d", &options); // allows user input to choose an option
    
    switch(options)
    { // gives an answer to the option the user chose
        case 1:
            printf("You have selected option 1. Do not worry! I will make sure you don't give up that green.\n");
            break;
        case 2:
            printf("You have selected option 2. Do not worry! You probably had good intention that just didn't work out properly.\n");
            break;
        case 3:
            printf("You have selected option 3. Do not worry! I understand you like to make a grand enterance.\n");
            break;
        case 4:
            printf("You have selected option 4. Do not worry! We will talk to the department of damage control.\n");
            break;
        case 5:
            printf("You have selected option 5. Do not worry! We will make sure that you are protected. Please be cautious if you decide to seek Dr. Strange's help.\n");
            break;
        default:
            printf("You have selected option 6. Do not worry! I will make sure to use my superhero mind to solve your super problem!\n");
            break;

    }
        

}

void coordinates(double x, double y)
{
    if( x > 0 && y > 0) // if both values positive then it's QI
	  printf("(%.2lf, %.2lf) is in quadrant I.\n",x,y);
	else if( x < 0 && y > 0) // if the x is negative and the y is positive then it's QII
	  printf("(%.2lf, %.2lf) is in quadrant II.\n",x,y);
	else if( x < 0 && y < 0) // if both values is negative then it's QIII
	  printf("(%.2lf, %.2lf) is in quadrant III.\n",x,y);
	else if( x > 0 && y < 0) // if x is positive and y is negative then it's QIV
	  printf("(%.2lf, %.2lf) is in quadrant IV.\n",x,y);
	else if( x == 0 && y == 0) // both values 0 then it's the origin
	  printf("(%.2lf, %.2lf) is in origin.\n",x,y);

}

int triangle(int a, int b, int c)
{
    printf("Checking these logistics from the input.\n");

// outputs each side of the triangle
    printf("%d + %d > %d\n", a, b, c);
    printf("%d + %d > %d\n", a, c, b);
    printf("%d + %d > %d\n", b, c, a);

    if(a + b > c && a + c > b && b + c > a) // decides if the values equals a triangle or not
        return 1; // 1 is triangle
    else
        return -1; // -1 is not triangle

        

}