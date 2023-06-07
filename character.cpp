#include "character.hpp"

int character::getPosition_X()const{
    return position_X ;
}

int character::getPosition_Y()const{
    return position_Y ;
}

void character::setPosition_X(int p){
    position_X = p ;
}

void character::setPosition_Y(int p){
    position_Y = p ;
}



string character::toString()const{

    ostringstream ss ;
    ss<< " his position :"<<"X = "<<getPosition_X()<<", Y = "<<getPosition_Y()<<endl ;

    return ss.str() ;
}