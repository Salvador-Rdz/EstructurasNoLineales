#pragma once
#include "edge.h"
#include "List.cpp"
class graph
{
private:
	int v, e;
	List <edge> **g; //apuntador a un arreglo de objetos (listas)
	int *visited;
	int visitOrder;
public:
	graph(int v);
	int getEdges();
	int getVertices();
	bool isEdge(int s, int d);
	double getEWeight(int s, int d);
	void insertE(int s, int d);
	void insertE(int s, int d, double w);
	List <edge> adjacentTo(int s);
	std::string to_string();
	~graph();
};

