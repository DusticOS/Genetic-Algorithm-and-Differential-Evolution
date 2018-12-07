/// \file DE.h

#pragma once
#include <random>
#include <chrono>
#include "population.h"
#include "stdfunctions.h"

/// \namespace std
using namespace std;

///struct boundaries
struct boundaries
{
	double min; ///< double that holds the minimum bounds for the population
	double max; ///< double that holds the maximum bounds for the population
};

/// \class DE
class DE
{
private:
	double cr;	///< double that holds the crossover rate for the algorithm
	double f;	///< double that holds the f constant for the algorithm
	boundaries bound;	///< boundaries struct that holds the minimum and maximum bounds for the population
	int dim;	///< int that holds the dimension of the solutions of the population
	int numSolutions;	///< int that holds the number of solutions in the population
	int maxItr;	///< int that holds the maximum number of generations to be performed
	int evalID;	///< int that stores the ID of the standard function to be used for evaluation
	int strat;	///< int that stores the ID of the Differential Evolution strategy to be performed
	mt19937 numGen;	///< mt19937 object that allows the mersenne twister random number generator to be used
	stdfunctions func;	///< stdfunctions object that allows the benchmark functions to be accessed

	/// a normal member taking four arguments and returning nothing
	/// @param r1 is an int argument
	/// @param r2 is an int argument
	/// @param r3 is an int argument
	/// @param ex is an int argument
	/// selects three unique random numbers and excludes ex
	void multiRandEx(int &r1, int &r2, int &r3, int ex);
	/// a normal member taking five arguments and returning nothing
	/// @param r1 is an int argument
	/// @param r2 is an int argument
	/// @param r3 is an int argument
	/// @param r4 is an int argument
	/// @param ex is an int argument
	/// selects four unique random numbers and excludes ex
	void multiRandEx(int &r1, int &r2, int &r3, int &r4, int ex);
	/// a normal member taking six arguments and returning nothing
	/// @param r1 is an int argument
	/// @param r2 is an int argument
	/// @param r3 is an int argument
	/// @param r4 is an int argument
	/// @param r5 is an int argument
	/// @param ex is an int argument
	/// selects five unique random numbers and excludes ex
	void multiRandEx(int &r1, int &r2, int &r3, int &r4, int &r5, int ex);
public:
	/// a normal constructor
	DE();
	/// a normal constructor taking nine argumenst
	/// @param cr is a double argument
	/// @param f is a double argument
	/// @param boundsU is a double argument
	/// @param boundsL is a double argument
	/// @param dimension is an int argument
	/// @param ns is an int argument
	/// @param genMax is an int argument
	/// @param eval is an int argument
	/// @param stratNum is an int argument
	DE(double cr, double f, double boundsU, double boundsL, int dimension, int ns, int genMax, int eval, int stratNum);
	/// a normal destructor
	~DE();


	/// a normal member taking no arguments and returning a vector of doubles
	/// base function and control center for the algorithm
	/// @return vector of doubles representing the best fitness of each generation
	vector<double> deBase();
	
	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat01(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat02(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat03(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat04(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat05(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat07
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat06(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat08
	/// @see strat09
	/// @see strat10
	void strat07(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat09
	/// @see strat10
	void strat08(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat10
	void strat09(population &pop);

	/// a normal member taking one argument and returning nothing
	/// @param pop is a population object argument
	/// @see strat01
	/// @see strat02
	/// @see strat03
	/// @see strat04
	/// @see strat05
	/// @see strat06
	/// @see strat07
	/// @see strat08
	/// @see strat09
	void strat10(population &pop);
};

