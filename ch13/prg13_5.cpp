#include <iostream>
#include <fstream>
#pragma hdrstop

#include "graph.h"
#include "conncomp.h"
using namespace std;
int main(void)
{
	Graph<char> G;

	G.ReadGraph((char*)"sctest.dat");

	cout << "Strong Components:" << endl;
	ConnectedComponent(G);
} 

/*
<Run of Program 13.5>

Strong Components:
A  B  C
D  G  F
E
*/