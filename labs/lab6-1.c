#include <stdio.h>

// function declarations
float fahrenheit_to_celsius(float temp_f);
float celsius_to_fahrenheit(float temp_c);
void print_menu();
int get_choice();
void handle_choice(int choice);

int main() 
{
    int choice;
    
    // loop until the user chooses to quit
    while (1) 
    {
        // print the menu, get the user's choice, and handle it
        print_menu();
        choice = get_choice();
        handle_choice(choice);
        
        // if the user chooses to quit, break out of the loop
        if (choice == 3) 
        {
            break;
        }
    }
    
    return 0;
}

// function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float temp_f) 
{
    return (5.0 / 9.0) * (temp_f - 32);
}

// function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float temp_c) 
{
    return (9.0 / 5.0) * temp_c + 32;
}

// function to print the menu
void print_menu() 
{
    printf("Please choose an option:\n");
    printf("1. Convert temperature from Fahrenheit to Celsius\n");
    printf("2. Convert temperature from Celsius to Fahrenheit\n");
    printf("3. Quit\n");
}

// function to get the user's choice from the menu
int get_choice() 
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to handle the user's choice
void handle_choice(int choice) 
{
    float temp_f, temp_c;
    
    switch (choice) 
    {
        case 1:
            // convert Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp_f);
            temp_c = fahrenheit_to_celsius(temp_f);
            printf("%.2f degree F = %.2f degree C\n", temp_f, temp_c);
            break;
            
        case 2:
            // convert Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp_c);
            temp_f = celsius_to_fahrenheit(temp_c);
            printf("%.2f degree C = %.2f degree F\n", temp_c, temp_f);
            break;
            
        case 3:
            // quit the program
            break;
            
        default:
            // handle invalid choice
            printf("Invalid choice. Please try again.\n");
    }
}
