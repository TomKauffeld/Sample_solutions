#include "CEventDB.h"
#include <iostream>


CEventDB::CEventDB( int maxEvents){
	// let's do some checking :
	// the array must at least be 10 items long
	m_maxEvents = maxEvents < 10 ? 10 : maxEvents;
	// this works like 
	// [condition, must return a bool] ? [if true, this gets executed] : [if false, this gets executed];
	/* this is the same as :
	if (maxEvents < 10)
		m_maxEvents = 10;
	else
		m_maxEvents = maxEvents;
	*/


	// let's create our array of size maxEvents
	m_pEvents = new CEvent[m_maxEvents];

}


CEventDB::~CEventDB(){
	// because we use "new" we need to put a "delete" here
	// and because of the "[]" we also put the "[]" after delete
	delete [] m_pEvents;
}


void CEventDB::print() {
	// let's check if we have anything in our array
	if (m_curEvents == 0) {
		// we don't, so let's print a message
		std::cout << "leere Databank!" << std::endl;
		return;
	}
	// let's loop over every event we have
	for (int i = 0; i < m_curEvents; i++) {
		// print the index
		std::cout << "(" << i << ") ";
		// and the information
		m_pEvents[i].print();
	}

}

int CEventDB::bookEvent(int pos, unsigned long numSeats) {
	// let's validate our input :
	// pos must be positive, and be less than our count of events in the array
	if (pos < 0 || pos >= m_curEvents) {
		std::cout << "ERROR : Invalid position" << std::endl;
		return 1;
	}
	// the position is correct, so let's book it
	return m_pEvents[pos].book(numSeats) ? 0 : 2;
	/* the above is the same as
	if (m_pEvents[pos].book(numSeats))
		return 0;
	return 2;
	*/
}

int CEventDB::findEvent(int posStart, eTypes type, std::string location, CEvent& event) {
	// let's validate our input :
	// posStart must be smaller than the number of events;
	if (posStart >= m_curEvents) {
		// the offset is too high
		return -1; // let's return -1
	}

	// posStart must be positive, so if it isn't, let's set it to 0, else it can stay the same
	posStart = posStart < 0 ? 0 : posStart;
	/* the above is the same as
	if (posStart < 0)
		posStart = 0;
	*/

	// let's loop over our events
	for (int i = posStart; i < m_curEvents; i++) {
		if (
			m_pEvents[i].getType() == type && // if the type is the same
			m_pEvents[i].getLocation().compare(location) == 0 // and the location is the same
			) {
			event = m_pEvents[i]; // let's set the address inside event to the one we found
			return i; // and return the index of the event
		}
	}
	// we didn't find an event matching the search parameters
	// let's return -2
	return -2;
}

bool CEventDB::operator+= (const CEvent& rop) {
	// let's check if we have space in our array
	if (m_curEvents >= m_maxEvents) {
		// we don't, so let's print a message
		std::cout << "ERROR : database is already full" << std::endl;
		// and return false
		return false;
	}
	// we do, so let's set the first empty spot to the event given, and incrise m_curEvents by 1
	m_pEvents[m_curEvents++] = rop;
	/* the above is the same as
	m_pEvents[m_curEvents] = rop;
	m_curEvents += 1;
	*/
	// the side of the ++ operator represents the order to do the operation :
	// ++number means : first add one, then give this new number
	// number++ means : first give the number, then add one
	// so if number = 0
	// int i = ++number; means i = 1 and number = 1
	// and if number = 0 again
	// int j = number++; means j = 0 and number = 1

	// and let's return true
	return true;
}