#include "pch.h" // Why do you bother me? I don't need a precompiled class that does nothing more than annoy me to the end.
#include <iostream>
#include <string>
#include "FBullCowGame.h"
using namespace std;

// Substituion of types to make C++ more Unreal like
using FText = string;

constexpr int WORD_LENGTH = 9;
FBullCowGame BCGame;

void printIntro();
void playGame();
bool willPlayAgain();
FText getGuess();

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
	int temp = BCGame.GetMaxTries();
	while (temp > 0)
	{

		FText guess = getGuess();
		cout << endl;
		if (BCGame.IsGuessValid(guess))
		{
			cout << "Your guess is : " << guess;
			BCGame.IncrementTry();
			temp--;
		}
		else
		{
			cout << "\nYour guess is not a valid isogram. Please check before entering.\n";
		}
	}
}

/*
This method takes a FText input and only accepts a Yes or a No
Why did I make it so complex? No one knows.
This could have been made far simpler by just checking for Y or by only taking a single character.
*/
bool willPlayAgain()
{
	FText response;
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
	BCGame.Reset();
	cout << "\nWelcome to Bulls and Cows\n";
	cout << "\nCan you think of " << WORD_LENGTH << " letter isogram I am thinking of?\n";
}

FText getGuess()
{
	FText Guess = "";

	// This entire system is utterly unnecessary but cool.
	if (BCGame.GetCurrentTry() == 1)
	{
		cout << "\nEnter your " << BCGame.GetCurrentTry() << "st guess: ";
	}
	else if (BCGame.GetCurrentTry() == 2)
	{
		cout << "\nEnter your " << BCGame.GetCurrentTry() << "nd guess: ";
	}
	else if (BCGame.GetCurrentTry() == 3)
	{
		cout << "\nEnter your " << BCGame.GetCurrentTry() << "rd guess: ";
	}
	else
	{
		cout << "\nEnter your " << BCGame.GetCurrentTry() << "th guess: ";
	}
	getline(cin, Guess); // TODO: Check validity of the guess, and only return valid guesses
	return Guess;
}