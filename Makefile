
CXX=g++
CXXFLAGS=-Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: carte.o maindecartes.o joueur.o plateaudejeu.o main.o

	$(CXX) $^ -o $@ $(CXXFLAGS)


.PHONY: 
	run clean

run: main
	./$<

clean:
	rm -f *.o *~ *.core 
