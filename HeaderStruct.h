#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <deque>
#include <iterator>

//siame faile - visos deklaracijos
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;

struct Studentas {
	string v = "";
	string pav = "";     //string pats rezervuos vietu kiek reikes, jei noriu rezervuot pvz 15, rasau char[15]
	vector<double> nd;
	int egz = 0;
	double vid = 0;
	double med = 0;
	double gal = 0;
	double galmed = 0;		//galutinis mediana		- cia kai spausdinu abu iskart
	double galvid = 0;		//galutinis vidurkis
}; 