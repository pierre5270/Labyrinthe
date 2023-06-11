#pragma once
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std ;

class character{
    protected :

        int position_X ;
        int position_Y ;

    public :

        // Rôle : Constructeur qui initialise les membres de la classe "character" par des valeurs par défaut
        character(){
            this->setPosition_X(0);              // initialisation de l'abscisse de la position du joueur à 0
            this->setPosition_Y(0);              // initialisation de l'ordonnée de la position du joueur à 0
        }

        // Rôle : Accéder à la valeur de la coordonnée abscisse de la position du joueur depuis l'extérieur de l'objet sans permettre les modifications
        int getPosition_X()const{
            return position_X ;
        }
        // Rôle : Accéder à la valeur de la coordonnée ordonnée de la position du joueur depuis l'extérieur de l'objet sans permettre les modifications
        int getPosition_Y()const{
            return position_Y ;
        }

        // Rôle : Modifier la valeur de la coordonnée abscisse de la position du joueur en lui attribuant une nouvelle valeur fournie en paramètre p
        void setPosition_X(int p){
            position_X = p ;
        }

        // Rôle : Modifier la valeur de la coordonnée orodonnée de la position du joueur en lui attribuant une nouvelle valeur fournie en paramètre p
        void setPosition_Y(int p){
            position_Y = p ;
        }

        // Rôle : Obtenir une chaîne de caractères qui représente les valeurs des membres de la classe character
        // coordonnées (x,y) du joueur
        string toString()const{
            ostringstream ss ;
            ss << " his position :"<<"X = "<<getPosition_X()<<", Y = "<<getPosition_Y()<<endl ;
            return ss.str() ;
        }

        // Rôle : Afficher un objet de la classe character dans un flux de sortie en utilisant son opérateur de flux de sortie surchargé
        friend ostream &operator<<(ostream &f, const character c ){
            return f<<c.toString() ;
        }
};
