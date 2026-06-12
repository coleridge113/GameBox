CXX = g++
CXXFLAGS = -std=c++23

SOURCES = main.cpp classes/*.cpp

game: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o game

run: game
	./game

clean:
	rm -f game
