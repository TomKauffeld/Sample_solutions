/*
 * CDrawing.cpp
 *
 *  Created on: 27 Jan 2019
 *      Author: mac
 */

#include<iostream>
#include "CDrawing.h"
using namespace std;




CDrawing::CDrawing(int initialSize ){

	if (initialSize < 10){
		initialSize = 10;
	}
	m_arraySize = initialSize;
	m_rectangles = new CRectangle[m_arraySize];
}


CDrawing::~CDrawing(){

	delete m_rectangles;
}

void CDrawing::add(const CRectangle& rectangle){
	// first let's check if there is enough space
	if (m_nextFree >= m_arraySize) {
		// there isn't, so let's double the size
		m_arraySize *= 2;
		// then create a new array with the new size
		CRectangle * tmp = new CRectangle[m_arraySize];

		// now we need to copy the rectangles from the old array to the new array
		for (int i = 0; i < m_nextFree; i++) {
			tmp[i] = m_rectangles[i];
		}
		// let's delete the old array (else we get a memory leak)
		delete m_rectangles;
		// and finaly we set the pointer to our new array
		m_rectangles = tmp;
	}
	// when there is space (enough space, or we created space)
	// let's add our new rectangle to the list
	m_rectangles[m_nextFree++] = rectangle;
}


void CDrawing::print(){
	CRectangle* pos = nullptr;

	for (int i = 0; i < m_nextFree; i++){
        pos = &m_rectangles[i];
		cout << i; // at the moment this just prints the index, what is the goal of this function ?
	}

}


