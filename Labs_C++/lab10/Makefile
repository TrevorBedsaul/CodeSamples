CXX	= clang++ -m64

CXXFLAGS= -Wall -g

AS	= nasm

ASFLAGS	= -f elf64 -g

EOFILES	=  huffmanenc.o HuffNode.o heap.cpp 

DOFILES = huffmandec.o HuffNode.o

OFILES = huffmandec.o huffmanenc.o HuffNode.o heap.cpp

ENCODER = encoder
DECODER = decoder

.SUFFIXES: .o .cpp

ENCODER:$(OFILES)
	$(CXX)  $(CXXFLAGS) -o encoder $(EOFILES)
	$(CXX)  $(CXXFLAGS) -o decoder $(DOFILES)

DECODER:$(DOFILES)


clean:
	/bin/rm -f *.o *~
