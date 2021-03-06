// exercice_individu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fichierBinaire.h"

using namespace std;

int main()
//BUT : Tester une classe Individu
//ENTREE : Données d'identité
//SORTIE : Affichage des données
{
	//Fichier de stockage des données des individus
	const string doc = "donneesIndividu.txt";
	const string Bdoc = "donneesBinaires.txt";

	//Création d'individus
	Individu personne("1900303655421", "Dupont", "Luc", "10/03/1990", "Viticulteur");
	Individu personne2("2880567633847", "Martin", "Julie", "22/05/1988", "Gendarme");
	Individu personne3("2011201123900", "Lenoir", "Marianne", "02/12/2001", "Etudiante");

	//Affichage de ses données
	cout << personne.getNumSecu() << endl << personne.getNom() << " " << personne.getPrenom() << endl << personne.getDateNaissance() << endl << personne.getProfession() << endl;
	
	//On change la profession de l'individu
	personne.setProfession("Apiculteur");
	
	//On vérifie qu'on a bien changé sa profession
	cout << "Changement de profession : " << personne.getProfession() << endl;

	//On écrit les données dans un fichier via une fonction du main
	ecrireFichier(doc, personne);
	ecrireFichier(doc, personne2);
	ecrireFichier(doc, personne3);

	//On lit le contenu du fichier
	lireFichier(doc);

	//Lecture des données d'un individu du fichier, par fonction membre
	
	cout << "Lecture des donnees d'une personne par fonction membre : " << endl;
	personne2.lire(doc);

	//On teste l'écriture en mode binaire
	ecrireFichierBinaire(Bdoc, personne);
	ecrireFichierBinaire(Bdoc, personne2);
	ecrireFichierBinaire(Bdoc, personne3);

	//Ainsi que la lecture
	lireFichierBinaire(Bdoc);

	//On marque un temps d'arrêt pour pouvoir observer ce qu'on a fait
	system("pause");

    return 0;
}
