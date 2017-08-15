//---------------------------------------------
// StepDecMin2Max.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "StepDecMax2Min.h"
#include <iostream>
using namespace std;

double SDM2M::GetValue(double minValue, double current, double stepValue)
{
	
	if (current >= minValue)
	{

		srand((unsigned int)(time(NULL))); 
		int random = (rand()&static_cast<int>(stepValue-minValue));
		m_dReturnValue = current - random;
	}
	else
	{
		m_dReturnValue = minValue;
	}
	if (m_dReturnValue < minValue)
	{
		m_dReturnValue = minValue;
	}
	return m_dReturnValue;
}