//---------------------------------------------
// Simulation2.cpp
// author: Todd Dick
// assignment: Programming Assignment2
// course: CS307
// instructor: Dr. Coleman
// date: July 2017
//
// This program is entirely my own work
//-------------------------------------------

#include "Simulation2.h"

Simulation::Simulation()
{
	IntializeSim();
}

Simulation::~Simulation()
{
	delete m_pWF;
}

void Simulation::IntializeSim()
{
	m_vWells;
	m_iNumActiveWells = 0;
	m_vActiveWells;
	m_iNumInactiveWells = 0;
	m_vInactiveWells;
	done = false;
	tStruct;
	thisTime = 0.0;
	outputTime = 0.0;
	m_pWF = NULL;
	m_pWF = m_pWF->GetInstance();
	m_iNumberWells = m_pWF->GetNumWells();
	cout << "Setting up Simulation...\n";
	for (int i = 0; i < m_iNumberWells; i++)
	{
		Well aWell;
		aWell = m_pWF->GetWell(i);
		m_vWells.push_back(aWell);
	}
}

void Simulation::EnterToContinue()
{
	cout << "Press Enter to Continue...\n";
	cin.ignore();
	cin.get();
	return;
}

void Simulation::RunSim()
{
	//set up timer loop
	_ftime(&tStruct);	// Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 5.0; // Set next 5 second interval time

	while (!done)     // Start an infiite loop
	{
		_ftime(&tStruct);    // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
		// Check for 5 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			PrintWells();
			PrintOptions();
			outputTime += 5.0;
		}
		hit = _kbhit();
		if (hit)
		{
			ch = _getch();
			ch = toupper(ch);
			if (ch == 'Q')	// Quit Sim
			{
				done = true;
			}
			else if (ch == 'W')	//Handle add or remove well
			{
				HandleW();
				continue;
			}
			else if (ch == 'S') //Handle add or remove sensor
			{
				if (m_iNumActiveWells == 0)
				{
					cout << "There are no active wells to add or remove sensors on. Returning to report\n";
					return;
				}
				else
					HandleS();
				continue;
			}
			else     //continue printing report
			{
				continue;
			}
				
		}
	}
}

void Simulation::PrintWells()
{
	m_vActiveWells.clear();
	m_iNumActiveWells = 0;
	m_vInactiveWells.clear();
	m_iNumInactiveWells = 0;
	for (int i = 0; i < m_iNumberWells; i++)
	{
		if (m_vWells[i].GetActiveState())
		{
			m_vActiveWells.push_back(m_vWells[i]);
			m_iNumActiveWells++;
			m_pWF->PrintWell(m_vWells[i]);
		}
		else
		{
			m_vInactiveWells.push_back(m_vWells[i]);
			m_iNumInactiveWells++;
		}
	}
	if (!m_iNumActiveWells)
		cout << endl << "No Active Wells.\n";
	return;
}

void Simulation::PrintOptions()
{
	static string header = string(55, '=');
	static string well = "|  Press 'W' to add or remove a well from the report  |\n";
	static string sensor = "| Press 'S' to add or remove a sensor from the report |\n";
	static string quit = "| \t   Press 'Q' to end the simulation            |\n";
	cout << endl << header  << endl << well << sensor << quit << header << endl;
}

void Simulation::HandleW()
{
	cout << endl << "Press 'A' to add a well or 'R' to remove one\n";
	ch = _getch();
	ch = toupper(ch);
	if (ch == 'A')
	{
		if (m_iNumActiveWells == m_iNumberWells)
		{
			cout << "All wells being monitored.\n";
			return;
		}
		else
			WellAdd();
	}
	else if (ch == 'R')
	{
		if (m_iNumActiveWells == 0)
		{
			cout << "No wells being monitored.\n";
			return;
		}
		else
			WellRemove();
	}
	else if (ch != 'A' || ch != 'R')
	{
		cout << "Invalid choice. Try again.\n";
		HandleW();
	}
}

void Simulation::WellAdd()
{
	int choice = 0;
	for (int i = 0; i < m_iNumInactiveWells; i++)
	{
		cout << "\t" << i + 1 << ".  " << m_vInactiveWells[i].GetWellID() << endl;
	}
	cout << "Choose between 1 and " << m_iNumInactiveWells << endl;
	ch = _getch();
	const char * x = &ch;
	choice = atoi(x);
	if (choice < 1 || choice > m_iNumInactiveWells)
	{
		cout << "\tInvalid choice. Try again...\n";
		WellAdd();
	}
	else
	{
		string str = m_vInactiveWells[choice - 1].GetWellID();
		for (int i = 0; i < m_iNumberWells; i++)
		{
			string str2 = m_vWells[i].GetWellID();
			if (str == str2)
				m_vWells[i].ToggleActiveState();
		}
	}
}

