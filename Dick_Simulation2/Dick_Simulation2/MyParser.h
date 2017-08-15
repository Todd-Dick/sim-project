//---------------------------------------------
// MyParser.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef MYPARSER_H
#define MYPARSER_H

#include "WellInfo.h"
#include "SensorInfo.h"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Parser
{
	private:
		int m_iNumWells;
		int m_iNumSensors;
		int m_iSensorsPerWell;
		string m_sFileName;
		ifstream inFile;
		vector<SensorInfo> m_vSensorInfo;
		vector<WellInfo> m_vWellInfo;

		Parser();
		string GetNextLine();
		void ClearWhiteSpace(string &s);
		//setter methods
		void InitializeParser();
		void GetFileName();
		void SetSensorInfo();
		void SetWellInfo();
		
	public:
		Parser* GetInstance();
		~Parser();
		//getter methods
		vector<SensorInfo> GetSensorInfo();
		vector<WellInfo> GetWellInfo();
		int GetNumSensors();
		int GetNumWells();
		

};

#endif