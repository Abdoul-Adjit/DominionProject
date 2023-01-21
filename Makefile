
CXX=g++
CXXFLAGS=-Wall -Wextra -g -no-pie

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: carte.o maindecartes.o Joueur.o plateaudejeu.o main.o victoire.o tresor.o humain.o

	$(CXX) $^ -o $@ $(CXXFLAGS)

sfml.o: test-sfml.cpp 

	$(CXX) $(CXXFLAGS) $< -c -o $@

sfml: sfml.o carte.o maindecartes.o Joueur.o victoire.o tresor.o humain.o royaume.o royaume_action.o royaume_effet.o plateaudejeu.o

	$(CXX) $^ -o $@ $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system 

.PHONY: 
	run clean

runsfml: sfml
	./$<

run: main
	./$<

clean:
	rm -f *.o *~ *.core DominionProject/*.o 
