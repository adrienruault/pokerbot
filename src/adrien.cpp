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

	Card card1;
	Card card2;

	int rank;
	rank=card1.GetRank();

	card1.PullRandom(forb);
	card2.PullRandom(forb);

	std::cout << "card1 is: " << card1 << "\n";
	std::cout << "card2 is: " << card2 << "\n";


	return 0;
}


