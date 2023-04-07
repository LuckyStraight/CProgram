// COP3223 section 1
// Large Program 4

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRIES 30

typedef struct{
    char name[20];
    char brand[20];
    int id;
    int stock;
    double price;
    double avginventory;
    }wallet;

void initializeEntries(wallet list[], int *size); // creates place holder entries.
char menu(); // gives user a menu to choose options.
void addEntry(wallet list[], int *size); // allows user to add entries.
void deleteEntry(wallet list[], int *size); // allows user to delete an entry in the text file.
void display(wallet list[], int *size); // allows the user to display all entries in the text file.
void createReport(wallet list[], int *size); // creates the text file.
void clearRecords(wallet list[], int *size); // allows user to clear all entries in the text file.
void update(wallet list[], int *size); // allows user to update parts of an entry.

int main()
{   
    wallet list[MAX_ENTRIES];
    int size = 0;
    initializeEntries(list, &size);

    printf("Hello and welcome. This program helps you create an inventory for skate shoes.\n");
    printf("To get you started, 5 shoes have already been entered.\n");

    char sel;

    while(sel != 'Q' && sel != 'q') //stops the loop when user selects q.
    {
        sel = menu(); // saves menu value in sel.

        if(sel == 'A' || sel == 'a')
        {
            addEntry(list, &size); //adds an entry when user inputs a.
        }
        else if(sel == 'D' || sel == 'd')
        {
            deleteEntry(list, &size); // deletes an entry when user inputs d.
        }
        else if(sel == 'P' || sel == 'p')
        {
            display(list, &size); //displays the entries when user inputs p.
        } 
        else if(sel == 'S' || sel == 's')
        {
            createReport(list, &size); // creates an entry asking inputs.
        }
        else if(sel == 'C' || sel == 'c')
        {
            clearRecords(list, &size); // allows the user to clear the text file.
        }
        else if(sel == 'U' || sel == 'u')
        {
            update(list, &size); // allows the user to update the data in the file.
        }
        else if(sel == 'Q' || sel == 'q')
        {
            printf("Goodbye.\n"); // if q is selected then.
        }
        else
        {
            printf("Invalid Input!!! Please enter a valid command.\n"); // if user inputs a invalid letter.
        }
        
    }
    return 0;    
}

/*Function creates a set number of entries just to fill the text file.*/
void initializeEntries(wallet list[], int *size)
{
    /*place holder in text file 1.*/
    strcpy(list[0].name, "Flemming_Tote");
    strcpy(list[0].brand, "Tori_Burch");
    list[0].id = 100;
    list[0].stock = 101;
    list[0].price = 500;
    list[0].avginventory = 200.2;
    
    /*place holder in text file 2.*/
    strcpy(list[1].name,"Marion_Crossbody");
    strcpy(list[1].brand,"Tori_Burch");
    list[1].id=101;
    list[1].stock=101;
    list[1].price=300;
    list[1].avginventory=200.2;
    
    /*place holder in text file 3.*/
    strcpy(list[2].name,"Adalyn_Clutch");
    strcpy(list[2].brand,"Tori_Burch");
    list[2].id=102;
    list[2].stock=101;
    list[2].price=325;
    list[2].avginventory=200.2;
    
    /*place holder in text file 4.*/
    strcpy(list[3].name,"Robinson_Bag");
    strcpy(list[3].brand,"Tori_Burch");
    list[3].id=103;
    list[3].stock=101;
    list[3].price=365;
    list[3].avginventory=200.2;
    
    /*place holder in text file 5.*/
    strcpy(list[4].name,"Elise_Satchel");
    strcpy(list[4].brand,"Tori_Burch");
    list[4].id=104;
    list[4].stock=101;
    list[4].price=595;
    list[4].avginventory=200.2;
    
    *size = 5; // makes the size of the text file to hold 5.                        
}   

char menu()
{
    char sel;

    /*User chooses what option they want to go with in the program.*/
    printf("\n***************************************\n");
    printf("Please select from the options below:\n");
    printf("A - ADD a new entry\n");
    printf("D - DELETE an entry\n");
    printf("P - PRINT entire catalog\n");
    printf("S - SAVE the current catalog\n");
    printf("C - CLEAR the entire catalog\n");
    printf("U - UPDATE the price\n");
    printf("Q - QUIT\n");
    printf("What would you like to do: ");
    scanf(" %c", &sel);

    return sel; // returns the user inputs to start the loop.
}

