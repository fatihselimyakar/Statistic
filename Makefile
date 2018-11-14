test : statistic.o main.o
	g++ -o test statistic.o main.o

maim.o : main.cpp
	g++ -c main.cpp -std=c++11 main.cpp

statistic.o : statistic.cpp
	g++ -c statistic.cpp -std=c++11 statistic.cpp

clean:
	rm*.o test