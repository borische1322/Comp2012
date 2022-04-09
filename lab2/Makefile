CPPFLAGS = -std=c++11

all: lab2.exe

lab2.exe: restaurant.o dish.o materials.o main.cpp
	g++ -o $@ $(CPPFLAGS) restaurant.o dish.o materials.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
