CXX	= clang++ -m64 -O2

CXXFLAGS= -Wall -g

AS	= nasm

ASFLAGS	= -f elf64 -g

OFILES = traveling.o middleearth.o

.SUFFIXES: .o .cpp

main:$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen -g

clean:
	/bin/rm -f *.o *~
