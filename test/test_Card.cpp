/*
 * adrien.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */




#include <iostream>
#include "../src/Card.hpp"
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

	std::cout << "Checking that the Error.h works fine:\n";
	try
	{
		std::cout << "Challenging with a card (14,3),\n";
		std::cout << "a rank of 14 is supposed to not be allowed:\n";
		Card card3(14,3);
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		std::cout << "Challenging with a card (8,0),\na suit of 0 is not supposed to be allowed:\n";
		Card card4(8,0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		std::cout << "Challenging with a card (0,5),\n";
		std::cout << "a rank of 0 and a suit of 5 are not supposed to be allowed:\n";
		Card card4(0,5);
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}


	std::set<Card> forbidden_cards;
	Card random_card1(forbidden_cards);
	Card random_card2;
	random_card2.PullRandom(forbidden_cards);
	std::cout << "\nTwo different random cards are pulled:\n";
	std::cout << "random_card1 is: " << random_card1 << "\n";
	std::cout << "random_card2 is: " << random_card2 << "\n";


	// Expectation calculations

	// We pull 1e6 cards independently
	int rank_sum=0;
	int suit_sum=0;
	int nb_cards_pulled=1000000;
	for(int i=0; i<nb_cards_pulled; i++)
	{
		Card card_exp(forbidden_cards);
		rank_sum+=card_exp.GetRank();
		suit_sum+=card_exp.GetSuit();
	}
	double rank_av=(double)rank_sum / (double)nb_cards_pulled;
	double suit_av=(double)suit_sum / (double)nb_cards_pulled;

	std::cout << "\n" << nb_cards_pulled << " have been pulled:\n";
	std::cout << "The rank average is supposed to be 7 and it is: " << rank_av << "\n";
	std::cout << "The suit average is supposed to be 2.5 and it is: " << suit_av << "\n";


	// Test of the less than operator<
	Card c1(5,2);


	return 0;
}


