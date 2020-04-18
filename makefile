main: 
	g++ -std=c++11 Fun,cpp Source.cpp Studentas.cpp -o main
functions:
	g++ -c Fun.cpp
class-functions:
	g++ -c Studentas.cpp
clean-win:
	del *.o main
clean-unix:
	rm *.o main
