//---------------------------------------------
// WellInfo.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "WellInfo.h"

WellInfo::WellInfo()
{
	m_sID = "";
	m_sOperator = "";
	m_vSensorTypes;
	m_iNumSensorTypes = 0;
}

WellInfo::~WellInfo()
{

}

//MARK: Setter Methods
// setter methods

void WellInfo::SetID(string s)
{
	m_sID = s;
}

void WellInfo::SetOperator(string s)
{
	m_sOperator = s;
}

void WellInfo::SetSensorTypes(vector<string> v)
{
	m_vSensorTypes = v;
}

void WellInfo::SetNumSensorTypes(int i)
{
	m_iNumSensorTypes = i;
}

string WellInfo::GetID()
{
	return m_sID;
}

string WellInfo::GetOperator()
{
	return m_sOperator;
}

vector<string> WellInfo::GetSensorTypes()
{
	return m_vSensorTypes;
}

int WellInfo::GetNumSensorTypes()
{
	return m_iNumSensorTypes;
}