#include "Graph.h"

Graph::Graph(int n)
{
	size = n;
	matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}
}

Graph::~Graph()
{
	delete[] matrix;
}

int Graph::getsize()
{
	return size;
}

int** Graph::getmatrix()
{
	return matrix;
}

bool Graph::add_edge(int line, int column)
{
	if (matrix[line][column] == 0)
	{
		matrix[line][column] = 1;
		matrix[column][line] = 1;
		return 1;
	}
	return 0;
}

std::ostream& operator<<(std::ostream& on, const Graph& gr)
{
	for (int i = 0; i < gr.size; i++)
	{
		for (int j = 0; j < gr.size; j++)
			on << gr.matrix[i][j] << ' ';
		on << '\n';
	}
	return on;
}
