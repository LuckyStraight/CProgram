#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

//structure of record
typedef struct{
    char *fname;    //first name
    char *lname;    //last name
    char *show;     //favorite show
}record_t;

//function prototypes
record_t *createArray(int maxsize);
record_t *insert(record_t *myarray, int *maxsize, int *currectsize);
void display(record_t *myarray, int currectsize);
record_t *doubleIt(record_t *arr, int size);
int removeRecord(record_t *arr, int size, int index);
void freeRecords(record_t *arr, int size);

//main function
int main()
{
    int maxsize;
    printf("Enter a size for the dynamic array: ");
    scanf("%d", &maxsize);

    //create an array of maxsize from heap
    record_t *myarray = createArray(maxsize);

    int currentsize = 0;
    int option = -1;

    while(option != 0)
    {
        //display menu
        printf("What would you like to do?\n");
        printf("1. Insert a record\n");
        printf("2. Display records\n");
        printf("3. Remove record\n");
        printf("4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                //insert a record to the array
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                printf("Display was selected...\n");
                //display the recoreds
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                //remove a recored from index position
                currentsize = removeRecord(myarray, currentsize, index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
                break;

            default:
                printf("Invalid Selection...\n");
        }//end of switch
    }//end of while

    //deallocate memory of the records
    freeRecords(myarray, currentsize);
    //deallocate memory of the array
    free(myarray);
    myarray = NULL;

    return 0;
}

//function to create array of maxsize from heap
record_t *createArray(int maxsize)
{
    record_t *arr = (record_t*) malloc(maxsize * sizeof(record_t));
    if(arr == NULL)
    {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    return arr;
}

//function to insert a record
record_t *insert(record_t *myarray, int *maxsize, int *currectsize)
{
    if(*currectsize == *maxsize)
    {
        printf("Array is full.. Need to doubleIt...");
        myarray = doubleIt(myarray, *maxsize);
        *maxsize = *maxsize * 2;
    }
    int i = *currectsize;
    myarray[i].fname = (char*)malloc(10);
    myarray[i].lname = (char*)malloc(10);
    myarray[i].show = (char*)malloc(20);

    if(myarray[i].fname == NULL || myarray[i].lname == NULL || myarray[i].show == NULL)
    {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    printf("Enter the first name: ");
    scanf("%s", myarray[i].fname);
    printf("Enter the last name: ");
    scanf("%s", myarray[i].lname);
    getchar();
    printf("Enter favorite show: ");
    scanf("%[^\n]", myarray[i].show);

    ++*currectsize;

    return myarray;
}

//function to display the recoreds
void display(record_t *myarray, int currectsize)
{
    printf("---------------------------------\n");
    for(int x = 0; x < currectsize; ++x)
    {
        printf("myarray[%d].fname = %s\n", x, myarray[x].fname);
        printf("myarray[%d].lname = %s\n", x, myarray[x].lname);
        printf("myarray[%d].show = %s\n", x, myarray[x].show);
        printf("---------------------------------\n");
    }
}

//function to double the size of the array
record_t *doubleIt(record_t *arr, int size)
{
    record_t *tarr = (record_t*) malloc(2 * size * sizeof(record_t));
    if(arr == NULL)
    {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    for(int i=0; i<size; i++)
    {
        tarr[i] = arr[i];
    }
    freeRecords(arr, size);
    free(arr);
    arr = NULL;
    return tarr;
}

//function to remove a recored from index position
int removeRecord(record_t *arr, int size, int index)
{
    if(index<0 || index >= size)
    {
        printf("Invalid Index...\n");
        return  size;
    }

    free(arr[index].fname);
    free(arr[index].lname);
    free(arr[index].show);
    
    for(int i=index; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    return size - 1;
}

//function to deallocate memory of the records
void freeRecords(record_t *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }
}