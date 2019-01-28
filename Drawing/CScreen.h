/*
 * CScreen.h
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */

#ifndef ASCIISCREENSOLUTION_MYCODE_CSCREEN_H_
#define ASCIISCREENSOLUTION_MYCODE_CSCREEN_H_
#include<iostream>

#include "CPoint.h"




/**
 * Dies Klasse repr‰sentiert einen Bereich von 80x24 "Punkten",
 * die als ein beliebiges Zeichen dargestellt werden kˆnnen.
 */
class CScreen
{
private:
	/** Der Speicher f¸r die Darstellung der Punkte. */
	char m_content[24*80];

public:
	/**
	 * Erzeugt eine neue Darstellung, bei der alle Punkte
	 * auf den Wert '.' gesetzt sind.
	 */
	CScreen();

	/**
	 * Setzt den angegebenen Punkt auf das angegebene Zeichen.
	 */
	void setPoint(CPoint point, char content);

	/**
	 * Gibt die Darstellung aus.
	 */
	void print() const;

	/**
	 * Lˆscht die Darstellung. Alle Zeichen werden wieder auf
	 * '.' gesetzt.
	 */
	void clear();
};

#endif /* ASCIISCREENSOLUTION_MYCODE_CSCREEN_H_ */
