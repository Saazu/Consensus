// ============================================================================
// Name: Agent object               				File: agent.cpp
// Author: Alfred Delle					            Copyright: Octover 2018
// ============================================================================

#include "agent.hpp"

//this function contructs the Agent object with parameter ch
Agent:: Agent(int ch) {
	decision = ch;
}

//this function uodates the Agents decision
void Agent:: update (int ch) {
	decision = ch;
}