//---------------------------------------------
// FollowLinkIfGreater.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "FollowLinkIfGreater.h"

double FLifG::GetValue(double current, double linkValue)
{
	if (linkValue > current)
	{
		m_dReturnValue = linkValue;
	}
	else
		m_dReturnValue = current;
	return m_dReturnValue;
}