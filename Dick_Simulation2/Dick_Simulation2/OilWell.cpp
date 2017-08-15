//---------------------------------------------
// OilWell.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "OilWell.h"

Well::Well()
{
	m_sWellID = "";
	m_sOperatorID = "";
	m_oWellInfo;
	m_vSensors;
	m_bIsActive = false;
}

Well::~Well()
{

}

//MARK: SETTER METHODS
//setter methods

void Well::SetWellID(string s)
{
	m_sWellID = s;
}

void Well::SetOperatorID(string s)
{
	m_sOperatorID = s;
}

void Well::SetWellinfo(WellInfo o)
{
	m_oWellInfo = o;
}

void Well::SetSensors(vector<Sensor> v)
{
	m_vSensors = v;
}

void Well::ToggleActiveState()
{
	if (m_bIsActive)
		m_bIsActive = false;
	else m_bIsActive = true;
}

//MARK: GETTER METHODS
//getter methods

bool Well::GetActiveState()
{
	return m_bIsActive;
}

string Well::GetWellID()
{
	return m_sWellID;
}

string Well::GetOperatorID()
{
	return m_sOperatorID;
}

WellInfo Well::GetWellInfo()
{
	return m_oWellInfo;
}

vector<Sensor> Well::GetSensors()
{
	return m_vSensors;
}

//MARK HELPER METHODS
//helper methods

void Well::PrintAWell(Well w)
{
	cout << "\tWellID:  " << m_sWellID << endl << "\tOperator ID:  " << m_sOperatorID << endl;
}