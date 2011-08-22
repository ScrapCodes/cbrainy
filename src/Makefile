#Although this make file is to test src only but is also reffered my the parent makefile. So please retain it in the code.
all:
	g++ -c wrapncs.cpp wrapncs.hpp -lncurses  && g++ aptiprep.cpp aptiprep.hpp wrapncs.o -lncurses -o test  && rm *.o *.gch -f
clean: 
	rm *.o *.gch test -f
