#include "writer.h"
Writer * Writer::instance = NULL;
Writer::Writer() {}
Writer * Writer::getInstance()
{
	if(Writer::instance == NULL) Writer::instance = new Writer();
	return Writer::instance;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,std::string data)
{
	size next = 4*sizeof(long) + data.size()+1;
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)data.size()+1);
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,long data)
{
	size next = 4*sizeof(unsigned long);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)sizeof(data));
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,int data)
{
	size next = 3*sizeof(unsigned long) + sizeof(int);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)sizeof(data));
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,char data)
{
	size next =  3*sizeof(unsigned long) + sizeof(char);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)sizeof(data));
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,float data)
{
	size next =  3*sizeof(unsigned long) + sizeof(float);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)sizeof(data));
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}
int Writer::write(char * path,id tablespace_id, id table_id,id columna_id,double data)
{
	size next =  3*sizeof(unsigned long) + sizeof(double);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile.seekp (0, ios::end);
	SerializadorBinario::serialize(outFile, (long)next);
	SerializadorBinario::serialize(outFile, (long)tablespace_id);
	SerializadorBinario::serialize(outFile, (long)table_id);
	SerializadorBinario::serialize(outFile, (long)columna_id);
	//SerializadorBinario::serialize(outFile, (long)sizeof(data));
	SerializadorBinario::serialize(outFile, data);
	outFile.close();
	return EXIT_SUCCESS;
}