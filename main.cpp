#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Graphe.h"
#include "TypeCarburant.h"
#include "Vehicule.h"
#include "Chemin.h"
#include "Arc.h"

using namespace std;


Graphe* creerGraphe(const string& nomFichier);
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax);
void plusCourtChemin(Graphe* graphe, Sommet* depart, Sommet* fin);
void lireGraphe() { return; } //TODO Complete


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------- main
//----------------------------------------------------------------------------------------------------------------------
int main() {
    //---------------------------------------------------- Variable ----------------------------------------------------
    int choix = 0;
    Graphe* graphe = nullptr;
    Vehicule vehicule;

    //------------------------------------------------------ Code ------------------------------------------------------
    while (true) {
        cout << "====================================================" << endl
            << "=== Veuillez choisir une option:" << endl
            << "===     1: Entrer les caracteristique du vehicule" << endl
            << "===     2: Mettre a jour la carte" << endl
            << "===     3: Trouver un itineraire" << endl
            << "===     4: Quitter" << endl
            << "====================================================" << endl
            << "Votre choix: ";

        cin >> choix;

        if (choix == 4)
            break;

        switch (choix) {
        case 1:
        {
            string typeVehicule;
            TypeCarburant type;
            int autonomieMax, autonomieActuelle;

            // Determine le type de vehicule
            cout << "Entrez les caracteristique du vehicule selon la methode suivante:" << endl
                << "Type de vehicule (choix: (e)ssence; e(l)ectrique; (h)ybrid): ";

            cin >> typeVehicule;

            if (typeVehicule == "e")
                type = TypeCarburant::essence;
            else if (typeVehicule == "l")
                type = TypeCarburant::electrique;
            else if (typeVehicule == "h")
                type = TypeCarburant::hybrid;
            else {
                cerr << "ERREUR: Type de vehicule invalide" << endl;
                break;
            }

            // Determine l'autonomie maximale et actuelle du vehicule
            cout << "Autonomie maximale du vehicule: ";
            cin >> autonomieMax;

            cout << "Autonomie actuelle du vehicule: ";
            cin >> autonomieActuelle;

            if (autonomieActuelle > autonomieMax) {
                cerr << "ERREUR: L'autonomie actuelle ne peut pas etre superieure a l'autonomie maximale" << endl;
                break;
            }

            // Cree le vehicule
            vehicule = Vehicule(type, autonomieMax, autonomieActuelle);
        }
        break;

        case 2:
        {
            string nomFichier;
            cout << "Entrez le nom du fichier contenant les informations sur la carte: ";
            cin >> nomFichier;

            // Cree et affiche le graphe
            graphe = creerGraphe(nomFichier);
            lireGraphe();
        }
        break;

        case 3:
        {
            string depart, arrive;
            if (vehicule.getTypeCarburant() == TypeCarburant::rien) {
                cerr << "ERREUR: Les caracteristiques du vehicule sont necessaire a la recherche d'un itineraire"
                    << endl;
                break;
            }
            else if (!graphe) {
                cerr << "ERREUR: Une carte est necessaire a la recherche d'un itineraire" << endl;
                break;
            }

            cout << "Entrez la station de depart: ";
            cin >> depart;

            cout << "Entrez la station d'arrive: ";
            cin >> arrive;

            Sommet* a = nullptr; Sommet* z = nullptr;
            for (auto sommet : graphe->getSommet()) {
                if (sommet->getName() == depart.at(0)) {
                    a = sommet;
                }
                else if (sommet->getName() == arrive.at(0)) {
                    z = sommet;
                }
            }
            if (a != nullptr && z != nullptr) {
                plusCourtChemin(graphe, a, z);

            }
        }
        break;

        default:
            cerr << "ERREUR: Choix invalide" << endl;
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

    if (fichier.fail()) {
        cerr << "ERREUR: Impossible de lire le fichier " << nomFichier << endl;
        return nullptr;
    }

    // Lire la premiere ligne (Donnees des sommets)
    cout << "Donnees des sommets" << endl;
    fichier >> donnees;
    parser.str(donnees);
    while (!parser.eof()) {
        string nomSommet;
        string valeurSommet;
        getline(parser, nomSommet, ',');
        getline(parser, valeurSommet, ';');

        if (nomSommet != "" && valeurSommet != "") {
            cout << "Nom du sommet: " << nomSommet << " Valeur du sommet: " << valeurSommet << endl;

            TypeCarburant valeur;
            if (valeurSommet == "rien")
                valeur = TypeCarburant::rien;
            else if (valeurSommet == "essence")
                valeur = TypeCarburant::essence;
            else if (valeurSommet == "electrique")
                valeur = TypeCarburant::electrique;
            else if (valeurSommet == "hybrid")
                valeur = TypeCarburant::hybrid;

            sommets.push_back(new Sommet(nomSommet.at(0), valeur));
        }
    }

    // Lire la deuxieme ligne (Donnees des arcs)
    cout << endl << "Donnees des arcs" << endl;
    fichier >> donnees;
    parser.clear();
    parser.str(donnees);
    while (!parser.eof()) {
        string sommet1;
        string sommet2;
        string distance;
        getline(parser, sommet1, ',');
        getline(parser, sommet2, ',');
        getline(parser, distance, ';');

        if (sommet1 != "" && sommet2 != "" && distance != "") {
            cout << "Sommet1: " << sommet1 << " Sommet2: " << sommet2 << " Distance: " << distance << endl;
            for (auto sommet : sommets) {
                if (sommet->getName() == sommet1.at(0)) {
                    for (auto fin : sommets) {
                        if (fin->getName() == sommet2.at(0)) {
                            Arc* arc = new Arc(fin, std::stoi(distance));
                            sommet->addArc(arc);
                        }
                    }
                }
            }
        }
    }

    return new Graphe(sommets);
} // creerGraphe

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------- extractionGraphe
//----------------------------------------------------------------------------------------------------------------------
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax) {
    //---------------------------------------------------- Variable ----------------------------------------------------
    Graphe* sousGraphe = nullptr;

    //------------------------------------------------------ Code ------------------------------------------------------
    /*for (auto sommet : graphe->getSommet()) {
        for (auto arc : sommet->getArc()) {

        }
    }*/

    return sousGraphe;
} // extractionGraphe

  //----------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------ plusCourtChemin
  //----------------------------------------------------------------------------------------------------------------------
void plusCourtChemin(Graphe* graphe, Sommet* depart, Sommet* fin) {
    //---------------------------------------------------- Variable ----------------------------------------------------

    //------------------------------------------------------ Code ------------------------------------------------------
    Chemin retour;
    bool aucun = false;
    //créer un chemin avec le depart dedans.
    //créer la liste des sommets parcourus.
    Chemin* parcourus = new Chemin(vector<Sommet*>(), 0);
    parcourus->addSommet(depart, 0);
    //créer la liste de tous les chemins empruntés et y ajouter un vecteur avec le sommet de départ
    vector<Chemin*> chemins;
    Chemin* debut = new Chemin(vector<Sommet*>(), 0);;
    debut->addSommet(depart, 0);
    chemins.push_back(debut);
    //commencer la recherche jusqu'à trouver la destination
    while (!parcourus->contains(fin) && !aucun) {
        //faire deux pointeurs, un qui pointe vers l'arc avec la distance
        //minimale et l'autre vers le chemin parcouru pour l'atteindre
        Chemin* cheminActuel = nullptr;
        Arc* minimal = nullptr;
        //trouver l'arc min à qui le sommet d'arrivé n'est pas dans le chemin parcourus.
        for (auto chemin : chemins) {//à travers tous les chemins parcourus jusqu'ici
            Sommet* sommet = chemin->getSommets().at(chemin->getSommets().size() - 1); //prendre le bout d'un chemin
            for (auto arc : sommet->getArcs()) { //trouver le minimum des arcs qui partent de lui
                if (minimal == nullptr) {
                    //initialiser minimal a un arc par le quel on n'est jamais passé
                    if (!parcourus->contains(arc->getFin())) {
                        cheminActuel = chemin;
                        minimal = arc;
                    }
                }
                else if (!parcourus->contains(arc->getFin()) && arc->getDistance() + chemin->getDistance() < minimal->getDistance() + cheminActuel->getDistance()) {
                    cheminActuel = chemin;
                    minimal = arc;
                }
            }
        }
        //ajouter le nouveau chemin dans le vecteur chemins.
        if (minimal != nullptr) {
            Chemin* newChemin = new Chemin((*cheminActuel));
            newChemin->addSommet(minimal->getFin(), minimal->getDistance());
            chemins.push_back(newChemin);
            retour = (*newChemin);
            //ajouter le sommet d'arrivé dans parcourus.
            parcourus->addSommet(minimal->getFin(), minimal->getDistance());
        }
        else {
            cout << "Aucun chemin trouvé" << endl;
            aucun = true;
        }
    }
    //TODO ici on est arrivé à destination. Retourner le dernier chemin trouvé.
    if(!aucun)cout << retour << endl;
    for (auto chemin : chemins)
        delete chemin;
}