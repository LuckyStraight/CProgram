#include <stdio.h>
#include <stdlib.h>

// Define struct for date
typedef struct {
    int month;
    int day;
    int year;
} DATE;

// Define struct for person
typedef struct {
    char name[50];
    DATE birthdate;
    char gender;
    double annualIncome;
} PERSON;

int isValidDate(int month, int day, int year);
void populatePerson(PERSON *person);
void printPerson(PERSON person);

int main() 
{
    PERSON person1, person2, person3;
    
    printf("Enter data for person 1:\n");
    populatePerson(&person1);
    printf("\n");
    
    printf("Enter data for person 2:\n");
    populatePerson(&person2);
    printf("\n");
    
    printf("Enter data for person 3:\n");
    populatePerson(&person3);
    printf("\n");
    
    printf("Data for all people:\n");
    printPerson(person1);
    printPerson(person2);
    printPerson(person3);
    
    return 0;
}

// Function to validate date
int isValidDate(int month, int day, int year) 
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) 
    {
        daysInMonth[1] = 29; // leap year
    }

    if (month < 1 || month > 12) 
    {
        return 0;
    }

    if (day < 1 || day > daysInMonth[month - 1]) 
    {
        return 0;
    }

    return 1;
}

// Function to populate a person
void populatePerson(PERSON *person) 
{
    printf("Enter name: ");
    scanf(" %[^\n]s", person->name); // read entire line, including spaces
    printf("Enter birthdate (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &person->birthdate.month, &person->birthdate.day, &person->birthdate.year);

    while (!isValidDate(person->birthdate.month, person->birthdate.day, person->birthdate.year)) 
    {
        printf("Invalid date. Enter birthdate (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &person->birthdate.month, &person->birthdate.day, &person->birthdate.year);
    }

    printf("Enter gender (M/F/O): ");
    scanf(" %c", &person->gender);

    while (person->gender != 'M' && person->gender != 'F' && person->gender != 'O') 
    {
        printf("Invalid gender. Enter gender (M/F/O): ");
        scanf(" %c", &person->gender);
    }
    printf("Enter annual income: ");
    scanf("%lf", &person->annualIncome);

    while (person->annualIncome < 0 || person->annualIncome > 1000000) 
    {
        printf("Invalid income. Enter annual income: ");
        scanf("%lf", &person->annualIncome);
    }
}

// Function to print a person
void printPerson(PERSON person) 
{
    printf("Name: %s\n", person.name);
    printf("Birthdate: %02d/%02d/%04d\n", person.birthdate.month, person.birthdate.day, person.birthdate.year);
    printf("Gender: %c\n", person.gender);
    printf("Annual income: $%.2f\n", person.annualIncome);
    printf("\n");
}