enigma: ForwardEncodingPart.o Plugboard.o\
	Reflector.o Rotor.o Main.o Enigma.o
	g++ -std=c++11 -o enigma $^

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Enigma.o: Enigma.hpp Enigma.cpp
	g++ -std=c++11 -c $^

ForwardEncodingPart.o: ForwardEncodingPart.hpp ForwardEncodingPart.cpp
	g++ -std=c++11 -c $^

Plugboard.o: Plugboard.hpp Plugboard.cpp
	g++ -std=c++11 -c $^

Reflector.o: Reflector.hpp Reflector.cpp
	g++ -std=c++11 -c $^

Rotor.o: Rotor.hpp Rotor.cpp
	g++ -std=c++11 -c $^

clean:
	rm -rf enigma *.o

.PHONY: clean
