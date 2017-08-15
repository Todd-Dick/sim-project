//---------------------------------------------
// MyParser.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "MyParser.h"

Parser::Parser()
{
	InitializeParser();
}

Parser::~Parser()
{

}

Parser* Parser::GetInstance()
{
	static Parser *theInstance = NULL;
	if (theInstance == 0)
	{
		theInstance = new Parser();
	}
	else
		return theInstance;
	return theInstance;
}

void Parser::InitializeParser()
{
	m_iNumWells = 0; //number of wells in the data file
	m_iNumSensors = 0; //number of sensor types.
	m_sFileName = "";
	m_iSensorsPerWell = 0;
	m_vSensorInfo;
	m_vWellInfo;
	GetFileName();
	SetWellInfo();
	SetSensorInfo();
}

//MARK::SETTER METHODS
//setter methods
void Parser::GetFileName()
{
	string banner = string(50, '=');
	string assignment = "Todd Dick: Programming Assignment 2";
	string programName = "Simulation 2 for CS307 Summer '17";
	string aSpace = string(10, ' ');
	string pSpace = string(10, ' ');
	cout << banner << endl;
	cout << "|" << aSpace << assignment << string(3,' ') << "|" << endl;
	cout << "|" << pSpace << programName << string(5,' ') << "|" << endl;
	cout << banner << endl;
	cout << endl << "Enter the name of the data file:\n";
	cout << string(20, ' ');
	getline(cin,m_sFileName);
}

void Parser::SetSensorInfo()
{
	inFile.open(m_sFileName.c_str(), ifstream::in);
	if (inFile.is_open())
	{
		string s = GetNextLine();
		SensorInfo o;
		while (s != "</SENSORS>")
		{	
			if (s == "<TYPE>")
			{
				s = GetNextLine();
				o.SetType(s);
				s = GetNextLine();
			}
			else if (s == "<CLASS>")
			{
				s = GetNextLine();
				o.SetClass(s);
				s = GetNextLine();
			}
			else if (s == "DISPLAYNAME")
			{
				s = GetNextLine(); 
				o.SetDisplayName(s);
				s = GetNextLine();
			}
			else if (s == "<MINVALUE>")
			{
				s = GetNextLine();
				o.SetMin(s);
				s = GetNextLine();
			}
			else if (s == "<MAXVALUE>")
			{
				s = GetNextLine();
				o.SetMax(s);
				s = GetNextLine();
			}
			else if (s == "<STEPVALUE>")
			{
				s = GetNextLine();
				o.SetStep(s);
				s = GetNextLine();
			}
			else if (s == "<UNITS>")
			{
				s = GetNextLine();
				o.SetUnits(s);
				s = GetNextLine();
			}
			else if (s == "<UNITABBREVIATION>")
			{
				s = GetNextLine();
				o.SetAbbreviation(s);
				s = GetNextLine();
			}
			else if (s == "<DATAGENALGORITHM>")
			{
				s = GetNextLine();
				o.SetAlgorithmName(s);
				s = GetNextLine();
			}
			else if (s == "<LINK_SENSOR>")
			{
				s = GetNextLine();
				o.SetLinkSensorName(s);
				s = GetNextLine();
			}
			else if (s == "</SENSOR_TYPE>")
			{
				m_vSensorInfo.push_back(o);
				m_iNumSensors++;
				s = GetNextLine();
			}
			else
				s = GetNextLine();

		}
		inFile.close();
		return;
	}
	else if (!inFile.is_open())
	{
		cout << "Error Opening File. Terminating Program." << endl;
		exit(9);
	}
}

void Parser::SetWellInfo()
{
	inFile.open(m_sFileName.c_str(), ifstream::in);
	if (inFile.is_open())
	{
		string s = GetNextLine();
		WellInfo w;
		vector<string> v;
		while (s != "</WELLS>")
		{
			if (s == "<WELLID>")
			{
				s = GetNextLine();
				w.SetID(s);
				s = GetNextLine();
			}
			else if (s == "<OPERATOR>")
			{
				s = GetNextLine();
				w.SetOperator(s);
				s = GetNextLine();
			}
			else if (s == "<SENSOR>")
			{
				s = GetNextLine();
				v.push_back(s);
				m_iSensorsPerWell++;
				s = GetNextLine();
			}
			else if (s == "</WELL>")
			{
				w.SetSensorTypes(v);
				v.clear();
				w.SetNumSensorTypes(m_iSensorsPerWell);
				m_vWellInfo.push_back(w);
				m_iSensorsPerWell = 0;
				m_iNumWells++;
				s = GetNextLine();
			}
			else
				s = GetNextLine();
		}
		inFile.close();
		return;
	}
	else if (!inFile.is_open())
	{
		cout << "Error Opening File. Terminating Program." << endl;
		exit(9);
	}
}

string Parser::GetNextLine()
{
	string buffer;
	if (inFile.good())
	{
		getline(inFile, buffer);
		ClearWhiteSpace(buffer);
		return buffer;
	}
	else
	{
		cout << "Data File unexpectedly closed.\n Exiting program.\n";
		exit(9);
	}
}

//This is from https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
void Parser::ClearWhiteSpace(string &s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(),
		not1(ptr_fun<int, int>(isspace))));
}

//MARK:://GETTER METHODS
//getter methods
vector<SensorInfo> Parser::GetSensorInfo()
{
	return m_vSensorInfo;
}

vector<WellInfo> Parser::GetWellInfo()
{
	return m_vWellInfo;
}

int Parser::GetNumSensors()
{
	return m_iNumSensors;
}

int Parser::GetNumWells()
{
	return m_iNumWells;
}