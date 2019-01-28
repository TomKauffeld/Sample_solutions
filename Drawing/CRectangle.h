/*
 * CRectangle.h
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */

#ifndef ASCIISCREENSOLUTION_MYCODE_CRECTANGLE_H_
#define ASCIISCREENSOLUTION_MYCODE_CRECTANGLE_H_

#include <iostream>
#include<string>
#include"CScreen.h"
#include "CPoint.h"




/**
 * Diese Klasse beschreibt ein Rechteck in einem
 * Ganzzahl-Koordinatensystem ¸ber die Eigenschaften
 * "untere linke Ecke" und "obere rechte Ecke".
 *
 * Als zus‰tzliche Eigenschaft hat die Klasse ein Zeichen
 * (char) das bei der graphischen Darstellung als
 * F¸llzeichen verwendet wird.
 */
class CRectangle
{
private:

	CPoint m_bottomLeft;
    CPoint m_topRight;

	 char m_fillChar;

public:
	/**
	 * Erzeugt ein neues Rechteck mit linker unterer und
	 * rechter oberer Ecke bei (0,0) und dem angegebenen
	 * F¸llzeichen.
	 */
	CRectangle(char fillChar = '#');


	/**
	 * Erzeugt ein neues Rechteck mit der angegebenen linken
	 * unteren und rechten oberen Ecken sowie dem angegebenen
	 * F¸llzeichen.
	 *
	 * Beim Erzeugen wird die Zusicherung ¸berpr¸ft, dass die
	 * rechte obere Ecke rechts von und oberhalt der linken
	 * unteren Ecke liegen muss! Falls die x-Koordinate
	 * der rechten oberen Ecke nicht grˆﬂer als die x-Koordinate
	 * der linken unteren Ecke ist, wird sie auf den Wert
	 * der x-Koordinate der linken unteren Ecke gesetzt. Falls
	 * die y-Koordinate der rechten oberen Ecke nicht grˆﬂer als
	 * die y-Koordinate der linken unteren Ecke ist, wird sie auf
	 * dem Wert der y-Koordinate der linken unteren Ecke gesetzt.
	 */
	CRectangle(CPoint bottomLeft, CPoint topRight, char fillChar = '#');

	/**
	 * Weist den Eigenschaften "linke untere Ecke" und "rechte obere
	 * Ecke" neue Werte zu.
	 *
	 * Vor der Zuweisung wird die Zusicherung ¸berpr¸ft, dass die
	 * rechte obere Ecke rechts von und oberhalt der linken
	 * unteren Ecke liegen muss! Ist das nicht der Fall wird keines
	 * der Attribute ver‰ndert.
	 */
	void setCorners (CPoint bottomLeft, CPoint topRight);

	/**
	 * Liefert die linke untere Ecke des Rechtecks zur¸ck.
	 */
	CPoint getBottomLeftCorner() const;

	/**
	 * Liefert die rechte obere Ecke des Rechtecks zur¸ck.
	 */
	CPoint getTopRightCorner() const;

	/**
	 * Weist dem F¸llzeichen den angegebene Wert zu.
	 */
	void setFillChar(char fillChar = '#');

	/**
	 * Liefert den Wert des F¸llzeichens.
	 */
	char getFillChar() const;

	/**
	 * Pr¸ft, ob die beiden Rechtecke in allen Eigenschaften ¸bereinstimmen.
	 */
	bool operator== (const CRectangle& other) const;

	/**
	 * Zeichnet das Rechteck in das ¸bergebene Bildschirmobjekt. Das heisst,
	 * es werden mit CScreen::setPoint die Werte aller "Punkte", die im
	 * Bereich des Rechtecks liegen, auf das F¸llzeichen des Rechtecks gesetzt.
	 */
	void draw(CScreen& screen) const;

	/**
	 * Gibt eine textuelle Darstellung des Rechtecks auf dem ¸bergebenen
	 * Ausgabestrom aus. Das Format ist in der Aufgabenstellung beschrieben.
	 */

	friend std::ostream& operator<< (std::ostream& lhs, const CRectangle& rhs);

};
std::ostream& operator<< (std::ostream& lhs, const CRectangle& rhs);


#endif /* ASCIISCREENSOLUTION_MYCODE_CRECTANGLE_H_ */

