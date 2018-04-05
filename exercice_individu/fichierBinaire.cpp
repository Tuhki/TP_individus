#include "fichierBinaire.h"

int ecrireFichierBinaire(string doc, Individu personne)
//BUT : Ecrire les données d'un individu dans un fichier en mode binaire
//ENTREE : Objet de type Individu et document passés en paramètre 
//SORTIE : Ecriture des données de l'individu en mode binaire
{
	//Ouverture du fichier en mode écriture
	ofstream fichier(doc, ios::out | ios::app | ios_base::binary);

	if (fichier)  //Si l'ouverture a réussi...
	{
		cout << "\nDebut de l'ecriture dans le fichier en mode binaire." << endl;

		//... on va à la fin du fichier afin de ne pas écraser les données précédentes...
		fichier.seekp(0, ios::end);

		//... on écrit les données de l'individu dedans
		fichier.write(personne.getNumSecu(), sizeof(char));
		fichier.write(personne.getNom(), sizeof(char));
		fichier.write(personne.getPrenom(), sizeof(char));
		fichier.write(personne.getDateNaissance(), sizeof(char));
		fichier.write(personne.getProfession(), sizeof(char));
		fichier.write(" ", sizeof (char));

		//Puis on ferme le fichier
		fichier.close();

		//On indique que c'est réussi
		cout << "\nLes donnees binaires ont bien ete ajoutees." << endl;
	}
	else  //Si le fichier n'a pas été trouvé
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return 0;
}

int lireFichierBinaire(string doc)
//BUT : Lire les données des individus écrites dans un fichier
//ENTREE : Fichier à lire
//SORTIE : Affichage du contenu du fichier
{
	//Ouverture du fichier en mode lecture
	ifstream fichier(doc, ios_base::binary);

	if (fichier)  //Si l'ouverture a réussi on affiche les données écrites dans le fichier
	{
		cout << "\n Lecture des données binaires" << endl;

		char caractere = ' ';

		//On affiche les caractères lus tant qu'on n'est pas arrivé à la fin du fichier
		while (!fichier.eof()) {
			fichier.read(reinterpret_cast<char*>(&caractere), sizeof(char));
			cout << caractere;
		}		
		cout << endl;

		//Puis on ferme le fichier
		fichier.close();
	}
	else {  //Si le fichier n'a pas été trouvé
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}