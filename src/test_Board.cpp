/*
 * test_Board.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: ruault
 */





#include "Board.hpp"





int main(int argc, char* argv[])
{
	Board board1;
	std::set<Card> forb;

	std::cout << board1 << "\n";

	for (int i=0; i<4; i++)
	{
		try
		{
			board1.NextRound(forb);
			std::cout << board1 << "\n";
		}
		catch(std::exception& e)
		{
			std::cerr << e.what();
		}
	}




}



