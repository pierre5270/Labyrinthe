#pragma once
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std ;

class edge{
    protected : 

        int source;
        int destination;
        int weight;
        bool free_road;
    
    public :

        edge() {}

        edge(int s ,int dest) :source(s),destination(dest){
            weight = 1;
            free_road = false;
        }

        int getSource()const ;

        int getDestination()const ;

        int getWeight()const ;

        bool isopen()const ;

        void setSource(int s) ;

        void setDestination(int d) ;

        void setWeight(int w) ;

        void open_wall() ;

        string toString() const ;

        friend ostream &operator<<(ostream &f , edge e){
            return f << e.toString() ;
        }

};