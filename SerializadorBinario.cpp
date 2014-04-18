#include "SerializadorBinario.h"
SerializadorBinario::SerializadorBinario()
{
}
// bloque de lectura de datos primitivos
string SerializadorBinario::deserializeString(istream& ifs)
{
	string r;

	size_t n = 0;
	ifs.read((char*)&n, sizeof(size_t));

	char* c = new char[n];
	ifs.read(c, (std::streamsize)n);
	r = string(c);
	delete c;
	if(!ifs.good())
		throw -1;

	return r;
}
int SerializadorBinario::deserializeInt(istream& ifs)
{
	size_t _sz = sizeof(int);
	char * c = new char[_sz];
	ifs.read(c, (std::streamsize)_sz);
	int ret = *((int*)c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}
long SerializadorBinario::deserializeLong(istream& ifs)
{
	size_t _sz = sizeof(long);
	char * c = new char[_sz];
	ifs.read(c, (std::streamsize)_sz);
	long ret = *((long*)c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}
double SerializadorBinario::deserializeDouble(istream& ifs)
{
	size_t _sz = sizeof(double);
	char * c = new char[_sz];
	ifs.read(c, (std::streamsize)_sz);
	double ret = *((double*)c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}
float SerializadorBinario::deserializeFloat(istream& ifs)
{
	size_t _sz = sizeof(float);
	char * c = new char[_sz];
	ifs.read(c, (std::streamsize)_sz);
	float ret = *((float*)c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}
char SerializadorBinario::deserializeChar(istream& ifs)
{
	size_t _sz = sizeof(char);
	char * c = new char(0);
	ifs.read(c, (std::streamsize)_sz);
	char ret = *(c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}

unsigned long SerializadorBinario::deserializeUlong(istream& ifs)
{
	size_t _sz = sizeof(unsigned long);
	char * c = new char[_sz];
	ifs.read(c, (std::streamsize)_sz);
	unsigned long ret = *((unsigned long*)c);
	delete c;
	if(!ifs.good()) throw -1;
	return ret;
}
//
// bloque de serializacion de datos primitivos
bool SerializadorBinario::serialize(ostream& out, const string& s)
{
	size_t n = s.size() + 1;
	out.write((char*)&n, sizeof(size_t));
	out.write(s.c_str(), (std::streamsize)n);
	return out.good();
}
bool SerializadorBinario::serialize(ostream& out, const int& y)
{
	int n = y;
	out.write((char*)&n, sizeof(int));
	return out.good();
}
bool SerializadorBinario::serialize(ostream& out, const long& y)
{
	long n = y;
	out.write((char*)&n, sizeof(long));
	return out.good();
}
bool SerializadorBinario::serialize(ostream& out, const double& y)
{
	double n = y;
	out.write((char*)&n, sizeof(double));
	return out.good();
}
bool SerializadorBinario::serialize(ostream& out, const float& y)
{
	float n = y;
	out.write((char*)&n, sizeof(float));
	return out.good();
}
bool SerializadorBinario::serialize(ostream& out, const char& y)
{
	char n = y;
	out.write((char*)&n, sizeof(char));
	return out.good();
}

bool SerializadorBinario::serialize(ostream& out, const unsigned long& y)
{
	unsigned long n = y;
	out.write((char*)&n, sizeof(unsigned long));
	return out.good();
}
