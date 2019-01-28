// ============================================================================
// Name: Simulator object               			File: simulator.hpp
// Author: Alfred Delle					            Copyright: Octover 2018
// ============================================================================

#pragma once
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "tools.hpp"
#include "agent.hpp"

class Simulator {
private:
	int numAgents;
	int numOne;
	unsigned int salt;
	int uRandom( int n);
public:
	Simulator () = default;
	Simulator( int numAgent, int numOnes, unsigned int seed );
	int run ( int& rounds );
};

#endif