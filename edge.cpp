#include "edge.hpp"

int edge::getSource()const {
    return source ;
}

int edge::getDestination()const{
    return destination ;
}

int edge::getWeight()const{
    return weight ;
}

bool edge::isopen()const{
    return free_road ;
}

void edge::open_wall(){
   free_road = true;
}

void edge::setSource(int s){
    source = s ;
}

void edge ::setDestination(int d) {
    destination = d ;
}

void edge::setWeight(int w){
    weight = w ;
}

string edge:: toString() const{
    ostringstream ss ;

    ss << " source_value :"<<to_string(getSource()) << endl ;
    ss << "destination value :"<<to_string(getDestination())<< endl ;
    ss << "weight :"<<to_string(getWeight())<< endl ;
    ss << "wall :"<<to_string(isopen())<<endl ;
    return ss.str() ;
}