//COP3223C Section 1
//Large Program 2

#include <stdio.h>

void greeting(); //welcome the user.
void displayVendingOptions(); //display beverage options and prices.
void viewHand(double *balance); //display current amount in hand.
void pullMoney(double *balance); //grab more money from the unlimited ←- wallet
void order(double *balance); //user will recieve the order.
void transaction(double *balance, double price); //transaction with user



int main()
{
    greeting();

    double balance;

    int menu = 0; // declaration of menu for while loop.
    char option;
    
    while(menu >= 0) // allows the while loop to work.
    {
        /*gives the user an input option of what they would like to do.*/
        printf("*****************************************************\n");
        printf("Please select one of the following options.\n");
        printf("O: Order from the unlimited vending machine.\n");
        printf("V: View what you have in your hand currently.\n");
        printf("D: Display what the unlimited vending machine contains.\n");
        printf("G: Grab money out of unlimited wallet.\n");
        printf("E: Exit.\n");
        printf("*****************************************************\n");
        printf("What option would you like to go with?");
        scanf(" %c", &option);

        if(option == 'o' || option == 'O')
        {
            order(&balance); // if o is inputted then the order function will be called.
        }
        else if(option == 'v' || option == 'V')
        {
            viewHand(&balance); // if v is inputted then the viewHand function will be called.
        }
        else if(option == 'd' || option == 'D')
        {
            displayVendingOptions(); // if d is inputted then the displayVendingOptions function will be called.
        }
        else if(option == 'g' || option == 'G')
        {
            pullMoney(&balance); //if g is inputted then the pullMoney function will be called.
        }
        else if(option == 'e' || option == 'E')
        {
            /*if e is inputted then the program will end.*/
            printf("Thank You for visiting the Ulimited Vending Machine!!\n");
            printf("Please come back next time!!\n");
            break;
        }
        else
        {
            printf("That's an incorrect option that was selected. Please try again.\n"); // if user inputs incorrect value.
        }
    }

    return 0;
}

void greeting() 
{
    /*Greets user to the vending machine game.*/
    printf("Welcome to the Unlimited Vending Machine.\n");
    printf("We have an unlimted variety of drinks.\n");
    printf("With your unliminted wallet, you will never run out of cash!\n");
    printf("What would you like to order today?\n");
    printf("*****************************************************\n");

}

void displayVendingOptions()
{
    /*shows the user what is in the vending machine along with the prices.*/
    printf("You have selected to view the vending machines options.\n");
    printf("*****************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
    printf("*****************************************************\n");

}

void viewHand(double *balance)
{
    /*Allows the user to view their hand balance.*/
    printf("You currently have selected to see how much cash you have in hand.\n");
    printf("*****************************************************\n");
    printf("You currently have $%.2lf in your wallet.\n", *balance);
}

void pullMoney(double *balance)
{
    int amount;
    /*shows the user what options they can input in the wallet.*/
    printf("You have selected to pull money out of the ulimited wallet.\n");
    printf("*****************************************************\n");
    printf("How much money would you like to pull out of the ulimited wallet?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");

    printf("Option selected:", amount); //user inputs the amount they want in the wallet.
    scanf("%d", &amount);
    printf("*****************************************************\n");
    
    if(amount == 1)
    {
        /*adds one dollar to the wallet.*/
        *balance = *balance + 1.00;
        printf("$%.2lf has been successfully added to your wallet.\n", *balance);
    }
    else if(amount == 2)
    {
        /*adds 5 dollars to the wallet.*/
        *balance = *balance + 5.00;
        printf("$%.2lf has been successfully added to your wallet.\n", *balance);
    }
    else if(amount == 3)
    {
        /*adds 10 dollars to the wallet.*/
        *balance = *balance + 10.00;
        printf("$%.2lf has been successfully added to your wallet.\n", *balance);
    }
    else
    {
        /*if user inputs incorrect value it will ask to "try again".*/
        printf("That's an incorrect selection. Please try again.\n");
    }
    printf("*****************************************************\n");

}

void order(double *balance)
{
    int product;

    /*shows the user what drinks are variable and for what price.*/
    printf("You have selected to order from The Unlimited Vending Machine.\n");
    printf("*****************************************************\n");
    printf("Here are the options!\n");
    printf("*****************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
    printf("*****************************************************\n");
    printf("What product are you intested in?\n");

    printf("Option selected:"); //user inputs what option of drink they would like.
    scanf("%d", &product);

    if(product == 1)
    {
        /*if sprite is selected it sends the value to transaction function.*/
        printf("Sprite has been selected. Total cost: $2.50.\n");
        transaction(balance, 2.50);
    }
    else if(product == 2)
    {
        /*if coca-cola is selected it sends the value to transaction function.*/
        printf("Coca-Cola has been selected. Total cost: $2.50.\n");
        transaction(balance, 2.50);
    }
    else if(product == 3)
    {
        /*if water is selected it sends the value to transaction function.*/
        printf("Water has been selected. Total cost: $2.00.\n");
        transaction(balance, 2.00);
    }
    else if(product == 4)
    {
        /*if gatorade is selected it sends the value to transaction function.*/
        printf("Gatorade has been selected. Total cost: $3.00.\n");
        transaction(balance, 3.00);
    }
    else if(product == 5)
    {
        /*if diet cola is selected it sends the value to transaction function.*/
        printf("Diet cola has been selected. Total cost : $2.55.\n");
        transaction(balance, 2.55);
    }
    else if(product == 6)
    {
        /*if fanta is selected it sends the value to transaction function.*/
        printf("Fanta has been selected. Total cost $2.55.\n");
        transaction(balance, 2.55);
    }
    else if(product == 7)
    {
        /*if root beer is selected it sends the value to transaction function.*/
        printf("Root Beer has been selected. Total cost $1.50.\n");
        transaction(balance, 1.50);
    }
    else if(product == 8)
    {
        /*if dr. pepper is selected it sends the value to transaction function.*/
        printf("Dr. Pepper has been selected. Total cost $1.55.\n");
        transaction(balance, 1.55);
    }
    else
    {
        printf("Incorrect product was selected. Please try again.\n"); //if user does incorrect input then it prompts user to retry selection.
    }

}
 
void transaction(double *balance, double price)
{
    printf("Beginning Transaction Process.\n");

    double total = *balance - price; //subtracts the amount that is in the wallet with the price of the product.

    if(total >= 0) // if the total is greater than 0 then the purchase was successfull.
    {
        /*shows the user the total left in their wallet after the purchase.*/
        printf("Putting %.2lf into the vending machine.\n", price);
        printf("Transaction was successful.\n");
        printf("You have %.2lf left in your wallet.\n", total);

        *balance = total;
    }
    else // if the total goes below 0 then the purchase was unsuccessfull 
    {
        /*prompts the user to add more money into their wallet.*/
        printf("The transaction wasn't sucessfull.\n");
        printf("You don't have enough money to complete transaction.\n");
        printf("Please pull more money from the unlimited wallet.\n");

        
    }


}