/// \file stdfunction.h

#pragma once
#include <vector>
#include <random>
#include <iostream>

/// \namespace std
using namespace std;

/// \class stdfunctions
class stdfunctions
{
private:
	double PI; ///< double field that stores the value of pi
	double e; ///< double filed that stores the value of e
	mt19937 numGen; ///< mt19937 object that allows access to the mersenne twister random number generator
	double C[30] = { 0.806,0.517,0.1,0.908,0.965,0.669,0.524,0.902,0.351,0.876,0.462,
		0.491,0.463,0.741,0.352,0.869,0.813,0.811,0.0828,0.964,0.789,0.360,0.369,
		0.992,0.332,0.817,0.632,0.883,0.608,0.326 };; ///< array field that stores constants needed for the Shekel's Foxhole function
	double A[30][10] = { { 9.681,0.667,4.783,9.095,3.517,9.325,6.544,0.211,5.122,2.02 },
	{ 9.4,2.041,3.788,7.931,2.882,2.672,3.568,1.284,7.033,7.374 },
	{ 8.025,9.152,5.114,7.621,4.564,4.711,2.996,6.126,0.734,4.982 },
	{ 2.196,0.415,5.649,6.979,9.510,9.166,6.304,6.054,9.377,1.426 },
	{ 8.074,8.777,3.467,1.863,6.708,6.349,4.534,0.276,7.633,1.567 },
	{ 7.650,5.658,0.720,2.764,3.278,5.283,7.474,6.274,1.409,8.208 },
	{ 1.256,3.605,8.623,6.905,4.584,8.133,6.071,6.888,4.187,5.448 },
	{ 8.314,2.261,4.24,1.781,4.124,0.932,8.129,8.658,1.208,5.762 },
	{ 0.226,8.858,1.42,0.954,1.622,4.698,6.228,9.096,0.972,7.637 },
	{ 7.305,2.228,1.242,5.928,9.133,1.826,4.06,5.204,8.713,8.247 },
	{ 0.652,7.027,0.508,4.876,8.807,4.632,5.808,6.937,3.291,7.016 },
	{ 2.699,3.516,5.847,4.119,4.461,7.496,8.817,0.69,6.593,9.789 },
	{ 8.327,3.897,2.017,9.57,9.825,1.15,1.395,3.885,6.354,0.109 },
	{ 2.132,7.006,7.136,2.641,1.882,5.943,7.273,7.691,2.88,0.564 },
	{ 4.707,5.579,4.08,0.581,9.698,8.542,8.077,8.515,9.231,4.67 },
	{ 8.304,7.559,8.567,0.322,7.128,8.392,1.472,8.524,2.277,7.826 },
	{ 8.632,4.409,4.832,5.768,7.05,6.715,1.711,4.323,4.405,4.591 },
	{ 4.887,9.112,0.17,8.967,9.693,9.867,7.508,7.77,8.382,6.74 },
	{ 2.44,6.686,4.299,1.007,7.008,1.427,9.398,8.48,9.95,1.675 },
	{ 6.306,8.583,6.084,1.138,4.350,3.134,7.853,6.061,7.457,2.258 },
	{ 0.652,2.343,1.37,0.821,1.31,1.063,0.689,8.819,8.833,9.07 },
	{ 5.558,1.272,5.756,9.857,2.279,2.764,1.284,1.677,1.244,1.234 },
	{ 3.352,7.549,9.817,9.437,8.687,4.167,2.57,6.54,0.228,0.027 },
	{ 8.798,0.88,2.37,0.168,1.701,3.68,1.231,2.39,2.499,0.064 },
	{ 1.46,8.057,1.337,7.217,7.914,3.615,9.981,9.198,5.292,1.224 },
	{ 0.432,8.645,8.774,0.249,8.081,7.461,4.416,0.652,4.002,4.644 },
	{ 0.679,2.8,5.523,3.049,2.968,7.225,6.73,4.199,9.614,9.229 },
	{ 4.263,1.074,7.286,5.599,8.291,5.2,9.214,8.272,4.398,4.506 },
	{ 9.496,4.83,3.15,8.27,5.079,1.231,5.731,9.494,1.883,9.732 },
	{ 4.138,2.562,2.532,9.661,5.611,5.5,6.886,2.341,9.699,6.5 } };; ///< array field that stores constants needed for the Shekel's foxhole function
public:
	/// a normal constructor
	stdfunctions();
	/// a normal destructor
	~stdfunctions();
	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double schwefel(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double dejong1(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double rosenbrock(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double rastrigin(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double griewangk(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double sesw(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double svsw(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double ackley1(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double ackley2(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double eggholder(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double rana(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double pathalogical(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double michalewicz(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double mcw(vector<double> inputVec);

	/// a normal member taking one argument and returns a double
	/// @param inputVec is a vector of doubles argument
	/// @return the cost of the passed solution
	double shekfoxhole(vector<double> inputVec);

	/// a normal member taking two arguments and returns a double
	/// @param x is an int argument
	/// @param inputVec is a vecot of doubles argument
	/// @see schwefel()
	/// @see dejong1()
	/// @see rosenbrock()
	/// @see rastrigin()
	/// @see griewangk()
	/// @see sesw()
	/// @see svsw()
	/// @see ackley1()
	/// @see ackley2()
	/// @see eggholder()
	/// @see rana()
	/// @see pathalogical()
	/// @see michalewicz()
	/// @see mcw()
	/// @see shekfoxhole()
	/// @return the cost of the passed solution using the function with ID x
	double evaluate(int x, vector<double> inputVec);
};

