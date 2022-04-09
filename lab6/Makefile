CPPFLAGS = -std=c++11
all: test1.exe test2.exe test3.exe

test1.exe: test1.o Request.o Response.o MailServer.o SearchServer.o LBServer.o
	g++ -o $@ $(CPPFLAGS) test1.cpp Request.o Response.o  MailServer.o SearchServer.o LBServer.o

test2.exe: test2.o Request.o Response.o MailServer.o SearchServer.o LBServer.o
	g++ -o $@ $(CPPFLAGS) test2.cpp Request.o Response.o  MailServer.o SearchServer.o LBServer.o

test3.exe: test3.o Request.o Response.o MailServer.o SearchServer.o LBServer.o
	g++ -o $@ $(CPPFLAGS) test3.cpp Request.o Response.o  MailServer.o SearchServer.o LBServer.o

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm  -f  *.o *.exe