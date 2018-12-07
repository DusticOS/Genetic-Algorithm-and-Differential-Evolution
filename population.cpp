/*! \class Population
*	\brief A class for storing data
*	
*	This class stores the data solutions that are acted upon by the algorithm classes.
*/

#include "stdafx.h"
#include "population.h"


population::population()
{
}

population::population(int d, int ns)
{
	numGen = *new mt19937(time(NULL));
	dim = d;
	numSolutions = ns;
}

population::~population()
{
}

void population::randPopulate(double boundsMin, double boundsMax, int evalID)
{
	uniform_real_distribution<double>rng(boundsMin, boundsMax);

	popContent tempContent;
	for (int i = 0; i < numSolutions; i++)
	{
		tempContent.solution.clear();
		for (int j = 0; j < dim; j++)
		{
			tempContent.solution.push_back(rng(numGen));
		}
		
		tempContent.cost = func.evaluate(evalID, tempContent.solution);
		tempContent.fitness = calcFitness(tempContent.cost);
		content.push_back(tempContent);

		if (!bestSol.cost || tempContent.cost < bestSol.cost)
		{
			bestSol = tempContent;
		}
	}
}

vector<popContent> population::getAllContent()
{
	return content;
}

popContent population::getContentAt(int x)
{
	return content.at(x);
}

vector<double> population::getSolutionAt(int x)
{
	return content.at(x).solution;
}

double population::getContentAt(int x, int y)
{
	return content.at(x).solution.at(y);
}

void population::addSolution(vector<double> inputVec, int evalID)
{
	if (content.size() >= numSolutions)
	{
		cout << ">Error: too many solutions." << endl;
	}
	else
	{
		popContent newContent;
		newContent.solution = inputVec;
		newContent.cost = func.evaluate(evalID, newContent.solution);
		newContent.fitness = calcFitness(newContent.cost);
		content.push_back(newContent);

		if (!bestSol.cost || newContent.cost < bestSol.cost)
		{
			bestSol = newContent;
		}
	}
}
void population::replaceSolution(int x, popContent newContent)
{
	content.at(x) = newContent;
	if (!bestSol.cost || newContent.cost < bestSol.cost)
	{
		bestSol = newContent;
	}
}

void population::replaceContent(vector<popContent> newPop, popContent potentialBest)
{
	content = newPop;
	if (!bestSol.cost || potentialBest.cost < bestSol.cost)
	{
		bestSol = potentialBest;
	}
}

double population::getCostAt(int x)
{
	return content.at(x).cost;
}

double population::getBestFitness()
{
	return bestSol.fitness;
}

double population::getBestCost()
{
	return bestSol.cost;
}

vector<double> population::getBestSol()
{
	return bestSol.solution;
}

popContent population::getBestSolContent()
{
	return bestSol;
}

double population::getTotalFitness()
{
	double counter = 0;
	for (int i = 1; i < numSolutions; i++)
	{
		counter += content.at(i).fitness;
	}
	return counter;
}

double population::calcFitness(double x)
{
	if (x >= 0)
		return 1 / (1 + x);
	else
		return 1 + fabs(x);
}

double population::getFitnessAt(int x)
{
	return content.at(x).fitness;
}

void population::sortByCostAscending()
{
	sort(content.begin(), content.end(), cmp);
}

int population::cmp(const popContent &p1, const popContent &p2)
{
	return p1.cost < p2.cost;
}
