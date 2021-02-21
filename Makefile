CFLAGS = -Wall -std=c++17 -g

kliens: kliens/*.cpp kliens/*.h common/*.cpp common/*.h
	g++ -o ./klie kliens/*.cpp common/*.cpp $(CFLAGS)

szerver: szerver/*.cpp szerver/*.cpp common/*.cpp common/*.h
	g++ -o ./serv szerver/*.cpp common/*.cpp $(CFLAGS)

all: kliens szerver

clean: 
	rm -f ./klie ./serv