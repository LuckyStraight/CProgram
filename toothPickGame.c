//COP3223C 
//Large Program 1

#define ROUNDS 3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
int playRound(int round); //play one round
int humanPick(); //retrieve the user's guess
int computerPick(int choice, int leftover); //computer makes its pick
int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
void winnerAnnouncment(int user); //overall winner of round announcement

int main()
{
	greeting();//insert some code here that will greet the user
	for(int x = 0; x < ROUNDS; ++x)
	{
		int result = playRound(x + 1); //call playRound and assign result the value function returns

		winnerAnnouncment(result); // calls the function to display the winner for 3 rounds.
	
	}
	

	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;
}

void greeting() //greets the user with the rules of the game.
{
    printf("********************************************************\n");
	printf("Welcome to toothpick Game!\n");
	printf("Here are the rules.\n");
	printf("There are currently 31 toothpicks on the table.\n");
	printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
	printf("The player that gets to pick the last toothpicks loses the game!\n");
	printf("Sound easy right? Well lets see if you can beat me!\n");
	printf("Ready to play?... Here we go!\n");
	printf("********************************************************\n");
}



int leftOnTable(int toothpicks, int taken)

{
    int leftover = toothpicks - taken; //subtracting the toothpicks with the number the user chose.

	return leftover;// sends the value to playround function.

}

int humanPick() //function allows the user to choose the amount of toothpicks.
{
	int humanpicks;
	printf("How many toothpicks are you going to take off the table? 1, 2, or 3?:");
	scanf("%d", &humanpicks);
	

	return humanpicks;// sends value to playround function.
	
}

int computerPick(int choice, int leftover)
{
	int picks;

	if(leftover >= 4) //subtracts the amount of toothpicks the user chose for the computer to make its choice.
		picks = 4 - choice;
	else if(leftover == 2)// if 2 then the computer chooses 1
		picks = 1;
	else if(leftover == 3)// if 3 then the computer chooses 2
		picks = 2;
	else if(leftover == 4)// if 4 then the computer chooses 3
		picks = 3;
	else
		picks = 1;// if 1 then the computer chooses 1

	return picks;// sends then the value to playround function.


}

int playRound(int round)
{
	printf("Welcome to round %d!\n", round);
	printf("You may go first!\n");
	
	int toothpicks = 31; //number of toothpicks to start with
	
	//loop that keeps track of toothpicks until respective no more toothpicks left. we will learn about conditional loops soon :)
	
	while(toothpicks != 0)// ends round when toothpicks left on table is 0.
	{

		int humanpicks = humanPick();// calls the humanPick function then assign value to humanpicks.
		if(humanpicks == 1 || humanpicks == 2 || humanpicks == 3) // restricts user from entering a higher value than 3 and no negatives.
			{
				printf("Okay... you took %d off the table.\n", humanpicks);// prints the value the user chose.
				printf("making my decision...\n");

				int leftontable = leftOnTable(toothpicks, humanpicks);// calls LeftOnTable function then assign value to leftontable.
				toothpicks = leftontable;
				printf("There are %d toothpick(s) left!\n", leftontable);// shows the amount of toothpicks after the user chose.
				if(leftontable == 1)// if there is one toothpick left on the table and computerpicks then user wins.
				{
					return 1;// sends the user winning value to winnerAnnouncment function.
				}

				int computerPicks = computerPick(humanpicks, leftontable);// calls computerPick function then assign value to computerPicks.
				printf("I am taking %d toothpick(s) off the table.\n", computerPicks); //computer makes the choice on how much toothpicks to pick.
				if (leftontable == 0)// if the user picks the last toothpick on the table then computer wins.
				{
					return 0;// sends the computer winning value to winnerAnnouncment function.
				}
				

				leftontable = leftOnTable(toothpicks, computerPicks);
				toothpicks = leftontable;
				printf("There are %d toothpick(s) left!\n", leftontable);// shows the amount of toothpicks left after computer picks.
			}
		
	}
	

}

void winnerAnnouncment(int user)
{
	if(user == 1)// if the value returned is 1 then the user wins.
	{
		printf("You won! I Will Get You Next Time!.\n");
		printf("********************************************************\n"); 
	}
	else// if the value is 0 then the computer wins.
	{
		printf("I won! Better Luck Next Time.\n");
		printf("********************************************************\n");
	}

}