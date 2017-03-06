/*
 * Board.hpp
 *
 *  Created on: Mar 6, 2017
 *      Author: ruault
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_


#include "Card.hpp"
#include <vector>


class Board
{
private:
	// Vector of cards that must contain 5 cards. An empty card is
	// represented as (0,0).
	std::vector<Card> mboard;

	// mround_state is used to keep track of the current round.
	// The associated numbers correspond to the number of the current
	// betting round.
	// pre-flop: takes value 1
	// flop: takes value 2
	// turn: takes value 3
	// river: takes value 4
	int mround_state;

public:

	// Default constructor that creates an empty board at the pre-flop
	// state mround_state is thus given the value 1
	// The mboard vector is filled with 5 empty cards.
	Board();

	// Method that checks mround_state to know at what round is the game
	// and then pull some random cards to the board.
	// The number of cards pulled depends at what round is the game
	void NextRound(std::set<Card>& forbidden_cards);

	// Method that reinitializes the board by bringing it back to the
	// pre-flop state and by setting all the cards of the mboard vector
	// to empty cards
	void BackPreFlop(std::set<Card>& forbidden_cards);

	friend std::ostream& operator<< (std::ostream& out, const Board& board_to_print);

};



#endif /* BOARD_HPP_ */
