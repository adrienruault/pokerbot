/*
 * test_Board.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: ruault
 */





#include "../src/Board.hpp"





int main(int argc, char* argv[])
{
	// Declaration of a seed for the generation of random numbers
	srand(time(NULL));


	Board board1;
	std::set<Card> forb;

	std::cout << board1 << "\n\n";

	for (int i=0; i<4; i++)
	{
		if (i==3)
		{
			std::cout << "\nNow we are trying to go further than the river to challenge the code:\n";
		}
		try
		{
			board1.NextRound(forb);
			std::cout << board1 << "\n\n";
		}
		catch(std::exception& e)
		{
			std::cerr << e.what();
		}
	}


	std::cout << "\n\n\n\t Call of the BringBackToPreFlop method of Board\n\n\n";


	board1.BringBackToPreFlop(forb);

	std::cout << board1 << "\n\n";

	for (int i=0; i<4; i++)
	{
		if (i==3)
		{
			std::cout << "\nNow we are trying to go further than the river to challenge the code:\n";
		}
		try
		{
			board1.NextRound(forb);
			std::cout << board1 << "\n\n";
		}
		catch(std::exception& e)
		{
			std::cerr << e.what();
		}
	}


}



