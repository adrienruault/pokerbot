/*
 * Board.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: ruault
 */



#include "Board.hpp"


// Default constructor that creates an empty board at the pre-flop state
// mround_state is thus given the value 1
// The mboard vector is filled with 5 empty cards.
Board::Board()
{
	// Filling mboard vector with 5 empty cards
	Card empty_card;
	for(int i=0; i<5; i++)
	{
		mboard.push_back(empty_card);
	}

	mround_state=1;
}


// Method that checks mround_state to know at what round is the game
// and then pull some random cards to the board.
// The number of cards pulled depends at what round is the game
void Board::NextRound(std::set<Card>& forbidden_cards)
{
	// Deal the flop if at pre-flop
	if (mround_state == 1)
	{
		mboard[0].PullRandom(forbidden_cards);
		forbidden_cards.insert(mboard[0]);
		mboard[1].PullRandom(forbidden_cards);
		forbidden_cards.insert(mboard[1]);
		mboard[2].PullRandom(forbidden_cards);
		forbidden_cards.insert(mboard[2]);




		mround_state+=1;
	}

	// Deal the turn if at flop
	else if (mround_state==2)
	{
		mboard[3].PullRandom(forbidden_cards);
		forbidden_cards.insert(mboard[3]);

		mround_state+=1;
	}

	// Deal the river if at turn
	else if (mround_state==3)
	{
		mboard[4].PullRandom(forbidden_cards);
		forbidden_cards.insert(mboard[4]);

		mround_state+=1;
	}
	else
	{
		throw ErrorBoardRound();
	}

	// The key card is used as a relay for the following insertion sort
	Card key;
	// for-loop to reorder the cards in the right order, it is an insertion-sort
	for(int i=1; i<=mround_state; i++)
	{
		int p=i-1;
		key=mboard[i];

		// Loop that find the index p where to exchange A[p] and A[i]
		while ((p>=0) && (mboard[p] > key))
		{
			mboard[p+1]=mboard[p];
			p=p-1;
		}

		mboard[p+1]=key;

	}
}



// Method that reinitializes the board by bringing it back to the
// pre-flop state and by setting all the cards of the mboard vector
// to empty cards
void Board::BackPreFlop(std::set<Card>& forbidden_cards)
{
	// First step is to erase the cards present on the board from the set
	// of forbidden cards since those cards will be available again
	// Then all the non-empty cards are replaced with empty cards.

	Card empty_card;

	if ((mround_state>=2) && (mround_state<=4))
	{
		for (int i=0; i<mround_state+1; i++)
		{
			forbidden_cards.erase(mboard[i]);
			mboard[i]=empty_card;
		}
	}

	mround_state=1;
}



std::ostream& operator<< (std::ostream& out, const Board& board_to_print)
{
	if (board_to_print.mround_state==1)
	{
		std::cout << "Pre-Flop\n";
	}
	else if (board_to_print.mround_state==2)
	{
		std::cout << "Flop\n";
	}
	else if (board_to_print.mround_state==3)
	{
			std::cout << "Turn\n";
	}
	else if (board_to_print.mround_state==4)
	{
			std::cout << "River\n";
	}
	else
	{
		throw ErrorUndefinedBoardState();
	}

	out << "[" << board_to_print.mboard[0] << " , " << board_to_print.mboard[1] << " , ";
	out << board_to_print.mboard[2] << " , " << board_to_print.mboard[3] << " , " << board_to_print.mboard[4] << "]";
	return out;
}





