/*
 * Error.hpp
 *
 *  Created on: Mar 5, 2017
 *      Author: adrien
 */

#ifndef SRC_ERROR_HPP_
#define SRC_ERROR_HPP_


#include <exception>
#include <iostream>
#include <sstream>
#include <string>


class ErrorRank : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorRank() throw()
	{
		mphrase="Error:\nThe rank assigned to the card is not allowed, out of the interval [1,13].\n";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorRank() throw()
	{}
};



class ErrorSuit : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorSuit(const int& suit) throw()
	{
		std::string converted_suit;          // string which will contain the result
		std::ostringstream convert;   // stream used for the conversion
		convert << suit;      // insert the textual representation of 'Number' in the characters in the stream
		converted_suit = convert.str(); // set 'Result' to the contents of the stream

		mphrase="Error:\nThe suit assigned to the card is ";
		mphrase+= converted_suit;
		mphrase+= "\nThis is not allowed because out of the interval [0,4].\n";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorSuit() throw()
	{}

};



class ErrorBoardRound : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorBoardRound() throw()
	{
		mphrase="Error:\nTrying to deal an unauthorized round.\nIt is likely that the board is at the river state and that it is asked to go further.\n";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorBoardRound() throw()
	{}

};



class ErrorUndefinedBoardState : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorUndefinedBoardState() throw()
	{
		mphrase="Using a board that has an undefined round state. It means that mround_state is not in {1,2,3,4}).\n";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorUndefinedBoardState() throw()
	{}

};



class ErrorWrongHandIndex : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorWrongHandIndex() throw()
	{
		mphrase="Wrong index used to access a Hand's Card.\n";
		mphrase+="It must be either 0 or 1\n.";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorWrongHandIndex() throw()
	{}

};



class ErrorWrongBoardIndex : public std::exception
{
private:
	std::string mphrase;
public:
	ErrorWrongBoardIndex() throw()
	{
		mphrase="Trying to access an index of the mboard attribute of Board that is not allowed.\n";
	}

	virtual const char* what() const throw()
	{
		return mphrase.c_str();
	}
	virtual ~ErrorWrongBoardIndex() throw()
	{}

};



#endif /* SRC_ERROR_HPP_ */
