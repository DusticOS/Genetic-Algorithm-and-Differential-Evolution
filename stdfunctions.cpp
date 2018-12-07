#include "stdafx.h"
#include "stdfunctions.h"


using namespace std;

//establish constants, pi and e
stdfunctions::stdfunctions()
{
	PI = 3.1415926535897;
	e = 2.71827;
}
stdfunctions::~stdfunctions()
{
}

//schwefel's algorithm, designation 0
double stdfunctions::schwefel(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size(); j++)
	{
		double x = inputVec.at(j);
		counter += (-1 * x) * sin(sqrt(fabs(x)));
	}
	return counter;
}
//dejongs algorithm 1, designation 1
double stdfunctions::dejong1(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size(); j++)
	{
		counter += pow(inputVec.at(j), 2);
	}
	return counter;
}
//rosenbrock algorithm, designation 2
double stdfunctions::rosenbrock(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += (100 * pow((pow(x, 2) - y), 2)) + pow((1 - x), 2);
	}
	return counter;
}
//rastgrin algorithm, designation 3
double stdfunctions::rastrigin(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size(); j++)
	{
		double x = inputVec.at(j);
		counter += pow(x, 2) - 10 * cos(2 * PI * x);
	}
	counter = counter * 2 * inputVec.size();
	return counter;
}
//griewangk algorithm, designation 4
double stdfunctions::griewangk(vector<double> inputVec)
{
	double counter = 0;
	double sub1 = 0;
	double sub2 = 0;
	for (int j = 0; j < inputVec.size(); j++)
	{
		double x = inputVec.at(j);
		sub1 += (pow(x, 2) / 4000);
		sub2 *= cos(x / sqrt(j + 1));
	}
	counter = 1 + sub1 - sub2;
	return counter;
}
//Sine Envelope Sine Wave, designation 5
double stdfunctions::sesw(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += 0.5 + (pow(sin(pow(x, 2) + pow(y, 2) - 0.5), 2)) / pow((1 + 0.001*(pow(x, 2) + pow(y, 2))), 2);
	}
	return (-1 * counter);
}
//Stretch V Sine Wave, designation 6
double stdfunctions::svsw(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += pow((pow(x, 2) + pow(y, 2)), 0.25) * pow(sin(50 * pow((pow(x, 2) + pow(y, 2)), 0.1)), 2) + 1;
	}
	return counter;
}
//ackley algorithm 1, designation 7
double stdfunctions::ackley1(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += (1 / pow(e, 0.2)) * sqrt(pow(x, 2) + pow(y, 2)) + 3 * (cos(2 * x) + sin(2 * y));
	}
	return counter;
}
//ackley algorithm 2, designation 8
double stdfunctions::ackley2(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += 20 + e - (20 / (pow(e, (0.2*sqrt((pow(x, 2) + pow(y, 2)) / 2))))) - pow(e, 0.5*(cos(2 * PI*x) + cos(2 * PI*y)));
	}
	return counter;
}
//eggholder algorithm, designation 9
double stdfunctions::eggholder(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += (-1 * x) * sin(sqrt(fabs(x - y - 47))) - (y + 47) * sin(sqrt(fabs(y + 47 + (x / 2))));
	}
	return counter;
}
//rana algorithm, designation 10
double stdfunctions::rana(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += x * sin(sqrt(fabs(y - x + 1))) * cos(sqrt(fabs(y + x + 1))) + (y + 1) * cos(sqrt(fabs(y - x + 1))) * sin(sqrt(fabs(y + x + 1)));
	}
	return counter;
}
//pathalogical algorithm, designation 11 
double stdfunctions::pathalogical(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += 0.5 + ((pow(sin(sqrt((100 * pow(x, 2)) + pow(y, 2))), 2) - 0.5) / (1 + (0.001 * pow(pow(x, 2) - ((2 * x) * y) + pow(y, 2), 2))));
	}
	return counter;
}
//Michalewicz algorithm, designation 12
double stdfunctions::michalewicz(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size(); j++)
	{
		double x = inputVec.at(j);
		counter += sin(x) * pow(sin(((j + 1) * pow(x, 2)) / PI), 20);
	}
	counter = counter * -1;
	return counter;
}
//Master Cosine Wave, designation 13
double stdfunctions::mcw(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < inputVec.size() - 1; j++)
	{
		double x = inputVec.at(j);
		double y = inputVec.at(j + 1);
		counter += pow(e, -0.125*(pow(x, 2) + pow(y, 2) + 0.5*y*x)) * cos(4 * sqrt(pow(x, 2) + pow(y, 2) + 0.5 * x * y));
	}
	return (-1 * counter);
}
//Shekle's foxhole algorithm, designation 14
double stdfunctions::shekfoxhole(vector<double> inputVec)
{
	double counter = 0;
	for (int j = 0; j < 30; j++)
	{

		double sub1 = 0;
		for (int k = 0; k < inputVec.size(); k++)
		{
			double x = inputVec.at(k);
			sub1 += pow(x - A[j][k], 2);
		}
		counter += 1 / (C[j] + sub1);
	}
	return (-1 * counter);
}
//function to determine which benchmark function to use, based on designation
//designations are provided in comments preceding their respective functions as well as in the switch statement
double stdfunctions::evaluate(int x, vector<double> inputVec)
{
	switch (x)
	{
	case 0:
		return schwefel(inputVec);
		break;
	case 1:
		return dejong1(inputVec);
		break;
	case 2:
		return rosenbrock(inputVec);
		break;
	case 3:
		return rastrigin(inputVec);
		break;
	case 4:
		return griewangk(inputVec);
		break;
	case 5:
		return sesw(inputVec);
		break;
	case 6:
		return svsw(inputVec);
		break;
	case 7:
		return ackley1(inputVec);
		break;
	case 8:
		return ackley2(inputVec);
		break;
	case 9:
		return eggholder(inputVec);
		break;
	case 10:
		return rana(inputVec);
		break;
	case 11:
		return pathalogical(inputVec);
		break;
	case 12:
		return michalewicz(inputVec);
		break;
	case 13:
		return mcw(inputVec);
		break;
	case 14:
		return shekfoxhole(inputVec);
		break;
	default:
		cout << "Error: Invalid function designation.";
		return NULL;
		break;
	}
}
