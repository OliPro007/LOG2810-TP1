#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Graphe.h"
#include "Vehicule.h"
#include "Chemin.h"
#include "Arc.h"

using namespace std;

Graphe* creerGraphe(const string& nomFichier);
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax);
void lireGraphe(Graphe* graphe);
int plusCourtChemin(Graphe* graphe, Sommet* depart, Sommet* fin, Vehicule* vehicule);

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------- main
//----------------------------------------------------------------------------------------------------------------------
int main() {
    int choix = 0;
    Graphe* graphe = nullptr;
    Vehicule* vehicule = nullptr;

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
                char type;
                int autonomieMax, autonomieActuelle;

                // Determine le type de vehicule
                cout << "Entrez les caracteristique du vehicule selon la methode suivante:" << endl
                     << "Type de vehicule (choix: (e)ssence; e(l)ectrique; (h)ybrid): ";

                cin >> type;

                if (type != 'e' && type != 'l' && type != 'h') {
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
                vehicule = new Vehicule(type, autonomieMax, autonomieActuelle);
            }
                break;

            case 2: 
            {
                string nomFichier;
                cout << "Entrez le nom du fichier contenant les informations sur la carte: ";
                cin >> nomFichier;

                // Cree et affiche le graphe
                graphe = creerGraphe(nomFichier);
                lireGraphe(graphe);
            }
                break;

            case 3:
            {
                string depart, arrive;
                if (!vehicule || vehicule->getTypeCarburant() == 'r') {
                    cerr << "ERREUR: Les caracteristiques du vehicule sont necessaire a la recherche d'un itineraire"
                         << endl;
                    break;
                } else if (!graphe) {
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
                    vehicule->setAutonomieActuelle(plusCourtChemin(extractionGraphe(graphe, vehicule->getAutonomieMax()), a, z, vehicule));

                }
            }
                break;

            default:
                cerr << "ERREUR: Choix invalide" << endl;
                break;
        }
    }

    delete vehicule;
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
    fichier >> donnees;
    parser.str(donnees);
    while (!parser.eof()) {
        string nomSommet;
        string valeurSommet;
        getline(parser, nomSommet, ',');
        getline(parser, valeurSommet, ';');

        if (nomSommet != "" && valeurSommet != "") {
            sommets.push_back(new Sommet(nomSommet.at(0), valeurSommet.at(0)));
        }
    }

    // Lire la deuxieme ligne (Donnees des arcs)
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
//----------------------------------------------------------------------------------------------------------- lireGraphe
//----------------------------------------------------------------------------------------------------------------------
void lireGraphe(Graphe* graphe) {
    cout << "Graphe actuel: " << endl;
    graphe->afficher();
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------- extractionGraphe
//----------------------------------------------------------------------------------------------------------------------
Graphe* extractionGraphe(Graphe* graphe, int autonomieMax) {
    vector<Sommet*>  sommets;

    // Copie tous les sommets du graphe original
    for (auto sommet : graphe->getSommet()) {
        sommets.push_back(new Sommet(sommet));
    }

    for (auto sommet : graphe->getSommet()) {
        for (auto arc : sommet->getArcs()) {
            if (arc->getDistance() < autonomieMax) {

                // Trouve nouveau sommet correspondant
                for (auto debut : sommets) {
                    if (debut->getName() == sommet->getName()) {

                        // Trouve nouveaux sommet correspondant a la fin de l'arc
                        for (auto fin : sommets) {
                            if (fin->getName() == arc->getFin()->getName()) {
                                Arc *newArc = new Arc(fin, arc->getDistance());
                                sommet->addArc(newArc);
                            }
                        }
                    }
                }
            }
        }
    }

    return new Graphe(sommets);
} // extractionGraphe

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------ plusCourtChemin
//----------------------------------------------------------------------------------------------------------------------
int plusCourtChemin(Graphe* graphe, Sommet* depart, Sommet* fin, Vehicule* vehicule) {
    Chemin* retour = nullptr;
    bool aucunChemin = false;
    int autonomieRestante = vehicule->getAutonomieActuelle();

    //Creer un chemin contenant le point de depart.
    Chemin* parcourus = new Chemin(new Vehicule(vehicule));
    parcourus->addSommet(depart, 0);

    //Creer la liste de tous les chemins empruntes et y ajouter une copie du chemin initial (pour historique).
    vector<Chemin*> chemins;
    chemins.push_back(new Chemin(*parcourus));

    //Commencer la recherche jusqu'a trouver la destination
    while (!parcourus->contains(fin) && !aucunChemin) {
        //Un pointeur vers l'arc avec la distance minimale et un autre vers le chemin parcouru pour l'atteindre.
        Chemin* cheminActuel = nullptr;
        Arc* minimal = nullptr;

        //Trouver l'arc min a qui le sommet d'arrive n'est pas dans le chemin parcourus.
        for (auto chemin : chemins) { //Traverser tous les chemins parcourus jusqu'ici
            Sommet* sommet = chemin->getSommets().at(chemin->getSommets().size() - 1); //Prendre le dernier sommet du chemin

            for (auto arc : sommet->getArcs()) { //Trouver le minimum des arcs qui partent de sommet
                if (!parcourus->contains(arc->getFin()) && arc->getDistance() <= chemin->getVehicule()->getAutonomieActuelle()) {
                    if (minimal == nullptr) {
                        //initialiser minimal a un arc par le quel on n'est jamais passe
                        cheminActuel = chemin;
                        minimal = arc;
                    } else if (arc->getDistance() + chemin->getDistance() <
                               minimal->getDistance() + cheminActuel->getDistance()) {
                        cheminActuel = chemin;
                        minimal = arc;
                    }
                }
            }
        }

        //Ajouter le nouveau chemin dans le vecteur chemins.
        if (minimal != nullptr) {
            Chemin* newChemin = new Chemin((*cheminActuel));
            newChemin->addSommet(minimal->getFin(), minimal->getDistance());

            chemins.push_back(newChemin);
            retour = newChemin;

            //Ajouter le sommet d'arrive dans parcourus.
            parcourus->addSommet(minimal->getFin(), minimal->getDistance());
        } else {
            cout << "Aucun chemin trouve" << endl;
            aucunChemin = true;
        }
    }

    //Ici on est arrive a destination. Retourner le dernier chemin trouve s'il existe.
    if(!aucunChemin && retour != nullptr) {
        cout << *retour << endl;

        //Recuperer l'etat du vehicule a partir du bon chemin
        autonomieRestante = retour->getVehicule()->getAutonomieActuelle();
    }

    //Nettoyage
    for (Chemin* chemin : chemins)
        delete chemin;

    delete parcourus;

    return autonomieRestante;
}
