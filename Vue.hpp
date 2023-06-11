#pragma once
#include "GameState.hpp"
#include "GridGame.hpp"
#include <iostream>
#include <string>

#define X_RESULT 300
#define Y_RESULT 125

using namespace std ;

class Vue : public Gtk::Window {                                        // La classe Vue hérite de la classe Gtk::Window. Vue est une fenêtre GTK.

    public :
        Gtk::Box box ;                                                  // Déclaration box pour désigner les affiches de notre programme
        Gtk::Button *button;                                            // Déclaration d'un pointeur qui permet de désigner les boutons de notre programme
        Gtk::ToggleButton *Algo;                                        // Déclaration d'un pointeur qui permet de désigner le bouton de sélection de l'algorithme
        Gtk::Entry *entry;                                              // Déclaration d'un pointeur qui permet de désigner les barres d'entrées d'informations
        Gamestate G_info ;                                              // Déclaration d'un objet Gamestate qui traduit l'état du jeu
        GridGame *grid;                                                 // Déclaration d'un objet GridGame qui donne la grille du jeu

    public :
        // Rôle : Constructeur qui initialise les membres de la classe "Vue" par des valeurs par défaut
        Vue() : box(Gtk::ORIENTATION_VERTICAL), button(new Gtk::Button[2]),Algo(new Gtk::ToggleButton[2]), entry(new Gtk::Entry[3]){
                                                                        // Initialisation de la fenêtre GTK avec une orientation vertical, un tableau contenant deux boutons,
                                                                        // un tableau contenant le bouton pour lancer l'algorithme de fusion et l'autre l'algorithme d'Aldous-Broder,
                                                                        // d'un tableau pour afficher trois barres d'informations
            G_info = Gamestate();                                       // Initialisation de l'état du jeu
            grid = new GridGame();                                      // Initialisation de la grille de jeu
            this->set_title("Bienvenue dans le jeu du labyrinthe !!");  // Initialisation du titre de la fenêtre
            this->set_border_width(5);                                  // Marge de 5 pixels entre le contenu de la fenêtre et ses bords
        }

        // Rôle : Destructeur qui est appelé pour fermer la fenêtre en appelant la fonction close()
        ~Vue(){ this->close();}
};
