all:
	 g++ -std=c++11 ./src/*.cpp
clean:
	rm -rf ./headers/*.gch ./src/*.gch a.out

