/*
 * 	reduce.h
 *	Reduces stuff in an image (dimension or quality)
 *	Can do batch jobs when put in a folder
 *	Platform : GNU/Linux
 *  Created on: 17 Oct 2010
 *      Author: alex
 */

#ifndef REDUCE_H_
#define REDUCE_H_

#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <Magick++.h>

using namespace std;
using namespace Magick;

class reduce{
private:
	vector<string> files;
	vector<string> n_files;
	string path;
public:
	reduce();
	void preprocess();
	void run(double scale, double quality);
	int getn();
};

reduce::reduce(){
	char pathname[256];
	getcwd(pathname, sizeof(pathname));
	path.assign(pathname);
	cout << "Initialised with path " << path << endl;
}

void reduce::preprocess(){
	DIR *dp;
	struct dirent *dirp;
	dp = opendir(path.c_str());
	while((dirp = readdir(dp)) != NULL){
		string temp = string(dirp->d_name);
		int dot = temp.find(".");
		string ext = temp.substr(dot + 1);
		if(ext == "jpg" || ext=="png"){
			files.push_back(string(dirp->d_name));
		}

	}
	closedir(dp);

	for(unsigned int i = 0; i < files.size(); i++){
		string r = "reduced_" + files[i];
		n_files.push_back(r);
	}
}

void reduce::run(double scale, double quality){
	for(unsigned int i = 0; i < files.size(); i++){
		Image input;
		input.read(files[i]);
		double x, y;
		x = input.rows();
		y = input.columns();

		/* double asr = x/y; */
		if(x <= 100 || y <= 100){
			cout << "Picture too small, skipping " << input.fileName() << endl;
		}
		else{
			int nsx = int(x*scale);
			int nsy = int(y*scale);
			input.blur(0.5);
			input.scale(Geometry(nsx, nsy));
			input.quality(quality);
			input.write(n_files[i]);
		}
	}
}
int reduce::getn(){
	return files.size();
}

#endif /* REDUCE_H_ */
