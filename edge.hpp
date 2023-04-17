#pragma once
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std ;

class edge{
    protected : 

        int source ;
        int destination ;
        int weight ;
    
    public :

        edge(int s , int dest , int w = 1) :source(s),destination(dest),weight(w){}

        int getSource()const ;

        int getDestination()const ;

        int getWeight()const ;

        void setSource(int s) ;

        void setDestination(int d) ;

        void setWeight(int w) ;

        string toString() const ;

        friend ostream &operator<<(ostream &f , edge e){
            return f << e.toString() ;
        }

} ;