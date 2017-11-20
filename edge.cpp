#include "stdafx.h"
#include "edge.h"



edge::edge(int dest)
{
	this->weight = 0.0;
	this->dest = dest;
}

edge::edge(int dest, double weight)
{
	this->dest = dest;
	this->weight = weight;
}

edge::~edge()
{
}

int edge::getDest()
{
	return this->dest;
}

double edge::getWeight()
{
	return this->weight;
}

std::string edge::toString()
{
	return std::to_string (this->dest)+" ("+std::to_string(this->weight)+")";
}
