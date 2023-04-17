#pragma once
#include "edge.hpp"
#include <cassert>
#include <vector>
using namespace std ;

class block{
    protected :
        int value ;
        bool visited ;
        vector<edge> neighboor ;

    public :

        block(){}
        
        block(int v ):value(v){
            visited = false ;
            neighboor = {} ;
            
        } 

        //Rôle : Cette fonction a pour but de retourner la valeur du bloc
        int getValue ()const ;

        //Rôle : Cette fonction attribue une valeur au bloc désigné
        void setValue(int v) ;

        //Rôle : Cette fonction retourne la liste des voisins du bloc
        vector<edge> getNeighboor()const ;

        //Rôle : Cette fonction ajoute un élément à la liste des voisins d'un bloc
        // à noter que :
        /*0 : côté Est
         *1 : côté Sud
         *2 : côté Ouest
         *3 : côté Nord
        */
        void setNeighboor(int n,int position) ;


        //Rôle : retourne true si la case a été visitée
        bool getVisited()const ;

        //Rôle : change la valeur de la case pour signaler qu'on l'a parcouru
        void setVisited() ;

        //Rôle : retourner sous forme de chaîne de caractères l'expression du block
        string toString() const ;

        // Rôle : édition de l'opérateur <<
        friend ostream &operator<<(ostream &f , block b){
            return f << b.toString() ;
        }

} ;