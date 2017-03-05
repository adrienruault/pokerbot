/*
 * adrien.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */




#include <iostream>
#include "Card.hpp"
#include <stdlib.h>
#include <time.h>


/*
 * Test function that checks the main functionalities of the Card class.
 * It should output the following:
 * 	The rank assigned to the card is not allowed, out of the interval [1,13]
 *	The suit assigned to the card is not allowed, out of the interval [1,4]
 *	random_card1 is: (~4,~2)
 *	random_card2 is: (~10,~3)
 *	The rank average is: 6.99843
 *	The suit average is: 2.49944
 *
 */
int main(int argc, char* argv[])
{

	// Declaration of a seed for the generation of random numbers
	srand(time(NULL));

	std::set<Card> forb;

	Card random_card1(forb);

	Card random_card2;
	random_card2.PullRandom(forb);

	try
	{
		Card card3(14,3);
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		Card card4(8,0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}


	std::cout << "random_card1 is: " << random_card1 << "\n";
	std::cout << "random_card2 is: " << random_card2 << "\n";


	// Expectation calculations

	// We pull 1e6 cards independently
	int rank_sum=0;
	int suit_sum=0;
	int n_pull=1000000;
	for(int i=0; i<n_pull; i++)
	{
		Card card_exp(forb);
		rank_sum+=card_exp.GetRank();
		suit_sum+=card_exp.GetSuit();
	}
	double rank_av=(double)rank_sum / (double)n_pull;
	double suit_av=(double)suit_sum / (double)n_pull;

	std::cout << "The rank average is: " << rank_av << "\n";
	std::cout << "The suit average is: " << suit_av << "\n";


	// Test of the less than operator<
	Card c1(5,2);


	return 0;
}


