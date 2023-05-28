#include "block.hpp"

int block::getValue() const {
    return value ;
}

int block::getID()const {
    return ID ;
}

bool block::getVisited()const {
    return visited ;
}

void block::setValue(int v){
    value = v ;
}

void block::setID(int i){
    ID = i ;
}

void block::setVisited() {
    visited = true ;
}

vector<edge*> block::getNeighboor() {
    return neighboor ;
}

vector<int> block::getChemin(){
    return chemin;
}

void block::setNeighboor(edge *e){
    neighboor.push_back(e) ;
}

void block::Setchemin(int block_id){
    chemin.push_back(block_id);
}

string block::toString()const {
    ostringstream ss ;
    ss << "block value = "<< to_string(getValue())<< endl ;
    ss << "neighboors : " ;
    for(edge *x : neighboor) ss << to_string(x->getDestination())<<", " ;

    return ss.str() ;
}
