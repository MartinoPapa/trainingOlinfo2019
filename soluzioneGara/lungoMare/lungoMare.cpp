#include "pch.h"
#include <fstream>
#include <vector>
#include <algorithm>

//pdf nazionali 2016 spiegazioni

//tutti i tentativi

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<int> distanza;
vector<int> pontile;

int calcoloDistanze(int index) {
	if (index == distanza.size()-1)
		return 0;
	return max(pontile[index + 1] + pontile[index] + (distanza[index + 1] - distanza[index]), calcoloDistanze(index + 1));
}

int main()
{
	int N;
	in >> N;
	
	int tmp;
	for (int i = 0; i < N; i++)
	{
		in >> tmp;
		distanza.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		in >> tmp;
		pontile.push_back(tmp);
	}

	int min = LONG_MAX;
	for (int i = 0; i < N; i++)
	{
		tmp=calcoloDistanze(i);
		if (tmp < min) {
			min = tmp;
		}
	}

	out << min;
}

