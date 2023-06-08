#pragma once
#include <iostream>
#include "Modele.hpp"
#include "Vue.hpp"

class Controleur {
    private :
        Modele *m_;
        Vue *interface;

    public :

        Controleur(Modele *m,Vue *V) ;

        ~Controleur(){}

        //Rôle : Cette fonction permet de retourner l'interface graphique du jeu
        Vue *VueGraphique();

        //Cette fonction ouvre la fenêtre de départ comportant les informations à remplir
        void on_setting() ;

        //Cette fonction retourne si l'algorithme de fusion est choisi
        void on_fusion();

        //Cette fonction retourne si l'algorithme d'Aldous Bröder est choisi
        void on_aldous();

        //Cette fonction enclenche la partie à partir du button bBegin
        void on_game() ;

        //Cette fonction renvoie le chemin exact à parcourir pour arriver au résultat
        void solution() ;

        //Cette fonction retourne la grille de jeu en fonction des paramètres de taille entrés par l'utilisateur
        Gtk::Box* grid_mode(GridGame *g);

        //Cette fonction dessine la grille de jeu sur l'écran en tenant compte des paramètres de jeu du joueur
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

        //Gère les mouvements du clavier et renvoie le fenêtre de fin 
        bool on_key_press_event(GdkEventKey* event) ;

        //Gère les relachements de boutons du clavier
        bool on_key_release_event(GdkEventKey* event) ;
    };
