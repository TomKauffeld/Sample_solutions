/*
 * CPoint.h
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */

#ifndef ASCIISCREENSOLUTION_MYCODE_CPOINT_H_
#define ASCIISCREENSOLUTION_MYCODE_CPOINT_H_
#include<iostream>




/**
 * Diese Klasse repr‰sentiert einen Punkt ein einem Ganzzahl-Koordinatensystem.
 */
class CPoint
{
private:
	/** Die x-Koordinate (Spalte) */
	int m_x;
	/** Die y-Koordinate (Zeile) */
	int m_y;

public:
	/**
	 * Erzeugt ein neues Objekt mit den angegeben
	 * Werten f¸r die x- und y-Koordinate.
	 */
	CPoint(int x = 0, int y = 0);

	/**
	 * Setzt die x-Koordinate auf den angegebenen Wert.
	 */
	void setX(int x);

	/**
	 * Setzt die y-Koordinate auf den angegebenen Wert.
	 */
	void setY(int y);

	/**
	 * Liefert den Wert der x-Koordinate.
	 */
	int getX() const;

	/**
	 * Liefert den Wert der y-Koordinate.
	 */
	int getY() const;

	/**
	 * Pr¸ft, ob die x- und y-Koordinaten der Punkte ¸bereinstimmen.
	 */
	bool operator== (const CPoint& other) const;

	/**
	 * Pr¸ft, ob sich die x- und y-Koordinaten der Punkte unterscheiden.
	 */
	bool operator!= (const CPoint& other) const;
};

#endif /* ASCIISCREENSOLUTION_MYCODE_CPOINT_H_ */
