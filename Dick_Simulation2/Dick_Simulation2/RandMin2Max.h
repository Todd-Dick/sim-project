//---------------------------------------------
// RandMin2Max.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef RANDMIN2MAX_H
#define RANDMIN2MAX_H

#include "Algorithm.h"

using namespace std;

class RM2M : public Algorithm
{
	public:
		double GetValue(double minValue, double maxValue);
		
};

#endif