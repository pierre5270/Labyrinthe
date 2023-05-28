#pragma once
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std ;

class character{
    protected :
        string name ;
        int position ;
    
    public :
        character(string n = "joueur"){};
    public :

        string getName()const ;

        int getPosition()const ;

        void setPosition(int p) ;

        void move(int order,int size) ;

        string toString()const ;

        friend ostream &operator<<(ostream &f, const character c ){
            return f<<c.toString() ;
        }
} ;