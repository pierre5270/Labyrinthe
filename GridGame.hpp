#pragma once
#include "labyrinthe.hpp"
#include "character.hpp"
#include <cmath>
#include <gtkmm-3.0/gtkmm.h>

#define X_GRID 600
#define Y_GRID 500


class GridGame : public Gtk::DrawingArea{   // GridGame h�rite de la classe Gtk::DrawingArea. GridGame, zone de dessin GTK, affiche des graphiques dans l'interface utilisateur.
    private:

        GdkEventKey *Key_;                  // D�claration d'un pointeur vers un objet GdkEventKey utilis� pour stocker les �v�nements clavier re�us par la grille de jeu

    public :

        // R�le : Constructeur qui initialise la classe "GridGame" par une taille par d�faut d�termin� � partir des param�tres X_GRID et Y_GRID
        GridGame(){
            this->set_size_request(X_GRID, Y_GRID);
        }

        // R�le : Acc�der � l'�v�nement clavier depuis depuis l'ext�rieur de l'objet sans permettre les modifications
        GdkEventKey *get_key(){
            return Key_ ;
        }

        // R�le : Modifier la valeur de l'�v�nement clavier de l'interface graphique en lui attribuant un nouvel �v�nement fournie en param�tre *Key
        void set_key(GdkEventKey *Key){
            this->Key_ = Key ;
        }
};
