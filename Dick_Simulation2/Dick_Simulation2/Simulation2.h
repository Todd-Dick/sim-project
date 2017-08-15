//---------------------------------------------
// Simulation2.h
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#pragma once
#ifndef SIMULATION2_H
#define SIMULATION2_H

#include "OilWellFactory.h"
#include "OilWell.h"
#include "Sensor.h"

#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
#include <conio.h>
#include <stdio.h>
#include <cctype>
#include <cstdio>

using namespace std;

class Simulation 
{
	private:
		OWF * m_pWF;
		void IntializeSim();
		int m_iNumberWells;
		vector<Well> m_vWells;
		vector<Well> m_vActiveWells;
		int m_iNumActiveWells;
		vector<Well> m_vInactiveWells;
		int m_iNumInactiveWells;
		vector<Sensor> m_vActiveSens;
		int m_iActiveSens;
		vector<Sensor> m_vInactiveSens;
		int m_iInactiveSens;
		//timerStuff
		struct _timeb   tStruct;
		double          thisTime;
		double          outputTime;
		bool            done;  // while loop flag
		//keyhitstuff
		int hit;     // key hit flag
		char ch;     // character key which was hit

		//timer loop methods
		void EnterToContinue();
		void PrintWells();
		void PrintOptions();
		//input handler methods
		void HandleW();
		void WellAdd();	//add a well to the sim
		void WellRemove();	//remove a well from the sim
		void HandleS();
		void SenAdd(int index);
		void SenRemove(int index);
	public:
		Simulation();
		~Simulation();
		
		void RunSim();
		
};

#endif