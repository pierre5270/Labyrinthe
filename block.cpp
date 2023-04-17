#include "block.hpp"

int block::getValue() const {
    return value ;
}

void block::setValue(int v){
    value = v ;
}

vector<int> block::getNeighboor()const {
    return neighboor ;
}

void block::setNeighboor(int n,int position){
    assert(position>=0 && position<4) ;
    neighboor[position] = n ;
}

string block::toString()const {
    ostringstream ss ;
    ss << "block value = "<< to_string(getValue())<< endl ;
    ss << "neighboors : " ;
    for(int x : neighboor) ss << to_string(x)<<", " ;

    return ss.str() ;
}
