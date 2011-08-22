#This make file is to test src only
all:
	g++ -c wrapncs.cpp wrapncs.hpp -lncurses  && g++ aptiprep.cpp aptiprep.hpp wrapncs.o -lncurses -o test  && rm *.o *.gch -f
clean: 
	rm *.o *.gch test -f
