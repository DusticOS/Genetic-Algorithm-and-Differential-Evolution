#include "stdafx.h"
#include "DE.h"


DE::DE()
{
}

//assign input to corrent fields
DE::DE(double crossover, double uf, double boundsU, double boundsL, int dimension, int ns, int genMax, int eval, int stratNum)
{
	cr = crossover;
	f = uf;
	bound.max = boundsU;
	bound.min = boundsL;
	dim = dimension;
	numSolutions = ns;
	maxItr = genMax;
	evalID = eval;
	strat = stratNum;
	numGen = *new mt19937(time(NULL));
}

DE::~DE()
{
}
//base function for Differential evolution
vector<double> DE::deBase()
{
	population pop(dim, numSolutions);
	pop.randPopulate(bound.min, bound.max, evalID);
	vector<double> returnVec;
	//perform each strategy
	for(int gen = 0; gen < maxItr; gen++)
	{
		switch (strat)
		{
		case 1:
			strat01(pop);
			break;
		case 2:
			strat02(pop);
			break;
		case 3:
			strat03(pop);
			break;
		case 4:
			strat04(pop);
			break;
		case 5:
			strat05(pop);
			break;
		case 6:
			strat06(pop);
			break;
		case 7:
			strat07(pop);
			break;
		case 8:
			strat08(pop);
			break;
		case 9:
			strat09(pop);
			break;
		case 10:
			strat10(pop);
			break;
		default:
			cout << ">Error: No differential evolution of designation: " << strat << " found." << endl;
		}
		returnVec.push_back(pop.getBestFitness());
	}
	return returnVec;
}
//Most strategies perform identically for the most part, comments will be limited but sufficient
void DE::strat01(population &pop)
{
	//select two random numbers, one to deterime if change happens
	//one determines if crossover happens, the other selects an element in a solution
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	//three ints that will hold random values
	int r1, r2, r3;
	popContent v;
	v.solution.assign(dim, 0);
	//iterate through the solutions, attempt to perform evolution on each element
	for (int i = 0; i < numSolutions; i++)
	{
		//select three random solutions in the popuation, excluding the current one
		multiRandEx(r1, r2, r3, i);
		//select element in solution, set second variable equal to it
		int jr = irng(numGen);
		int j = jr;
		//will always try to perform evolution at least once
		do
		{
			//perform evolution if allowed by crossover, or if j is still the same as jr
			if (rng(numGen) < cr || j == jr)
			{
				//change solution at index x to the same index in the best solution * the f constant * (index j of r2 -index j of r3)
				//this stage of evolution is basedon the strategy used, but is generally a variation on this function
				//sometimes requiring extra random solutions
				v.solution.at(j) = pop.getBestSol().at(j) + f * (pop.getContentAt(r2, j) - pop.getContentAt(r3, j));
				//return out of bounds values in bounds
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			//if evolution is not performed, set v's index j to index j of the current solution
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		//continue trying to performing evolution if j changed
		} while (j != jr);
		//determine the cost of population v
		v.cost = func.evaluate(evalID, v.solution);
		//normalize cost of population v into fitness
		v.fitness = pop.calcFitness(v.cost);
		//replace current solution with v if v is superior
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat02(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr || j == jr)
			{
				v.solution.at(j) = pop.getContentAt(r1, j) + f * (pop.getContentAt(r2, j) - pop.getContentAt(r3, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat03(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr || j == jr)
			{
				v.solution.at(j) = pop.getContentAt(i, j) + lambda * ((pop.getBestSol().at(j) - pop.getContentAt(i, j)) + f * (pop.getContentAt(r1, j) - pop.getContentAt(r2, j)));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat04(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3, r4;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, r4, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr || j == jr)
			{
				v.solution.at(j) = pop.getBestSol().at(j) + f * (pop.getContentAt(r1, j) + pop.getContentAt(r2, j) - pop.getContentAt(r3, j) - pop.getContentAt(r4, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat05(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3, r4, r5;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, r4, r5, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr || j == jr)
			{
				v.solution.at(j) = pop.getContentAt(r5, j) + f * (pop.getContentAt(r1, j) + pop.getContentAt(r2, j) - pop.getContentAt(r3, j) - pop.getContentAt(r4, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat06(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr)
			{
				v.solution.at(j) = pop.getBestSol().at(j) + f * (pop.getContentAt(r2, j) - pop.getContentAt(r3, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat07(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3;
	popContent v;
	
	for (int i = 0; i < numSolutions; i++)
	{
		int counter = 0;
		v.solution.assign(dim, 0);
		multiRandEx(r1, r2, r3, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr)
			{
				v.solution.at(j) = pop.getContentAt(r1, j) + (f * (pop.getContentAt(r2, j) - pop.getContentAt(r3, j)));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if(v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
			{
				v.solution.at(j) = pop.getContentAt(i, j);
			}
			j = (j + 1) % dim;
		} while (j != jr);
		counter++;
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat08(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr)
			{
				v.solution.at(j) = pop.getContentAt(i, j) + lambda * ((pop.getBestSol().at(j) - pop.getContentAt(i, j)) + f * (pop.getContentAt(r1, j) - pop.getContentAt(r2, j)));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat09(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3, r4;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, r4, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr)
			{
				v.solution.at(j) = pop.getBestSol().at(j) + f * (pop.getContentAt(r1, j) + pop.getContentAt(r2, j) - pop.getContentAt(r3, j) - pop.getContentAt(r4, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}

void DE::strat10(population &pop)
{
	uniform_real_distribution<double>rng(0, 1);
	uniform_int_distribution<int>irng(0, dim - 1);
	int r1, r2, r3, r4, r5;
	double lambda = f / 2;
	popContent v;
	v.solution.assign(dim, 0);
	for (int i = 0; i < numSolutions; i++)
	{
		multiRandEx(r1, r2, r3, r4, r5, i);
		int jr = irng(numGen);
		int j = jr;
		do
		{
			if (rng(numGen) < cr)
			{
				v.solution.at(j) = pop.getContentAt(r5, j) + f * (pop.getContentAt(r1, j) + pop.getContentAt(r2, j) - pop.getContentAt(r3, j) - pop.getContentAt(r4, j));
				if (v.solution.at(j) < bound.min)
				{
					v.solution.at(j) = bound.min;
				}
				else if (v.solution.at(j) > bound.max)
				{
					v.solution.at(j) = bound.max;
				}
			}
			else
				v.solution.at(j) = pop.getContentAt(i, j);
			j = (j + 1) % dim;
		} while (j != jr);
		v.cost = func.evaluate(evalID, v.solution);
		v.fitness = pop.calcFitness(v.cost);
		if (v.cost <= pop.getCostAt(i))
			pop.replaceSolution(i, v);
	}
}
//random number generation functions, overloaded based on need of strategy, cound need anywhere from 3 to 5 random numbers
void DE::multiRandEx(int &r1, int &r2, int &r3, int ex)
{
	//numbers generated cannot include the excluded number or any previously generated numbers
	uniform_int_distribution<int>rng(0, numSolutions - 1);
	do
	{
		r1 = rng(numGen);
	} while (r1 == ex);
	do
	{
		r2 = rng(numGen);
	} while (r2 == ex || r2 == r1);
	do
	{
		r3 = rng(numGen);
	} while (r3 == ex || r3 == r2 || r3 == r1);
	return;
}

void DE::multiRandEx(int &r1, int &r2, int &r3, int &r4, int ex)
{
	uniform_int_distribution<int>rng(0, numSolutions - 1);
	do
	{
		r1 = rng(numGen);
	} while (r1 == ex);
	do
	{
		r2 = rng(numGen);
	} while (r2 == ex || r2 == r1);
	do
	{
		r3 = rng(numGen);
	} while (r3 == ex || r3 == r2 || r3 == r1);
	do
	{
		r4 = rng(numGen);
	} while (r4 == ex || r4 == r3 || r4 == r2 || r4 == r1);
	return;
}

void DE::multiRandEx(int &r1, int &r2, int &r3, int &r4, int &r5, int ex)
{
	uniform_int_distribution<int>rng(0, numSolutions - 1);
	do
	{
		r1 = rng(numGen);
	} while (r1 == ex);
	do
	{
		r2 = rng(numGen);
	} while (r2 == ex || r2 == r1);
	do
	{
		r3 = rng(numGen);
	} while (r3 == ex || r3 == r2 || r3 == r1);
	do
	{
		r4 = rng(numGen);
	} while (r4 == ex || r4 == r3 || r4 == r2 || r4 == r1);
	do
	{
		r5 = rng(numGen);
	} while (r5 == ex || r5 == r4 || r5 == r3 || r5 == r2 || r5 == r1);
	return;
}
