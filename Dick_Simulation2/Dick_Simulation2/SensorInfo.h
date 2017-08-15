//---------------------------------------------
// SensorInfo.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef SENSORINFO_H
#define SENSORINFO_H

#include <string>

using namespace std;

class SensorInfo
{
	private:
		string m_sType;
		string m_sClass;
		string m_sDisplayName;
		string m_sMinValue;
		string m_sMaxValue;
		string m_sStepValue;
		string m_sUnits;
		string m_sUnitAbbreviation;
		string m_sAlgorithmName;
		string m_sLinkSensor;
	public:
		SensorInfo();
		~SensorInfo();
		//setter methods
		void SetType(string aString);
		void SetClass(string aString);
		void SetDisplayName(string aString);
		void SetMin(string aString);
		void SetMax(string aString);
		void SetStep(string aString);
		void SetUnits(string aString);
		void SetAbbreviation(string aString);
		void SetAlgorithmName(string aString);
		void SetLinkSensorName(string aString);
		//getter methods
		string GetType();
		string GetClass();
		string GetDisplayName();
		string GetMin();
		string GetMax();
		string GetStep();
		string GetUnits();
		string GetAbbreviation();
		string GetAlgorithmName();
		string GetLinkSensorName();
};

#endif