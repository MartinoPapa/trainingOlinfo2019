#include "pch.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
 
int main()
{
	vector<int> pezzi;

	int lunghezza;
	in >> lunghezza;

	int tmp;
	int max = -1;
	for (int i = 0; i < lunghezza; i++)
	{
		in >> tmp;
		pezzi.push_back(tmp);
		if (lunghezza - i < pezzi[i]) {
			pezzi[i] = lunghezza - i; //velocizzabile
		}
	}

	int sum;
	int diff;
	for (int i = 0; i < pezzi.size(); i++)
	{
		sum = 0;
		for (int j = pezzi[i] - 1; j > 0; j--)
		{
			if (pezzi[i + j] != 1)
			{
				diff = pezzi[i + j] + j - pezzi[i];
				if (diff > sum)
					sum = diff;
			}
		}
		pezzi[i] += sum;
	}
	for (int i = 0; i < pezzi.size(); i++)
	{
		for (int j = i+1; j < pezzi[i]+i; j++)
		{
			pezzi[j] = 0;
		}
	}

	sort(pezzi.begin(), pezzi.end());
	
	int tot = 0;
	for (int i = pezzi.size()-1; i >= 0; i--)
	{
		tot += pezzi[i];
		out << tot << " ";
	}
}
		
