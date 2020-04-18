main: Fun.o Source.o Studentas.o
	g++ -o main Source.cpp Fun.o Studentas.o
functions:
	g++ -c Fun.cpp
class-functions:
	g++ -c Studentas.cpp
clean-win:
	del *.o main
clean-unix:
	rm *.o main