#include "Individu.h"

Individu::Individu(char * nSecu, char * name, char * fName, char * bDate, char * job)
{
	Num�roS�curit�Sociale = nSecu;
	Nom = name;
	Pr�nom = fName;
	dateNaissance = bDate;
	Profession = job;
}

char * Individu::getNom()
{
	return Nom;
}

char * Individu::getPrenom()
{
	return Pr�nom;
}

char * Individu::getNumSecu()
{
	return Num�roS�curit�Sociale;
}

char * Individu::getDateNaissance()
{
	return dateNaissance;
}

char * Individu::getProfession()
{
	return Profession;
}

void Individu::setProfession(char * job)
{
	Profession = job;
}

void Individu::lire(string doc)
{
	int i;
	int nbr = 5; //nombre d'attributs d'un objet individu
	string ligne = "";
	ifstream fichier(doc, ios::in);
	
	//On recherche les donn�es
	while (ligne != Num�roS�curit�Sociale)
	{
		getline(fichier, ligne);
	}

	//Quand on a trouv� l'identifiant, on affiche les lignes suivantes
	for (i = 0; i < nbr; i++) {
		cout << ligne << endl;
		getline(fichier, ligne);
	}

	//On referme le fichier
	fichier.close();
}


Individu::~Individu()
{
}
