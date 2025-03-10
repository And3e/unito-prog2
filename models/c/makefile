FOLDER=$(notdir $(CURDIR))
PREFIX=$(patsubst -%,%,$(subst 0,,$(shell echo $(FOLDER) | sed 's/[0-9]*//g')))
COM="Upload di '$(PREFIX)'"

OPZ=-Wall -Werror
SRC_DIR=../../src/

ifeq ($(OS),Windows_NT)

main: $(INCLUDE_O)  main.o
	gcc -o main main.o $(INCLUDE_O)  $(OPZ)
main.o: main.c
	gcc -o main.o -c main.c $(OPZ)

run:
	start main.exe
clear:
	rm -f *.o main.exe

else

main: $(INCLUDE_O)  main.o
	gcc -o main main.o $(INCLUDE_O)  $(OPZ)
main.o: main.c
	gcc -o main.o -c main.c $(OPZ)

run:
	./main
clear:
	rm -f *.o ./main

endif

git:
	git config core.editor "vim"
	make clear
	git add .
	git commit -m $(COM)
	git push
