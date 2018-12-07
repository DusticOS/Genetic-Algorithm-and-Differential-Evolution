#include "stdafx.h"
#include "GA.h"


GA::GA()
{
	numGen = * new mt19937(time(NULL));
}

GA::GA(double crossRate, int ns, int d, double boundsL, double boundsU, int tmax, double mrt, double mrg, double mpr, double eliter, int eval)
{
	numGen = *new mt19937(time(NULL));
	cr = crossRate;
	numSolutions = ns;
	dim = d;
	bound.min = boundsL;
	bound.max = boundsU;
	maxItr = tmax;
	mut.rate = mrt;
	mut.range = mrg;
	mut.precision = mpr;
	er = eliter;
	evalID = eval;
}

GA::~GA()
{
}

vector<double> GA::gaBase()
{
	population pop(dim, numSolutions);
	pop.randPopulate(bound.min, bound.max, evalID);
	stdfunctions func;
	int elitism = (int)(er * numSolutions);
	int parent1;
	int parent2;
	vector<double> returnVec;
	for (int t = 0; t < maxItr; t++)
	{
		population newPop(dim, numSolutions);
		for (int s = 1; s <= numSolutions; s += 2)
		{
			//select parents
			do
			{
				parent1 = selectParent(pop);
				parent2 = selectParent(pop);
			} while (parent1 == parent2);
			//perform crossover (Has function)
			parents o;
			o = crossover(pop, parent1, parent2);
			//perform mutation
			mutate(o.p1);
			mutate(o.p2);
			//add to new population
			newPop.addSolution(o.p1, evalID);
			newPop.addSolution(o.p2, evalID);
		}
		//combine population and newpopulation into population
		//calculate normalized fitness
		reduce(pop, newPop, elitism);
		returnVec.push_back(pop.getBestFitness());
	}
	return returnVec;
}
//Perform crossover with selected parents
parents GA::crossover(population& pop, int parent1, int parent2)
{
	//generate random number to determine if crossover even happens (must be below crossover rate)
	uniform_real_distribution<double>rng(0, 1);
	//generate random number to determine location of crossover
	uniform_int_distribution<int>drng(1, dim);
	parents o;
	//if crossover happens, create a new set of parents, splitting the current parents at index x
	//the new parent 1 will have the index 0 through x of the original parent 1, but the x+1 through n of parent 2
	//the new parent 2 will be the opposite
	if (rng(numGen) < cr)
	{
		int d = drng(numGen);
		for (int i = 0; i < d; i++)
		{
			o.p1.push_back(pop.getContentAt(parent1, i));
			o.p2.push_back(pop.getContentAt(parent2, i));
		}
		for (int i = d; i < dim; i++)
		{
			o.p1.push_back(pop.getContentAt(parent2, i));
			o.p2.push_back(pop.getContentAt(parent1, i));
		}
	}
	//If crossover does not happen, return the original parents
	else
	{
		o.p1 = pop.getSolutionAt(parent1);
		o.p2 = pop.getSolutionAt(parent2);
	}
	return o;
}
//select parent populations
int GA::selectParent(population& pop)
{
	//generate random number between 0 and the total fitness of the population
	uniform_real_distribution<double>rng(0, pop.getTotalFitness());
	double r = rng(numGen);
	//start the counter at 0
	int s = 0;
	//increment the counter until it reaches the last element, or the random generated number reaches 0
	while (s < numSolutions - 1 && r > 0)
	{
		r -= pop.getFitnessAt(s);
		s++;
	}
	//return the counter, designating the index of the solution to serve as the parent
	return s;
}

//mutation function
void GA::mutate(vector<double>& S)
{
	//generate two random numbers, one to determine whether mutation happens (must be below mutation rate)
	//The other to contribute to the degree of mutation
	uniform_real_distribution<double>rng(0,1);
	uniform_real_distribution<double>rng2(-1, 1);
	//for every element in the solution
	for (int i = 0; i < dim; i++)
	{
		//Perform mutation if the random number is below the mutation rate
		if (rng(numGen) < mut.rate)
		{
			//random number * the allowed ranger * mutation range * (first random number * mutation precision)^2
			//if at any point the value exceeds the allowed bounds, set the value to the bounds 
			//this wil prevent solutions from going out of control
			S.at(i) += rng2(numGen) * (bound.max - bound.min) * mut.range * pow(2, (-1 * rng(numGen) * mut.precision));
			if (S.at(i) < bound.min)
			{
				S.at(i) = bound.min;
			}
			else if (S.at(i) > bound.max)
			{
				S.at(i) = bound.max;
			}
		}
		
	}
}

//reduce function, adds new generation of solutions to population
void GA::reduce(population& pop, population& newPop, int e)
{
	//sort the populations by their costs
	pop.sortByCostAscending();
	newPop.sortByCostAscending();
	//replace members of the old population with that of the new
	for (int i = 0; i < e; i++)
	{
		newPop.replaceSolution(numSolutions -1 - i, pop.getContentAt(i));
	}
	pop.replaceContent(newPop.getAllContent(), newPop.getBestSolContent());
}



