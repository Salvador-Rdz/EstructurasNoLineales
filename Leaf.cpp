#include "Leaf.h"
#include <iostream>

Leaf::Leaf() {
	left = right = NULL;
	data = 0;
}

Leaf::Leaf(int d) {
	left = right = NULL;
	data = d;
}

Leaf::~Leaf() {}

void Leaf::print() {
	std::cout << " " << data << " ";
}

int Leaf::getData() {
	return data;
}

void Leaf::setData(int d) {
	data = d;
}