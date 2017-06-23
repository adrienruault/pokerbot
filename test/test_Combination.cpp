/*
 * test_Combination.cpp
 *
 *  Created on: Jun 23, 2017
 *      Author: adrien
 */







#include "../src/Combination.hpp"





int main(int argc, char* argv[])
{
	std::set<Card> forbidden_cards;

	int nb_pulled_hands = 8;

	std::cout << "Pulled hands:\n";
	std::vector<Hand> vec_hand;
	for (int i=0; i < nb_pulled_hands; i++)
	{
		Hand current_hand(forbidden_cards);
		vec_hand.push_back(current_hand);
		std::cout << "no: " << i+1 << "->" << current_hand << "\n";
	}
	std::cout << "\n\n";


	Board board;
	for (int i=0; i < 4; i++)
	{
		std::cout << board << "\n";
		for (int j=0; j < nb_pulled_hands; j++)
		{
			Combination comb(vec_hand[j],board);
			std::cout << "no: " << j+1 << "->" << comb << "\n";
		}
		if (i < 3)
		{
			board.NextRound(forbidden_cards);
		}
		std::cout << "\n";
	}
	/*
	 * BE CAREFUL PROBLEM WHEN PULLING CARDS BECAUSE IT SEEMS THAT IT S IMPOSSIBLE TO GET TWICE THE SAME
	 * SUIT IN THE SAME HAND (SEE CONSTRUCTOR CARD(FORBIDDN_CARDS)
	 */

	return 0;
}
