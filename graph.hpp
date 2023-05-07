#include <iostream>
#include <map>
#include "block.hpp"
#include <cassert>

class graph {
    protected :
        map<int,block*> all_block ; // l'ensemble des cellules ID --> bloc
        map <pair<int,int>, edge> road ; // Ensemble des chemins ou murs possibles
    public:
        graph(){}

        //Rôle : retourne la valeur de la grille à l'indice indiquée
        virtual int getGrid(int i, int j)const = 0;

        //Rôle : retourne un bloc présent dans notre labyrinthe
        virtual block *getBlock() const = 0;

        //Rôle : retourne le chemin entre 2 cellules
        virtual edge getEdge()const = 0  ;

        //Rôle : intialise toutes les matrices d'adjacences de tous les points de la grille
        virtual void adjacent_list() = 0 ;
} ;