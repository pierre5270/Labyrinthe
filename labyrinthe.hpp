#include "graph.hpp"
#include "character.hpp"
#include <iomanip>

class labyrinthe: public graph{

    private :

        int length,width ; // M, N
        int size ;


    public :
        labyrinthe (int l,int w):length(l), width(w),size(w*l){

            //Initialisation des blocs
            for(int i =0 ; i< l ;i++){
                for(int j = 0 ; j<w ;j++){
                    all_block[cord(i,j)] = new block(rand()%size,cord(i,j)) ;

                   if (i==0){
                    if(j==0){
                        road.emplace(pair(0,cord(i,j+1)),edge(0,cord(i,j+1))) ;
                        road.emplace(pair(0, cord(i+1,j)),edge(0,cord(i+1,j))) ;
                    } else if(j>0 && j<width-1){
                        road.emplace(pair(cord(i,j),cord(i,j+1)),edge(cord(i,j),cord(i,j+1))) ;
                        road.emplace(pair(cord(i,j), cord(i+1,j)),edge(cord(i,j),cord(i+1,j))); 
                        road.emplace(pair(cord(i,j),cord(i,j-1)),edge(cord(i,j),cord(i,j-1))) ;
                    }
                    else{
                        road.emplace(pair(width-1,cord(i+1,j)),edge(width-1,cord(i+1,j))) ;
                        road.emplace(pair(width-1, cord(i,j-1)),edge(width-1,cord(i,j-1))) ;                        
                    }
                     
                   }else if (i>0 && i<length -1){
                    if(j==0){
                        road.emplace(pair(cord(i,j),cord(i,j+1)),edge(cord(i,j),cord(i,j+1)));
                        road.emplace(pair(cord(i,j), cord(i-1,j)),edge(cord(i,j),cord(i-1,j)));
                        road.emplace(pair(cord(i,j), cord(i+1,j)),edge(cord(i,j),cord(i+1,j)));                        
                    }else if(j>0 && j<width-1){
                        road.emplace(pair(cord(i,j),cord(i,j+1)),edge(cord(i,j),cord(i,j+1))) ;
                        road.emplace(pair(cord(i,j), cord(i+1,j)),edge(cord(i,j),cord(i+1,j))) ; 
                        road.emplace(pair(cord(i,j),cord(i,j-1)),edge(cord(i,j),cord(i,j-1))) ;
                        road.emplace(pair(cord(i,j),cord(i-1,j)),edge(cord(i,j),cord(i-1,j))) ;                        
                    }
                    else{
                        road.emplace(pair(cord(i,j),cord(i-1,j)),edge(cord(i,j),cord(i-1,j))) ;
                        road.emplace(pair(cord(i,j), cord(i,j-1)),edge(cord(i,j),cord(i,j-1))) ;
                        road.emplace(pair(cord(i,j),cord(i+1,j)),edge(cord(i,j),cord(i+1,j))) ;                        
                    }
                   }
                   else{
                    if(j==0){
                        road.emplace(pair(cord(i,j),cord(i,j+1)),edge(cord(i,j),cord(i,j+1))) ;
                        road.emplace(pair(cord(i,j), cord(i-1,j)),edge(cord(i,j),cord(i-1,j))) ;                       
                    } else if (j>0 && j<width-1){
                        road.emplace(pair(cord(i,j), cord(i-1,j)),edge(cord(i,j),cord(i-1,j))) ;
                        road.emplace(pair(cord(i,j), cord(i,j-1)),edge(cord(i,j),cord(i,j-1))) ;
                        road.emplace(pair(cord(i,j),cord(i,j+1)),edge(cord(i,j),cord(i,j+1))) ;                    
                    } else{
                        road.emplace(pair(cord(i,j), cord(i-1,j)),edge(cord(i,j),cord(i-1,j))) ;
                        road.emplace(pair(width-1, cord(i,j-1)),edge(width-1,cord(i,j-1))) ;                        
                    }
                   }

                }
            }
        }
            

    //Rôle : initialise la matrice constituant notre labyrinthe en un état initial
    void init_labyrinthe() ;

    //Rôle : retourne l'indice de la cellule
    int cord (int i,int j) const ;


    //Rôle : retourne la valeur de la grille à l'indice indiquée
    virtual int getGrid(int i, int j)const override ;

    //Rôle : retourne un bloc présent dans notre labyrinthe
    virtual block *getBlock() const override ;

    //Rôle : retourne le chemin entre 2 cellules
   virtual edge getEdge()const override ;

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
};