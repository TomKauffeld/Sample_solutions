/*
 * CPoint.cpp
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */
#include<iostream>
#include "CPoint.h"
using namespace std;




CPoint::CPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CPoint::setX(int x)
{
	m_x = x;
}

void CPoint::setY(int y)
{
	m_y = y;
}

int CPoint::getX() const
{
	return m_x;
}

int CPoint::getY() const
{
	return m_y;
}

bool CPoint::operator ==(const CPoint& other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

bool CPoint::operator !=(const CPoint& other) const
{
	return m_x != other.m_x || m_y != other.m_y;
}





