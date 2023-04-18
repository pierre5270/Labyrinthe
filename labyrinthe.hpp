#include "block.hpp"
#include "character.hpp"
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
            
        }

    //Rôle : initialise la matrice constituant notre labyrinthe en un état initial
    void init_labyrinthe() ;

    //Rôle : retourne la valeur de la grille à l'indice indiquée
    int getGrid(int i, int j)const ;

    //Rôle : retourne le résultat à l'indice indiquée
    bool getH_wall(int i, int j) const ;

    //Rôle : retourne le résultat à l'indice indiquée
    bool getV_wall(int i, int j) const ;

    template<typename T>
    void draw_check_box(ostringstream &ss,T* box) const {

        for (int i = 0; i < width; i++){
            for (int j = 0; j < width; j++){
                ss << setw(2) << to_string(box[width*j+i]) << " ";
        }
        ss << endl ;
        }
    }

    //Rôle : intialise toutes les matrices d'adjacences de tous
    //les points de la grille
    void adjacent_list() ;
    //Rôle : génère le labyrinthe à partir de l'algorithme de fusion
    void fusion_labyrinth() ;

    //Rôle : génère le labyrinthe à partir de l'algorithme d'Aldous-Broder
    void aldous_broder_labyrinth() ;

    //Rôle : dessine le labyrinthe sur la sortie standard
    string toString()const ;

    //Rôle : Opérateur écrivant sur la sortie standard
    friend ostream &operator<<(ostream &f, labyrinthe l){
        return f<<l.toString() ;
    }
} ;