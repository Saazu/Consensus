// ============================================================================
// Name: Agent object               				File: agent.cpp
// Author: Alfred Delle					            Copyright: Octover 2018
// ============================================================================
#include "tools.hpp"

#pragma once
#ifndef AGENT_HPP
#define AGENT_HPP

class Agent {
private:
	int decision;
public:
	Agent() = default;
	Agent (int ch);
	Agent(const Agent& a);
	void update(int m);
	int choice() const { return decision; } //return the current choice
	ostream& print(ostream& out) const { return out << decision; }
};

inline ostream& operator<<(ostream& out, const Agent& a) {
	return a.print(out);
}

#endif