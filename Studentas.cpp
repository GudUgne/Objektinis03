#include "Studentas.h"


Base::Base(){}

Base::Base(string vardas, string pavarde) {

	v = vardas;
	pav = pavarde;
}

Base::~Base() {}


//-----------------------------------------------------------Derived


Studentas::Studentas(const Studentas& SenaKlase) {			//kopijavimas	
																//sukuri klase, i ja nukopijuoji
	v = SenaKlase.v;
	pav = SenaKlase.pav;
	nd = SenaKlase.nd;
	egz = SenaKlase.egz;
	vid = SenaKlase.vid;
	med = SenaKlase.med;
	galmed = SenaKlase.galmed;
	galvid = SenaKlase.galvid;

}

Studentas::Studentas() {
	int egz = 0;
	double vid = 0.0;
	double med = 0.0;
	double galmed = 0.0;			//string ir vector inicialiazuoti nereikia
	double galvid = 0.0;
}

Studentas::~Studentas() {}

void Studentas::setName(string vardas) { v = vardas; }

void Studentas::setSurname(string pavarde) { pav = pavarde; }

void Studentas::setHomework(vector <double> namud) { nd = namud; }

void Studentas::setExam(int egzam) { egz = egzam; }

int Studentas::getExam() const { return egz; }

string Studentas::getName() const { return v; }

string Studentas::getSurname() const { return pav; }

double Studentas::getFinalAve() const { return galvid; }

double Studentas::getFinalMed() const { return galmed; }



//Operatoriai 
Studentas& Studentas::operator=(const Studentas& s) {
	if (&s == this) return *this;
	v = s.getName();										//o cia antras budas nopijuoti
	pav = s.getSurname();
	galmed = s.getFinalMed();
	galvid = s.getFinalAve();
	return *this;
}

bool Studentas::operator<(const Studentas& s2) {
	if (v != s2.getName()) return v < s2.getName();
	else return pav < s2.getSurname();
}

bool Studentas::operator>(const Studentas& s2) {
	if (v != s2.getName()) return v > s2.getName();
	else return pav > s2.getSurname();
}

bool Studentas::operator==(const Studentas& s2) {
	if (v == s2.getName() &&
		pav == s2.getSurname() &&
		galmed == s2.getFinalMed() &&
		galvid == s2.getFinalAve())
	{
		return true;
	}
}

bool Studentas::operator!=(const Studentas& s2) {
	if (v != s2.getName() ||
		pav != s2.getSurname() ||
		galmed != s2.getFinalMed() ||
		galvid != s2.getFinalAve())
	{
		return false;
	}


}




//funkcija 

void Studentas::Skaiciavimas() {

	sort(nd.begin(), nd.end());		//mediana kai lyg skc nariu
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
	galvid = (0.4 * vid) + (0.6 * egz);

}