// our include guard
#ifndef CEVENTDB_H
#define CEVENTDB_H

// let's include our CEvent header
#include "CEvent.h"

// we also need the string header
#include <string>

class CEventDB
{
private:
	CEvent * m_pEvents; // an array of CEvents 
	/*
	a pointer is the same as an array :
	m_pEvents[0].book()
	
	is the same as :

	m_pEvents->book()
	*/
	int m_maxEvents; // our size of the array
	int m_curEvents = 0; // the number of elements in the array
public:
	/*
	Creates a store of events

	Parameters :
	IN	maxEvents:int	the maximum number of events this DB can hold
	*/
	CEventDB(int maxEvents = 10);

	/*
	Deletes the DB and frees our array
	*/
	~CEventDB();

	/*
	Prints information of the events stored
	*/
	void print();

	/*
	Books a specified number of seats for an event

	Parameters :
	IN	pos:int			the index of the event we would like to book for
	IN	numSeats:long	the number of seats we would like to book

	Returns :
	int	0	if successfull
		1	if the index is out of range
		2	if there isn't enough seats available for our booking
	*/
	int bookEvent(int pos, unsigned long numSeats);

	/*
	this method gives us the position and instance of the first CEvent that matches our search parameters

	Parameters :
	IN	posStart:int	the offset we want to start searching for (everthing below is skipped)
	IN	type:eTypes		the type of event we want to search for
	IN	location:string	the location of where the event should be
	OUT	event:CEvent	the first instance that matches our search parameters

	Returns :
	int	the index of the event if found
		-1	if the index was too high
		-2	if no event matching out search parameters was found
	*/
	int findEvent(int posStart, eTypes type, std::string location, CEvent& event);

	// this overrides the default behavior for the += operator (the default behavior being : E0349 no operator "+=" matches these operands)
	bool operator+= (const CEvent& rop);
};

#endif