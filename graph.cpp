#include "stdafx.h"
#include "graph.h"
using namespace std;


graph::~graph()
{
}

graph::graph(int v)
{
	this->v = v;
	this->e = 0;
	g = new List<Edge>*[v + 1];
	for (int i = 1; i < v + 1; i++)
	{
		g[i] = new List<edge>();
	}
}

int graph::getEdges()
{
	return this->e;
}

int graph::getVertices()
{
	return this->v;
}

bool graph::isEdge(int s, int d)
{
	List<edge> l = *this->g[s];
	Node<edge> *p = l.first;
	for (int i = 0, i < l.length; i++)
	{
		if (d == p->data.getDest())
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

double graph::getEWeight(int s, int d)
{
	List<edge> l = *this->g[s];
	Node<edge> *p = l.first;
	for (int i = 0, i < l.length; i++)
	{
		if (d == p->data.getDest())
		{
			return p->data.getWeight();
		}
		p = p->next;
	}
	return -1.0;
}

void graph::insertE(int s, int d)
{
	insertE(s, d, 0.0);
}

void graph::insertE(int s, int d, double w)
{
	if (!isEdge(s,d))
	{
		this->g[s]->insertFirst(*new Edge(d, w));
		this->e++;
	}
	else
	{
		std::cout << "No es posible insertar elemento, ya se encuentra en el grafo" << endl;
	}
}

List<edge> graph::adjacentTo(int s)
{
	return *this->g[s];
}

std::string graph::to_string()
{
	return std::string();
}
