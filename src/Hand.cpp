/*
 * Hand.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */



#include "Hand.hpp"




// Default constructor that initializes a hand made of two empty cards (0,0)
Hand::Hand()
{
	Card empty_card;
	mhand.push_back(empty_card);
	mhand.push_back(empty_card);
}



// Constructor that initializes a hand with two cards pulled randomly. It accounts
// for the list of forbidden cards provided as input.
Hand::Hand(const std::set& forbidden_cards)
{
	// Pulling the first card of the hand
	Card card1(forbidden_cards);

	// Adding the last pulled card to the forbidden set of cards
	forbidden_cards.insert(card1);

	// Pulling the second card
	Card card2(forbidden_cards);

	mhand.push_back(card1);
	mhand.push_back(card2);
}



// Print a hand of 2 cards using the following formalism:
// 		[(rank1,suit1) , (rank2,suit2)]
std::ostream& operator<< (std::ostream& out, const Hand& hand_to_print)
{
	out << "[" << hand_to_print.mhand[0] << " , " << hand_to_print.mhand[1] << "]";
	return out;
}




