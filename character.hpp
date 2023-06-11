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

        // R�le : Constructeur qui initialise les membres de la classe "character" par des valeurs par d�faut
        character(){
            this->setPosition_X(0);              // initialisation de l'abscisse de la position du joueur � 0
            this->setPosition_Y(0);              // initialisation de l'ordonn�e de la position du joueur � 0
        }

        // R�le : Acc�der � la valeur de la coordonn�e abscisse de la position du joueur depuis l'ext�rieur de l'objet sans permettre les modifications
        int getPosition_X()const{
            return position_X ;
        }
        // R�le : Acc�der � la valeur de la coordonn�e ordonn�e de la position du joueur depuis l'ext�rieur de l'objet sans permettre les modifications
        int getPosition_Y()const{
            return position_Y ;
        }

        // R�le : Modifier la valeur de la coordonn�e abscisse de la position du joueur en lui attribuant une nouvelle valeur fournie en param�tre p
        void setPosition_X(int p){
            position_X = p ;
        }

        // R�le : Modifier la valeur de la coordonn�e orodonn�e de la position du joueur en lui attribuant une nouvelle valeur fournie en param�tre p
        void setPosition_Y(int p){
            position_Y = p ;
        }

        // R�le : Obtenir une cha�ne de caract�res qui repr�sente les valeurs des membres de la classe character
        // coordonn�es (x,y) du joueur
        string toString()const{
            ostringstream ss ;
            ss << " his position :"<<"X = "<<getPosition_X()<<", Y = "<<getPosition_Y()<<endl ;
            return ss.str() ;
        }

        // R�le : Afficher un objet de la classe character dans un flux de sortie en utilisant son op�rateur de flux de sortie surcharg�
        friend ostream &operator<<(ostream &f, const character c ){
            return f<<c.toString() ;
        }
};
