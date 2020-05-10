#include "pch.h"
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int numAzionamenti(int numCm) {
	int cm[1000];
	int count = 0;
	for (int i = 0; i < numCm; i++)
	{
		in >> cm[i];		
	}
	int i;
	int j = 0;
	while (j<numCm)
	{
		i = j;
		while (i<numCm && cm[i]!=0)
		{
			--cm[i];
			i++;
		}
		while (cm[j]==0) {
			j++;
		}
		count++;
	}
	return count;
}

int main()
{
	int numCasi;
	in >> numCasi;

	int numCm;

	for (int i = 0; i < numCasi; i++)
	{
		in >> numCm;
		out << "Case #" << i+1 << ": " << numAzionamenti(numCm) << endl;
	}
}

