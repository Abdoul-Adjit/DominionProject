
CXX=g++
CXXFLAGS=-Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: carte.o maindecartes.o joueur.o plateaudejeu.o main.o

	$(CXX) $^ -o $@ $(CXXFLAGS)

sfml.o: test-sfml.cpp

	$(CXX) $(CXXFLAGS) $< -c -o $@

sfml: sfml.o

	$(CXX) $^ -o $@ $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: 
	run clean

runsfml: sfml
	./$<

run: main
	./$<

clean:
	rm -f *.o *~ *.core 