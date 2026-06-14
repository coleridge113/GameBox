CXX = g++
CXXFLAGS = -std=c++23

SOURCES = main.cpp utils/*.cpp

game: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o main

run: game
	./game

clean:
	rm -f game
