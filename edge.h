#pragma once
#include <string>
class edge
{
private:
	int dest;
	double weight;
public:
	edge(int dest);
	edge(int dest, double weight);
	~edge();
	int getDest();
	double getWeight();
	std::string toString();
};

