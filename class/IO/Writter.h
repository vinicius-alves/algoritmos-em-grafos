#include <fstream>
#include <iostream>

using namespace std;

#ifndef WRITTER_H
#define WRITTER_H

class Writter {

	public:
		Writter(const char * filename);
		~Writter();
		ofstream * getContent();
		void closeFile();
		ofstream * content;

	private:
		const char * filename;
};

#endif