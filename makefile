CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= sorting_algorithms.h test_sorting_algorithms.h general.h shortcut.h

TEST = test_sorting_algorithms
PROGRAM = sorting_algorithms_main								# to be inserted by student

TESTOBJECT = sorting_algorithms_test_driver.o
MAINOBJECT = sorting_algorithms_main_driver.o		# to be inserted by student
OBJS = shortcut.o sorting_algorithms.o test_sorting_algorithms.o stopwatch.o test_stopwatch.o

DOXY = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp sorting_algorithms.cpp.sample sorting_algorithms.cpp
	cp sorting_algorithms.h.sample sorting_algorithms.h
	cp stopwatch.cpp.sample stopwatch.cpp
	cp stopwatch.h.sample stopwatch.h
	cp sorting_algorithms_main_driver.cpp.sample sorting_algorithms_main_driver.cpp

#sets project as assignment
setassignment:
	cp sorting_algorithms.cpp.assignment sorting_algorithms.cpp
	cp sorting_algorithms.h.assignment sorting_algorithms.h
	cp stopwatch.cpp.assignment stopwatch.cpp
	cp stopwatch.h.assignment stopwatch.h
	cp sorting_algorithms_main_driver.cpp.assignment sorting_algorithms_main_driver.cpp


# defines current state of project as sample solution
definesample:
	cp sorting_algorithms.cpp sorting_algorithms.cpp.sample
	cp sorting_algorithms.h sorting_algorithms.h.sample
	cp stopwatch.cpp stopwatch.cpp.sample
	cp stopwatch.h stopwatch.h.sample
	cp sorting_algorithms_main_driver.cpp sorting_algorithms_main_driver.cpp.sample


# defines current sate of project as assignment
defineassignment:
	cp sorting_algorithms.cpp sorting_algorithms.cpp.assignment
	cp sorting_algorithms.h sorting_algorithms.h.assignment
	cp stopwatch.cpp stopwatch.cpp.assignment
	cp stopwatch.h stopwatch.h.assignment
	cp sorting_algorithms_main_driver.cpp sorting_algorithms_main_driver.cpp.assignment


# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall
	@echo ****************************************************************
	@echo Remove lines in makefile indicated with \"to be inserted by student\"

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
