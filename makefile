CC			= g++
CCLINK		= g++
LIBS		=
CCOPTIONS	= -Wall -pedantic -g
LDOPTIONS	=
HDRS		= counter.h test_counter.h shortcut.h

TEST = counter_test
PROGRAM = counter

TESTOBJECT = counter_test_driver.o
MAINOBJECT = counter_main_driver.o
OBJS = counter.o test_counter.o shortcut.o

FILE_TO_IMPLEMENT = counter

DOXY		= /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(LIBS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<

#sets project as sample solution
setsample:
	cp $(FILE_TO_IMPLEMENT).cpp.sample $(FILE_TO_IMPLEMENT).cpp
	cp $(FILE_TO_IMPLEMENT).h.sample $(FILE_TO_IMPLEMENT).h

#sets project as assignment
setassignment:
	cp $(FILE_TO_IMPLEMENT).cpp.assignment $(FILE_TO_IMPLEMENT).cpp
	cp $(FILE_TO_IMPLEMENT).h.assignment $(FILE_TO_IMPLEMENT).h

# defines current state of project as sample solution
definesample:
	cp $(FILE_TO_IMPLEMENT).cpp $(FILE_TO_IMPLEMENT).cpp.sample
	cp $(FILE_TO_IMPLEMENT).h $(FILE_TO_IMPLEMENT).h.sample

# defines current sate of project as assignment
defineassignment:
	cp $(FILE_TO_IMPLEMENT).cpp $(FILE_TO_IMPLEMENT).cpp.assignment
	cp $(FILE_TO_IMPLEMENT).h $(FILE_TO_IMPLEMENT).h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
