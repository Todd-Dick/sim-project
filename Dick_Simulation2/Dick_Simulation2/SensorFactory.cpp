//---------------------------------------------
// SensorFactory.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "SensorFactory.h"


SensorFactory::SensorFactory()
{
	f = NULL;  //algorithm factory pointer
	f = f->GetInstance();
}

SensorFactory *SensorFactory::GetInstance()
{
	static SensorFactory* instance = NULL;
	if (instance == 0)
	{
		instance = new SensorFactory();
	}
	return instance;
}

SensorFactory::~SensorFactory()
{
	delete f;
}

Sensor SensorFactory::GetSensorObject(SensorInfo o)
{
	Sensor s;
	string str;

	//start creation

	//set type
	str = o.GetType();
	s.SetType(str);
	//set class
	str = o.GetClass();
	s.SetClass(str);
	//set display name
	str = o.GetDisplayName();
	s.SetDisplayName(str);
	//set min value
	str = o.GetMin();
	if (str == "UNDEFINED")
	{
		s.SetMinValue(1.0);
	}
	else
	{
		s.SetMinValue(atof(str.c_str()));
	}
	//set max value
	str = o.GetMax();
	if (str == "UNDEFINED")
	{
		s.SetMaxValue(1.0);
	}
	else
	{
		s.SetMaxValue(atof(str.c_str()));
	}
	//set step value
	str = o.GetStep();
	s.SetStepValue(atof(str.c_str()));
	//set unit name
	str = o.GetUnits();
	s.SetUnits(str);
	//set unit abbreviation name
	str = o.GetAbbreviation();
	s.SetUnitAbbreviation(str);
	//set algorithm name and algorithm object
	str = o.GetAlgorithmName();
	s.SetAlgorithmName(str);
	auto p = s.GetDataGenerator();
	p = f->GetAlgorithmObject(p, str);
	s.SetDataGenerator(p);
	//set link name and hasLink
	str = o.GetLinkSensorName();
	s.SetLinkSensor(str);
	if (str != "NONE")
		s.SetHasLink();
	//set current value to max if stepdecmax2min else current = min
	str = s.GetDataGenName();
	double d;
	if (str == "STEPDEC_MAX2MIN")
	{
		d = s.GetMax();
		s.SetCurrentValue(d);
	}
	else
	{
		d = s.GetMin();
		s.SetCurrentValue(d);
	}
	//end creation
	return s;
}