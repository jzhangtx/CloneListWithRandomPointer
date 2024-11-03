CloneListWithRandomPointer: CloneListWithRandomPointer.o
	g++ -g -o CloneListWithRandomPointer.exe CloneListWithRandomPointer.o -pthread    

CloneListWithRandomPointer.o: CloneListWithRandomPointer/CloneListWithRandomPointer.cpp
	g++ -g  -c -pthread CloneListWithRandomPointer/CloneListWithRandomPointer.cpp
