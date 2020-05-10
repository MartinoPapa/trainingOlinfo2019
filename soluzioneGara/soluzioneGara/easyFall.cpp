/*
	100/100
*/


#include "pch.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<int> pezzi;

void Ricorsione(int i) {
	int diff;
	int sum = 0;
	for (int j = pezzi[i] - 1; j > 0; j--)
	{
		if (pezzi[i + j] != 1)
		{
			diff = pezzi[i + j] + j - pezzi[i];
			if (diff > sum)
				sum = diff;
		}
	}
	if (sum > 0) {
		pezzi[i] += sum;
		Ricorsione(i);
	}
}

int main()
{
	int lunghezza;
	in >> lunghezza;

	int tmp;
	for (int i = 0; i < lunghezza; i++)
	{
		in >> tmp;
		pezzi.push_back(tmp);
		if (lunghezza - i < pezzi[i]) {
			pezzi[i] = lunghezza - i; //velocizzabile
		}
	}

	for (int i = 0; i < pezzi.size(); i++)
	{
		Ricorsione(i);
	}

	for (int i = 0; i < pezzi.size(); i++)
	{
		for (int j = i + 1; j < pezzi[i] + i; j++)
		{
			pezzi[j] = 0;
		}
	}

	sort(pezzi.begin(), pezzi.end());

	int tot = 0;
	for (int i = pezzi.size() - 1; i >= 0; i--)
	{
		tot += pezzi[i];
		out << tot << " ";
	}
}

