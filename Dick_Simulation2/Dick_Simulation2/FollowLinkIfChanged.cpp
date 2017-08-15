//---------------------------------------------
// FollowLinkIfChanged.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "FollowLinkIfChanged.h"

double FLifC::GetValue(double current, double link)
{
	if (m_dReturnValue == link)
	{
		
		return m_dReturnValue;
	}
	else
	{
		m_dReturnValue = link;
		return m_dReturnValue;
	}
}