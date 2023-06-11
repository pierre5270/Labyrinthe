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
        map<int,block*> all_block ;             // ensemble des blocs identifi�s par leurs IDs
        map <pair<int,int>, way*> road ;        // ensemble des chemins possibles

    public:

        // R�le : constructeur
        graph(){}

        //R�le : Acc�der au pointeur vers le bloc correspondant � l'identifiant sp�cifi� en param�tre d'entr�e ID
        virtual block *getBlock(int ID)  = 0;

        //R�le : Acc�der au pointeur vers le chemin entre deux blocs sp�cifi�s en param�tre d'entr�e par leurs identifiants source (sID) et destination (dID)
        virtual way *getWay(int sID,int dID) = 0  ;

        // R�le : Modifier la liste des chemins du labyrinthe en ajoutant la valeur du chemin du bloc dont la valeur est fournie en param�tre e
        virtual void addWay(way *e) = 0 ;

        // R�le : Modifier la liste des chemins adjacents au bloc en ajoutant la valeur du chemin du bloc dont la valeur est fournie en param�tre e
        virtual void addAdjacentlist(way *e) = 0 ;

        // R�le : Obtenir une cha�ne de caract�res qui repr�sente les valeurs des membres de la classe graph
        virtual string toString () = 0 ;

        //R�le : Modifie toutes les tailles des chemins des blocs pour les initialiser � la valeur value donn�e en param�tre d'entr�e
        virtual void set_all_vertex_to_max_value(double value) = 0;

        //R�le : Calcule la distance Euclidienne entre deux points de coordonn�es (x,y) diff�rentes
        virtual double heuristic_distance_estimator(int id1_x,int id1_y, int id2_x,int id2_y) = 0;

        //R�le : D�termine le chemin le plus court entre la source et la destination en fonction des murs ouverts et ferm�s
        virtual deque<int> astar(int vstart, int vend) = 0 ;
} ;
