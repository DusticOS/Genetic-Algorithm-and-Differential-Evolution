/// \file population.h

#pragma once
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "stdfunctions.h"


///	\namespace std
using namespace std;

/// \struct popContent
struct popContent
{
	vector<double> solution;	///< Vector of doubles containing the solution
	double cost;				///< Double representing the cost of the solution
	double fitness;				///< Double representing the normalized fitness of the solution
};

///	\class population
class population
{
private:
	stdfunctions func;	///< stdfunction object field that allows access to the standard functions for solution evaluation
	int dim;			///< integer field that holds the dimension of the population solutions
	int numSolutions;	///< integer field that holds the number of solutions in the population
	vector<popContent> content;	///< vector of popContent structs field, stores the whole population as well as cost and normalized fitness of each solution
	mt19937 numGen;		///< mt19937 object field that allows use of the mersenne twister random number generator
	popContent bestSol;	///< popContent struct field that stores the solution, cost, and normalized fitness of the most desirable solution in the population
public:
	/// A constructor.
	population();
	/// A constructor.
	/// A constructor taking two arguments
	/// @param d an int argument
	/// @param ns an int argument
	population(int d, int ns);
	/// A destructor
	~population();

	/// a normal member taking three arguments and returning nothing
	/// @param boundsMin a double argument
	/// @param boundsMax a double argument
	/// @param evalID an int argument
	///	@see populaion()
	/// @see addSolution()
	/// @see replaceSolution()
	/// @see replaceContent()
	void randPopulate(double boundsMin, double boundsMax, int evalID);
	/// a normal member taking no arguments and returning a vector of popContents
	/// @see getContentAt()
	/// @see getSolutionAt()
	/// @see getBestSolution()
	/// @see getBestSolContent()
	/// @see getBestSol()
	///	@return the entire population
	vector<popContent> getAllContent();
	/// a normal member taking one argument and returning a popContent
	/// @param x an int argument
	/// @see getAllContent()
	/// @see getSolutionAt()
	/// @see getBestSolution()
	/// @see getBestSolContent()
	/// @see getBestSol()
	/// @return the popContent at the designated index
	popContent getContentAt(int x);
	/// a normal member taking one argument and returning a vector of doubles
	/// @param x is an int argument
	/// @see getAllContent()
	/// @see getContentAt()
	/// @see getBestSolution()
	/// @see getBestSolContent()
	/// @see getBestSol()
	/// @return the solution vector at the designated index
	vector<double> getSolutionAt(int x);
	/// a normal member taking two arguments and returning a double
	/// @param x is an int argument
	/// @param y is an int argument
	/// @see getAllContent()
	/// @see getSolutionAt()
	/// @see getBestSolution()
	/// @see getBestSolContent()
	/// @see getBestSol()
	/// @return the element at index y from the vector at index x
	double getContentAt(int x, int y);
	/// a normal member taking two arguments and returning nothing
	/// @param inputVec is a vector of doubles argument
	/// @param evalID is an int argument
	/// @see randPopulate()
	/// @see replaceSolution()
	/// @see replaceContent()
	void addSolution(vector<double> inputVec, int evalID);
	/// a normal member taking two arguments and returning nothing
	/// @param x is an int argument
	/// @param newContent is a popContent argument
	/// @see randPopulate()
	/// @see addSolution()
	/// @see replaceContent()
	void replaceSolution(int x, popContent newContent);
	/// a normal member taking two arguments and returning nothing
	/// @param newPop is a vector of popContents argument
	/// @param potentialBest is a popContent argument
	/// @see randPopulate()
	/// @see addSolution()
	/// @see replaceSolution()
	void replaceContent(vector<popContent> newPop, popContent potentialBest);
	/// a normal member taking one argument and returning a double
	/// @param x is an int argument
	/// @see getBestCost()
	/// @see getBestFitness()
	/// @see getFitnessAt()
	/// @see getTotalFitness()
	/// @return the cost of the solution at index x
	double getCostAt(int x);
	/// a normal member taking no arguments and returning a double
	///	@see getBestCost()
	/// @see getCostAt()
	/// @see getFitnessAt()
	/// @see getTotalFitness()
	/// @return the most desireable fitness of the population
	double getBestFitness();
	/// a normal member taking no arguments and returning a double
	/// @see getBestFitness()
	/// @see getCostAt()
	/// @see getFitnessAt()
	/// @see getTotalFitness()
	/// @return the most desirable cost of the population
	double getBestCost();
	/// a normal member taking no arguments and returning a vector of doubles
	/// @see getAllContent()
	/// @see getSolutionAt()
	/// @see getBestSolution()
	/// @see getBestSolContent()
	/// @see getContentAt()
	/// @return a vector of doubles representing the most desirable solution in the population
	vector<double> getBestSol();
	/// a normal member taking no arguments and returning a popContent 
	/// @see getAllContent()
	/// @see getSolutionAt()
	/// @see getBestSolution()
	/// @see getBestSol()
	/// @see getContentAt()
	/// @return the most desirable solution, cost, and normalized fitness
	popContent getBestSolContent();
	/// a normal member taking no arguments and returning a double
	/// @see getBestFitness()
	/// @see getCostAt()
	/// @see getFitnessAt()
	/// @see getBestCost()
	/// @return the summed fitness of the population
	double getTotalFitness();
	/// a normal member taking one argument and returning a double
	/// @param x is a double argument
	/// @see getBestFitness()
	/// @see getCostAt()
	/// @see getFitnessAt()
	/// @see getBestCost()
	/// @getTotalFitness()
	/// @return the normalized fitness of the designated cost
	double calcFitness(double x);
	/// a normal member taking one argument and returning a double
	/// @param x is an int argument
	/// @see getBestFitness()
	/// @see getCostAt()
	/// @see getBestCost()
	/// @getTotalFitness()
	/// @return the fitness at the designated index
	double getFitnessAt(int x);
	/// a normal member taking no arguments and returning nothing
	/// this function sorts the population solutions in ascending order by cost
	/// @see cmp()
	void sortByCostAscending();
	/// a static member taking two arguments and returning an int
	/// @param p1 is a const popContent argument
	/// @param p2 is a const popContent argument
	/// @see sortByCostAscending()
	/// @returns the result of comparing both parameters
	static int cmp(const popContent &p1, const popContent &p2);
};

