CPPFLAGS = -std=c++11
all: GoogleMain.exe

GoogleMain.exe: Request.o Response.o DefaultServer.o MailServer.o SearchServer.o Router.o GoogleMain.cpp
	g++ -o $@ $(CPPFLAGS) Request.o Response.o DefaultServer.o MailServer.o SearchServer.o Router.o GoogleMain.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm  -f  *.o *.exe


