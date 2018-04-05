#include "Individu.h"

Individu::Individu(char * nSecu, char * name, char * fName, char * bDate, char * job)
{
	NuméroSécuritéSociale = nSecu;
	Nom = name;
	Prénom = fName;
	dateNaissance = bDate;
	Profession = job;
}

char * Individu::getNom()
{
	return Nom;
}

char * Individu::getPrenom()
{
	return Prénom;
}

char * Individu::getNumSecu()
{
	return NuméroSécuritéSociale;
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
	
	//On recherche les données
	while (ligne != NuméroSécuritéSociale)
	{
		getline(fichier, ligne);
	}

	//Quand on a trouvé l'identifiant, on affiche les lignes suivantes
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
