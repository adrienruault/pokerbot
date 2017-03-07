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
// Note that the set of forbidden cards is passed by reference and is modified
// according to the cards that are pulled to serve the hand
Hand::Hand(std::set<Card>& forbidden_cards)
{
	// Pulling the first card of the hand
	Card card1(forbidden_cards);

	// Adding the last pulled card to the forbidden set of cards
	forbidden_cards.insert(card1);

	// Pulling the second card
	Card card2(forbidden_cards);

	// Adding the last pulled card to the forbidden set of cards
	forbidden_cards.insert(card2);

	if (card1<card2)
	{
		mhand.push_back(card1);
		mhand.push_back(card2);
	}
	else
	{
		mhand.push_back(card2);
		mhand.push_back(card1);
	}


}



// Redistribute 2 new cards to the hand, accounting for the forbidden set of cards
// that is provided as input.
void Hand::PullRandom(std::set<Card>& forbidden_cards)
{
	// Pulling the first card of the hand
	Card card1(forbidden_cards);

	// Adding the last pulled card to the forbidden set of cards
	forbidden_cards.insert(card1);

	// Pulling the second card
	Card card2(forbidden_cards);

	// Adding the last pulled card to the forbidden set of cards
	forbidden_cards.insert(card2);



	if (card1<card2)
	{
		mhand[0]=card1;
		mhand[1]=card2;
	}
	else
	{
		mhand[0]=card2;
		mhand[1]=card1;
	}
}


// Print a hand of 2 cards using the following formalism:
// 		[(rank1,suit1) , (rank2,suit2)]
std::ostream& operator<< (std::ostream& out, const Hand& hand_to_print)
{
	out << "[" << hand_to_print.mhand[0] << " , " << hand_to_print.mhand[1] << "]";
	return out;
}




