DATA=$(shell date +%Y%m%d)
FOLDER=backup$(DATA)
FILES=$(wildcard *.h *.cpp)

ifeq ($(OS),Windows_NT)

base.o: base.h base.cpp
	g++ -o base.o -c base.cpp -Wall
vet.o: vet.h vet.cpp
	g++ -o vet.o -c vet.cpp -Wall
mat.o: mat.h mat.cpp
	g++ -o mat.o -c mat.cpp -Wall
conversions.o: conversions.h conversions.cpp
	g++ -o conversions.o -c conversions.cpp -Wall
colors.o: colors.h colors.cpp
	g++ -o colors.o -c colors.cpp -Wall

else

base.o: base.h base.cpp
	g++ -o base.o -c base.cpp -Wall -lncurses
vet.o: vet.h vet.cpp
	g++ -o vet.o -c vet.cpp -Wall -lncurses
mat.o: mat.h mat.cpp
	g++ -o mat.o -c mat.cpp -Wall -lncurses
conversions.o: conversions.h conversions.cpp
	g++ -o conversions.o -c conversions.cpp -Wall -lncurses
colors.o: colors.h colors.cpp
	g++ -o colors.o -c colors.cpp -Wall -lncurses
endif

all:
	make base.o
	make vet.o
	make mat.o
	make conversions.o
	make colors.o
backup:
	rm -f -r $(FOLDER)
	mkdir $(FOLDER)
	cp $(FILES) $(FOLDER)
