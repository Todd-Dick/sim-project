//---------------------------------------------
// Algorithm.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "Algorithm.h"

using namespace std;

Algorithm::Algorithm()
{
	m_dReturnValue = 0.0;
	m_dLinkValue = 0.0;

}

Algorithm::~Algorithm()
{

}

double Algorithm::GetValue()
{
	return 0.0; 
}

double  Algorithm::GetValue(double minValue, double maxValue)
{ 
	return 0.0; 
}

double  Algorithm::GetValue(double minValue, double current, double stepValue)
{ 
	return 0.0; 
}

double  Algorithm::GetValue(double minValue, double maxValue, double current, double stepValue)
{
	return 0.0;
}

//double Algorithm::GetValue()
//{
//	return m_dReturnValue;
//}
//
//double Algorithm::GetM2M(double minValue, double maxValue)
//{
//	srand((unsigned int)(time(NULL)));
//	m_dReturnValue = minValue + (rand() % (int)(maxValue - minValue));
//	return m_dReturnValue;
//}
//
//double Algorithm::GetMaxD2Min(double minValue, double current, double stepValue)
//{
//	if (current > minValue)
//	{
//
//		srand((unsigned int)(time(NULL)));
//		m_dReturnValue = current - (rand() % (int)(stepValue));
//	}
//	else
//	{
//		m_dReturnValue = minValue;
//	}
//	if (m_dReturnValue < minValue)
//	{
//		m_dReturnValue = minValue;
//	}
//	return m_dReturnValue;
//}
//double Algorithm::GetMinI2Max(double max, double current, double step)
//{
//	if (current < max)
//	{
//		srand((unsigned int)(time(NULL)));
//		m_dReturnValue = current + (rand() % (int)(step));
//	}
//	else
//	{
//		m_dReturnValue = max;
//	}
//	if (m_dReturnValue > max)
//	{
//		m_dReturnValue = max;
//	}
//	return m_dReturnValue;
//}
//
//double Algorithm::FLifG(double current, double link)
//{
//	if (link > current)
//	{
//		m_dReturnValue = link;
//	}
//	else
//		m_dReturnValue = current;
//	return m_dReturnValue;
//}
//
//double Algorithm::FLifC(double current, double link)
//{
//	if (m_dReturnValue == link)
//	{
//		m_dReturnValue = current;
//		return m_dReturnValue;
//	}
//	else
//	{
//		m_dReturnValue = link;
//		return m_dReturnValue;
//	}
//}