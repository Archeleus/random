/*
 * 	Program to reduce image dimension or compression quality
 * 	Uses ImageMagick
 *	GPL, no guarantees.
 *	v1.0
 *  Created on: 17 Oct 2010
 *      Author: Archeleus
 */

#include "reduce.h"
#include <iostream>
using namespace std;

int main(void){
	cout << "Image scaler for non official small scale purposes" << endl;
	reduce image;
	cout << "Make sure that the binary is in the folder with the images" << endl;
	image.preprocess();
	cout << "Found " << image.getn() << " file(s)" << endl;
	cout << "Enter scale in percentage. Ex : 60% = 0.6 and so on: ";
	double scale;
	cin >> scale;
	cout << "Enter quality (1-100) (lower quality, lower filesize): ";
	double quality;
	cin >> quality;
	cout << "Processing" << endl;
	image.run(scale, quality);
	cout << "Done\n";

return 0;
}
