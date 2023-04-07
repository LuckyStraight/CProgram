#include <stdio.h>
#include <string.h>

void greeting();
int question1(int points);
int question2(int points);
int question3(int points);
int question4(int points);
int question5(int points);

int main()
{
    greeting();

    int choice, points = 0;
    printf("Are you ready to get started? 1. Yes or 2. No?");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("You chose to move forward with the challenge!\n");
    }
    else if(choice == 2)
    {
        printf("You can't say no, You're forced to answer by the Knight Counsel.\n");
    }
    else
    {
        printf("That's incorrect input!\n");
    }

    while(points < 5)
    {
        if(choice == 1 || choice == 2)
        {
        question1(points);
        printf("You currently have %d points.\n", points);

        question2(points);
        printf("You currently have %d points.\n", points);

        question3(points);
        printf("You currently have %d points.\n", points);

        question4(points);
        printf("You currently have %d points.\n", points);

        question5(points);
        printf("You currently have %d points.\n", points);
        }
    }

    if(points == 5)
    {
        printf("You're truly a Knight to get all the questions correct!!!\n");
    }
    else if(points == 4)
    {
        printf("You only got 4 points. Almost there to becoming a Knight!\n");
    }
    else if(points == 3)
    {
        printf("You only got 3 points. Not Too Bad! You're the average fan!\n");
    }
    else if(points == 2)
    {
        printf("You only got 2 points. That's a bit low. Better Luck Next time.\n");
    }
    else if(points == 1)
    {
        printf("You only got 1 point. That's bad luck. We can't accept that!\n");
    }
    else
    {
        printf("You got 0 points!!! That's a TERRIBLE SCORE. YOU'RE AN IMPOSTER!!!!\n");
    }

    return 0;
}

void greeting()
{
    printf("************************************************************************\n");
    printf("Welcome to the Space U Questionaire!!!\n");
    printf("This questionaire is to test if you're a true Knight\n");

    char name[10];
    printf("What's your name challenger?");
    fgets(name, 9, stdin);

    printf("Alright Challenger %c you have 5 questions to answer correctly\n", name[10]);
    printf("We will be collecting points to decide if you're a true Knight fan or an imposter\n");
    printf("************************************************************************\n");

}

int question1(int points)
{
    int answer;

    printf("************************************************************************\n");
    printf("Welcome to round 1!\n");
    printf("What was UCF's original name?\n");
    printf("1. College of Central Florida\n");
    printf("2. Florida Technological University\n");
    printf("3. NASA University\n");
    printf("choice:");
    scanf("%d", &answer);

    if(answer == 2)
    {
        ++points;
    }
    else
    {
        points += 0;
    }

    return points;

}

int question2(int points)
{
    int answer2; 

    printf("************************************************************************\n");
    printf("Welcome to round 2!\n");
    printf("What was the name of the University's Mascot?\n");
    printf("1. Pegasus\n");
    printf("2. Knightro\n");
    printf("3. Citronaut\n");
    printf("choice: ");
    scanf("%d", &answer2);

    if(answer2 == 3)
    {
        ++points;
    }
    else
    {
        points += 0;
    }

    return points;
}

int question3(int points)
{
    int answer3;

    printf("************************************************************************\n");
    printf("Welcome to round 3!\n");
    printf("What was the first building on campus?\n");
    printf("1. Library\n");
    printf("2. Student Union\n");
    printf("3. Classroom Building 1\n");
    printf("choice: ");
    scanf("%d", &answer3);

    if(answer3 == 1)
    {
        ++points;
    }
    else
    {
        points += 0;
    }

    return points;
}

int question4(int points)
{
    int answer4;

    printf("************************************************************************\n");
    printf("Welcome to round 4!\n");
    printf("What Homecoming tradition does UCF have that has been rated as part of the Top 20 Best College Traditions in the United States?\n");
    printf("1. Space U game\n");
    printf("2. Spirit Splash\n");
    printf("3. Free event tickets\n");
    printf("choice: ");
    scanf("%d", &answer4);

    if(answer4 == 2)
    {
        ++points;
    }
    else
    {
        points += 0;
    }

    return points;
}

int question5(int points)
{
    int answer5;

    printf("************************************************************************\n");
    printf("Welcome to round 5!\n");
    printf("What is the name of the body of water in front of Millican Hall on the UCF Main Campus?\n");
    printf("1. Lake Claire\n");
    printf("2. Knight pond\n");
    printf("3. Reflection Pond\n");
    printf("choice: ");
    scanf("%d", answer5);

    if(answer5 == 3)
    {
        ++points;
    }
    else
    {
        points += 0;
    }

    return points;
}
