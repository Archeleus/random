/*
 * 	__FILE__ : test.h
 *  Testing file for Magick++
 *  When this file is included, the main file needn't have
 *  Magick++ or the namespace defined. Initialisation for Win/OS X, I'm not sure.
 *  Created on: 3 Aug 2010
 *  Author: Alex
 */

#ifndef TEST_H_
#define TEST_H_

#include <Magick++.h>
#include <fstream>
#include <string.h>
using namespace std;
using namespace Magick;
typedef ssize_t ss;
typedef size_t s;
class test{
public:
	test();
	void run();
	void test3();
	void dump(int, int, string);
	void mod(int, int, string, string);
	void duplicate(int , int , string, string);
};

test::test(){
	cout << "This shite works" << endl;
}

void test::test3(){
	Image image("200x100", "white");
	image.type(TrueColorType);
	image.modifyImage();
	Pixels view(image);
	size_t columns = 20;
	size_t rows = 100;
	Color red("red");

	PixelPacket *pixels = view.get(0, 0, columns, rows);
	for(ssize_t row = 0; row < rows; row++){
		for(ssize_t column = 0; column < columns; column++){
			*pixels++=red;
		}
	}

	view.sync();


	s x = 60;
	s y = 100;
	Color blue("blue");
	Color yellow("yellow");
	Color green("green");

	PixelPacket *p = view.get(20, 0, x, y);

	for(ss tx = 0; tx < x; tx++){
			for(ss ty = 0; ty < y; ty++){
				if(tx <= 30)
					*p++=blue;

				else if(tx > 30 && tx <= 50)
					*p++=yellow;
				else if(tx > 50)
					*p++=green;

			}
		}

	view.sync();

	image.modifyImage();
	image.crop(Geometry(80, 100, 0, 0)); // last two args are offsets

	image.write("test3.png");
}

void test::run(){
	ofstream fout("dump.txt");


	Image image;
	image.magick("png");
	image.read("test3.png");
	Pixels view(image);
	int i, j;
	ColorRGB t; //Derived class

	for(i = 0; i < 80; i++){
		for(j = 0; j < 100; j++){
			t = image.pixelColor(i, j);
			fout << "Pixel at : " << i << "," << j << " " <<"R = " << t.red() << " G = " << t.green() << " b = " << t.blue() << endl;
		}
	}
	fout.close();

}

void test::dump(int x, int y, string name){
	Image image;
	image.read(name);
	Pixels view(image);
	ColorRGB t;
	int i, j;
	ofstream fout("dump_file.txt");
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			t = image.pixelColor(i, j);
			fout << "Pixel at : " << i << "," << j << " " <<"R = " << t.red() << " G = " << t.green() << " b = " << t.blue() << endl;
		}
	}
	fout.close();
}

void test::mod(int x, int y, string name, string outFileName){
	Image image;
	image.read(name);

	Pixels view(image);
	ColorRGB t;
	int i, j;
	for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				t = image.pixelColor(i, j);
				if(t.red() == 1){
					image.pixelColor(i, j, "green");
				}
			}
		}
	image.write(outFileName);
}

void test::duplicate(int x , int y, string name, string out){
	Image image;
	Image dup;
	image.read("test3.png");
	Pixels view(image);
	Pixels th(dup);
	ColorRGB t;
	int i , j;
	for(i = 0; i < x; i++){
				for(j = 0; j < y; j++){
					t = image.pixelColor(i, j);
					dup.pixelColor(i, j, t);
					}
				}
	dup.write("fuck.png");

}

#endif /* TEST_H_ */
