// COP3223 Section 1
// Large Program 3

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXGUESS 6 // allows only 6 guesses from user.
#define SIZE 20 //size of string is 20.

//function prototypes
void rules (void); //display rules of the game
void maskWord (char starword[], int size); //mask the word with stars to display
int playRound (char starword[], char answer[]); //play a round of hangman
int occurancesInWord (char userguess, char answer[]); //number of times a letter occurs in a word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective *
void playAgain (int *play); //ask user if they want to play again. 1 is yes 2 is no

int main()
{
	rules();
	
	FILE *wordgame = fopen ("words.txt", "r"); //wordgame pointer opens the word.txt file
	int play = 0;

	/*creating and initializing strings for answer and starword*/
	char answer[SIZE]; 
	char starword[SIZE];
	
	while(play != 2) //while the  player is choosing to play, the game will run
	{
		fscanf(wordgame, "%s", answer); //scanning the document for a word
		strcpy(starword, answer); //copying the string for starword into answer
		int size = sizeof(starword); // checking the size of starword and stores it into size

		maskWord(starword, size); //calling on maskWord function to hide it 
	
		int x = playRound (starword, answer); //storing playRound in X value
		/*if the user loses the game, x is equal to 0*/
		if(x == 0)
		{
			printf("\n");
			printf("You didn't Win!!. Try Again Next Time!\n");
			printf("The word was %s.\n", answer);
			printf("************************************************************************\n");
		}
		/*if the user wins the game, x is equal to 1*/
		else if(x == 1)
		{
			printf("\n");
			printf("Congratulations! You won!");
			printf("The word was %s.\n", answer);
			printf("************************************************************************\n");
		}
		/*asking user if they would like to play another round*/ 
		printf("Would you like to play another round?\n");
		printf("1. Yes\n");
		printf("2. No\n");

		/*Ask user for choice input.*/
		printf("Choice: "); 
		scanf("%d", &play);

		playAgain(&play); //calling the playAgain function 
	}
	
	fclose(wordgame); //closes the word.txt file

	return 0;
}

/*1st user-defined function to display the rules of the game*/
void rules(void)
{
	printf("Welcome to the Hangman Game!\n");
	printf("************************************************************************\n");
	printf("Here are the rules.\n");
	printf("I will provide you a set of * characters for each round.\n");
	printf("Each * represents a letter in the English Alphabet.\n");
	printf("You must figure out each letter of the missing word.\n");
	printf("For every correct letter guessed, I will reveal its place in the word.\n");
	printf("Each mistake will result in a strike.\n");
	printf("6 strikes will result in a loss that round.\n");
	printf("Are you ready? Here we go!\n");
	printf("************************************************************************\n");
}

/*2nd user-defined function, masks the words with * as they are displayed*/
void maskWord(char starword[], int size)
{
	for (int x = 0; starword[x] != '\0'; ++x) //for loop scanning the string
	{
		starword[x] = '*'; //replacing the letters in the word with *
	}
}

/*3rd user-defined function, allows user to play at least one round of hangman*/
int playRound(char starword[], char answer[])
{
	int letters = strlen(answer); //stores the length of answer in letters.
	int strikes = 0;
	int z = 0; //counter variable for the guesses string.  
	char guess;
	char guesses[SIZE]; //initialize the string that will hold all of the user's guesses
	
	guesses[z] = '\0'; // set the first element as the null character.
	
	
	printf("Welcome to the Round!\n");
	printf("The word has %d letters in it.\n\n", letters); //tell the user the size of the word.
	while(strikes < MAXGUESS) //loop will run until the user gets to 6 strikes or until they get the word right.
	{
		printf("You currently have %d strike(s).\n", strikes); // keeps track of the strikes the user has for each round.
		printf("Letter(s) you have guessed: %s", guesses); // allows user to know what letter they have already guessed
		printf("\n\n");
		printf("%s\n", starword);
		printf("\n");

		/*asks the user for guess input*/
		printf("Enter your guess: "); 
		scanf(" %c", &guess);
		printf("************************************************************************\n");

		if(isalpha(guess)) //checks to see if the user input was a letter.
		{
			guess = tolower(guess); //converts the uppercase letters in the guess to lowercase.
			guesses[z] = guess;
			z = z + 1;
			guesses[z] = '\0';

			if(occurancesInWord(guess, answer) == 1) // if the guessed letter is in the word then the if statement runs.
			{
				printf("\n");
				printf("The letter %c is in the word.\n\n", guess); // the user is told that their guess was in the word.
				updateStarWord(starword, answer, guess); // the star string is updated.
			}
			else if(occurancesInWord(guess, answer) == 0) // if the guessed letter is not in the word then the else if runs.
			{
				printf("\n");
				printf("The letter %c is NOT in the word.\n\n", guess); // the user is told that their guess was incorrect
				strikes = strikes + 1; // the strikes variable is incremented by 1.
			}
		
		if(strcmp(starword, answer) == 0) // if the user gets the correct word, then 1 is returned.
			return 1;
		}
		
		else // if the user did not enter a letter, they are shown a message that they did not enter a letter.
		{
			printf("\n");
			printf("You did not enter a letter from the alphabet.\n\n");
		}
	}
	return 0;
}

/*4th user-defined function, sees how many times a letter is repeated in a string*/
int occurancesInWord(char userguess, char answer[])
{
	/*for loop scans answer string to see multiple letters in a word*/
	for(int x = 0; answer[x] != '\0'; ++x)
	{
		if(answer[x] == userguess)
			return 1;
	}
	return 0;
}

/*5th user-defined function, replaces the respective * with the letter found in the word*/
void updateStarWord(char starword[], char answer[], char userguess)
{
	/*for loop that scans the answer string*/
	for(int x = 0; answer[x] != '\0'; ++x)
	{
		//if the user guess is equal to a letter in the answer, it will be replaced with the appropriate letter
		if(answer[x] == userguess) 
		{
			starword[x] = userguess;
		}
	}
}

/*6th user-defined function, asks user to decide if they want to play again*/
void playAgain(int *play)
{
	printf("************************************************************************\n");
	if(*play == 2) // if option 2 was chosen then it ends the game.
	{
		printf ("Thank you for playing!\n");
		printf ("\n");
	}
}
