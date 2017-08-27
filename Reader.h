#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <bitset>

using namespace std;

typedef bitset<1> bit;

class Reader{

	public:
		Reader(const char *);
		vector<vector<bit> > getMatrix();

	private:
		const char * path;

};

