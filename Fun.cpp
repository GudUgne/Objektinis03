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

void DuomenuNuskaitymas(vector<Studentas>& Stud, int p) {
	string FailoPav;

	if (p == 1) { FailoPav = "kursiokai.txt"; }
	else { FailoPav = "SukurtasFailas" + std::to_string(p) + ".txt"; }

	std::ifstream FD(FailoPav);

	string a;		//tik nuskaityti pirmai eil
	int NdKiekis = 0;			//kiek faile yra aprasytu ND
	int l;			//laikinas
	Studentas Duomenys;

	string vardas, pavarde;
	int exam;

	vector<double> namud;


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
		FD >> vardas >> pavarde;	//stud v ir pav

		Duomenys.setName(vardas);
		Duomenys.setSurname(pavarde);

		for (int i = 0; i < NdKiekis; i++) {			//visi nd (dabar - 15)
			FD >> l;
			if ((l < 0) || (l > 10)) {
				l = 0;
				cout << "Ivedant pazymius buvo rasta klaidu, vietoj jo buvo irasytas 0" << endl;
			}
			namud.push_back(l);
		}
		FD >> exam;
		Duomenys.setExam(exam);				//egz rez

		Duomenys.setHomework(namud);
		Stud.push_back(Duomenys);				//viskas perkeliama i pagr strukturos viena nari
		namud.clear();
	}

	FD.close();

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

	int ss, n, l, t, exam;									//studentu skaicius, nd skc, laikinas ir patikrinimo kintamieji
	string pat, vardas, pavarde;
	vector<double> namud;

	cout << "Kiek mokiniu bus?" << endl;
	cin >> ss;
	t = 2;
	ss = Tikrinimas(ss, t);
	Studentas Duomenys;
	for (int i = 0; i < ss; i++) {
		cout << "Iveskite studento varda:" << endl;
		cin >> vardas;
		Duomenys.setName(vardas);
		cout << "Iveskite studento pavarde:" << endl;
		cin >> pavarde;
		Duomenys.setSurname(pavarde);
		cout << "Ar norite random sugeneruotu skaiciu? Taip/Ne" << endl;
		cin >> pat;

		//dalis, kai skaiciai ivedami ranka
		if (pat == "Ne") {
			cout << "Iveskite studento egzamino rezultata:" << endl;
			cin >> exam;

			int t = 1;										//tikrinimo fun. tikrins egz
			Tikrinimas(exam, t);		//perraso jei kazkas negerai

			Duomenys.setExam(exam);

			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1)" << endl;
			cin >> n;
			t = 0;											// tikrinimo fun. tikrins paz kieki
			n = Tikrinimas(n, t);
			if (n == -1) {
				for (int j = 0; j < 1; j++) {
					cout << "Veskite pazymi. Jei daugiau nera, veskite 0" << endl;
					cin >> l;
					if (l != 0) {
						namud.push_back(l);
						j--;
					}
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					cout << "Veskite pazymi:" << endl;
					cin >> l;
					namud.push_back(l);
				}
			}
		}

		else {						//random pazymiu generavimas
			srand(time(0));
			Duomenys.setExam((1 + rand() % 10));		//egz pazymys generuojamas nuo 1 iki 10
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1):" << endl;
			cin >> n;
			t = 0;
			n = Tikrinimas(n, t);

			if (n == -1) {
				int j = (1 + rand() % 20);			//generuojama nuo 1 iki 20, kad nebutu per daug

				for (int c = 0; c < j; c++) {
					l = (1 + rand() % 10);			//random pazymys nuo 1 iki 10
					namud.push_back(l);

				}
			}
			else {
				for (int j = 0; j < n; j++) {
					l = (1 + rand() % 10);
					namud.push_back(l);
				}
			}

		}
		Duomenys.setHomework(namud);
		Stud.push_back(Duomenys);				//viskas perkeliama i pagr struktura
		namud.clear();							//isvaloma naudoti kitam studentui
		cout << "Sio studento duomenu vedimas baigtas" << endl;
	}
}


void Skaiciavimai(vector <Studentas>& Stud) {


	for (int i = 0; i < Stud.size(); i++) {

		Stud.at(i).Skaiciavimas();

	}
}





bool Skola1(Studentas& Stud)
{
	return (Stud.getFinalAve() > 5);
}

bool Skola2(Studentas& Stud)
{
	return (Stud.getFinalMed() > 5);
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
void Spausdinimas(vector <Studentas>& Stud, int t, string text) {


	std::ofstream FR(text);

	FR << left << setw(25) << "Vardas:" << left << setw(30) << "Pavarde:";
	if (t == 1) { FR << "Gal. med" << endl; }
	else if (t == 2) { FR << "Gal. vid" << " Gal. med" << endl; }
	else { FR << "Gal. vid" << endl; }

	for (int i = 0; i < Stud.size(); i++) {

		FR << left << setw(25) << Stud.at(i).getName() << left << setw(30) << Stud.at(i).getSurname();
		if (t != 1) {
			FR << left << setw(9) << setprecision(3) << Stud.at(i).getFinalAve();
		}

		if (t != 0) {
			FR << left << setw(9) << setprecision(2) << Stud.at(i).getFinalMed();
		}

		FR << endl;
	}
	FR.close();

}