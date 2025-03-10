# if not command line → PROG = project_model
PROG ?= project_model

# count elements in cpp folder
LAST_DIR_NUM_CPP = $(shell ls -l cpp/ | grep ^d | wc -l)
# new number of project → last + 1
NEW_DIR_NUM_CPP = $(shell echo $$(( $(LAST_DIR_NUM_CPP) + 1)))
# if NEW_DIR_NUM_CPP < 10 → add 0 before
FORMATED_DIR_NUM_CPP = $(shell printf "%02d" $(NEW_DIR_NUM_CPP))
# resulting dir = cpp/<number>-<name>
NEW_DIR_CPP = cpp/$(FORMATED_DIR_NUM_CPP)-$(PROG)

# count elements in c folder
LAST_DIR_NUM_C = $(shell ls -l c/ | grep ^d | wc -l)
# new number of project → last + 1
NEW_DIR_NUM_C = $(shell echo $$(( $(LAST_DIR_NUM_C) + 1)))
# if NEW_DIR_NUM_C < 10 → add 0 before
FORMATED_DIR_NUM_C = $(shell printf "%02d" $(NEW_DIR_NUM_C))
# resulting dir = cpp/<number>-<name>
NEW_DIR_C = c/$(FORMATED_DIR_NUM_C)-$(PROG)


clear:
	find . -name '*.o' -delete
	find . -name '*.exe' -delete
	find . -name '*.out' -delete
#	@cd src && make all -s
prog-cpp:
	cp -r ./models/cpp ./$(NEW_DIR_CPP)
prog-c:
	cp -r ./models/c ./$(NEW_DIR_C)
git:
	git config core.editor "vim"
	make clear
	git add .
	git commit
	git push
