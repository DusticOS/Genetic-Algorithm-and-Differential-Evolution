This project was written in C++ using and compiled with Visual Studio 2017.

The experiments were performed on my personal laptop, specs as follows:
Operating System: Windows 10 Home, 64-bit
Processor: Intel Core i7-2670QM CPU @ 2.20GHz
RAM: 8.00 GB

The program itself is made up of five classes, main, population, GA, DE, and stdfunctions.
population stores the population, GA performs genetic algorithm, DE performs differential evolution,
and stdfunctions store the benchmark functions.

To use the program, the included file "config.json" must be passed as a command line argument or
using Visual Studio's argument setting.  This stores all the constants and data to be used in the program
Upon running the program, the user will be prompted to input a string.  Input "GA" to run the genetic
algorithm, or "DE" to run differential evolution.  The user can also input "exit" to exit the program.
Once an algorithm is selected, the program will print to "output.csv"