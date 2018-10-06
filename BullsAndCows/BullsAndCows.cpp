#include "pch.h" // Why do you bother me? I don't need a precompiled class that does nothing more than annoy me to the end.
#include <iostream>
#include <string>
using namespace std;

constexpr int WORD_LENGTH = 9;
const int NUMBER_OF_TURNS = 5;

void printIntro();
void playGame();
bool willPlayAgain();
string getGuess();

int main()
{
	do
	{
		printIntro();
		playGame();
	} while (willPlayAgain());
	cout << endl;
	return 0;
}

void playGame()
{
	int temp = NUMBER_OF_TURNS;
	while (temp > 0)
	{
		cout << "\nYour guess is : " << getGuess();
		cout << endl;
		temp--;
	}
}

/*
This method takes a string input and only accepts a Yes or a No
Why did I make it so complex? No one knows.
This could have been made far simpler by just checking for Y or by only taking a single character.
*/
bool willPlayAgain()
{
	string response;
	cout << "\nDo you want to play again? (Y/N)\n";
	getline(cin, response);
	if (response[0] == 'Y' || response[0] == 'y')
		return true;
	else if (response[0] == 'N' || response[0] == 'n')
		return false;
	else
	{
		cout << "\nPlease enter either Yes or No.\n";
		return willPlayAgain();
	}
}

void printIntro()
{
	// system("cls"); is used to clear the console window. This is windows specific and works with the Command prompt. In linux the command and code will be different.
	system("cls");
	cout << "\nWelcome to Bulls and Cows\n";
	cout << "\nCan you think of " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	
}

string getGuess()
{
	string Guess = "";
	cout << "\nEnter your guess: ";
	getline(cin, Guess);
	return Guess;
}