void Simulation::WellRemove()
{
	int choice = 0;
	for (int i = 0; i < m_iNumActiveWells; i++)
	{
		cout << "\t" << i + 1 << ". " << m_vActiveWells[i].GetWellID() << endl;
	}
	cout << "Choose between 1 and " << m_iNumActiveWells << endl;
	ch = _getch();
	const char *x = &ch;
	choice = atoi(x);
	if (choice < 1 || choice > m_iNumActiveWells)
	{
		cout << "\tInvalid choice. Try again...\n";
		WellRemove();
	}
	else
	{
		string str = m_vActiveWells[choice - 1].GetWellID();
		for (int i = 0; i < m_iNumberWells; i++)
		{
			string str2 = m_vWells[i].GetWellID();
			if (str == str2)
				m_vWells[i].ToggleActiveState();
		}
	}
}

void Simulation::HandleS()
{
	int choice = 0;
	cout << endl << "Choose a well to (A)dd or (R)emove sensors on\n";
	for (int i = 0; i < m_iNumActiveWells; i++)
	{
		cout << "\t" << i + 1 << ". " << m_vActiveWells[i].GetWellID();
	}
	ch = _getch();
	const char* x = &ch;
	choice = atoi(x);
	int n = choice - 1;
	string str = m_vActiveWells[n].GetWellID();
	cout << "\tYou chose " << str << endl;
	for (int j = 0; j < m_iNumberWells; j++)
	{
		string str2 = m_vWells[j].GetWellID();
		if (str == str2)
			n = j;
	}
	cout << "Choose to (A)dd or (R)emove a sensor\n";
	ch = _getch();
	ch = toupper(ch);
	if (ch == 'A')
		SenAdd(n);
	else if (ch == 'R')
		SenRemove(n);
	else if (ch != 'A' || ch != 'R')
	{
		cout << "\tInvalid choice. Returning to reports...\n";
		return;
	}
}

void Simulation::SenAdd(int n)
{
	m_vInactiveSens.clear();
	m_iInactiveSens = 0;
	int choice = 0;
	WellInfo w = m_vWells[n].GetWellInfo();
	vector<Sensor> s = m_vWells[n].GetSensors();
	int max = w.GetNumSensorTypes();
	for (int i = 0; i < max; i++)
	{
		if (!s[i].GetIsActive())
		{
			m_vInactiveSens.push_back(s[i]);
			m_iInactiveSens++;
		}
	}
	if (m_iInactiveSens == 0)
	{
		cout << "No inactive sensors on this well. Returning to reports...\n";
		return;
	}
	else
	{
		for (int k = 0; k < m_iInactiveSens; k++)
		{
			cout << k + 1 << ".  " << m_vInactiveSens[k].GetType() << endl;
		}
		cout << "Choose between sensor 1 and " << m_iInactiveSens << " to activate\n";
		ch = _getch();
		const char *x = &ch;
		choice = atoi(x);
		int y = choice - 1;
		if (choice < 1 || choice > m_iInactiveSens)
		{
			cout << "Invalid choice. Returning to report...\n";
			return;
		}
		else
		{
			string str = m_vInactiveSens[y].GetType();
			for (int j = 0; j < max; j++)
			{
				string str2 = s[j].GetType();
				if (str == str2)
				{
					s[j].ToggleState();
				}
			}
			m_vWells[n].SetSensors(s);
		}
		return;
	}
}

void Simulation::SenRemove(int n)
{
	m_vActiveSens.clear();
	m_iActiveSens = 0;
	int choice = 0;
	vector<Sensor> s = m_vWells[n].GetSensors();
	WellInfo w = m_vWells[n].GetWellInfo();
	int max = w.GetNumSensorTypes();
	for (int i = 0; i < max; i++)
	{
		if (s[i].GetIsActive())
		{
			m_vActiveSens.push_back(s[i]);
			m_iActiveSens++;
		}
	}
	if (m_iActiveSens == 0)
	{
		cout << "No active sensors to remove. Returning to reports.\n";
		return;
	}
	else
	{
		for (int k = 0; k < m_iActiveSens; k++)
		{
			cout << k + 1 << ".  " << m_vActiveSens[k].GetType() << endl;
		}
		cout << "Choose between sensor 1 and " << m_iActiveSens << " to remove\n";
		ch = _getch();
		const char *x = &ch;
		choice = atoi(x);
		int y = choice - 1;
		if (choice < 1 || choice > m_iActiveSens)
		{
			cout << "Invalid choice. Returning to report...\n";
			return;
		}
		else
		{
			string str = m_vActiveSens[y].GetType();
			for (int j = 0; j < max; j++)
			{
				string str2 = s[j].GetType();
				if (str == str2)
				{
					s[j].ToggleState();
				}
			}
			m_vWells[n].SetSensors(s);
		}
	}
	return;
}