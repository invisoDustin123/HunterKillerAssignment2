// Hunterkiller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;


int main()
{

	cout << "Generate Random enemy location on 8x8 grid...." << endl;
	srand(time(0));


	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	int targetLocationPredictionCounter = 0;
	bool targetFound = false;

	cout << "Begin search." << endl;

	while (targetFound == false)
	{
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		targetLocationPredictionCounter++;

		if (targetLocationPrediction > enemyLocation)
		{
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "Too high." << endl;

		}
		else if (targetLocationPrediction < enemyLocation)
		{
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "Too low." << endl;
		}
		else
		{
			cout << "Hunted and Killed after " << targetLocationPredictionCounter << " areas searched." << endl;
			targetFound = true;
		}
	}
	return 0;
}

