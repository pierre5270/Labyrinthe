#include "labyrinthe.hpp"


int labyrinthe::cord(int i,int j) const {
    assert((i>=0 && i<length) &&(j>=0 && j<width)) ;
    return width*i+j ;
}


void labyrinthe::fusion_labyrinth(){
    //écriture de l'algorithme
    //Initialisation des listes d'adjacences (adjacent_list)
}

void labyrinthe::aldous_broder_labyrinth(){
    //écriture de l'algorithme
    //Initialisation des listes d'adjacences   
}

