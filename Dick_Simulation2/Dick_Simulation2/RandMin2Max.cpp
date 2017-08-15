//---------------------------------------------
// RandMin2Max.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "RandMin2Max.h"
class Algorithm;


double RM2M::GetValue(double minValue, double maxValue)
{
	srand((unsigned int)(time(NULL)));
	//double random = (rand()*(1.0 / (double(RAND_MAX) + 1.0))*(maxValue - minValue + 1) - minValue);
	int random2 = (rand()&static_cast<int>(maxValue - minValue));
	double wtf = static_cast<double>(random2);
	if (wtf > maxValue)
		wtf = maxValue;
	m_dReturnValue = wtf;
	return m_dReturnValue;
}
