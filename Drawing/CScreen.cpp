/*
 * CScreen.cpp
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */

#include <iostream>
#include "CScreen.h"
using namespace std;



CScreen::CScreen()
{
	clear();
}

void CScreen::setPoint(CPoint point, char content)
{
	if (point.getX() < 0 || point.getY() < 0
			|| point.getY() * 80 + point.getX() >= 24*80) {
		return;
	}
	m_content[point.getY() * 80 + point.getX()] = content;
}

void CScreen::print() const
{
	cout << "    ";
	for (int col = 0; col < 80; col++) {
		cout << col / 10;
	}
	cout << endl;
	cout << "    ";
	for (int col = 0; col < 80; col++) {
		cout << col % 10;
	}
	cout << endl;
	for (int row = 23; row >= 0; row--) {
		if (row < 10) {
			cout << ' ';
		}
		cout << row << ": ";
		for (int col = 0; col < 80; col++) {
			cout << m_content[row * 80 + col];
		}
		cout << endl;
	}
	cout << endl;
}

void CScreen::clear() {
	for (int i = 0; i < 24*80; i++) {
		m_content[i] = '.';
	}
}




