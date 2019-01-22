
// our include guard
#ifndef CEVENT_H
#define CEVENT_H

#include <string>

/*
the type of event
*/
enum eTypes {
	NOTYPE,
	THEATER,
	ROCKPOP,
	SCIENCE,
	NUMTYPES
};


class CEvent
{
private:
	eTypes m_type;						// the type of event
	std::string m_name;					// the name of the event
	std::string m_datetime;				// the date and time of the event
	std::string m_location;				// the location of the event
	unsigned long m_maxSeats;			// the number of seats
	unsigned long m_bookedSeats = 0;	// the number of seats booked
	float m_pricePerTicket;				// the price of a ticket
public:
	/*
	Creates an event

	Parameters :
	IN	type:eTypes				the type of the event			defaults to NOTYPE
	IN	name:string				the name of the event			defaults to ""
	IN	datetime:string			the date and time of the event	defaults to ""
	IN	location:string			the location of the event		defaults to ""
	IN	maxSeats:long			the number of seats				defaults to 0
	IN	pricePerTicket:float	the price of a ticket			defaults to 0.0f
	*/
	CEvent(eTypes type = NOTYPE, std::string name = "", std::string datetime = "", std::string location = "", unsigned long maxSeats = 0, float pricePerTicket = 0.0f);

	/*
	Getter for the type of the event

	Returns:
	eTypes	the type of the event
	*/
	eTypes getType();

	/*
	Getter for the location of the event

	Returns:
	string	the location of the event
	*/
	std::string getLocation();

	/*
	Returns the number of available seats (not yet booked)
	
	Returns:
	long	the number of seats available
	*/
	unsigned long getNumAvailSeats();

	/*
	prints information :
		if numSeats equals 0, it prints information about the event
		else it prints information about the price/booking

	Parameters:
	IN	numSeats:long	the number of seats we booked/look up							defaults to 0
						or if 0, to indicate we only want information about the event
	*/
	void print(unsigned long numSeats = 0);

	/*
	Registers a booking

	Parameters:
	IN	numSeats:long	the number of seats we would like to book

	Returns:
	bool	true  if successfull
			false if there wasn't enough seats available
	*/
	bool book(unsigned long numSeats);

	/*
	returns a string representing the type

	Parameters:
	IN type:eType	the type we want to represent as a string

	Returns:
	string	the string representation of the type
	*/
	static std::string getTypeAsString(eTypes type);

};

#endif