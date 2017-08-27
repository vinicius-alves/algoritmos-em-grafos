#include "Reader.h"

using namespace std;

Reader::Reader(const char * path):path(path){};


vector<vector<bit > > Reader::getMatrix(){

ifstream file;
file.open(this->path);

if (file.is_open()){

	string line;

    getline(file,line); 
    

    int lines = atoi(line.c_str());

    cout<<lines<<endl;
    cout<<"\'=\'"<<endl;

	file.close();

	vector<vector<bit > > matrix(lines, vector<bit >(lines));

	return matrix;

} else{
	throw invalid_argument( "File not found!" );
}


};