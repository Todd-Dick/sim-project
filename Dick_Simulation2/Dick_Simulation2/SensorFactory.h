//---------------------------------------------
// SensorFactory.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "Sensor.h"
#include "AlgorithmFactory.h"
#include "SensorInfo.h"

class SensorFactory
{
	private:
		SensorFactory();
		AlgorithmFactory *f;
	public:
		static SensorFactory* GetInstance();
		~SensorFactory();
		Sensor GetSensorObject(SensorInfo o);
		
};

#endif