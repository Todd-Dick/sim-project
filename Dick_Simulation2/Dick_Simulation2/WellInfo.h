//---------------------------------------------
// WellInfo.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef WELLINFO_H
#define WELLINFO_H

#include <vector>
#include <string>

using namespace std;

class WellInfo
{
	private:
		string m_sID;
		string m_sOperator;
		vector<string> m_vSensorTypes;
		int m_iNumSensorTypes;
	public:
		WellInfo();
		~WellInfo();

		//setter methods
		void SetID(string aWellID);
		void SetOperator(string anOperatorID);
		void SetSensorTypes(vector<string> SensorTypes);
		void SetNumSensorTypes(int anInt);

		//getter methods
		string GetID();
		string GetOperator();
		vector<string> GetSensorTypes();
		int GetNumSensorTypes();
};

#endif