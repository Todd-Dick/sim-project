//---------------------------------------------
// OilWellFactory.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef OILWELLFACTORY_H
#define OILWELLFACTORY_H

#include "OilWell.h"
#include "Sensor.h"
#include "WellInfo.h"
#include "SensorInfo.h"
#include "MyParser.h"
#include "SensorFactory.h"

class OWF
{
	private:
		//variables
		Parser *m_pParser;
		SensorFactory *m_pSensorFactory;
		vector<WellInfo> m_vWellInfo;
		vector<SensorInfo> m_vSensorTypes;
		int m_iNumWells;
		int m_iIndex;
		int m_iNumSensorTypes;
		//methods
		OWF();
		void InitializeOWF();
		Well CreateWell(WellInfo object); //internal creation method

	public:
		static OWF* GetInstance();
		~OWF();
		Well GetWell(int index); //returns a Well to calling object
		void PrintWell(Well &object);
		int GetNumWells();
		
};

#endif