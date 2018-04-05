#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>

using namespace std;

class Individu
{
	char * NuméroSécuritéSociale;
	char * Nom;
	char * Prénom;
	char * dateNaissance;
	char * Profession;
public:
	Individu(char * nSecu, char * name, char * fName, char * bDate, char * job);
	char * getNom();
	char * getPrenom();
	char * getNumSecu();
	char * getDateNaissance();
	char * getProfession();
	void setProfession(char *);
	void lire(string);
	~Individu();
};

