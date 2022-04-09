CPPFLAGS = -std=c++11

all: PA1.exe

PA1.exe: thing.o cell.o game.o main.cpp
	g++ -o $@ $(CPPFLAGS) thing.o cell.o game.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
