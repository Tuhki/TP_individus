#include "fichierTexte.h"

int ecrireFichier(string doc, Individu personne)
//BUT : Ecrire les données d'un individu dans un fichier texte
//ENTREE : Objet de type Individu et nom du fichier passés en paramètre
//SORTIE : Ecriture des données de l'individu
{
	//Ouverture du fichier en mode écriture en fin de fichier
	ofstream fichier(doc, ios::out | ios::app);

	if (fichier)  //Si l'ouverture a réussi...
	{
		//... on écrit les données de l'individu dedans
		fichier << personne.getNumSecu() << endl;
		fichier << personne.getNom() << endl;
		fichier << personne.getPrenom() << endl;
		fichier << personne.getDateNaissance() << endl;
		fichier << personne.getProfession() << endl;

		//Puis on ferme le fichier
		fichier.close();

		//On indique que c'est réussi
		cout << "\nLes donnees ont bien ete ajoutees." << endl;
	}
	else  //Si le fichier n'a pas été trouvé
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}

int lireFichier(string doc)
//BUT : Lire les données des individus écrites dans un fichier texte
//ENTREE : Fichier à lire
//SORTIE : Affichage du contenu du fichier
{
	//Ouverture du fichier en mode lecture
	ifstream fichier(doc, ios::in);

	if (fichier)  //Si l'ouverture a réussi on affiche les données écrites dans le fichier
	{
		//On crée une variable qui va récupérer un caractère à la fois
		string ligne;

		//Tant qu'il y a des lignes à lire
		while (getline(fichier, ligne))
		{
			//On les affiche
			cout << ligne << endl;

		}
		
		//Puis on ferme le fichier
		fichier.close();
	}
	else   //Si le fichier n'a pas été trouvé
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}