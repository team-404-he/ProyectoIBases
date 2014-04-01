<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "writer.h"
using namespace std;
=======
#include <cstdio>

>>>>>>> d23371fc4bd4fe76a0ac6b7e9bbbe1e83f4afd8d
int main(int argc, char **argv)
{
	/*Writer * w = Writer::getInstance();
	char c = '0';
	w->write("fs.dbf",1,5,1,c);
	w->write("fs.dbf",1,2,2,2.8);
	w->write("fs.dbf",1,3,2,"Johan");
	w->write("fs.dbf",1,1,1,5);
	w->write("fs.dbf",1,1,1,73);*/
	
	streampos size;
  char * memblock;

  ifstream file ("fs.dbf", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [sizeof(short)];
    file.seekg (0, ios::beg);
    file.read (memblock, sizeof(short));
	 short c = *memblock;
	//for(int i = 0; i< size ;i++){
			printf("%d\n",c);//<<endl;
	//}
	
    file.close();
    delete[] memblock;
  }
  else cout << "Unable to open file";
  cin.get();
}
