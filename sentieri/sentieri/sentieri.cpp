#include "pch.h"
#include <fstream>
#include <vector>

#define HOT 1
#define COLD 0

using namespace std;

ifstream input("input.txt");
ofstream out("output.txt");

vector<vector<int>> graph;

int main() {
	int numNodi, numFreddi, numCaldi;
	input >> numNodi;
	
	graph.resize(numNodi);
	for (int i = 0; i < graph.size(); i++)
	{
		graph[i].resize(numNodi);
	}
	input >> numFreddi;
	input >> numCaldi;

	int x, y, i = 0;
	while (input >> x && i < numFreddi) {
		input >> y;
		graph[x-1][y-1] = COLD;
		i++;
	}

	while (input >> x) {
		input >> y;
		graph[x-1][y-1] = HOT;
	}



	for (int i = 0; i < numNodi; i++)
	{
		for (int j = 0; j < numNodi; j++)
		{
			out << graph[i][j] << " ";
		}
		out << endl;
	}
}


