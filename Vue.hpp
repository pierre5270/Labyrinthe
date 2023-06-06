#pragma once
#include "gtkmm-3.0/gtkmm.h"
#include "GameState.hpp"
#include "GridGame.hpp"
#include <iostream>
#include <string>

#define X_DEFAUT_SIZE 200
#define Y_DEFAUT_SIZE 200

#define X_RESULT 200
#define Y_RESULT 100

using namespace std ;

class Vue : public Gtk::Window {

    private :
        Gtk::Box box ; // Différentes affiches de notre programme
        Gtk::Button *button; // Différents boutons de notre programme
        Gtk::ToggleButton *Algo; // Toggle bouton de sélection de l'algorithme
        Gtk::Label *label; // Les différents labels retrouvés
        Gtk::Entry *entry; // Les différentes barres d'entrées des informations
        Gamestate G_info ;

    public :
        Vue(int);

        ~Vue(){ this->close();}

        //Cette fonction enclenche la partie à partir du button bBegin
        void on_game() ;

        //Cette fonction retourne si l'algorithme de fusion est choisi
        void on_fusion() ;

        //Cette fonction retourne si l'algorithme d'Aldous Bröder est choisi
        void on_aldous() ;

        //Cette fonction retourne la grille de jeu en fonction des paramètres de taille entrés par l'utilisateur
        Gtk::Box* grid_mode(int l, int w,bool m);

        //Trace le chemin solution du labyrinthe
        void solution();

        //Cette fonction retourne le bloc de fin du programme
        Gtk::Box* end_mode();

};