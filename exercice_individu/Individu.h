#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>

using namespace std;

class Individu
{
	char * Num�roS�curit�Sociale;
	char * Nom;
	char * Pr�nom;
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

