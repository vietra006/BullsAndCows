#include "pch.h" // Why do you bother me? I don't need a precompiled class that does nothing more than annoy me to the end.
#include <iostream>
#include <string>
using namespace std;

constexpr int WORD_LENGTH = 9;
int NUMBER_OF_TURNS = 5;

void printInfo();
void playGame();
string getGuess();

int main()
{
	printInfo();
	// Debugging code. Will be removed later
	playGame();
	cout << endl;
	return 0;
}

void playGame()
{
	while (NUMBER_OF_TURNS > 0)
	{
		cout << "\nYour guess is : " << getGuess();
		cout << endl;
		NUMBER_OF_TURNS--;
	}
}

void printInfo()
{
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