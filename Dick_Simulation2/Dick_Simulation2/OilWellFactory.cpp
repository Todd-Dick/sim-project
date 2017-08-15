//---------------------------------------------
// OilWellFactory.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "OilWellFactory.h"

OWF::OWF()
{
	InitializeOWF();
}

OWF *OWF::GetInstance()
{
	static OWF* instance = NULL;
	if (instance == 0)
	{
		instance = new OWF;
	}
	return instance;
}

void OWF::InitializeOWF()
{
	//initialize Sensor Facotry object pointer
	m_pSensorFactory = NULL;
	m_pSensorFactory = m_pSensorFactory->GetInstance();
	//initialize Parser object pointer
	m_pParser = NULL;
	m_pParser = m_pParser->GetInstance();
	m_vWellInfo;
	//initialize vector of WellInfo Objects (used to create wells)
	m_vWellInfo = m_pParser->GetWellInfo();
	//Get number of wells in simulation  <=> actual(sizeof(m_vWellInfo>))...calling that gives data size, not how many objects are in the vector
	m_iNumWells = m_pParser->GetNumWells();
	m_iIndex = 0;//index for m_vWellInfo

	m_vSensorTypes;
	//initialize vector of SensorInfo Objects (used to create sensors)
	m_vSensorTypes = m_pParser->GetSensorInfo();
	//Get number of sensor types in the simulation <=> actual(sizeof(m_vSenserInfo))...calling that gives data size, not how many objects are in the vector
	m_iNumSensorTypes = m_pParser->GetNumSensors();

}

OWF::~OWF()
{
	delete m_pParser;
	delete m_pSensorFactory;
}

Well OWF::GetWell(int index)
{	
	Well w;
	m_iIndex = index;
	if (m_iIndex < m_iNumWells)
	{
		w = CreateWell(m_vWellInfo[m_iIndex]);
		return w;
	}
	else
		return w;
}

Well OWF::CreateWell(WellInfo o)
{
	Well w;
	vector<Sensor> aSensorVector;
	w.SetWellID(o.GetID());
	w.SetOperatorID(o.GetOperator());
	w.SetWellinfo(o);
	int numSensorsThisWell = o.GetNumSensorTypes();
	vector<string> typesThisWell = o.GetSensorTypes();
	//take numsensors this well create a for loop; create sensor object;
	for (int i = 0; i < numSensorsThisWell; i++)
	{
		Sensor sen;
		string str = typesThisWell[i];
		/*take m_iNumSensorTypes create a for loop; compare typesthiswell[index] to m_vSensorTypes.getType();
			if == use sensorfactory to create the sensor; pushback to aSensorVector*/
		for (int j = 0; j < m_iNumSensorTypes; j++)
		{
			string str2 = m_vSensorTypes[j].GetType();
			if (str2 == str)
			{
				SensorInfo temp = m_vSensorTypes[j];
				sen = m_pSensorFactory->GetSensorObject(temp);
				aSensorVector.push_back(sen);

			}
		}
	}
	w.SetSensors(aSensorVector);
	return w;
}

void OWF::PrintWell(Well &w)
{
	WellInfo info = w.GetWellInfo(); //to get an index max
	vector<Sensor> theseSensors = w.GetSensors(); //the sensors for this well
	int value = info.GetNumSensorTypes(); //the inex max
	w.PrintAWell(w);
	for (int i = 0; i < value; i++)
	{
		if (theseSensors[i].GetIsActive())
		{
			Sensor tempSen = theseSensors[i];
			//check for link
			if (tempSen.GetHasLink())
			{
				string str = tempSen.GetLinkSensor();
				for (int j = 0; j < value; j++)
				{
					string str2 = theseSensors[j].GetType();
					if (str == str2)
					{
						double a = theseSensors[j].GetCurrent();
						theseSensors[i].SetLinkValue(a);
					}
				}
			}
			tempSen.PrintASensor(theseSensors[i]);
			w.SetSensors(theseSensors);
		}
	}

}

int OWF::GetNumWells()
{
	return m_iNumWells;
}