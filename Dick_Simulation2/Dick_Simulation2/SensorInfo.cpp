//---------------------------------------------
// SensorInfo.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "SensorInfo.h"

SensorInfo::SensorInfo()
{
	m_sType ="";
	m_sClass = "";
	m_sDisplayName = "";
	m_sMinValue = "";
	m_sMaxValue = "";
	m_sStepValue = "";
	m_sUnits = "";
	m_sUnitAbbreviation = "";
	m_sAlgorithmName = "";
	m_sLinkSensor = "";
}

SensorInfo::~SensorInfo()
{

}

//MARK::SETTER METHODS
//setter methods
void SensorInfo::SetType(string s)
{
	m_sType = s;
}

void SensorInfo::SetClass(string s)
{
	m_sClass = s;
}

void SensorInfo::SetDisplayName(string s)
{
	m_sDisplayName = s;
}

void SensorInfo::SetMin(string s)
{
	m_sMinValue = s;
}

void SensorInfo::SetMax(string s)
{
	m_sMaxValue = s;
}

void SensorInfo::SetStep(string s)
{
	m_sStepValue = s;
}

void SensorInfo::SetUnits(string s)
{
	m_sUnits = s;
}

void SensorInfo::SetAbbreviation(string s)
{
	m_sUnitAbbreviation = s;
}

void SensorInfo::SetAlgorithmName(string s)
{
	m_sAlgorithmName = s;
}

void SensorInfo::SetLinkSensorName(string s)
{
	m_sLinkSensor = s;
}

//MARK::GETTER METHODS
//getter methods
string SensorInfo::GetType()
{
	return m_sType;
}

string SensorInfo::GetClass()
{
	return m_sClass;
}

string SensorInfo::GetDisplayName()
{
	return m_sDisplayName;
}

string SensorInfo::GetMin()
{
	return m_sMinValue;
}

string SensorInfo::GetMax()
{
	return m_sMaxValue;
}

string SensorInfo::GetStep()
{
	return m_sStepValue;
}

string SensorInfo::GetUnits()
{
	return m_sUnits;
}

string SensorInfo::GetAbbreviation()
{
	return m_sUnitAbbreviation;
}

string SensorInfo::GetAlgorithmName()
{
	return m_sAlgorithmName;
}

string SensorInfo::GetLinkSensorName()
{
	return m_sLinkSensor;
}