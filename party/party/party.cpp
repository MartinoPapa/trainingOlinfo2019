#include "pch.h"
#include <fstream>
#include <cstdio>

using namespace std;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int numCasi;
	in >> numCasi;
	int sum=0;
	int tmpData;
	int NumInvitati;

	for (int i = 0; i < numCasi; i++)
	{
		sum = 0;
		in >> NumInvitati;
		for(int j = 0; j < NumInvitati; j++)
		{			
			in >> tmpData;
			if (tmpData > 0) {
				sum += tmpData;
			}
		}
		out << "Case #" << i+1 << ": " << sum << endl;
	}
}
