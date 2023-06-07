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

    //Constructeur
        character(){
            //Initialisation de la position du joueur
            this->setPosition_X(0);
            this->setPosition_Y(0);
        }
        
        int getPosition_X()const ;

        int getPosition_Y()const ;

        void setPosition_X(int p) ;

        void setPosition_Y(int p) ;

        string toString()const ;

        friend ostream &operator<<(ostream &f, const character c ){
            return f<<c.toString() ;
        }
} ;