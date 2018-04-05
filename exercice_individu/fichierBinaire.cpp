#include "fichierBinaire.h"

int ecrireFichierBinaire(string doc, Individu personne)
//BUT : Ecrire les donn�es d'un individu dans un fichier en mode binaire
//ENTREE : Objet de type Individu et document pass�s en param�tre 
//SORTIE : Ecriture des donn�es de l'individu en mode binaire
{
	//Ouverture du fichier en mode �criture
	ofstream fichier(doc, ios::out | ios::app | ios_base::binary);

	if (fichier)  //Si l'ouverture a r�ussi...
	{
		cout << "\nDebut de l'ecriture dans le fichier en mode binaire." << endl;

		//... on va � la fin du fichier afin de ne pas �craser les donn�es pr�c�dentes...
		fichier.seekp(0, ios::end);

		//... on �crit les donn�es de l'individu dedans
		fichier.write(personne.getNumSecu(), sizeof(char));
		fichier.write(personne.getNom(), sizeof(char));
		fichier.write(personne.getPrenom(), sizeof(char));
		fichier.write(personne.getDateNaissance(), sizeof(char));
		fichier.write(personne.getProfession(), sizeof(char));
		fichier.write(" ", sizeof (char));

		//Puis on ferme le fichier
		fichier.close();

		//On indique que c'est r�ussi
		cout << "\nLes donnees binaires ont bien ete ajoutees." << endl;
	}
	else  //Si le fichier n'a pas �t� trouv�
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return 0;
}

int lireFichierBinaire(string doc)
//BUT : Lire les donn�es des individus �crites dans un fichier
//ENTREE : Fichier � lire
//SORTIE : Affichage du contenu du fichier
{
	//Ouverture du fichier en mode lecture
	ifstream fichier(doc, ios_base::binary);

	if (fichier)  //Si l'ouverture a r�ussi on affiche les donn�es �crites dans le fichier
	{
		cout << "\n Lecture des donn�es binaires" << endl;

		char caractere = ' ';

		//On affiche les caract�res lus tant qu'on n'est pas arriv� � la fin du fichier
		while (!fichier.eof()) {
			fichier.read(reinterpret_cast<char*>(&caractere), sizeof(char));
			cout << caractere;
		}		
		cout << endl;

		//Puis on ferme le fichier
		fichier.close();
	}
	else {  //Si le fichier n'a pas �t� trouv�
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
	return 0;
}