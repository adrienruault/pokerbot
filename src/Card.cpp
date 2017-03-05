/*
 * card.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */


#include "Card.hpp"
#include <stdlib.h>
#include <time.h>




// Default constructor that initializes an empty card (0,0)
Card::Card()
{
	mrank=0;
	msuit=0;
}



// Constructor that initializes a card using a random generator and takes as input a
// list of forbidden cards.
Card::Card(const std::set<Card>& forbidden_cards)
{
	// Pull random rank number [1,13]
	mrank = rand() % 13 + 1;

	// Pull random suit number [1,4]
	msuit = rand() % 4 + 1;

	// while loop to check that the random card that has just been pulled does not
	// belong to the forbidden list
	while (forbidden_cards.find(*this) != forbidden_cards.end())
	{
		// If we enter the loop it means that a forbidden card has been pulled.
		// Therefore another one has to be pulled until an allowed card is pulled.

		// Pull random rank number [1,13]
		mrank = rand() % 13 + 1;

		// Pull random suit number [1,4]
		msuit = rand() % 4 + 1;
	}
}



int Card::GetRank() const
{
	return mrank;
}



int Card::GetSuit() const
{
	return msuit;
}



void Card::SetRank(const int& new_rank)
{
	mrank=new_rank;
}



void Card::SetSuit(const int& new_suit)
{
	msuit=new_suit;
}



void Card::SetCard(const int& new_rank, const int& new_suit)
{
	mrank=new_rank;
	msuit=new_suit;
}



// Update the attributes of the Card object by pulling random cards and accounting
// for the forbidden cards.
void Card::PullRandom(const std::set<Card>& forbidden_cards)
{
	// Pull random rank number [1,13]
	mrank = rand() % 13 + 1;

	// Pull random suit number [1,4]
	msuit = rand() % 4 + 1;

	// while loop to check that the random card that has just been pulled does not
	// belong to the forbidden list
	while (forbidden_cards.find(*this) != forbidden_cards.end())
	{
		// If we enter the loop it means that a forbidden card has been pulled.
		// Therefore another one has to be pulled until an allowed card is pulled.

		// Pull random rank number [1,13]
		mrank = rand() % 13 + 1;

		// Pull random suit number [1,4]
		msuit = rand() % 4 + 1;
	}
}


// Overriding of the less than equal operator in order to make the std::set::find method
// working
bool Card::operator< (const Card& right_card) const
{
	if (mrank >= right_card.mrank)
	{
		return false;
	}
	else
	{
		if (msuit >= right_card.msuit)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}



std::ostream& operator<< (std::ostream &out, const Card& card_to_print)
{
	out << "(" << card_to_print.mrank << "," << card_to_print.msuit << ")";
	return out;
}



