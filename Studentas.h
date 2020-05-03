#pragma once
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

/*struct Studentas {
	string v = "";
	string pav = "";     //string pats rezervuos vietu kiek reikes, jei noriu rezervuot pvz 15, rasau char[15]
	vector<double> nd;
	int egz = 0;
	double vid = 0;
	double med = 0;
	double galmed = 0;		//galutinis mediana		- cia kai spausdinu abu iskart
	double galvid = 0;		//galutinis vidurkis
}; */



class Studentas {

public:
	// Default constructor
	Studentas();


	//Destructor
	~Studentas();

	Studentas(const Studentas&);

	//set - nustato
	void setName(string);

	void setSurname(string);

	void setHomework(vector <double>);

	void setExam(int);

	//get - gauna naudojimui
	string getName() const;

	int getExam() const;

	string getSurname() const;

	double getFinalMed() const;

	double getFinalAve() const;

	Studentas& operator=(const Studentas& stud);

	bool operator<(const Studentas& s2);		//lyginami studentu vardai ir pavardes

	bool operator>(const Studentas& s2);

	bool operator!=(const Studentas& s2);

	bool operator==(const Studentas& s2);

	void Skaiciavimas();


private:
	string v;
	string pav;
	vector<double> nd;
	int egz;
	double vid;
	double med;
	double galmed;
	double galvid;

};

