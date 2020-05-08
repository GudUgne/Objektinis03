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
#include <iterator>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;

class Base {

protected:
	string v;
	string pav;

public:
	// Default constructor
	Base(string, string);
	Base();

	//Destructor
	~Base();

	//--------------------------------
	virtual void setName(string) = 0;
															// <- nesu tikra, ar reikia?
	virtual void setSurname(string) = 0;

	//-------------------
	 string getName() const;

	 string getSurname() const;
};

class Studentas: public Base {

public:

	Studentas();

	~Studentas();


	//set - nustato
	void setName(string);
	void setSurname(string);
	void setHomework(vector <double>);
	void setExam(int);

	//get - gauna naudojimui
	string getName() const;
	string getSurname() const;
	int getExam() const;
	double getFinalMed() const;
	double getFinalAve() const;

	//operatoriai 
	Studentas& operator=(const Studentas& stud);
	bool operator<(const Studentas& s2);		//lyginami studentu vardai ir pavardes
	bool operator>(const Studentas& s2);
	bool operator!=(const Studentas& s2);
	bool operator==(const Studentas& s2);

	void Skaiciavimas();

	Studentas(const Studentas&);

private:

	vector<double> nd;
	int egz;
	double vid;
	double med;
	double galmed;
	double galvid;

};