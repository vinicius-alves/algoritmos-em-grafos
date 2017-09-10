#include "Writter.h"

using namespace std;

Writter::Writter(const char * filename):filename(filename){

	this->content = new ofstream();
	this->content->open (this->filename);
}

Writter::~Writter(){
	delete content;
}

void Writter::closeFile(){

  this->content->close();
  cout<<"Resultados salvos em ./"<<filename<<endl;

}
