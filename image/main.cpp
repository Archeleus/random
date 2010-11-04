/*
 * main.cpp
 *
 *  Created on: 3 Aug 2010
 *      Author: alex
 */

#include <iostream>
#include "test.h"
#include "doppler.h"
using namespace std;

int main(int argc, char **argv){
	test t;
	doppler d;
//	t.run();
	string name, out;
	printf("name\n");
	getline(cin, name);
	printf("out\n");
	getline(cin, out);
	int x, y;
	cin >> x >> y;
	t.duplicate(x, y, name, out);
//	t.mod(x,y, name);
//	double  fo;
	//d.calc(0.5, 200);
	//fo = d.fo;
	//printf("%d %d",  fo, d.t);
	return 0;
}
