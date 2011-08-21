all: clean
	mkdir bin && g++ src/aptiprep.cpp src/aptiprep.hpp -o bin/aptiprep
debug: clean
	mkdir debug && g++ src/aptiprep.cpp src/aptiprep.hpp -o debug/aptiprep -g
clean:
	rm -rf *.o *.gch aptiprep.tar.gz bin/ doc/ debug/
doc: all
	doxygen Doxyfile
install: all
	cp bin/aptiprep /usr/bin/aptiprep
tar: doc
	tar -cvzf aptiprep.tar.gz src/ bin/ doc/ Makefile Doxyfile README LICENSE
