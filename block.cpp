#include "block.hpp"

int block::getValue() const {
    return value ;
}

void block::setValue(int v){
    value = v ;
}

vector<edge> block::getNeighboor()const {
    return neighboor ;
}

void block::setNeighboor(int n,int position=0){
    assert(position>=0 && position<4) ;
    //neighboor[position] = edge(this->getValue(),n) ;
    neighboor.push_back(edge(this->getValue(),n)) ;
}

string block::toString()const {
    ostringstream ss ;
    ss << "block value = "<< to_string(getValue())<< endl ;
    ss << "neighboors : " ;
    for(edge x : neighboor) ss << to_string(x.getDestination())<<", " ;

    return ss.str() ;
}
