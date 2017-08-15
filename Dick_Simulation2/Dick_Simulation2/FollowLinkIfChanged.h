//---------------------------------------------
// FollowLinkIfChanged.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef FOLLOWLINKIFCHANGED_H
#define FOLLOWLINKIFCHANGED_H

#include "Algorithm.h"

class FLifC: public Algorithm
{
	public:
		double GetValue(double current, double linkValue);
};

#endif
