/*
	Autor: Steven Brenes Chavarría
	Email: sbrenesms@gmail.com
	Universidad Nacional de Costa Rica
	Licencia: GNU
*/
#ifndef SEBI_H
#define SEBI_H

#include <string>
#include <fstream>
using namespace std;

//namespace serializador
//{
class SerializadorBinario
{
public:
	//
	// bloque de lectura de datos primitivos
	static string deserializeString(istream&);
	static int deserializeInt(istream&);
	static long deserializeLong(istream&);
	static double deserializeDouble(istream&);
	static float deserializeFloat(istream&);
	static char deserializeChar(istream&);

	static unsigned long deserializeUlong(istream&);
	//
	// bloque de serializacion de datos primitivos
	static bool serialize(ostream&, const string&);
	static bool serialize(ostream&, const int&);
	static bool serialize(ostream&, const long&);
	static bool serialize(ostream&, const double&);
	static bool serialize(ostream&, const float&);
	static bool serialize(ostream&, const char&);

	static bool serialize(ostream&, const unsigned long&);

protected:
	SerializadorBinario();
};
//}
#endif
