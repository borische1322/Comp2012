CPPFLAGS = -std=c++11

all: lab3.exe

lab3.exe: ChineseDish.o Customer.o Customer_order_ChineseDish.o Customer_order_WesternDish.o Dish.o Person.o Waiter.o WesternDish.o main.cpp
	g++ -o $@ $(CPPFLAGS) ChineseDish.o Customer.o Customer_order_ChineseDish.o Customer_order_WesternDish.o Dish.o Person.o Waiter.o WesternDish.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
