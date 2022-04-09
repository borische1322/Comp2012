CPPFLAGS = -std=c++11
all: mainFridge.exe mainSuperfridge.exe mainBox.exe

mainFridge.exe: apple.o elephant.o fridge.o mainFridge.cpp
	g++ -o $@ $(CPPFLAGS) apple.o elephant.o fridge.o mainFridge.cpp

mainSuperfridge.exe:apple.o elephant.o superfridge.o mainSuperfridge.cpp
	g++ -o $@ $(CPPFLAGS) apple.o elephant.o superfridge.o mainSuperfridge.cpp

mainBox.exe: apple.o elephant.o box.o mainBox.cpp
	g++ -o $@ $(CPPFLAGS) apple.o elephant.o box.o mainBox.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm  -f  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
