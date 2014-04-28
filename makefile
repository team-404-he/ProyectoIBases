CC=g++
CFLAGS=-c -g #-Wall
LDFLAGS=
SOURCES=main.cpp definitions.h definitions.cpp any.h DBElement.h columna.h columna.cpp diccionario_datos.h diccionario_datos.cpp silly.cpp SerializadorBinario.h SerializadorBinario.cpp table.h table.cpp table_space.h table_space.cpp writer.h writer.cpp user.h user.cpp data_carrier.h db_system.h db_system.cpp data_set.h data_set.cpp sesion_actual.h sesion_actual.cpp login.h login.cpp operaciones.h operaciones.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Bases1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:	
	rm *.o
	rm Bases1
