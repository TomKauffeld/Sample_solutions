/*
 * CDrawing.h
 *
 *  Created on: 27 Jan 2019
 *      Author: mac
 */

#ifndef CDRAWING_H_
#define CDRAWING_H_
#include<iostream>
#include"CRectangle.h"

class CDrawing{
private:

	CRectangle* m_rectangles;
	int m_nextFree = 0;
	int m_arraySize;

public:
	CDrawing(int initialSize = 10);
	 ~CDrawing();
	void add(const CRectangle& rectangle);
	void print();
	void drawFiltered(CScreen& screen,char filter = 0);
};





#endif /* CDRAWING_H_ */
