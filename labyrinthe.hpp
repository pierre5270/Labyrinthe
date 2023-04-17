#include "block.hpp"
#include <map>


class labyrinthe: public block{

    private :
        int width ;
        int size ;
        block *grid ; // l'ensemble des cellules 
        bool *h_wall ; // mur horizontal
        bool *t_wall ; // mur vertical


    public :
        labyrinthe (int w): width(w),size(w*w){

            grid = new block[size] ;
            h_wall = new bool[size] ;
            t_wall = new bool[size] ;
            for(int i =0 ; i<size; i++){
                this->grid[i].setValue(rand()%size) ;
                this->h_wall[i] = false ;
                this->t_wall[i] = false ;
            }
        }

    //Rôle : initialise la matrice constituant notre labyrinthe
    void init_labyrinthe() ;

} ;