#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	string psw[4];
	int risultati[4];
	int numCasi;
	int virusLenght;
	int pswLenght[4];
	string subs;

	in >> numCasi;
	for (int i = 0; i < numCasi; i++)
	{
		for (int j = 0; j < 4; j++) {
			in >> pswLenght[j];
		}

		in >> virusLenght;

		for (int j = 0; j < 4; j++)
		{
			in >> psw[j];
		}

		for (int j = 0; j < pswLenght[0] - (virusLenght-1); j++)
		{
			subs = psw[0].substr(j, virusLenght);
			risultati[0] = j;
			risultati[1] = psw[1].find(subs);
			if (risultati[1] != -1) {
				risultati[2] = psw[2].find(subs);
				if (risultati[2] != -1) {
					risultati[3] = psw[3].find(subs);
					if (risultati[3] != -1) {
						out << "Case #" << i+1 << ": " << risultati[0] << " " << risultati[1] << " " << risultati[2] << " " << risultati[3] << endl;
					}
				}
			}
		}
	}
}