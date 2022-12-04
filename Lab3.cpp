//Дан неориентированный граф. Посчитайте, сколько в нем различных простых циклов.
//Заметим, что циклы называются одинаковыми, если они обходят одно и то же множество вершин в одном и том же порядке, возможно,
//начиная при этом из другой вершины, или если порядок обхода противоположный

//Вход. В первой строке задано количество вершин n (1 <= n <= 10) и ребер m в графе, соответственно
//Следующие m строк содержат по два числа ui и vi (1 <= ui, vi <= n, ui != vi); каждая строка означает, что в графе существует ребро между вершинами
//ui и vi. В графе нет кратных ребер
//Выход. Выведите количество простых циклов в заданном графе

#include <iostream>
#include "Graph.h"
#include <fstream>
using namespace std;

int step;
int sw;

void DSF(int** arr, int size, bool* flag, int in, int start, int& count_cycles)
{
	step++;
	cout << in + 1 << "/" << step << " ";
	flag[in] = true;
	if (step == 3 && !sw)
	{
		flag[start] = false;
		sw++;
	}
	if (step > 3 && in == start)
	{
		count_cycles++;
	}
	for (int i = 0; i < size; i++)
	{
		if (!flag[i] && arr[in][i] == 1)
		{
			DSF(arr, size, flag, i, start, count_cycles);
		}
	}
	step--;
}

//int SearchCycles(Graph& graph)
//{
//	int n = graph.getsize();
//	bool* flag = new bool[n];
//	int count_cycles = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			flag[j] = false;
//		}
//		step = 0;
//		if (!flag[i])
//		{
//			DSF(graph.getmatrix(), n, flag, i, i, count_cycles);
//		}
//	}
//	return count_cycles;
//}

int SearchCycles(Graph& graph)
{
	int n = graph.getsize();
	bool* flag = new bool[n];
	int count_cycles = 0;
	for (int i = 0; i < n; i++)
	{
		int** new_graph = graph.getmatrix();
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				flag[k] = false;
			}
			if (new_graph[i][j])
			{
				new_graph[i][j] = 0;
				new_graph[j][i] = 0;
				step = 0;
				sw = 0;
				DSF(new_graph, n, flag, i, i, count_cycles);
				new_graph[i][j] = 1;
				new_graph[j][i] = 1;
				cout << endl;
			}
		}
	}
	return count_cycles;
}

int main()
{
	int n, m;
	fstream file("input.txt");
	file >> n >> m;
	Graph g(n);
	int first, second;
	for (int i = 0; i < m; i++)
	{
		file >> first >> second;
		g.add_edge(first - 1, second - 1);
	}

	cout << endl << SearchCycles(g);
}
