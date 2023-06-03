#pragma once
#include "edge.hpp"
#include <cassert>
#include <vector>
using namespace std ;

class block{
    protected :
        int x , y ;
        int ID ;
        int value ;
        bool visited ;
        int weight ;
        double estimate ;
        vector<edge*> neighboor ;
        vector<int> chemin ;

    public :

        block(){}

        block(int cord_x,int cord_y,int v):x(cord_x),y(cord_y){
            ID = v;
            value = ID;
            weight = 0;
            visited = false ;
            neighboor = {} ;
            chemin.push_back(v) ;
            estimate = 0.0 ;
            
        } 
        //Rôle : retourne l'abscisse du point
        int getX()const;

        //Rôle : retourne l'ordonnée du point
        int getY()const;

        //Rôle : Cette fonction a pour but de retourner la valeur du bloc
        int getValue ()const ;

        //Rôle : identinfiant du bloc
        int getID()const ;

        //Rôle : retourne true si la case a été visitée
        bool getVisited()const ;

        //Rôle : retourne le poids du chemin parcouru
        int getWeight()const ;

        //Rôle :retourne le trajet constituant le bloc
        vector<int> getChemin() ;

        //Rôle : Cette fonction retourne la liste des voisins du bloc
        vector<edge*> getNeighboor() ;

        //Rôle : retourne la valeur du paramètre estimé
        double getEstimate()const ;


        //Rôle : Cette fonction attribue une valeur au bloc désigné
        void setValue(int v) ;

        //Rôle : Modifier l'identifiant du bloc
        void setID(int i) ;

        //Rôle : change la valeur de la case pour signaler qu'on l'a parcouru
        void setVisited() ;



        //Rôle : Cette fonction ajoute un élément à la liste des voisins d'un bloc
        // à noter que :
        /*0 : côté Est
         *1 : côté Sud
         *2 : côté Ouest
         *3 : côté Nord
        */
        void setNeighboor(edge *e) ;

        //Rôle : permet d'ajouter un bloc dans la liste des chemins
        void Setchemin(int c) ;

        //Rôle : modifie la valeur du poids d'un chemin
        void SetWeight(int x) ;

        //Rôle : modifie la valeur de paramètre estimé
        void SetEstimate(double x) ;

        //Rôle : retourner sous forme de chaîne de caractères l'expression du block
        string toString() const ;

        // Rôle : édition de l'opérateur <<
        friend ostream &operator<<(ostream &f , block b){
            return f << b.toString() ;
        }



} ;