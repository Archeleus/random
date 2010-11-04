/*
 * 	Greatest Common Divisor using Euclid's Algorithm
 *
 *  Created on: 23 Sep 2010
 *      Author: Archeleus
 */
#include <stdio.h>
#define uint unsigned int

uint gcd(uint a, uint b){
	uint divisor;
	asm volatile(
			"movl %1, %%eax;"
			"movl %2, %%ebx;"
			"CONTD: cmpl $0, %%ebx;"
			"je DONE;"
			"xorl %%edx, %%edx;"
			"idivl %%ebx;"
			"movl %%ebx, %%eax;"
			"movl %%edx, %%ebx;"
			"jmp CONTD;"
			"DONE: movl %%eax, %0;"
			: "=d" (divisor) : "a" (a), "b" (b)

	);

	return divisor;
}

int main(int argc, char** argv){
	if(argc < 2) printf("Usage: binarygcd [first number] [second number]\n");
	uint i , j;
	sscanf(argv[1], "%u", &i);
	sscanf(argv[2], "%u", &j);
	printf("%u\n", gcd(i, j));
return 0;
}
