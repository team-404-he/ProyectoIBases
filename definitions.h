#define EXIT_SUCCESS 1
#define NO_OPEN_FILE 2
#define UNSPECIFIED_ID 3
typedef unsigned long size;
typedef unsigned long id;

enum Tipo_Dato {
	INTEGER,
	DOUBLE,
	STRING,
	BYTE
};
int sizeDT(Tipo_Dato t){
		switch(t){
			case Tipo_Dato::BYTE:
				return sizeof(char);
			case Tipo_Dato::DOUBLE:
				return sizeof(float);
			case Tipo_Dato::INTEGER:
				return sizeof(int);
			case Tipo_Dato::STRING;
				return sizeof(char[128]);
		}
}