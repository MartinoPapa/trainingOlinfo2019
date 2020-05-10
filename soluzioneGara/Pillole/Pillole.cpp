/*
	90/100
*/

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

long long int memoria[30][30];

long long int pillole(int intere, int meta) {
	if (memoria[intere][meta] == -1) {
		memoria[intere][meta] = pillole(intere - 1, meta + 1);
		if (meta > 0)
			memoria[intere][meta] += pillole(intere, meta - 1);
	}
	return memoria[intere][meta];
}

int main() {
	int N;
	in >> N;
	for (int i = 0;i <= N;++i) {
		memoria[0][i] = 1;
		for (int j = 1;j <= N;++j) {
			memoria[j][i] = -1;
		}
	}
	out << pillole(N, 0);
	return 0;
}