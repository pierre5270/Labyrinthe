#include "character.hpp"

string character::getName()const{
    return name ;
}

int character::getPosition()const{
    return position ;
}

void character::setPosition(int p){
    position = p ;
}

void character::move(int order,int width){
    assert(order>=0 && order<4) ;

    if(order==0 && position+1<width*width) setPosition(position++ );
    if(order==1 && position+width<width*width) setPosition(position+width) ;
    if(order==2 && position-1>=0) setPosition(position--) ;
    if(order==3 && position-width>=0) setPosition(position-width ) ;
}

string character::toString()const{
    ostringstream ss ;

    ss<< "the character :"<<getName()<<endl ;
    ss<< " his position :"<<getPosition()<<endl ;

    return ss.str() ;
}