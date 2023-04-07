//COP3223c section 1
//Small Program 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char *fname; //first name
	char *lname; //last name
	char *show; //favorite show
}record_t;

record_t *createArray(int maxsize); // creates the array.
record_t *insert(record_t *myarray, int *maxsize, int *currentsize); // inserts the record in the array.
void display(record_t *myarray, int currentsize); // displays the inputed values by user.
record_t *doubleIt(record_t *arr, int size); // doubles the memory of the array.
int removeRecord(record_t *arr, int size, int index); //removes a selected record.
void freeRecords(record_t *arr, int size); // frees records that are in the heap.

int main()
{
    /*allows user to choose the size of the array.*/
    int maxsize;
    
    printf("Enter a size for the dynamic array: ");
    scanf("%d", &maxsize);

    record_t *myarray = createArray(maxsize); // crates a maxsize array from the heap.

    int currentsize = 0;
    int option = -1;
    int index;

    while(option != 0)
    {
        /*display menu on user can choose.*/
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");

        printf("Enter an option: ");
        scanf("%d", &option);

        while(option <= 0 || option >= 0)
        {
            if(option == 1)
            {
                /*insert a record to the array*/
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;
            }
            else if(option == 2)
            {
                printf("Display was selected...\n");
                /*display the records*/
                display(myarray, currentsize);
                break;
            }
            else if(option == 3)
            {
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                scanf("%d", &index);
                /*remove a record from the index position*/
                currentsize = removeRecord(myarray, currentsize, index);
                break;
            }
            else if(option == 4)
            {
                printf("Exiting...\n");
                option = 0; // breaks if no option was chosen.
                break;
            }
            else
            {
                printf("Invalid Selection...\n"); // if user inputs incorrect value.
                exit(1);
            }
        }
    }

    freeRecords(myarray, currentsize); // de-allocate memory of the records.

    free(myarray);// de-allocate memory of the array.
    myarray = NULL; // sets my myarray to hold nothing.

    return 0;
}

/*function to create array of maxsize from heap*/
record_t *createArray(int maxsize)
{
    record_t *arr = (record_t*) malloc(maxsize * sizeof(record_t)); // creating the *arr value that checks the sizeof value held in *arr.
    if(arr == NULL)
    {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    return arr;// returns the value arr to main.
}

/*function to insert a record*/
record_t *insert(record_t *myarray, int *maxsize, int *currentsize)
{
    if(*currentsize == *maxsize) // checks if the currentsize is equal to maxsize allowed.
    {
        /*Doubles the maxsize to allow more storage in the array.*/
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, *maxsize);
        *maxsize = *maxsize * 2;
    }

    int i = *currentsize;
    myarray[i].fname = (char*)malloc(sizeof(char *) *10); //setting the size of fname.
    myarray[i].lname = (char*)malloc(sizeof(char *) *10); // seeting the size of lname.
    myarray[i].show = (char*)malloc(sizeof(char *) *20); // setting the size of show.

    /*if fname, lname, and show is equal to nothing, then program exits because no values are inputted or stored.*/
    if(myarray[i].fname == NULL || myarray[i].lname == NULL || myarray[i].show == NULL)
    {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    /*asks user to input a first name.*/
    printf("Enter the first name: ");
    scanf("%s", myarray[i].fname);

    /*asks user to input a last name.*/
    printf("Enter the last name: ");
    scanf("%s", myarray[i].lname);

    /*asks user to input show name.*/
    printf("Enter favorite show: ");
    scanf("%s", myarray[i].show);

    ++*currentsize; // iterates the currentsize pointer.

    return myarray;// returns the value of myarray to main.
}

/*function to display the records.*/
void display(record_t *myarray, int currentsize)
{
    printf("---------------------------------\n");
    for(int x = 0; x < currentsize; ++x)
    {
        printf("myarray[%d].fname = %s\n", x, myarray[x].fname); // displays the first name.
        printf("myarray[%d].lname = %s\n", x, myarray[x].lname);// displays the last name.
        printf("myarray[%d].show = %s\n", x, myarray[x].show);// displays the show.
        printf("\n");
    }
    printf("---------------------------------\n");
}

//function to double the size of the array
record_t *doubleIt(record_t *arr, int size)
{
    record_t *tarr = (record_t*) malloc(2 * size * sizeof(record_t)); //creating the varible *tarr that will hold double the size of *arr.
    
    if(arr == NULL)
    {
        /*if arr doesn't hold any values, then it ends the function.*/
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    for(int i = 0; i < size; i++)
    {
        tarr[i] = arr[i]; // copies arr value to tarr.
    }
    freeRecords(arr, size); // calls the freerecords function.
    free(arr); // free the arr value before getting lost.
    arr = NULL; // removes the arr value.

    return tarr; // returns tarr which holds the value arr held before NULL.
}

//function to remove a recored from index position
int removeRecord(record_t *arr, int size, int index)
{
    /*if index isn't greater than 0, then that's invalid index.*/
    if(index < 0 || index >= size)
    {
        printf("Invalid Index...\n");
        return size;// if invalid index, then return size to main.
    }

    /*allows the program to free the information before it gets lost.*/
    free(arr[index].fname);
    free(arr[index].lname);
    free(arr[index].show);

    /*removes the data stored at the first index and shifts over from the other indexes.*/
    for(int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return size - 1; // returns the size - 1 to main.
}

/*function to de-allocate memory of the records*/
void freeRecords(record_t *arr, int size)
{
    /*frees the infromation stored in a memory block.*/
    for(int i = 0; i < size; i++)
    {
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }
}