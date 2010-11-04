/*
 *	Prime Generator
 *	Ignore even numbers, multiples of 5 and only 6k+1 and 6k+5 numbers are primes.
 *	Haven't gotten around to that yet.
 *	17 numbers per byte. This either.
 * 	Another guy somewhere has a similar macro structure/sieve. I can't find the link
 *	now but if you do/you are that guy, let me know and I'll credit.
 *
 */
#include <stdio.h>
#include <malloc.h>

/* define MAX 2147483647 */
#define LIM 46340
#define u unsigned

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

#define setbit(x, n) (x[n>>3] |= (1<<((n>>1)&7)))
#define checkbit(x, n) (x[n>>3] & (1<<((n>>1)&7)))
#define sq(x) (x * x)

unsigned *base, *primes;

/*void sieve(){
	base = calloc(MAX/16, sizeof(unsigned int));
	short register t = 1;
	unsigned register i, j, k; i = 3;
	for(i = 3; i < 216; i+= 2){
		if(!checkbit(base, i)){
			for(j = sq(i), k = i << 1; j < LIM; j+=k)
				setbit(base, j);
		}
		if(t) { i = 6*i + 1; t = 0;}
		else{ i = 6*i + 5; t = 1;}
	}
	primes = calloc(4830, sizeof(u));
	t = 1;
	for(i = 3, j = 0; i < LIM; i += 2){
		if(!checkbit(base, i))
			primes[j++] = i;
			printf("%u\n", i);
		if(t) { i = 6*i + 1; t = 0;}
		else{ i = 6*i + 5; t = 1;}
	}

}*/

void sieve()
{
	primes = calloc(LEN, sizeof(unsigned));
	base = calloc(MAX/64, sizeof(unsigned));
	unsigned register i, j, k;
	    for(i=3; i<LMT; i+=2)
	        if(!chkC(base, i))
	            for(j=i*i, k=i<<1; j<MAX; j+=k)
	                setC(base, j);
	    for(i=3, j=0; i<MAX; i+=2)
	        if(!chkC(base, i))
	            primes[j++] = i;
}

int main(void){
	sieve();
	int s;
	for(s = 0; s < LEN; s++){
		printf("%u\n", primes[s]);
	}
	return 0;
}
