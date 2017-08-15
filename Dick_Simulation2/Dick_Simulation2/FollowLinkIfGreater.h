//---------------------------------------------
// FollowLinkIfGreater.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef FOLLOWLINKIFGREATER_H
#define FOLLOWLINKIFGREATER_H

#include "Algorithm.h"

class FLifG : public Algorithm
{
	public:
		double GetValue(double current, double linkValue);
};

#endif
