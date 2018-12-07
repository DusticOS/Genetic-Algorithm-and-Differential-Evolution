/// \file GA.h

#pragma once
#include <random>
#include <vector>
#include <chrono>
#include "population.h"

/// \namesapce std
using namespace std;

/// \struct parents
struct parents
{
	vector<double> p1; ///< vector of doubles that acts as the first parent
	vector<double> p2; ///< vector of doubles that acts as the second parent
};

/// \struct mutation
struct mutation
{
	double rate;	///< double that holds the mutation rate
	double range;	///< double that holds the mutation range
	double precision;	///< double that hounds the mutation precision
};

/// \struct bounds
struct bounds
{
	double max;	///< double that holds the maximum bounds
	double min;	///< double that holds the minimum bounds
};

/// \class GA
class GA
{
private:
	double cr;	///< double that holds the crossover rate
	int numSolutions;	///< int that holds the number of solutions in the population
	int dim;	///< int that holds the dimension of the solutions in the population
	bounds bound;	///< bounds that holds the minimum and maximum bounds for the population
	int maxItr;	///< int that holds the maximum number of iterations the algorithm will perform
	mutation mut;	///< mutation that holds the mutation rate, range, and precision
	double er;	///< double that holds the algorithm's elitism rate
	mt19937 numGen;	///< mt19937 object that allows the algorithm to access the mersenne twister random number generator
	int evalID;	///< int that holds the evaluation ID and determines which standard function is used
public:
	/// a constructor
	GA();

	/// a constructor taking eleven arguments
	/// @param cr is a double argument
	/// @param ns is an int argument
	/// @param dim is an int argument
	/// @param boundsL is an double argument
	/// @param boundsU is an double argument
	/// @param maxItr is an int argument
	/// @param mrt is a double argument
	/// @param mrg is a double argument
	/// @param mpr is a double argument
	/// @param er is a double argument
	/// @param evalId is an int argument
	GA(double cr, int ns, int dim, double boundsL, double boundsU, int maxItr, double mrt, double mrg, double mpr, double er, int evalID);

	/// a destructor
	~GA();

	/// a normal member function taking no arguments and returning a vector of doubles
	/// @return a vector of the best fitnesses from the population at each iteration
	vector<double> gaBase();

	/// a normal member taking three arguments and returning a parents struct
	/// @param pop is a population object argument
	/// @param p1 is an int argument
	/// @param p2 is an int argument
	/// @return a struct of two vectors which are a crossover of the solutions at the designated indeces
	parents crossover(population& pop, int p1, int p2);

	/// a nromal member taking one argument and returning an int
	/// @param pop is a population object argument
	/// @return an int representing an index of the population
	int selectParent(population& pop);

	/// a normal member taking one argument and returning nothing
	/// @param S is a vector of doubles argument
	/// function mutates contents of passed vector
	void mutate(vector<double>& S);

	/// a normal member taking three arguments and returning nothing
	/// @param pop is a population object argument
	/// @param newPop is a population object argument
	/// @param e is an int argument
	/// merges the passed populations into one population, saving the most desirable solutions based on elitism e
	void reduce(population& pop, population& newPop, int e);
};

