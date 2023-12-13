all:
	g++ -I inc/include -L inc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2