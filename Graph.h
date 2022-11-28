#pragma once
#include <iostream>
class Graph
{
	int size;
	int** matrix;
public:
	Graph() { size = 0;};
	Graph(int n);
	~Graph();
	int getsize();
	int** getmatrix();
	bool add_edge(int line, int column);
	friend std::ostream& operator<<(std::ostream& on, const Graph& gr);
};

