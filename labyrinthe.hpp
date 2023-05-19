#pragma once
#include "graph.hpp"
#include "character.hpp"
#include <iomanip>
#include <random>
#include <numeric>

class labyrinthe: public graph{

    private :

        int length,width ; // M, N
        int size ;


    public :

        labyrinthe(){}

        labyrinthe (int l,int w):length(l), width(w),size(w*l){

            //Initialisation des blocs
            for(int i =0 ; i< l ;i++){
                for(int j = 0 ; j<w ;j++){
                    all_block[cord(i,j)] = new block(cord(i,j),cord(i,j)) ;

                   if (i==0){
                    if(j==0){

                        addEdge(edge(0,cord(i,j+1))) ;
                        addEdge(edge(0,cord(i+1,j))) ;

                    } else if(j>0 && j<width-1){    

                        addEdge(edge(cord(i,j),cord(i,j+1))) ;
                        addEdge(edge(cord(i,j),cord(i+1,j))) ;
                        addEdge(edge(cord(i,j),cord(i,j-1))) ;
                    }
                    else{
                        
                        addEdge(edge(width-1,cord(i+1,j))) ; 
                        addEdge(edge(width-1,cord(i,j-1))) ;
                    }
                     
                   }else if (i>0 && i<length -1){
                    if(j==0){
                        
                        addEdge(edge(cord(i,j),cord(i,j+1))) ;
                        addEdge(edge(cord(i,j),cord(i-1,j))) ;
                        addEdge(edge(cord(i,j),cord(i+1,j))) ;

                    }else if(j>0 && j<width-1){
                        
                        addEdge(edge(cord(i,j),cord(i,j+1))) ;
                        addEdge(edge(cord(i,j),cord(i+1,j))) ;
                        addEdge(edge(cord(i,j),cord(i,j-1))) ;
                        addEdge(edge(cord(i,j),cord(i-1,j))) ;
                    
                    }
                    else{
                        
                        addEdge(edge(cord(i,j),cord(i-1,j))) ;
                        addEdge(edge(cord(i,j),cord(i,j-1))) ;
                        addEdge(edge(cord(i,j),cord(i+1,j)));                        
                    }
                   }
                   else{
                    if(j==0){
      
                        addEdge(edge(cord(i,j),cord(i,j+1)));  
                        addEdge(edge(cord(i,j),cord(i-1,j)));   

                    } else if (j>0 && j<width-1){ 

                        addEdge(edge(cord(i,j),cord(i-1,j)));
                        addEdge(edge(cord(i,j),cord(i,j-1))) ; 
                        addEdge(edge(cord(i,j),cord(i,j+1))) ;   

                    } else{
                        addEdge(edge(cord(i,j),cord(i-1,j))) ;
                        addEdge(edge(cord(i,j),cord(width-1,j-1))) ;                        
                    }
                   }
                   
                }
            }
            


        }
         
        //Rôle : retourne l'indice de la cellule
        int cord (int i,int j) const ;

        //Rôle : retourne un bloc présent dans notre labyrinthe
        virtual block *getBlock(int ID) override {
            return all_block[ID] ;
        }

        //Rôle : retourne le chemin entre 2 cellules
        virtual edge getEdge(int sID,int dID) override{
            return road[pair(sID,dID)] ;
        }

        virtual void addEdge(edge e) override {
            road.emplace(pair(e.getSource(),e.getDestination()),e) ;
            addAdjacentlist(e) ;
        }

        virtual void addAdjacentlist(edge e) override {
            block *b = getBlock(e.getSource()) ;
            b ->setNeighboor(e) ;
        }    

        //Rôle : affiche l'ensemble des voisins d'un bloc de la grille
        virtual void adjacent_list(int ID) override {
            block* b = getBlock(ID) ;
            cout << "some ways :"<<endl ;
            for ( edge e : b->getNeighboor())
                if(e.isopen()) cout << e ;
        
        }

        //Rôle : fusionner 2 cellules
        void merge(int first_ID,int second_ID) ;

        //Rôle : retourne si labyrinthe est achevé donc si les blocs ont tous la même valeur
        bool is_ready() ;

        //Rôle : nombre de cases visitées
        int nb_opened() ;

        //Rôle : retourne la liste des edges de la grille
        vector<pair<int,int>> Edgelist() const ;

        //Rôle : retourne la liste des blocs de la grille
        vector<int> Blocklist() const ;

        //Rôle : créer une liste de d'identifiants adjacent à un bloc
        vector<int> adjacent_list_ID(int ID) ;

        //Rôle : génère le labyrinthe à partir de l'algorithme de fusion
        void fusion_labyrinth() ;

        //Rôle : génère le labyrinthe à partir de l'algorithme d'Aldous-Broder
        void aldous_broder_labyrinth() ;

        //Rôle : dessine le labyrinthe sur la sortie standard
        virtual string toString() override {
            ostringstream ss;
            ss << "Labyrinthe :" << endl;

            for (int i = 0; i < length; i++){
                for (int j = 0; j < width; j++){ 
                    ss << setw(2) << graph::all_block[cord(i,j)]->getValue()<< " " ;
                }
                ss << endl ;
            }
            
            return ss.str();
        }

        //Rôle : Opérateur écrivant sur la sortie standard
        friend ostream &operator<<(ostream &f, labyrinthe l){
            return f<<l.toString() ;
        }
        
};