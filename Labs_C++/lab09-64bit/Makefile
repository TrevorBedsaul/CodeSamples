CXX	= clang -m64

CXXFLAGS	= -Wall -g

AS	= nasm

ASFLAGS	= -f elf64 -g

OFILES	=  linkedlist.o

.SUFFIXES: .o .c

main:	$(OFILES)
	$(CXX)  $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
