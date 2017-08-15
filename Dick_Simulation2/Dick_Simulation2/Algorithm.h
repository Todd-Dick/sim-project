//---------------------------------------------
// Algorithm.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <sys/timeb.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Algorithm
{
	protected:
		double m_dReturnValue;
		double m_dLinkValue;
	public:
		Algorithm();
		~Algorithm();
		virtual double GetValue();
		virtual double GetValue(double minValue, double maxValue);
		virtual double GetValue(double minValue, double current, double stepValue);
		virtual double GetValue(double minValue, double maxValue, double current, double stepValue);
};

#endif