#pragma once
#include "edge.hpp"
#include <cassert>
#include <vector>
using namespace std ;

class block{
    protected :
        int ID ;
        int value ;
        bool visited ;
        vector<edge> neighboor ;

    public :

        block(){}

        block(int v ,int i):value(v){
            ID = i ;
            visited = false ;
            neighboor = {} ;
            
        } 

        //Rôle : Cette fonction a pour but de retourner la valeur du bloc
        int getValue ()const ;

        //Rôle : identinfiant du bloc
        int getID()const ;

        //Rôle : retourne true si la case a été visitée
        bool getVisited()const ;

        //Rôle : Cette fonction attribue une valeur au bloc désigné
        void setValue(int v) ;

        //Rôle : Modifier l'identifiant du bloc
        void setID(int i) ;

        //Rôle : change la valeur de la case pour signaler qu'on l'a parcouru
        void setVisited() ;

        //Rôle : Cette fonction retourne la liste des voisins du bloc
        vector<edge> getNeighboor()const ;

        //Rôle : Cette fonction ajoute un élément à la liste des voisins d'un bloc
        // à noter que :
        /*0 : côté Est
         *1 : côté Sud
         *2 : côté Ouest
         *3 : côté Nord
        */
        void setNeighboor(edge e) ;

        //Rôle : retourner sous forme de chaîne de caractères l'expression du block
        string toString() const ;

        // Rôle : édition de l'opérateur <<
        friend ostream &operator<<(ostream &f , block b){
            return f << b.toString() ;
        }



} ;