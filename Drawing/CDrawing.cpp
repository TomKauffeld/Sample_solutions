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

	if(initialSize <10){

		initialSize =10;
	}
	m_arraySize = initialSize;
	m_rectangles = new CRectangle [m_arraySize];
}


CDrawing::~CDrawing(){

	delete m_rectangles;
}

void CDrawing::add(const CRectangle& rectangle){
	m_rectangles = new CRectangle [m_arraySize];

	CRectangle* temp = new CRectangle [m_arraySize];

	if(m_nextFree > m_arraySize && m_nextFree <100 ){
        for(int i = 0; i < m_arraySize; i++){
			temp[i] = m_rectangles[i];

        }

		delete m_rectangles;

		CRectangle* temp2 = new CRectangle [m_arraySize];

		for(int i = 0; i < m_arraySize; i++) {
			temp2[i] = temp[i];
		}

			delete[] temp;
			m_arraySize = (m_arraySize*2);



				}

	if(m_nextFree > m_arraySize && m_nextFree >100 ){
			for(int j = 0; j < m_arraySize; j++){
				temp[j] = m_rectangles[j];

	        }

			delete m_rectangles;

			 CRectangle* space = new CRectangle [m_arraySize];

			for(int j = 0; j < m_arraySize; j++) {
				space[j] = temp[j];
			}

				delete[] temp;
				m_arraySize +=  100;



					}

	      m_rectangles[m_nextFree++] = rectangle;

}

void CDrawing::print(){
	CRectangle* pos = nullptr;



	for( int i = 0;i < m_nextFree; i++){
        CRectangle* pos = &m_rectangles[i];
		cout << i;



	}





}


