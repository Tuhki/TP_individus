#include "fichierTexte.h"

int ecrireFichier(string doc, Individu personne)
//BUT : Ecrire les donn�es d'un individu dans un fichier texte
//ENTREE : Objet de type Individu et nom du fichier pass�s en param�tre
//SORTIE : Ecriture des donn�es de l'individu
{
	//Ouverture du fichier en mode �criture en fin de fichier
	ofstream fichier(doc, ios::out | ios::app);

	if (fichier)  //Si l'ouverture a r�ussi...
	{
		//... on �crit les donn�es de l'individu dedans
		fichier << personne.getNumSecu() << endl;
		fichier << personne.getNom() << endl;
		fichier << personne.getPrenom() << endl;
		fichier << personne.getDateNaissance() << endl;
		fichier << personne.getProfession() << endl;

		//Puis on ferme le fichier
		fichier.close();

		//On indique que c'est r�ussi
		cout << "\nLes donnees ont bien ete ajoutees." << endl;
	}
	else  //Si le fichier n'a pas �t� trouv�
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}

int lireFichier(string doc)
//BUT : Lire les donn�es des individus �crites dans un fichier texte
//ENTREE : Fichier � lire
//SORTIE : Affichage du contenu du fichier
{
	//Ouverture du fichier en mode lecture
	ifstream fichier(doc, ios::in);

	if (fichier)  //Si l'ouverture a r�ussi on affiche les donn�es �crites dans le fichier
	{
		//On cr�e une variable qui va r�cup�rer un caract�re � la fois
		string ligne;

		//Tant qu'il y a des lignes � lire
		while (getline(fichier, ligne))
		{
			//On les affiche
			cout << ligne << endl;

		}
		
		//Puis on ferme le fichier
		fichier.close();
	}
	else   //Si le fichier n'a pas �t� trouv�
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}