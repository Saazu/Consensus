//                  -*- mode:c++; tab-width:4 -*-
// -------------------------------------------------------------------
//Main file for consensus program
//File: main.cpp
//Created by Alfred Delle on Oct 26 2018
//--------------------------------------------------------------------
//This is  a program that simulates the distributed consensus 
//algorithm using the fickle method
//--------------------------------------------------------------------
#include "tools.hpp"
#include "simulator.hpp"
#include "agent.hpp"

void run(int argc, char** argv);
//--------------------------------------------------------------------
//this is the main function that controls the entire program
//it takes the file name from the command line argument and 
//produces outputs as specified
int main ( int argc, char** argv ) {
	//banner();
	run(argc, argv);
	//bye();
}

//this function creates a simulator and runs a simulation
//using command line options
void run( int argc, char** argv ) {
	if (argc < 3 || argc > 4) {
		cout << "consensus numAgents numOne [seed]" << endl;
		return;
	}
	int numAgents, numOne;
	unsigned int seed;
	if (argc == 4) {
		seed = strtoul(argv[3], NULL, 0);
	}
	else {
		seed = time(0);
	}
	numAgents = atoi(argv[1]);
	numOne = atoi(argv[2]);

	Simulator s(numAgents, numOne, seed);
	int rounds = 0;
	s.run(rounds);
}