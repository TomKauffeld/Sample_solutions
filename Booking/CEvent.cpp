#include "CEvent.h"
#include <iostream>

CEvent::CEvent(eTypes type, std::string name, std::string datetime, std::string location, unsigned long maxSeats, float pricePerTicket) {
	m_type = type;
	m_name = name;
	m_datetime = datetime;
	m_location = location;
	m_maxSeats = maxSeats;
	m_pricePerTicket = pricePerTicket;
}

eTypes CEvent::getType() {
	return m_type;
}

std::string CEvent::getLocation() {
	return m_location;
}

unsigned long CEvent::getNumAvailSeats() {
	return m_maxSeats - m_bookedSeats;
}

void CEvent::print(unsigned long numSeats) {
	if (numSeats == 0) // if it's 0, we want to print the information about the event
		std::cout << "Objektinfo: ";
	else               // else we want to print information about the booking
		std::cout << "Buchungsinfo: " << numSeats << "x ";

	// this part is always printed, so we might as well take it out of the if statement
	// (less code to write ;) )
	std::cout << "(" << getTypeAsString(m_type) << ") " << m_name + "/" << m_location << ": " << m_datetime;


	if (numSeats == 0) // if it's 0, we print the price per ticket
		std::cout << " Einzelpreis: " << m_pricePerTicket << "€" << std::endl;
	else               // else we print the total price of the booking
		std::cout << " Gesamtpreis: " << (numSeats*m_pricePerTicket) << "€" << std::endl;
}

bool CEvent::book(unsigned long numSeats) {
	// let's check if we have enough seats

	// (or in this case, let's check if we have NOT enough seats available)
	if (getNumAvailSeats() < numSeats) {
		// we don't, so let's print a message
		std::cout << "Nicht genügent Plätze vorhanden!" << std::endl;
		// and return false
		return false;
	}// because of the return inside the if statement, the "else" statement becomes redundant
	// we have enough place

	// let's add to the number of booked seats for this event, the number of seats requested by this booking
	m_bookedSeats += numSeats;

	// and give some information
	print(numSeats);

	// finally, let's return true
	return true;
}

std::string CEvent::getTypeAsString(eTypes type) {
	switch (type) // we switch to the "context" of type
	{
	case NOTYPE:	// if type equals NOTYPE
		return "No Type";	
		// normaly in a case block we would end with a 
		// break;
		// however because of the return, the break statement becomes redundant
	case THEATER:
		return "Theater";
	case ROCKPOP:
		return "Rock/Pop";
	case SCIENCE:
		return "Wissenschaft";
	case NUMTYPES:
		return "numtypes";
	default: // the type doesn't correspond to any of the above 
		//(this shouldn't happen, but error handeling is always nice)
		return "Unknown Type";
	}
	/* the above is the same as :
	if (type == NOTYPE)
		return "No Type";
	if (type == THEATER)
		return "Theater";
	if (type == ROCKPOP)
		return "Rock/Pop";
	if (type == SCIENCE)
		return "Wissenschaft";
	if (type == NUMTYPES)
		return "numtypes";
	return "Unknown Type";
	*/
}