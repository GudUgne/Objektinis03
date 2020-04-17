#include "HeaderStruct.h"

void DuomenuFailoGeneravimas(int kiekis, int paz);

template <typename T1>
void DuomenuNuskaitymas(T1& Stud, int p) {
	string FailoPav;

	if (p == 1) { FailoPav = "kursiokai.txt"; }
	else { FailoPav = "SukurtasFailas" + std::to_string(p) + ".txt"; }

	std::ifstream FD(FailoPav);

	string a;		//tik nuskaityti pirmai eil
	int NdKiekis = 0;			//kiek faile yra aprasytu ND
	int l;			//laikinas
	Studentas Duomenys;


	if (!FD) {
		cout << "Duomenu failas nerastas, programa nebus vykdoma" << endl;
		exit(0);
	}

	FD >> a >> a >> a;		//skaito  pirmos eiles teksta
	while (a[0] == 'N') {			//atpazista kiek ND yra
		NdKiekis++;
		FD >> a;		//ciklo pabaigoje a tampa egzaminu
	}

	while (!FD.eof()) {
		FD >> Duomenys.v >> Duomenys.pav;	//stud v ir pav
		for (int i = 0; i < NdKiekis; i++) {			//visi nd (dabar - 15)
			FD >> l;
			if ((l < 0) || (l > 10)) {
				l = 0;
				cout << "Ivedant pazymius buvo rasta klaidu, vietoj jo buvo irasytas 0" << endl;
			}
			Duomenys.nd.push_back(l);
		}
		FD >> Duomenys.egz;				//egz rez

		Stud.push_back(Duomenys);				//viskas perkeliama i pagr strukturos viena nari
		Duomenys.nd.clear();
	}

	FD.close();

}

bool Isrikiavimas(Studentas& s1, Studentas& s2);

int Tikrinimas(int n, int t);

void DuomenuIvedimas(vector <Studentas>& Stud);

template<typename T1>
void Skaiciavimai(T1& Stud) {

	auto it = Stud.begin();
	int pozicija;

	for (int i = 0; i < Stud.size(); i++) {

		sort(it->nd.begin(), it->nd.end());		//mediana kai lyg skc nariu
		pozicija = it->nd.size();
		if (pozicija % 2 == 0) {
			it->med = ((it->nd.at(pozicija / 2)) + (it->nd.at(pozicija / 2 - 1))) / 2;
		}
		else {
			it->med = it->nd.at(pozicija / 2);				//skaiciuojama mediana kai nelyg skc nariu
		}
		it->galmed = (0.4 * it->med) + (0.6 * it->egz);



		for (int j = 0; j < it->nd.size(); j++) {
			it->vid += it->nd.at(j);			//visu nd pazymiu suma
		}

		it->vid = it->vid / it->nd.size();		//suskaiciuojamas vidurkis
		it->galvid = (0.4 * it->vid) + (0.6 * it->egz);

		it++;
	}
}

template<typename T1>
void Spausdinimas(T1& Stud, int t, string text) {

	auto it = Stud.begin();		//iteratorius


	std::ofstream FR(text);

	FR << left << setw(25) << "Vardas:" << left << setw(30) << "Pavarde:";
	if (t == 1) { FR << "Gal. med" << endl; }
	else if (t == 2) { FR << "Gal. vid" << " Gal. med" << endl; }
	else { FR << "Gal. vid" << endl; }

	for (int i = 0; i < Stud.size(); i++) {

		FR << left << setw(25) << it->v << left << setw(30) << it->pav;
		if (t != 1) {
			FR << left << setw(9) << setprecision(3) << it->galvid;
		}

		if (t != 0) {
			FR << left << setw(9) << setprecision(2) << it->galmed;
		}

		FR << endl;
		it++;
	}
	FR.close();

}


template<typename T1, typename T2, typename T3>
void Isrusiavimas(T1& Stud, T2& Nuskriausti, T3& Praslyde, int t) {
	if (t == 0) {
		for (int i = 0; i < Stud.size(); i++) {
			if (Stud.at(i).galvid < 5) {
				Nuskriausti.push_back(Stud.at(i));

			}
			else {
				Praslyde.push_back(Stud.at(i));
			}


		}
	}

	else {
		for (int i = 0; i < Stud.size(); i++) {
			if (Stud.at(i).galmed < 5) {

				Nuskriausti.push_back(Stud.at(i));
			}
			else {
				Praslyde.push_back(Stud.at(i));
			}

		}
	}

	Stud.clear();

}



template<typename T1, typename T2>
void Isrusiavimas2(T1& Stud, T2& Nuskriausti, int t) {
	if (t == 0) {
		for (int i = 0; i < Stud.size(); i++) {
			if (Stud.at(i).galvid < 5) {
				Nuskriausti.push_back(Stud.at(i));
				Stud.erase(Stud.begin() + i);
				i--;
			}

		}
	}

	else {
		for (int i = 0; i < Stud.size(); i++) {
			if (Stud.at(i).galmed < 5) {

				Nuskriausti.push_back(Stud.at(i));
				Stud.erase(Stud.begin() + i);
				i--;
			}

		}
	}

}

bool Skola1(Studentas& Stud);

bool Skola2(Studentas& Stud);

void IsrusiavimasVectorTobulintas(vector <Studentas>& Stud, vector <Studentas>& Nuskriausti, vector <Studentas>& Praslyde, int t);

void IsrusiavimasList(list<Studentas>& Stud, list<Studentas>& Nuskriausti, list<Studentas>& Praslyde, int t);

void IsrusiavimasList2(list<Studentas>& Stud, list<Studentas>& Nuskriausti, int t);

