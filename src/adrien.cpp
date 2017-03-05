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


	return 0;
}


