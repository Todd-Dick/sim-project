//---------------------------------------------
// Sensor.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include "Algorithm.h"

class AlgorithmFactory;

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Sensor
{
	private:
		//all of these variables are read in as strings, conversions handled elswhere
		string m_sType;
		string m_sClass;
		string m_sDisplayName;
		double m_dMinValue;
		double m_dMaxValue;
		double m_dStepValue;
		string m_sUnits;
		string m_sUnitAbbreviation;
		string m_sAlgorithmName;
		string m_sLinkSensor;
		//helper value
		double m_dCurrentValue;
		double m_dLinkValue;
		bool m_bIsActive;
		bool m_bHasLink;
		Algorithm *m_pDataGenerator;
	public:
		// Constructor
		Sensor();
		~Sensor();

		//each sensor will have a datagen object
		// This pointer has to be public
		
		
		//setter methods
		void SetType(string aString);
		void SetClass(string aString);
		void SetDisplayName(string aString);
		void SetMinValue(double aDouble);
		void SetMaxValue(double aDouble);
		void SetStepValue(double aDouble);
		void SetUnits(string aString);
		void SetUnitAbbreviation(string aString);
		void SetAlgorithmName(string aString);
		void SetLinkSensor(string aString);
		void SetCurrentValue(double aDouble);
		void SetLinkValue(double aDouble);
		void ToggleState();
		void SetHasLink();
		void SetDataGenerator(Algorithm* p);
		// helper method
		void PrintASensor(Sensor &object);
		// getter methods
		string GetDataGenName();
		Algorithm* GetDataGenerator();
		string GetType();
		string GetClass();
		string GetDisplayValue();
		double GetMin();
		double GetMax();
		double GetStep();
		string GetUnits();
		string GetAbbreviation();
		string GetLinkSensor();
		double GetCurrent();
		double GetLinkValue();
		bool GetIsActive();
		bool GetHasLink();

};

#endif