//COP3223C Section 1
//Small Program 6

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

/*user defined functions.*/
void meanMinMax(int arr[]);
void mySort(int arr[]);
void doubleShift(int arr[]);
void reverse(int arr[]);
void display(int arr[]);

int main(void)
{
	int arr[SIZE];

	/*Asks user to enter a number what seed they want.*/
	int seed;
	printf("Enter a seed: "); 
	scanf("%d", &seed);
	srand(seed); //randomizes the seed.
	
	//generate numbers for the array.
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}
	
	//calls the functions to run in main.
	meanMinMax(arr);
	printf("\n");
	mySort(arr);
	display(arr);
	doubleShift(arr);
	display(arr);
	reverse(arr);
	display(arr);
	
	return 0;
}

void meanMinMax(int arr[])
{
	int min, max, total = 0;
	double average; //could define it as a double as well.

	min = max = arr[0]; // assigning the min and max to the arr.


	for(int x = 0; x < SIZE; x++)
	{
		total = total + arr[x]; //updates total to have a new value for the average calculation.
		
		if(arr[x] < min) //allows the computer to sort which is the minimum value.
		{
			min = arr[x];
		}
		if(arr[x] > max) //allows the computer to sort which is the maximum value.
		{
			max = arr[x];
		}

	}

	average = (double)total / SIZE; // calculates the average.

	/*prints the values of the min, max, and average.*/
	printf("Average: %f\n", average);
	printf("Max: %d\n", max);
	printf("Min: %d\n", min);


}

void mySort(int arr[])
{
	int x, y, yolo; // defining the variables as integers.

	for(x = 0; x < SIZE; x++) 
	{
		for(y = 0; y < SIZE - 1; y++) // allows the values to sort through the values numerically
		{
			if(arr[y] > arr[y + 1])
			{
				/*Swaps the arr[y] with the arr[y+1]*/
				yolo = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = yolo;
			}
		}
	}
}

void doubleShift(int arr[])
{
	int last = arr[SIZE - 1]; // decide what the last value is going to be.
	int secLast = arr[SIZE - 2]; // decides what the second to last value is going to be.

/*The loop allows a double shift to happen for each of the values.*/
	for(int z = SIZE - 1; z -2 >= 0; z--)
	{
		arr[z] = arr[z - 2];
	}

	arr[0] = secLast;
	arr[1] = last; 
}

void reverse(int arr[])
{

	for(int r = 0; r < SIZE / 2; r++) // if r gets greater than the size then the  reverse loop will stop.
	{
		/*Allows the values to move backwards without the values overlapping eachother (also known as swap values).*/
		int swap = arr[r];
		arr[r] = arr[SIZE - r - 1];
		arr[SIZE - r - 1] = swap;
	}
}

void display(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}