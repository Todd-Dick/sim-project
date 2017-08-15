//---------------------------------------------
// AlgorithmFactory.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "AlgorithmFactory.h"

AlgorithmFactory::AlgorithmFactory()
{

}

AlgorithmFactory::~AlgorithmFactory()
{

}

AlgorithmFactory *AlgorithmFactory::GetInstance()
{
	static AlgorithmFactory * instance = NULL;
	if (instance == 0)
	{
		instance = new AlgorithmFactory();
		//exists = true;
	}
	return instance;
}

Algorithm* AlgorithmFactory::GetAlgorithmObject(Algorithm* p, string name)
{
	if (name == "RAND_MIN2MAX")
	{
		RM2M* ptemp = new RM2M();
		p = dynamic_cast<RM2M*>(ptemp);
	}
	else if (name == "STEPDEC_MAX2MIN")
	{
		SDM2M* ptemp = new SDM2M();
		p = dynamic_cast<SDM2M*>(ptemp);
	}
	else if (name == "STEPINC_MIN2MAX")
	{
		SIM2M* ptemp = new SIM2M();
		p = dynamic_cast<SIM2M*>(ptemp);
	}
	else if (name == "FOLLOWLINK_IFCHANGED")
	{
		FLifC* ptemp = new FLifC();
		p = dynamic_cast<FLifC*>(ptemp);
	}
	else if (name == "FOLLOWLINK_IFGREATER")
	{
		FLifG* ptemp = new FLifG();
		p = dynamic_cast<FLifG*>(ptemp);
	}
	return p;
}