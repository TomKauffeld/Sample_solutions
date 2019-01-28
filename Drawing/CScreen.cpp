/*
 * CScreen.cpp
 *
 *  Created on: 05.01.2015
 *      Author: mnl
 */

#include <iostream>
#include "CScreen.h"
using namespace std;



CScreen::CScreen(){
	clear();
}

void CScreen::setPoint(CPoint point, char content){
	if (point.getX() < 0 || point.getY() < 0
			|| point.getY() >= SCREEN_HEIGHT || point.getX() >= SCREEN_WIDTH) {
		return;
	}
	m_content[point.getY() * SCREEN_WIDTH + point.getX()] = content;
}

void CScreen::print() const{
	// in order to print, first we loop over all the rows
	for (int y = SCREEN_HEIGHT - 1; y >= 0; y--) {
		// for each row, we loop over every column
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			// and for each point, we print the character to the screen at that position
			cout << m_content[y * SCREEN_WIDTH + x];
		}
		// and at the end of every row, we print an endline in order to go to the next row in the console
		cout << endl;
	}
}

void CScreen::clear() {
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_content[i] = '.';
	}
}




