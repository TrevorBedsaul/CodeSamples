#Trevor Bedsaul
#tdb7mw
#10.13.17
#Makefile

CXX = clang++ -O2

CXXFLAGS = -Wall -g

OFILES = hashTable.o timer.o wordPuzzle.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX)  $(OFILES)
clean:
	/bin/rm -f *.o *~

getWordInGrid.o: getWordInGrid.cpp
hashTable.o: hashTable.cpp hashTable.h
primenumber.o: primenumber.cpp
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
