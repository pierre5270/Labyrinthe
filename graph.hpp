#pragma once
#include <iostream>
#include <map>
#include <utility>
#include "block.hpp"
#include <cassert>
#include <deque>
#include <set>

class graph {
    protected :
        map<int,block*> all_block ; // l'ensemble des cellules ID --> bloc
        map <pair<int,int>, edge*> road ; // Ensemble des chemins ou murs possibles
        
    public:
        graph(){}

        //Rôle : retourne un bloc présent dans notre labyrinthe
        virtual block *getBlock(int ID)  = 0;

        //Rôle : retourne le chemin entre 2 cellules
        virtual edge *getEdge(int sID,int dID) = 0  ;

        //Rôle : ajouter un chemin dans la liste des chemins
        virtual void addEdge(edge *e) = 0 ;

        //Rôle : ajouter un chemin dans la liste d'adjacence du bloc
        virtual void addAdjacentlist(edge *e) = 0 ;

        //Rôle : affiche l'ensemble des voisins d'un bloc de la grille
        virtual void adjacent_list(int ID) = 0 ;

        //Rôle : afficher le graph sur la sortie standard
        virtual string toString () = 0 ;

        //Rôle : met toute les tailles des edges à une certaine valeur
        virtual void set_all_vertex_to_max_value(double value) = 0;

        //Rôle : calcule la distance Euclidienne entre 2 points
        virtual double heuristic_distance_estimator(int id1_x,int id1_y, int id2_x,int id2_y) = 0;

        //Rôle : Détermine le chemin le plus court vers le résultat
        virtual void astar (int vstart, int vend) = 0 ;


} ;