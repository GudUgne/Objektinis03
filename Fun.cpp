#include "Header.h"			//siame faile yra visos funkcijos pilnai aprasytos

void DuomenuFailoGeneravimas(int kiekis, int paz) {

	string FailoPav;
	FailoPav = "SukurtasFailas" + std::to_string(kiekis) + ".txt";		//pvz SukurtasFailas1000

	std::ofstream  Sukurtas(FailoPav);

	Sukurtas << left << setw(15) << "Vardas:" << left << setw(20) << "Pavarde:";

	for (int i = 1; i <= paz; i++) {
		Sukurtas << left << setw(5) << "ND" + std::to_string(i);
	}

	Sukurtas << left << setw(5) << "Egz." << endl;


	for (int i = 1; i <= kiekis; i++) {
		Sukurtas << left << setw(15) << "Vardas" + std::to_string(i) << left << setw(20) << "Pavarde" + std::to_string(i);

		for (int j = 1; j <= paz; j++) {
			int p = (1 + rand() % 10);					//sugeneruoja ND paz
			Sukurtas << left << setw(5) << p;
		}
		int egz = (1 + rand() % 10);		//sugeneruoja egz paz
		Sukurtas << left << setw(5) << egz << endl;

	}

	Sukurtas.close();

}


int Tikrinimas(int n, int t) {

	for (int i = 0; i < 1; i++) {

		if (t == 0) {							//tikrinamas ivestas pazymiu kiekis
			if (cin.fail() || (n < -1)) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Klaida - veskite dar karta" << endl;
				cin >> n;
				i--;
			}
			else { return n; }

		}
		if (t == 1) {										//tikrinamas egz pazymys ar nd pazymys
			if (cin.fail() || (n < 0) || (n > 10)) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Klaida - veskite dar karta" << endl;
				cin >> n;
				i--;
			}
			else { return n; }

		}

		if (t == 2) {
			if (cin.fail() || (n < 0)) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Klaida - veskite dar karta" << endl;
				cin >> n;
				i--;
			}
			else { return n; }
		}
	}

}

void DuomenuIvedimas(vector <Studentas>& Stud) {

	int ss, n, l, t;									//studentu skaicius, nd skc, laikinas ir patikrinimo kintamieji
	string pat;

	cout << "Kiek mokiniu bus?" << endl;
	cin >> ss;
	t = 2;
	ss = Tikrinimas(ss, t);
	Studentas Duomenys;
	for (int i = 0; i < ss; i++) {
		cout << "Iveskite studento varda:" << endl;
		cin >> Duomenys.v;
		cout << "Iveskite studento pavarde:" << endl;
		cin >> Duomenys.pav;
		cout << "Ar norite random sugeneruotu skaiciu? Taip/Ne" << endl;
		cin >> pat;

		//dalis, kai skaiciai ivedami ranka
		if (pat == "Ne") {
			cout << "Iveskite studento egzamino rezultata:" << endl;
			cin >> Duomenys.egz;

			int t = 1;										//tikrinimo fun. tikrins egz
			Duomenys.egz = Tikrinimas(Duomenys.egz, t);		//perraso jei kazkas negerai

			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1)" << endl;
			cin >> n;
			t = 0;											// tikrinimo fun. tikrins paz kieki
			n = Tikrinimas(n, t);
			if (n == -1) {
				for (int j = 0; j < 1; j++) {
					cout << "Veskite pazymi. Jei daugiau nera, veskite 0" << endl;
					cin >> l;
					if (l != 0) {
						Duomenys.nd.push_back(l);
						j--;
					}
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					cout << "Veskite pazymi:" << endl;
					cin >> l;
					Duomenys.nd.push_back(l);
				}
			}
		}

		else {						//random pazymiu generavimas
			srand(time(0));
			Duomenys.egz = (1 + rand() % 10);		//egz pazymys generuojamas nuo 1 iki 10
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1):" << endl;
			cin >> n;
			t = 0;
			n = Tikrinimas(n, t);

			if (n == -1) {
				int j = (1 + rand() % 20);			//generuojama nuo 1 iki 20, kad nebutu per daug

				for (int c = 0; c < j; c++) {
					l = (1 + rand() % 10);			//random pazymys nuo 1 iki 10
					Duomenys.nd.push_back(l);

				}
			}
			else {
				for (int j = 0; j < n; j++) {
					l = (1 + rand() % 10);
					Duomenys.nd.push_back(l);
				}
			}

		}
		Stud.push_back(Duomenys);				//viskas perkeliama i pagr struktura
		Duomenys.nd.clear();							//isvaloma naudoti kitam studentui
		cout << "Sio studento duomenu vedimas baigtas" << endl;
	}
}


bool Isrikiavimas(Studentas& s1, Studentas& s2) {
	if (s1.v < s2.v) return s1.v < s2.v;
	else if (s1.v == s2.v) return s1.pav < s2.pav;

}

void IsrusiavimasList(list<Studentas>& Stud, list<Studentas>& Nuskriausti, list<Studentas>& Praslyde, int t) {

	auto it = Stud.begin();
	int x = Stud.size();

	if (t == 0) {
		for (int i = 0; i < x; i++)
		{
			if (it->galvid < 5)
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galvid = it->galvid;
				Nuskriausti.push_back(a);
			}
			else
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galvid = it->galvid;
				Praslyde.push_back(a);
			}
			it++;
		}
	}

	else {
		for (int i = 0; i < x; i++)
		{
			if (it->galmed < 5)
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galmed = it->galmed;
				Nuskriausti.push_back(a);
			}
			else
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galmed = it->galmed;
				Praslyde.push_back(a);
			}
			it++;
		}

	}

	Stud.clear();

}

void IsrusiavimasList2(list<Studentas>& Stud, list<Studentas>& Nuskriausti, int t) {

	auto it = Stud.begin();

	if (t == 0) {
		for (int i = 0; i < Stud.size(); i++)
		{
			if (it->galvid < 5)
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galvid = it->galvid;
				Nuskriausti.push_back(a);
				Stud.erase(it);
				it = Stud.begin();
				advance(it, i);
				i--;
			}

			else it++;
		}
	}

	else {
		for (int i = 0; i < Stud.size(); i++)
		{
			if (it->galmed < 5)
			{
				Studentas a;
				a.v = it->v;
				a.pav = it->pav;
				a.galmed = it->galmed;
				Nuskriausti.push_back(a);
				Stud.erase(it);
				it = Stud.begin();
				advance(it, i);
				i--;
			}

			else it++;
		}

	}

}

bool Skola1(Studentas& Stud)
{
	return (Stud.galvid > 5);
}

bool Skola2(Studentas& Stud)
{
	return (Stud.galmed > 5);
}

void IsrusiavimasVectorTobulintas(vector <Studentas>& Stud, vector <Studentas>& Nuskriausti, vector <Studentas>& Praslyde, int t) {


	if (t == 0) {

		std::remove_copy_if(Stud.begin(), Stud.end(), std::back_inserter(Nuskriausti), Skola1);
		std::copy_if(Stud.begin(), Stud.end(), std::back_inserter(Praslyde), Skola1);

		Stud.erase(Stud.begin(), Stud.end());

	}

	else {

		std::remove_copy_if(Stud.begin(), Stud.end(), std::back_inserter(Nuskriausti), Skola2);
		std::copy_if(Stud.begin(), Stud.end(), std::back_inserter(Praslyde), Skola2);

		Stud.erase(Stud.begin(), Stud.end());
	}

}