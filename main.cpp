#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Graphe.h"
#include "TypeCarburant.h"
#include "Vehicule.h"

using namespace std;

Graphe* creerGraphe(const string& nomFichier);
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax);
void lireGraphe() { return; }

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------- main
//----------------------------------------------------------------------------------------------------------------------
int main() {
	//---------------------------------------------------- Variable ----------------------------------------------------
	int choix = 0;
	Graphe* graphe = nullptr;
	Vehicule vehicule;

	//------------------------------------------------------ Code ------------------------------------------------------
	while(true) {
		cout << "Veuillez choisir une option:" << endl
			<< "1: Entrer les caracteristique du vehicule" << endl
			<< "2: Mettre a jour la carte" << endl
			<< "3: Trouver un itineraire" << endl
			<< "4: Quitter" << endl;

		cin >> choix;

		if(choix == 4)
			break;

		switch(choix) {

			case 1: {
				string typeVehicule;
				TypeCarburant type;
				int autonomieMax, autonomieActuelle;

				// Determine le type de vehicule
				cout << "Entrez les caracteristique du vehicule selon la methode suivante:" << endl
					<< "Type de vehicule (choix: (e)ssence; e(l)ectrique; (h)ybrid): ";

				cin >> typeVehicule;

				if(typeVehicule == "e")
					type = TypeCarburant::essence;
				else if(typeVehicule == "l")
					type = TypeCarburant::electrique;
				else if(typeVehicule == "h")
					type = TypeCarburant::hybrid;
				else {
					cout << "ERREUR: Type de vehicule invalide" << endl;
					break;
				}

				// Determine l'autonomie maximale et actuelle du vehicule
				cout << "Autonomie maximale du vehicule: ";
				cin >> autonomieMax;

				cout << "Autonomie actuelle du vehicule: ";
				cin >> autonomieActuelle;

				// Cree le vehicule
				vehicule = Vehicule(type, autonomieMax, autonomieActuelle);
			}
					break;

			case 2: {
				string nomFichier;
				cout << "Entrez le nom du fichier contenant les informations sur la carte: ";
				cin >> nomFichier;

				// Cree et affiche le graphe
				graphe = creerGraphe(nomFichier);
				lireGraphe();
			}
					break;

			case 3: {
				string depart, arrive;
				if(vehicule.getTypeCarburant() == TypeCarburant::rien) {
					cout << "ERREUR: Les caracteristiques du vehicule sont necessaire a la recherche d'un itineraire"
						<< endl;
					break;
				} else if(!graphe) {
					cout << "ERREUR: Une carte est necessaire a la recherche d'un itineraire" << endl;
					break;
				}

				cout << "Entrez la station de depart: ";
				cin >> depart;

				cout << "Entrez la station d'arrive: ";
				cin >> arrive;

				// TODO call plusCourtChemin
			}
					break;

			default:
				cout << "ERREUR: Choix invalide" << endl;
				break;
		}
	}

	delete graphe;
	return 0;

} // main

//----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------- creerGraphe
//----------------------------------------------------------------------------------------------------------------------
Graphe* creerGraphe(const string& nomFichier) {
	ifstream fichier(nomFichier);
	stringstream parser;
	string donnees;

	vector<Sommet*> sommets;
	
	// Lire la première ligne (Données des sommets)
	cout << "Donnees des sommets" << endl;
	fichier >> donnees;
	parser.str(donnees);
	while(!parser.eof()) {
		string nomSommet;
		string valeurSommet;
		getline(parser, nomSommet, ',');
		getline(parser, valeurSommet, ';');

		if(nomSommet != "" && valeurSommet != "") {
			cout << "Nom du sommet: " << nomSommet << " Valeur du sommet: " << valeurSommet << endl;

			TypeCarburant valeur;
			if(valeurSommet == "rien")
				valeur = TypeCarburant::rien;
			else if(valeurSommet == "essence")
				valeur = TypeCarburant::essence;
			else if(valeurSommet == "electrique")
				valeur = TypeCarburant::electrique;
			else if(valeurSommet == "hybrid")
				valeur = TypeCarburant::hybrid;

			sommets.push_back(new Sommet(nomSommet.at(0), valeur));
		}
	}

	// Lire la deuxième ligne (Données des arcs)
	cout << endl << "Donnees des arcs" << endl;
	fichier >> donnees;
	parser.clear();
	parser.str(donnees);
	while(!parser.eof()) {
		string sommet1;
		string sommet2;
		string distance;
		getline(parser, sommet1, ',');
		getline(parser, sommet2, ',');
		getline(parser, distance, ';');

		if(sommet1 != "" && sommet2 != "" && distance != "") {
			cout << "Sommet1: " << sommet1 << " Sommet2: " << sommet2 << " Distance: " << distance << endl;
		}
	}

	return new Graphe(sommets);
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------- extractionGraphe
//----------------------------------------------------------------------------------------------------------------------
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax) {
	//---------------------------------------------------- Variable ----------------------------------------------------
	Graphe* sousGraphe;

	//------------------------------------------------------ Code ------------------------------------------------------
	for(auto sommet : graphe->getSommet()) {
		for(auto arc : sommet->getArc()) {

		}
	}

	return sousGraphe;
}