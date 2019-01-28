
/*
 * CRectangle.cpp
 *
 *  Created on: 05.02.2015
 *      Author: lipp
 */


#include<iostream>
#include "CRectangle.h"
#include"CPoint.h"
using namespace std;


CRectangle::CRectangle(char fillChar)
{
	m_fillChar = fillChar;
	setCorners(CPoint(), CPoint());
}




CRectangle::CRectangle(CPoint bottomLeft, CPoint topRight, char fillChar)
{
	m_fillChar = fillChar;
	setCorners(bottomLeft, topRight);
}


void CRectangle::setCorners(CPoint bottomLeft, CPoint topRight){
	m_bottomLeft = bottomLeft;
	m_topRight = topRight;
	if (topRight.getX() < bottomLeft.getX()) {
		m_topRight.setX(bottomLeft.getX());
		m_bottomLeft.setX(topRight.getX());
	}
	if (topRight.getY() < bottomLeft.getY()) {
		m_topRight.setY(bottomLeft.getY());
		m_bottomLeft.setY(topRight.getY());
	}
}

CPoint CRectangle::getBottomLeftCorner()const{
	return m_bottomLeft;
}

CPoint CRectangle::getTopRightCorner() const{
	return m_topRight;

}

void CRectangle::setFillChar(char fillChar){
	m_fillChar = fillChar;
}

char CRectangle::getFillChar() const{
	return m_fillChar;
}

bool CRectangle::operator ==(const CRectangle& other) const{
	return m_topRight == other.m_topRight &&  m_bottomLeft == other.m_bottomLeft &&m_fillChar == other.m_fillChar;

}

void CRectangle::draw(CScreen& screen) const{


    for (int x = m_bottomLeft.getX(); x <= m_topRight.getX(); x++) {
        //let's loop over all the y (from bottom to top)
        for (int y = m_bottomLeft.getY(); y <= m_topRight.getY(); y++) {
            // let's draw m_fillChar to the screen at the position x,y
            screen.setPoint(CPoint(x, y), m_fillChar);
        }
    }
}

ostream& operator<< (ostream& lhs, const CRectangle& rhs){

	lhs << "CRectangle[(" << rhs.getBottomLeftCorner().getX() << "," <<rhs.getTopRightCorner().getY() << ")"<< ","<< "("<<rhs.getTopRightCorner().getX()<< ","<< rhs.getTopRightCorner().getY()<<"),"<< rhs.getFillChar()<<"]" << endl;
	return lhs;

}
