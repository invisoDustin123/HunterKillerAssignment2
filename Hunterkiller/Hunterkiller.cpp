// Hunterkiller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;



int main()
{

	cout << "Generate Random enemy location on 8x8 grid...." << endl;
	srand(time(0));


	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	int BinaryPredictionCounter = 0;
	int LinearPredictionCounter = 0;
	int RandomPredictionCounter = 0;
	int PlayerPredictionCounter = 0;
	int LinearPrediction = 0;
	int PlayerPrediction = 0;
	int BinaryPrediction = 0;
	int RandomPrediction = 0;
	int turns = 0;
	bool targetFound = false;

	//game loops while the target isn't found
	while (!targetFound) {

		//using switch to iterate through turns
		switch (turns) {
		case 0:
			//Binary AI
			if (!targetFound) {
				//Does a binary search to find the enemy
				cout << "Begin binary search." << endl;

				BinaryPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

				BinaryPredictionCounter++;

				if (BinaryPrediction > enemyLocation)
				{
					searchGridHighNumber = BinaryPrediction - 1;
				}
				else if (BinaryPrediction < enemyLocation)
				{
					searchGridLowNumber = BinaryPrediction + 1;
				}
				else
				{
					cout << "Hunted and Killed after " << BinaryPredictionCounter << " areas searched by Binary AI." << endl;
					targetFound = true;
				}
			}
			break;
		case 1:
			//Linear AI
			if (!targetFound) {
				//Always guesses counting by 1 starting at 1
				cout << "Begin linear search." << endl;

				LinearPrediction++;

				LinearPredictionCounter++;

				if (LinearPrediction == enemyLocation) {
					cout << "Hunted and Killed after " << LinearPredictionCounter << " areas searched by Linear AI" << endl;
					targetFound = true;
				}
			}
			break;
		case 2:
			//Random AI
			if (!targetFound) {
				//Makes a random guess
				cout << "Begin random search." << endl;

				RandomPrediction = rand() % 64 + 1;

				RandomPredictionCounter++;

				if (RandomPrediction == enemyLocation) {
					cout << "Hunted and Killed after " << RandomPredictionCounter << " areas searched by Random AI" << endl;
					targetFound = true;
				}
			}
			break;
		case 3:
			//Player
			if (!targetFound) {
				//Gets a guess from a player and gives them hints if incorrect
				PlayerPredictionCounter++;

				cout << "Your turn, make your guess." << endl;

				cin >> PlayerPrediction;

				if (PlayerPrediction > enemyLocation) {
					cout << "Too High." << endl;
				}
				else if (PlayerPrediction < enemyLocation) {
					cout << "Too Low." << endl;
				}
				else {
					cout << "You found it after " << PlayerPredictionCounter << " areas searched." << endl;
					targetFound = true;
				}
			}
			break;
			
		}
		//after the turn is finished, increments turn variable which is checked by switch and used to determine next turn
		turns++;
		if (turns > 3) {
			turns = 0;
		}
	}






	return 0;
}

