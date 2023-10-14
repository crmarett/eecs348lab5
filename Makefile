all: sales football

sales: sales.o
	g++ -std=c++11 -g -Wall lab5_sales.o -o sales

sales.o: lab5_sales.cpp
	g++ -std=c++11 -g -Wall -c lab5_sales.cpp

football: football.o
	g++ -std=c++11 -g -Wall lab5_fb.o -o fb

football.o: lab5_fb.cpp
	g++ -std=c++11 -g -Wall -c lab5_fb.cpp


clean:
	rm *.o sales fb
