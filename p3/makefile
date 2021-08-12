
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes 
LD=gcc
LDFLAGS=
GTKFLAGS=pkg-config --cflags --libs gtk+-2.0
DOXYGEN=doxygen

# Files
EXEC=oxo
MODULES=main.c oxo.c
OBJECTS=main.o oxo.o 
 
all: $(EXEC)

oxo: $(OBJECTS)
    $(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS) $(GTKFLAGS)

main.o: main.c
    $(CC) -c main.c -o main.o $(CFLAGS) $(GTKFLAGS)

oxo.o: oxo.c
    $(CC) -c oxo.c -o oxo.o $(CFLAGS) $(GTKFLAGS)

doc:
    $(DOXYGEN) doc_conf

clean:
    rm -f *.o $(EXEC) *~