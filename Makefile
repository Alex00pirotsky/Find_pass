all:
	g++ ./src/*.cpp ./headers/*.h
clean:
		rm -rf ./headers/*.gch ./src/*.gch a.out

