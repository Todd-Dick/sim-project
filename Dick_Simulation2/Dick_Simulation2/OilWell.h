//---------------------------------------------
// OilWell.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef OILWELL_H
#define OILWELL_H

#include "Sensor.h"
#include "WellInfo.h"

#include <string>
#include <vector>

using namespace std;

class Well
{
	private:
		string m_sWellID;
		string m_sOperatorID;
		WellInfo m_oWellInfo;
		vector<Sensor> m_vSensors;
		bool m_bIsActive;
	public:
		Well();
		~Well();
		//setters
		void SetWellID(string aString);
		void SetOperatorID(string aString);
		void SetWellinfo(WellInfo anObject);
		void SetSensors(vector<Sensor> v);
		void ToggleActiveState();
		//getters
		bool GetActiveState();
		string GetWellID();
		string GetOperatorID();
		WellInfo GetWellInfo();
		vector<Sensor> GetSensors();
		//helper
		void PrintAWell(Well object);
		
};

#endif