/*
 * card.hpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */

#ifndef SRC_CARD_HPP_
#define SRC_CARD_HPP_

#include <iostream>
#include <set>


/*
 * Class that represents one of the 52 cards of a Texas Hold'em card game.
 * The Card class is characterized by 2 attributes: mrank and mcolor.
 *
 * mrank is a number comprised between 1 and 13 included and stores the rank of the
 * card according to the following conversion table: (mrank -> card rank)
 * 		1 -> 2 / 2 -> 3 / 3 -> 4 / 4 -> 5 / 5 -> 6 / 6 -> 7 / 7 -> 8 / 8 -> 9 / 9 -> 10 /
 * 		10 -> J / 11 -> Q / 12 -> K / 13 -> A
 *
 * msuit is a number comprised between 1 and 4 included and stores the suit of the card
 * according to the following conversion table: (msuit -> card suit)
 * 		1 -> Club (Trèfle) / 2 -> Diamond (Carreau) / 3 -> Heart (Coeur) /
 * 		4 -> Spade (Pique)
 *
 * For the sake of clarity, Cards objects are related through the following notation
 * convention in the rest of the documentation: (mrank, msuit).
 *
 * Note that an undefined card is refered as (0,0).
 */
class Card
{

private:
	int mrank;
	int msuit;

public:
	// Default constructor that initializes an empty card (0,0)
	Card();

	// Constructor that initializes a card using a random generator and takes as input a
	// list of forbidden cards.
	Card(const std::set<Card>& forbidden_cards);

	int GetRank() const;
	int GetSuit() const;

	void SetRank(const int& new_rank);
	void SetSuit(const int& new_suit);
	void SetCard(const int& new_rank, const int& new_suit);

	// Update the attributes of the Card object by pulling random cards and accounting
	// for the forbidden cards.
	void PullRandom(const std::set<Card>& forbidden_cards);

	// Overriding f the less than equal operator in order to make the std::set::find method
	// working
	bool operator< (const Card& right_card) const;

	friend std::ostream& operator<< (std::ostream &out, const Card& card_to_print);



};



#endif /* SRC_CARD_HPP_ */
