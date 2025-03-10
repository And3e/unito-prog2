FOLDER=$(notdir $(CURDIR))
PREFIX=$(patsubst -%,%,$(subst 0,,$(shell echo $(FOLDER) | sed 's/[0-9]*//g')))
COM="Upload di '$(PREFIX)'"

OPZ=-Wall -Werror
LIB_DIR=../../lib/
INCLUDE_O=$(LIB_DIR)base.o $(LIB_DIR)conversions.o
INCLUDE_H=$(LIB_DIR)base.h $(LIB_DIR)conversions.h

ifeq ($(OS),Windows_NT)

main: $(INCLUDE_O) func.o main.o
	g++ -o main main.o $(INCLUDE_O)  func.o $(OPZ)
func.o: func.h $(INCLUDE_H) func.cpp
	g++ -o func.o -c func.cpp $(OPZ)
main.o: func.h main.cpp
	g++ -o main.o -c main.cpp $(OPZ)

run:
	start main.exe
clear:
	rm -f *.o main.exe

else

main: $(INCLUDE_O) func.o main.o
	g++ -o main main.o $(INCLUDE_O)  func.o $(OPZ) -lncurses
func.o: func.h $(INCLUDE_H) func.cpp
	g++ -o func.o -c func.cpp $(OPZ) -lncurses
main.o: func.h main.cpp
	g++ -o main.o -c main.cpp $(OPZ) -lncurses

run:
	./main
clear:
	rm -f *.o main.out

endif

git:
	git config core.editor "vim"
	make clear
	git add .
	git commit -m $(COM)
	git push
