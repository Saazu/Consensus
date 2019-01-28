// ============================================================================
// Name: Simulator object               			File: simulator.cpp
// Author: Alfred Delle					            Copyright: Octover 2018
// ============================================================================

#include "simulator.hpp"

//Credit: Mike Fischer, Homework Spec
int Simulator::uRandom ( int n ) {
	long int usefulMax = RAND_MAX-((RAND_MAX-n)+1)%n;
	long int r;
	do { r = random(); }
	while ( r > usefulMax );
	return r % n;
}

//this function constructs a simulator object using the parameters
//provided
Simulator::Simulator( int numAgent, int numOnes, unsigned int seed ) {
	numAgents = numAgent;
	numOne = numOnes;
	salt = seed;
}

//this function runs the simulation for as many rounds as it takes
//to reach consensus.  The number of communication rounds used is stored in the
//output parameter rounds
int Simulator::run( int& rounds ) {
	Agent Agents[numAgents];
	for (int m = 0; m < numOne; m++) {
		Agents[m].update(1);
	}

	for (int n = numOne; n < numAgents; n++ ) {
		Agents[n].update(0);
	}

	int numZero = numAgents - numOne; //number of agents with choice zero
	srandom(salt);
	while ( (numOne != numAgents ) && (numZero != numAgents) ) {
		int j, k;
		j = uRandom(numAgents); //sender
		k = uRandom((numAgents-1)); //receiver

		if (k >= j) k++;
		int oldChoice = Agents[k].choice();
		Agents[k].update( Agents[j].choice() );

		if (oldChoice != Agents[k].choice()) {
			switch(oldChoice) {
				case 0:
					numZero--;
					numOne++;
					break;
				case 1:
					numZero++;
					numOne--;
					break;
			}

		}
		rounds++;
	}
	cout << numAgents << " " << numOne << " " << salt << " " << rounds << " "
		 << Agents[0].choice() << endl;

	return rounds;
}



