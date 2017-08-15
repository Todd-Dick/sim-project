//---------------------------------------------
// Sensor.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "Sensor.h"

Sensor::Sensor()
{
	m_sType ="";
	m_sClass = "";
	m_sDisplayName = "";
	m_dMinValue = 0.0;
	m_dMaxValue = 0.0;
	m_dStepValue = 0.0;
	m_sUnits = "";
	m_sUnitAbbreviation = "";
	m_sAlgorithmName = "";
	m_sLinkSensor = "";
	m_dCurrentValue = 0.0;
	m_dLinkValue = 0.0;
	m_bIsActive = true;
	m_bHasLink = false;
	m_pDataGenerator = NULL;
}

Sensor::~Sensor()
{
	//delete m_pDataGenerator;
}

//MARK::SETTERS
// setter methods

void Sensor::SetType(string aString)
{
	m_sType = aString;
}

void Sensor::SetClass(string aString)
{
	m_sClass = aString;
}

void Sensor::SetDisplayName(string aString)
{
	m_sDisplayName = aString;
}

void Sensor::SetMinValue(double aDouble)
{
	m_dMinValue = aDouble;
}

void Sensor::SetMaxValue(double aDouble)
{
	m_dMaxValue = aDouble;
}

void Sensor::SetStepValue(double aDouble)
{
	m_dStepValue = aDouble;
}

void Sensor::SetUnits(string aString)
{
	m_sUnits = aString;
}

void Sensor::SetUnitAbbreviation(string aString)
{
	m_sUnitAbbreviation = aString;
}

void Sensor::SetAlgorithmName(string aString)
{
	m_sAlgorithmName = aString;
}

void Sensor::SetLinkSensor(string aString)
{
	m_sLinkSensor = aString;
}

void Sensor::SetCurrentValue(double aDouble)
{
	m_dCurrentValue = aDouble;
}

void Sensor::SetLinkValue(double aDouble)
{
	m_dLinkValue = aDouble;
}

void Sensor::ToggleState()
{
	if (!m_bIsActive)
		m_bIsActive = true;
	else
		m_bIsActive = false;
}

void Sensor::SetHasLink()
{
	m_bHasLink = true;
}

void Sensor::SetDataGenerator(Algorithm* p)
{
	m_pDataGenerator = p;
}

//MARK: HELPER
// helper print method
void Sensor::PrintASensor(Sensor &s)
{
	double d = 0.0;
	Algorithm *p = s.GetDataGenerator();
	string str = s.GetDataGenName();
	if (str == "FOLLOWLINK_IFCHANGED" || str == "FOLLOWLINK_IFGREATER")
	{
		d = p->GetValue(s.GetCurrent(), s.GetLinkValue());
	}
	else if (str == "RAND_MIN2MAX")
	{
		d = p->GetValue(s.GetMin(), s.GetMax());
	}
	else if (str == "STEPDEC_MAX2MIN")
	{
		d = p->GetValue(s.GetMin(), s.GetCurrent(), s.GetStep());
	}
	else if (str == "STEPINC_MIN2MAX")
	{
		d = p->GetValue(s.GetMin(), s.GetMax(), s.GetCurrent(), s.GetStep());
	}
	s.SetCurrentValue(d);
	cout.flush();
	cout << string(12, ' ') << s.m_sType << right << "\t" << d << "  " << s.m_sUnitAbbreviation << endl;
}

//MARK: GETTER METHODS
// getter methods
string Sensor::GetDataGenName()
{
	return m_sAlgorithmName;
}

Algorithm* Sensor::GetDataGenerator()
{
	return m_pDataGenerator;
}

string Sensor::GetType()
{
	return m_sType;
}

string Sensor::GetClass()
{
	return m_sClass;
}

string Sensor::GetDisplayValue()
{
	return m_sDisplayName;
}

double Sensor::GetMin()
{
	return m_dMinValue;
}

double Sensor::GetMax()
{
	return m_dMaxValue;
}

double Sensor::GetStep()
{
	return m_dStepValue;
}

string Sensor::GetUnits()
{
	return m_sUnits;
}

string Sensor::GetAbbreviation()
{
	return m_sUnitAbbreviation;
}

string Sensor::GetLinkSensor()
{
	return m_sLinkSensor;
}

double Sensor::GetCurrent()
{
	return m_dCurrentValue;
}

double Sensor::GetLinkValue()
{
	return m_dLinkValue;
}

bool Sensor::GetIsActive()
{
	return m_bIsActive;
}

bool Sensor::GetHasLink()
{
	return m_bHasLink;
}

