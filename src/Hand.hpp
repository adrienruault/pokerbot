/*
 * Hand.hpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */

#ifndef HAND_HPP_
#define HAND_HPP_


#include <vector>
#include "Card.hpp"


class Hand
{
private:
	std::vector<Card> mhand;

public:
	// Default constructor that initializes a hand made of two empty cards (0,0)
	Hand();
	Hand(const Card& card1, const Card& card2);
	Hand(int rank_card1, int suit_card1, int rank_card2, int suit_card2);

	// Constructor that initializes a hand with two cards pulled randomly. It accounts
	// for the list of forbidden cards provided as input.
	// Note that the set of forbidden cards is passed by reference and is modified
	// according to the cards that are pulled to serve the hand
	Hand(std::set<Card>& forbidden_cards);

	// Redistribute 2 new cards to the hand, accounting for the forbidden set of cards
	// that is provided as input.
	// Note that the set of forbidden cards is passed by reference and is modified
	// according to the cards that are pulled to serve the hand
	void PullRandomHand(std::set<Card>& forbidden_cards);

	// Return the card with index 0 or 1
	Card GetCard(const int& index);

	friend std::ostream& operator<< (std::ostream& out, const Hand& hand_to_print);
};










#endif /* HAND_HPP_ */
