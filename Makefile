all: clean
	mkdir bin && g++ -c src/wrapncs.cpp src/wrapncs.hpp -lncurses  && g++ src/aptiprep.cpp src/aptiprep.hpp wrapncs.o -lncurses -o bin/aptiprep  && rm *.o *.gch -f
debug: clean
	mkdir debug && g++ -c src/wrapncs.cpp src/wrapncs.hpp -lncurses -g && g++ src/aptiprep.cpp src/aptiprep.hpp wrapncs.o -lncurses -o debug/aptiprep -g  && rm *.o *.gch -f 
clean:
	rm -rf *.o *.gch aptiprep.tar.gz bin/ doc/ debug/
doc: all
	doxygen Doxyfile && echo 'You will need doxygen installed for this option'
install: all
	cp bin/aptiprep /usr/bin/aptiprep
tar: doc
	tar -cvzf aptiprep.tar.gz src/ bin/ doc/ Makefile Doxyfile README LICENSE
