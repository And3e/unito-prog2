FOLDER=$(notdir $(CURDIR))
PREFIX=$(patsubst -%,%,$(subst 0,,$(shell echo $(FOLDER) | sed 's/[0-9]*//g')))
COM="Upload di '$(PREFIX)'"

# OPZ=-Wall -Werror
OPZ=-Wall

# SRC_DIR=../../src/
# INCLUDE_O=$(SRC_DIR)base.o $(SRC_DIR)conversions.o
# INCLUDE_H=$(SRC_DIR)base.h $(SRC_DIR)conversions.h

FLAGS = -g

ifeq ($(OS),Windows_NT)

main: $(INCLUDE_O) contact.o main.o
	gcc $(FLAGS) -o main main.o $(INCLUDE_O) contact.o $(OPZ)
contact.o: contact.h $(INCLUDE_H) contactOpq.c
	gcc $(FLAGS) -o contact.o -c contactOpq.c $(OPZ)
main.o: contact.h main.c
	gcc $(FLAGS) -o main.o -c main.c $(OPZ)

run:
	start main.exe
debug:
	gdb main.exe
clear:
	rm -f *.o main.exe

else

main: $(INCLUDE_O) contact.o main.o
	gcc $(FLAGS) -o main main.o $(INCLUDE_O) contact.o $(OPZ)
contact.o: contact.h $(INCLUDE_H) contactOpq.c
	gcc $(FLAGS) -o contact.o -c contactOpq.c $(OPZ)
main.o: contact.h main.c
	gcc $(FLAGS) -o main.o -c main.c $(OPZ)

run:
	./main
debug:
	gdb ./main
clear:
	rm -f *.o ./main

endif

git:
	git config core.editor "vim"
	make clear
	git add .
	git commit -m $(COM)
	git push
