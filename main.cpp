/// \file

#include "stdafx.h"
#include "GA.h"
#include "DE.h"
#include "population.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>

using namespace std;

/*	\struct inputVariables
*	\brief This is a struct that can store all of the input values
*/

struct inputVariables
{
	double cr;
	int ns;
	int dim;
	double boundsL;
	double boundsU;
	int maxItr;
	double mrt;
	double mrg;
	double mpr;
	double er;
	double f;
	int strat;
	int evalID;
};

void run(char *argv);

/*	\brief	Main Function
*	\param	argc An integer argument count of the command line arguments
*	\param	argv An argument vector of the command line arguments
*	\return an integer 0 upon exit success
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Error: Invlalid Arguments" << endl;
		return 0;
	}
	else
	{
		run(argv[1]);
	}
	
    return 0;
}

/*	\brief	Run Function
*	\param	argv An argument vector of the command line arguments passed from Main
*/
void run(char *argv)
{
	//read in file, prepare variables for output
	fstream myfile;
	inputVariables arg;
	vector<double> outputVec1;
	vector<double> outputVec2;
	vector<double> outputVec3;
	myfile.open(argv);
	if (myfile.is_open())
	{
		string temp;
		
		char* inpTok;
		char* nextTok;
		while (getline(myfile, temp))
		{
			//read contents of file, save values to appropriate variables
			char *cstr = new char[temp.length() + 1];
			strcpy_s(cstr, temp.length()+1,temp.c_str());
			inpTok = strtok_s(cstr, ":", &nextTok);
			vector<string> tokVec;
			while (inpTok != NULL)
			{
				tokVec.push_back(inpTok);
				inpTok = strtok_s(NULL, ":", &nextTok);
			}
			if (tokVec.at(0).compare("cr") == 0)
				arg.cr = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("ns") == 0)
				arg.ns = stoi(tokVec.at(1));
			else if (tokVec.at(0).compare("dim") == 0)
				arg.dim = stoi(tokVec.at(1));
			else if (tokVec.at(0).compare("boundsL") == 0)
				arg.boundsL = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("boundsU") == 0)
				arg.boundsU = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("maxItr") == 0)
				arg.maxItr = stoi(tokVec.at(1));
			else if (tokVec.at(0).compare("mrt") == 0)
				arg.mrt = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("mrg") == 0)
				arg.mrg = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("mpr") == 0)
				arg.mpr = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("er") == 0)
				arg.er = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("f") == 0)
				arg.f = stod(tokVec.at(1));
			else if (tokVec.at(0).compare("strat") == 0)
				arg.strat = stoi(tokVec.at(1));
			else if (tokVec.at(0).compare("evalID") == 0)
				arg.evalID = stoi(tokVec.at(1));
		}
		string line;
		chrono::duration<double> elapsed1;
		chrono::duration<double> elapsed2;
		chrono::duration<double> elapsed3;
		while (true)
		{
			cout << ">Please input the desired algorithm designation (GA or DE):" << endl;
			cout << ">";
			getline(cin, line);
			if (line.compare("GA") == 0)
			{
				cout << ">Running Genetic Algorithm." << endl;
				auto stime1 = chrono::high_resolution_clock::now();
				GA runGenAlg1(arg.cr, arg.ns, arg.dim, arg.boundsL, arg.boundsU, arg.maxItr, arg.mrt, arg.mrg, arg.mpr, arg.er, arg.evalID);
				outputVec1 = runGenAlg1.gaBase();
				auto etime1 = chrono::high_resolution_clock::now();
				elapsed1 = etime1 - stime1;
				auto stime2 = chrono::high_resolution_clock::now();
				GA runGenAlg2(arg.cr, arg.ns, arg.dim + 10, arg.boundsL, arg.boundsU, arg.maxItr, arg.mrt, arg.mrg, arg.mpr, arg.er, arg.evalID);
				outputVec2 = runGenAlg2.gaBase();
				auto etime2 = chrono::high_resolution_clock::now();
				elapsed2 = etime2 - stime2;
				auto stime3 = chrono::high_resolution_clock::now();
				GA runGenAlg3(arg.cr, arg.ns, arg.dim + 20, arg.boundsL, arg.boundsU, arg.maxItr, arg.mrt, arg.mrg, arg.mpr, arg.er, arg.evalID);
				outputVec3 = runGenAlg3.gaBase();
				auto etime3 = chrono::high_resolution_clock::now();
				elapsed3 = etime3 - stime3;
				break;
			}
			else if (line.compare("DE") == 0)
			{
				cout << ">Running Differential Evolution Algorithm." << endl;
				auto stime1 = chrono::high_resolution_clock::now();
				DE runDifAlg1(arg.cr, arg.f, arg.boundsU, arg.boundsL, arg.dim, arg.ns, arg.maxItr, arg.evalID, arg.strat);
				outputVec1 = runDifAlg1.deBase();
				auto etime1 = chrono::high_resolution_clock::now();
				elapsed1 = etime1 - stime1;
				auto stime2 = chrono::high_resolution_clock::now();
				DE runDifAlg2(arg.cr, arg.f, arg.boundsU, arg.boundsL, arg.dim + 10, arg.ns, arg.maxItr, arg.evalID, arg.strat);
				outputVec2 = runDifAlg2.deBase();
				auto etime2 = chrono::high_resolution_clock::now();
				elapsed2 = etime2 - stime2;
				auto stime3 = chrono::high_resolution_clock::now();
				DE runDifAlg3(arg.cr, arg.f, arg.boundsU, arg.boundsL, arg.dim + 20, arg.ns, arg.maxItr, arg.evalID, arg.strat);
				outputVec3 = runDifAlg3.deBase();
				auto etime3 = chrono::high_resolution_clock::now();
				elapsed3 = etime3 - stime3;
				break;
			}
			else if (line.compare("exit") == 0)
			{
				cout << ">Logging off." << endl;
				return;
			}
			else
			{
				cout << ">Error: Designation: " << line << " not found." << endl;
			}
		}
		ofstream myfile("output.csv");
		for (int i = 0; i < arg.maxItr; i++)
		{
			myfile << outputVec1.at(i) << ",";
		}
		myfile << elapsed1.count() << "s" << endl;
		for (int i = 0; i < arg.maxItr; i++)
		{
			myfile << outputVec2.at(i) << ",";
		}
		myfile << elapsed2.count() << "s" << endl;
		for (int i = 0; i < arg.maxItr; i++)
		{
			myfile << outputVec3.at(i) << ",";
		}
		myfile << elapsed3.count() << "s" << endl;
	}
	else
	{
		cout << "Error: Could not open file." << endl;
		return;
	}
	
}

