//---------------------------------------------
// AlgorithmFactory.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef ALGORITHMFACTORY_H
#define ALGORITHMFACTORY_H

#include "Sensor.h"
#include "RandMin2Max.h"
#include "StepDecMax2Min.h"
#include "StepIncMin2Max.h"
#include "FollowLinkIfChanged.h"
#include "FollowLinkIfGreater.h"
#include <memory>

class AlgorithmFactory
{
	private:
		//static bool exists;
		AlgorithmFactory();
	public:
		static AlgorithmFactory *GetInstance();
		~AlgorithmFactory();
		Algorithm* GetAlgorithmObject(Algorithm* p, string name);
};

#endif