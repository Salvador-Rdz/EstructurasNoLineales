#pragma once
#include <stdio.h>

class Leaf {
private:
	int data;

public:
	Leaf *left;
	Leaf *right;

	Leaf();
	Leaf(int d);
	~Leaf();
	void print();
	int getData();
	void setData(int d);
};

