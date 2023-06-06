#pragma once
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std ;

class edge{
    protected : 

        int source;
        int destination;
        int length;
        bool free_road;
        
    
    public :

        edge() {}

        edge(int s ,int dest) :source(s),destination(dest){
            length = 1;
            free_road = false;
            
        }

        int getSource()const ;

        int getDestination()const ;

        int getLength()const ;

        bool isopen()const ;

        void setSource(int s) ;

        void setDestination(int d) ;

        void setLength(int w) ;

        void open_wall() ;

        string toString() const ;

        friend ostream &operator<<(ostream &f , edge e){
            return f << e.toString() ;
        }

};