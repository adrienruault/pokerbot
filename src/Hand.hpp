/*
 * Hand.hpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */

#ifndef HAND_HPP_
#define HAND_HPP_

#include <iostream>
#include <set>
#include <vector>
#include "Card.hpp"


class Hand
{
private:
	std::vector<Card> mhand;

public:
	// Default constructor that initializes a hand made of two empty cards (0,0)
	Hand();

	// Constructor that initializes a hand with two cards pulled randomly. It accounts
	// for the list of forbidden cards provided as input.
	Hand(const std::set& forbidden_cards);

	friend std::ostream& operator<< (std::ostream& out, const Hand& hand_to_print);

};










#endif /* HAND_HPP_ */