void addEntry(wallet list[], int *size)
{
    printf("\nEnter name : ");
    scanf("%s",list[*size].name); // asks user to input their name.

    printf("\nEnter brand : "); // asks user to input a brand name they would like to create.
    scanf("%s",list[*size].brand);

    printf("\nEnter id : "); // asks the user to input an ID number.
    scanf("%d",&list[*size].id);

    printf("\nEnter stock : "); // asks user to input the amount of stock they want.
    scanf("%d",&list[*size].stock);

    printf("\nEnter price : "); // asks user to input the price of the stock.
    scanf("%lf",&list[*size].price);

    printf("\nEnter average inventory : "); // asks user to input the average inventory of product.
    scanf("%lf",&list[*size].avginventory);

    (*size)++;// iterates the size.
}
void deleteEntry(wallet list[], int *size)
{
    int i, id;
    printf("List of ID #'s:\n"); // lists the entries in the text file by ID.

    for(i = 0; i < *size ; i++)
    {
        /*asks user to input ID to choose which entry to delete.*/
        printf("%d ",list[i].id);
        printf("\nPlease enter the I.D.: ");
        scanf("%d", &id);

        for(i = 0; i < *size; i++)
        {
            if(list[i].id == id) //checks the ID to match what is in the text file.
            {
                /*deletes only the entry matching the ID inputted by the user.*/
                strcpy(list[i].brand,list[*size-1].brand);
                strcpy(list[i].name,list[*size-1].name);
                list[i].id = list[*size-1].id;  
                list[i].stock = list[*size-1].stock;
                list[i].price = list[*size-1].price;
                list[i].avginventory = list[*size-1].avginventory;
                (*size)--;
                break;
            }
        }        
    }          
}
void display(wallet list[],int *size)
{    
    int i;

    if(*size == 0) // checks if nothing is in the text file.
    {
        printf("*****Catalog is empty*****\n"); // if nothing is in the text file then display it's empty.
        
        for(i = 0; i <* size; i++)
        {
            /* allows the user to display all the information stored in the text file.*/
            printf("***Catalog Entry %d***\n",i+1);
            printf("BRAND: %s\n",list[i].brand);
            printf("NAME: %s\n",list[i].name);
            printf("I.D.#: %d\n",list[i].id);
            printf("QTY:    %d\n",list[i].stock);
            printf("PRICE:   $%.2lf\n",list[i].price);
            printf("AVERAGE INVENTORY: $%.2lf\n\n",list[i].avginventory);            
        }       
    }           
}
void createReport(wallet list[], int *size)
{
    FILE *rec = fopen("records.txt","w"); // opens and writes in the text file.
    int i;

    if (rec == NULL)
    {
        printf("Error opening file!\n"); // if the text file is unable to open.
        exit(1);
    }

    if(*size == 0)
    {
        fprintf(rec,"*****Catalog is empty*****\n"); // shows if the text file is empty.
    }

    for(i = 0; i < *size; i++)
    {
        /*writes the info into the text file to be stored.*/                          
        fprintf(rec, "***Catalog Entry %d***\n",i + 1);
        fprintf(rec,"BRAND: %s\n",list[i].brand);
        fprintf(rec,"NAME: %s\n",list[i].name);
        fprintf(rec,"I.D.#: %d\n",list[i].id);
        fprintf(rec,"QTY:    %d\n",list[i].stock);
        fprintf(rec,"PRICE:   $%.2lf\n",list[i].price);
        fprintf(rec,"AVERAGE INVENTORY: $%.2lf\n\n",list[i].avginventory);       
    }
    
    fclose(rec); // closes the text file.
}

void clearRecords(wallet list[], int *size)
{   
    *size = 0; // clears the text file.
}

void update(wallet list[],int *size)
{   
    int i, id;
    double price_up;
    printf("List of ID #'s:\n");

    for(i = 0; i < *size; i++)
    {
        /*searches the entries using the ID to update.*/
        printf("%d ",list[i].id);
        printf("\nPlease enter the I.D.: ");
        scanf("%d", &id);

        for(i = 0; i < *size; i++)
        {
           if(list[i].id == id)
           {
                /*Shows user what info they want to update in the entry.*/
                printf("***Catalog Entry %d***\n",i+1);
                printf("BRAND: %s\n",list[i].brand);
                printf("NAME: %s\n",list[i].name);
                printf("I.D.#: %d\n",list[i].id);
                printf("QTY:    %d\n",list[i].stock);
                printf("PRICE:   $%.2lf\n",list[i].price);
                printf("AVERAGE INVENTORY: $%.2lf\n\n",list[i].avginventory);   
                printf("Please enter the updated price: ");
                scanf("%lf", &price_up); // asks the user to update the price.

                list[i].price = price_up; //updates the price the user inputed.
                break;
           }
        }                
    }

}