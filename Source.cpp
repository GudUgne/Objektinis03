#include "Header.h"	

int main()
{
	std::chrono::steady_clock sc;		//timeris
	string atsakymas;
	int t, p;				//tikrinimui 
	vector <Studentas> Stud, Nuskriausti, Praslyde;

	cout << "Studentai ivedami ranka ar skaitomi is failo? Failas/Ranka" << endl;
	cin >> atsakymas;

	for (int i = 0; i < 1; i++) {

		if (atsakymas == "Failas") {
			cout << "Faila skaityti jau sukurta, ar generuoti nauja? Senas/Naujas" << endl;
			cin >> atsakymas;

			for (int i = 0; i < 1; i++) {

				if (atsakymas == "Naujas") {				//jei naujas failas

					cout << "Galutini rezultata skaiciuoti naudojant mediana ar namu darbu vidurki? Mediana/Vidurkis" << endl;
					cin >> atsakymas;

					for (int i = 0; i < 1; i++) {

						if (atsakymas == "Mediana") {
							t = 1;
						}
						else if (atsakymas == "Vidurkis") {
							t = 0;
						}

						else {
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Klaida - veskite dar karta" << endl;
							cin >> atsakymas;
							i--;
						}

					}

					int a = 100000;
					std::ofstream L("Laikai.txt");

					for (int i = 0; i < 2; i++) {

						//DuomenuFailoGeneravimas(a, 5);


						//palikta trecia strategija - tobulintas vector

						auto start = sc.now();
						DuomenuNuskaitymas(Stud, a);

						Skaiciavimai(Stud);
						sort(Stud.begin(), Stud.end(), Isrikiavimas);

						IsrusiavimasVectorTobulintas(Stud, Nuskriausti, Praslyde, t);

						Spausdinimas(Nuskriausti, t, "NuskriaustiVT" + std::to_string(a) + ".txt");
						Spausdinimas(Praslyde, t, "PraslydeVT" + std::to_string(a) + ".txt");

						Nuskriausti.clear();
						Stud.clear();

						auto end = sc.now();
						auto time_span = static_cast<std::chrono::duration<double>>(end - start);

						L << a << " stud. f. vek. apskaiciavimas TRECIA strategija truko " << time_span.count() << " sek." << endl;

					
						a = a * 10;

					}

					L.close();
				}

				else if (atsakymas == "Senas") {		//jau ikeltas failas
					p = 1;
					DuomenuNuskaitymas(Stud, p);
					t = 2;							//spausdins ir gal med ir gal vid
					Skaiciavimai(Stud);
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
					Spausdinimas(Stud, t, "Rezultatai.txt");
				}

				else {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Klaida - veskite dar karta" << endl;
					cin >> atsakymas;
					i--;
				}
			}
		}

		else if (atsakymas == "Ranka") {
			DuomenuIvedimas(Stud);
			cout << "Galutini rezultata skaiciuoti naudojant mediana ar namu darbu vidurki? Mediana/Vidurkis" << endl;
			cin >> atsakymas;

			for (int i = 0; i < 1; i++) {

				if (atsakymas == "Mediana") {
					t = 1;
					Skaiciavimai(Stud);
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
					Spausdinimas(Stud, t, "Rezultatai.txt");
				}

				else if (atsakymas == "Vidurkis") {
					t = 0;
					Skaiciavimai(Stud);
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
					Spausdinimas(Stud, t, "Rezultatai.txt");
				}

				else {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Klaida - veskite dar karta" << endl;
					cin >> atsakymas;
					i--;
				}

			}
		}

		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Klaida - veskite dar karta" << endl;
			cin >> atsakymas;
			i--;

		}
	}


	return 0;
}