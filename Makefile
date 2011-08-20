all: clean
	mkdir bin && g++ src/aptiprep.cpp src/aptiprep.hpp -o bin/aptiprep
clean:
	rm -rf *.o *.gch aptiprep.tar.gz bin/ doc/
doc: all
	doxygen Doxyfile
tar: clean all doc
	tar -cvzf aptiprep.tar.gz src/ bin/ doc/ Makefile Doxyfile README LICENSE
