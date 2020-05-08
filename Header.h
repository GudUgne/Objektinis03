#pragma once
#include "Studentas.h"

void DuomenuFailoGeneravimas(int kiekis, int paz);

//bool Isrikiavimas(Studentas& s1, Studentas& s2);

int Tikrinimas(int n, int t);

void DuomenuNuskaitymas(vector<Studentas>& Stud, int p);

void DuomenuIvedimas(vector <Studentas>& Stud);

void Skaiciavimai(vector <Studentas>& Stud);

bool Skola1(Studentas& Stud);

bool Skola2(Studentas& Stud);

void IsrusiavimasVectorTobulintas(vector <Studentas>& Stud, vector <Studentas>& Nuskriausti, vector <Studentas>& Praslyde, int t);

void Spausdinimas(vector <Studentas>& Stud, int t, string text);

//funkcijos testavimui

bool Praslydes(double vidurkis);

double GalutinisVidurkis(double vidurkis, int egz);