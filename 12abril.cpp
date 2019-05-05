#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>




using namespace std;

//  #define FILE_LOG(file,type) File( (file),File::type ).getFileStream()  /*MACRO*/

class File{
public:
	enum mode_t {READ=0, WRITE, READ_WRITE, APPEND} ;

private:
	mode_t type;
	fstream fs;

public:
	File(const char* filename, mode_t mode=APPEND);
	~File(void);
	fstream& getFileStream(){return fs;}
};




File::~File(){
	fs.close();
}



File::File(const char* filename, mode_t mode){
	switch(mode){
	case WRITE:
		fs.open(filename, ios::out);
		break;
	case READ:
		fs.open(filename, ios::in);
		break;
	case APPEND:
		fs.open(filename, ios::app);
		break;	
	default:
		cerr<<"error en el modo"<<endl;

	//    /.../
	}

}



void main(){
	File f("log.txt", File::WRITE);
	f.getFileStream()<<"hola mundo"<<endl;

	//FILE_LOG("log.txt", WRITE)<<"hola mundo cruel"<<endl;      //utilizando la macro
}