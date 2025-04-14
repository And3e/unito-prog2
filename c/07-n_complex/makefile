FOLDER=$(notdir $(CURDIR))
PREFIX=$(patsubst -%,%,$(subst 0,,$(shell echo $(FOLDER) | sed 's/[0-9]*//g')))
COM="Upload di '$(PREFIX)'"

# OPZ=-Wall -Werror
OPZ=-Wall
FLAGS=

HDRS = $(wildcard *.h)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

ifeq ($(OS),Windows_NT)
	BIN = main.exe
else
	BIN = main
endif

all: $(BIN)

$(BIN): $(OBJS)
	gcc $(FLAGS) -o $(BIN) $(OBJS) $(OPZ)

%.o: %.c $(HDRS)
	gcc $(FLAGS) -c $< -o $@ $(OPZ)

ifeq ($(OS),Windows_NT)
run: $(BIN)
	start $(BIN)

debug: $(BIN)
	gdb $(BIN)

clear:
	rm -f *.o $(BIN)
else
run: $(BIN)
	./$(BIN)

debug: $(BIN)
	gdb ./$(BIN)

clear:
	rm -f *.o ./$(BIN)
endif

# Git commands: clear and then commit changes with a message and push.
git:
	git config core.editor "vim"
	$(MAKE) clear
	git add .
	git commit -m $(COM)
	git push