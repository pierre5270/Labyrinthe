#include "block.hpp"
#include <map>
#include <iomanip>

class labyrinthe: public block{

    private :
        int width ;
        int size ;
        block *grid ; // l'ensemble des cellules 
        bool *h_wall ; // mur horizontal
        bool *v_wall ; // mur vertical


    public :
        labyrinthe (int w): width(w),size(w*w){

            grid = new block[size] ;
            h_wall = new bool[size+w] ;
            v_wall = new bool[size+w] ;
            
            for(int i =0 ; i<size+w; i++){
                this->h_wall[i] = false ;
                this->v_wall[i] = false ;
                if (i<size) this->grid[i].setValue(rand()%size) ;
            }
        }

    //Rôle : initialise la matrice constituant notre labyrinthe
    void init_labyrinthe() ;

    //Rôle : retourne la valeur de la grille à l'indice indiquée
    int getGrid(int i, int j)const ;

    //Rôle : retourne le résultat à l'indice indiquée
    bool getH_wall(int i, int j) const ;

    //Rôle : retourne le résultat à l'indice indiquée
    bool getV_wall(int i, int j) const ;

    //Rôle : dessine un mur vertical
    string v_obstacle(bool b) const ;

    //Rôle : dessine un mur horizontal
    string h_obstacle(bool b) const ;

    //Rôle : dessine le labyrinthe sur la sortie standard
    string toString()const ;

    //Rôle : Opérateur écrivant sur la sortie standard
    friend ostream &operator<<(ostream &f, labyrinthe l){
        return f<<l.toString() ;
    }
} ;