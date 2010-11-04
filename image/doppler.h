/*
 * doppler.h
 * Calculates relativistic doppler shifting
 *  Created on: 5 Aug 2010
 *      Author: alex
 */

#ifndef DOPPLER_H_
#define DOPPLER_H_
typedef double dp;
#include <math.h>
#define c 299792458;
class doppler{
public:
	doppler();
	dp fo, fs,t;
	dp beta(dp);
	void calc(dp, dp);
	void h_();
};

doppler::doppler(){
	fo = fs = 0;
}

dp doppler::beta(dp v){
	return v/c;
}

void doppler::calc(dp v, dp s){
	if(v > 1){
		v = beta(v);
	}
	dp temp = sqrt((1-v)/(1+v));
	fs = s;
	fo = fs/temp;
	t = sqrt((1-v)/(1+v)) - 1;
}


#endif /* DOPPLER_H_ */
