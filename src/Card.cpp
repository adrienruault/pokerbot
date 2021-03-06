/*
 * card.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */


#include "Card.hpp"





// Default constructor that initializes an empty card (0,0)
Card::Card()
{
	mrank=0;
	msuit=0;
}



// Constructor that initializes an card with the provided rank and suit
Card::Card(const int rank, const int suit)
{
	if ((rank < 1) || (rank > 13))
	{
		throw ErrorRank();
	}
	mrank=rank;

	if ((suit < 0) || (suit > 4))
	{
		throw ErrorSuit(suit);
	}
	msuit=suit;
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

		//std::cout << (*this) << " Card Constructor\n";
		//std::cout << (forbidden_cards.find(*this) != forbidden_cards.end()) << "\n";
		//std::cout << forbidden_cards.size() << "\t"<< "\n";
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
	if ((new_rank < 1) || (new_rank > 13))
	{
		throw ErrorRank();
	}
	mrank=new_rank;
}



void Card::SetSuit(const int& new_suit)
{
	if ((new_suit < 0) || (new_suit > 4))
	{
		throw ErrorSuit(new_suit);
	}
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



// Overriding of the assignment operator
Card& Card::operator= (const Card& card_to_copy)
{
	mrank=card_to_copy.mrank;
	msuit=card_to_copy.msuit;
	return *this;
}



// Overriding of the less than equal operator in order to make the std::set::find method
// working
bool Card::operator< (const Card& right_card) const
{
	// First step is to make the (0,0) cards as greater than any others
	if (right_card.mrank==0)
	{
		return true;
	}
	if (mrank==0)
	{
		return false;
	}

	if (mrank > right_card.mrank)
	{
		return false;
	}
	else if (mrank < right_card.mrank)
	{
		return true;
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




bool Card::operator> (const Card& right_card) const
{
	if ((*this) < right_card)
	{
		return false;
	}
	else
	{
		return true;
	}
}






std::ostream& operator<< (std::ostream &out, const Card& card_to_print)
{
	out << "(" << (card_to_print.mrank>=10) << (card_to_print.mrank%10) << "," << card_to_print.msuit << ")";
	return out;
}



