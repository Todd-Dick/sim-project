//---------------------------------------------
// StepDecMin2Max.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef STEPDECMIN2MAX_H
#define STEPDECMIN2MAX_H

#include "Algorithm.h"

class SDM2M : public Algorithm
{
	public:
		double GetValue(double minValue, double current, double stepValue);
};

#endif