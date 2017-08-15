//---------------------------------------------
// StepIncMin2Max.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "StepIncMin2Max.h"
#include <iostream>

using namespace std;

double SIM2M::GetValue(double minValue, double maxValue, double current, double stepValue)
{
	if (current < maxValue)
	{
		int random2 = 0;
		int zerocount = 0;
		srand((unsigned int)(time(NULL)));
		for (int i = 0; i < 1000; i++)
		{
			double random = (rand()*(1.0 / (double(RAND_MAX) + 1.0))*(stepValue - minValue + 1) - minValue);
			random2 = static_cast<int>(random);
			if (random2 == 0)
				zerocount++;
		}
		cout << zerocount << endl;
		cout << random2 << endl;
		m_dReturnValue = current + random2;
	}
	else
	{
		m_dReturnValue = maxValue;
	}
	if (m_dReturnValue > maxValue)
	{
		m_dReturnValue = maxValue;
	}
	return m_dReturnValue;
}