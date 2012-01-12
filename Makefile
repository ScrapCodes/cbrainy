all: clean
	mkdir bin && g++ -c src/wrapncs.cpp src/wrapncs.hpp -lncurses  && g++ src/cbrainy.cpp src/cbrainy.hpp wrapncs.o -lncurses -o bin/cbrainy  && cd src/ && make clean && cd ../ && rm -f wrapncs.o
debug: clean
	mkdir debug && g++ -c src/wrapncs.cpp src/wrapncs.hpp -lncurses -g && g++ src/cbrainy.cpp src/cbrainy.hpp wrapncs.o -lncurses -o debug/cbrainy -g  && cd src/ && make clean && cd ../ && rm -f wrapncs.o
clean:
	rm -rf *.o *.gch src/*.o src/*.gch cbrainy.tar.gz bin/ doc/ debug/
doc: all
	doxygen Doxyfile && echo 'You will need doxygen installed for this option'
install: all
	cp bin/cbrainy /usr/bin/cbrainy
tar: doc
	tar -cvzf cbrainy.tar.gz src/ bin/ doc/ Makefile Doxyfile README LICENSE
