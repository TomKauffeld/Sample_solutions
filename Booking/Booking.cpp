#include "CEvent.h"
#include "CEventDB.h"


// A simple main to give the same screen as indicated by the images
int main(){
	CEventDB eventDB(10);

	eventDB.print();

	eventDB += CEvent(eTypes::THEATER, "Aida", "23.7.14 20:00", "Orangerie", 10, 25);
	eventDB += CEvent(eTypes::SCIENCE, "Blitze", "17.7.14 18:00", "h-da", 10, 0);
	eventDB += CEvent(eTypes::ROCKPOP, "The Rockers", "1.7.14 22:00", "Musikkneipe", 10, 5);
	eventDB += CEvent(eTypes::SCIENCE, "Geistesblitze", "3.7.14 18:00", "h-da", 10, 0);
	

	eventDB.print();

	eventDB.bookEvent(2, 20);
	eventDB.bookEvent(2, 10);

	CEvent event;
	int offset = -1;
	while ((offset = eventDB.findEvent(offset+1, eTypes::SCIENCE, "h-da", event)) >= 0) {
		event.print();
	}

	system("PAUSE"); // and a pause so it does't directly close
}



