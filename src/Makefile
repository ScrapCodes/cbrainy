#Although this make file is to test src only but is also reffered my the parent makefile. So please retain it in the code.
all:
	g++ -c -Wall wrapncs.cpp wrapncs.hpp -lncurses  && g++ -Wall cbrainy.cpp cbrainy.hpp wrapncs.o -lncurses -o test  && rm *.o *.gch -f
clean: 
	rm *.o *.gch test -f
