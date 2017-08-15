//---------------------------------------------
// main.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "Simulation2.h"



//MARK: UNIT TESTS


//algorithm factory

//#include "Sensor.h"
//#include "AlgorithmFactory.h"
//#include "Algorithm.h"
//#include "RandMin2Max.h"
//#include "FollowLinkIfGreater.h"
//#include "FollowLinkIfChanged.h"
//#include <windows.h>
//void GetAlgorithmObject()
//{
//	//FLifG a;
//	Sensor s;
//	AlgorithmFactory *f;
//	s.SetAlgorithmName("STEPDEC_MAX2MIN");
//	f = AlgorithmFactory::GetInstance();
//	string algoName = s.GetDataGenName();
//	auto p = s.GetDataGenerator();
//	cout << " " << endl;
//	p = f->GetAlgorithmObject(p, algoName);
//	s.SetDataGenerator(p);
//	double temp = 500.0;
//	for (int i = 0; i < 10;i++)
//	{
//		temp = p->GetValue(0.0, temp, 10.0);
//		cout << "Temp = " << temp << ".\n";
//		Sleep(5000);
//	}
//	cout << "Press Enter to Continue...\n";
//	//cin.ignore();
//	cin.get();
//
//}

//Sensor GetSensorObject(Sensor a)
//{
//	
//	a.SetAlgorithmName("test");
//	Sensor b;
//	b = a;
//	cout << "Press Enter to Continue...\n";
//	cin.get();
//	return b;
//}

//#include "MyParser.h"
//void TestParser()
//{
//	static Parser *p = NULL;
//	p = p->GetInstance();
//	vector<WellInfo> w;
//	vector<SensorInfo> s;
//
//	int iw = p->GetNumWells();
//	int is = p->GetNumSensors();
//
//	w = p->GetWellInfo();
//	s = p->GetSensorInfo();
//	
//	cout << "Press Enter to Continue...\n";
//	cin.get();
//
//}

//#include "Sensor2.h"
//#include "Algorithm.h"
//#include "RandMin2Max.h"
//void test()
//{
//	//Algorithm o;
//	Sensor2 s;
//	//o = s.GetDataGenerator();
//	RM2M *p;
//	void *o;
//	p = new RM2M;
//	o = dynamic_cast<RM2M*>(p);
//	
//}

int main()
{
	//GetAlgorithmObject();
	//Sensor a;
	//a = GetSensorObject(a);
	//TestParser();
	//test();
	Simulation s;
	s.RunSim();
	
	return 12;
}
