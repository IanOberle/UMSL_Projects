/*Created by: Ian Oberle
Started on: 11/10/16
Completed on: 11/10/16
Submitted on:11/12/16
Due on:11/18/16
*/
// This program plays "Rock, Paper, Scissors" with a user and the computer
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//Function Prototypes
int userChoice();
int computerChoice();
void playGame();

//Plays a game of "Rock, Paper, Scissors" till the user decides to quit
//Also displays score for user, computer, and stalemates
int main()
{
	char again;
	unsigned seed = time(0);
	srand(seed);
	do //Creates a loop to play the game as long as the user wants
	{
		system("CLS");
		playGame();
		cout << "\nWould you like to play again? (Y/N)\n";
		cin >> again;
	} while (toupper(again) == 'Y');
	if (toupper(again) != 'Y')
		cout << "\nThank you for playing.\nHave a good day.\n";
	system("pause");
}

//Creates and checks for valid user input
int userChoice()
{
	string object;
	int player_choice;
	bool check_choice = false;

	cout << "Enter your choice";
	cout << "\n1.\tRock\n2.\tPaper\n3.\tScissors\n";
	cin >> player_choice;
	
	if (player_choice > 3 || player_choice < 1)
	{
		while (check_choice == false)
		{
			cout << "Your choice is invalid.\n";
			cout << "Choose 1, 2, or 3.\n";
			cout << "Please choose again.\n";
			cin >> player_choice;
			if (player_choice <= 3 && player_choice >= 0)
				check_choice = true;
		}
	}
	
	if (player_choice == 1)
		object = "Rock";
	else if (player_choice == 2)
		object = "Paper";
	else 
		object = "Scissors";
	
	cout << "\nYou have selected " << player_choice << "'" << object << "'" << endl;
	return player_choice;
}

//Creates the computers input
int computerChoice()
{
	string object;
	int computer_choice;
	
	computer_choice = (1 + (rand() % 3));
	if (computer_choice == 1)
		object = "Rock";
	else if (computer_choice == 2)
		object = "Paper";
	else 
		object = "Scissors";
	cout << "\nThe computer has selected " << computer_choice << "'" << object << "'" << endl;
	return computer_choice;
}

//Compares values from user input and computer input and determines a winner.
void playGame()
{
	int player_choice = userChoice();
	int computer_choice = computerChoice();
	static int playerWin = 0, computerWin = 0, stalemate = 0;

	if ((player_choice == 1 && computer_choice == 3) || 
		(player_choice == 2 && computer_choice == 1) || 
		(player_choice == 3 && computer_choice == 2))
	{
		cout << "\nPlayer is  victorious!";
		playerWin++;
	}
	if ((player_choice == 1 && computer_choice == 2) ||
		(player_choice == 2 && computer_choice == 3) ||
		(player_choice == 3 && computer_choice == 1))
	{
		cout << "\nThe computer has defeated the Player!";
		computerWin++;
	}
	if ((player_choice == 1 && computer_choice == 1) ||
		(player_choice == 2 && computer_choice == 2) ||
		(player_choice == 3 && computer_choice == 3))
	{
		cout << "\nThe game ends in a draw.";
		stalemate++;
	}
	cout << "\nThe player has won " << playerWin << " times.\n";
	cout << "The computer has won " << computerWin << " times.\n";
	cout << "There have been " << stalemate << " stalemates.\n";
}