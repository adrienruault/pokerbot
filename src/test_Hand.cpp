/*
 * test_Hand.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */



#include "Hand.hpp"


int main(int argc, char* argv[])
{
	// Declaration of a seed for the generation of random numbers
	srand(time(NULL));

	std::set<Card> forb;

	// Generation of 10 hands that are printed on the command line
	// Note that the hands are not independents. Therefore there souldn't be twice the
	// same card distributed
	Hand H;
	std::cout << "Empty hand made of 2 empty cards:\n";
	std::cout << H << "\n\n";

	std::cout << "10 hands pulled in a row\n";
	for(int i=0; i<10; i++)
	{
		H.PullRandom(forb);
		std::cout << H << "\n";
	}

	return 0;
}






