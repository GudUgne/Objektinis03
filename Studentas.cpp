#include "Studentas.h"

Studentas::Studentas(){
	int egz = 0;
	double vid = 0.0;
	double med = 0.0;
	double galmed = 0.0;
	double galvid = 0.0;
}

Studentas::~Studentas(){

}

void Studentas::setName(string vardas) {
	v = vardas;
}

void Studentas::setSurname(string pavarde) {
	pav = pavarde;
}

void Studentas::setHomework(vector <double> namud) {
	nd = namud;
}

void Studentas::setExam(int egzam) {
	egz = egzam;
}

string Studentas::getName() const {
	return v;
}

string Studentas::getSurname() const {
	return pav;
}

double Studentas::getFinalAve() const {
	return galvid;
}

double Studentas::getFinalMed() const {
	return galmed;
}

void Studentas::Skaiciavimas() {

	sort(nd.begin(),nd.end());		//mediana kai lyg skc nariu
	int pozicija = nd.size();

	if (pozicija % 2 == 0) {
		med = ((nd.at(pozicija / 2)) + (nd.at(pozicija / 2 - 1))) / 2;
	}
	else {
		med = nd.at(pozicija / 2);				//skaiciuojama mediana kai nelyg skc nariu
	}
	galmed = (0.4 * med) + (0.6 * egz);


	for (int j = 0; j < nd.size(); j++) {
		vid += nd.at(j);			//visu nd pazymiu suma
	}

	vid = vid / nd.size();		//suskaiciuojamas vidurkis
	galvid = (0.4 * vid) + (0.6 *egz);

}