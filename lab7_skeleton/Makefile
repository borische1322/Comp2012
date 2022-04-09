CXX := g++
CXXFLAGS := -std=c++11
COMPONENTS := Request.o Response.o DefaultServer.o MailServer.o SearchServer.o Router.o

all: GoogleMain.exe 

GoogleMain.exe: $(COMPONENTS) GoogleMain.o
	$(CXX) -o $@ $(CXXFLAGS) $^

GoogleMain.o: GoogleMain.cpp
	$(CXX) $(CXXFLAGS) -DBLOCK_LOOPS -c $< -o $@

Router.o: Router.cpp
	$(CXX) $(CXXFLAGS) -DBLOCK_LOOPS -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm  -f  *.o *.exe
