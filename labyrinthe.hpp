#pragma once
#include "graph.hpp"
#include "character.hpp"
#include <iomanip>
#include <algorithm>

class labyrinthe: public graph{

    private :

        int length,width ; // M, N
        int size ;


    public :

        labyrinthe(){}

        labyrinthe(int l,int w)  ;

        //Rôle : retourne un bloc présent dans notre labyrinthe
        virtual block *getBlock(int ID) override {
            return all_block[ID] ;
        }

        //Rôle : retourne le chemin entre 2 cellules
        virtual edge *getEdge(int sID,int dID) override{
            return road[pair(sID,dID)] ;
        }

        virtual vector<int> getTrajet() override {
            vector<int> t;
            for (auto it = Chemins.begin();it!=Chemins.end();it++){
                t.push_back(it->first) ;
            }
            return t ;
        }

        virtual void addEdge(edge *e) override {
            road.emplace(pair(e->getSource(),e->getDestination()),e) ;
            addAdjacentlist(e) ;
        }

        virtual void addAdjacentlist(edge *e) override {
            block *b = getBlock(e->getSource()) ;
            b ->setNeighboor(e) ;
        }    

        //Rôle : affiche l'ensemble des voisins d'un bloc de la grille
        virtual void adjacent_list(int ID) override {
            block* b = getBlock(ID) ;
            cout << "some ways :"<<endl ;
            for ( edge *e : b->getNeighboor())
                if(e->isopen()) cout << e ;
        
        }

        //Rôle: ajoute un point dans la map de chemin
        virtual void SetTrajet(int x_p,int x_c) override {
            assert(x_p!=x_c);
            Chemins[x_p] = x_c ;
        }

        //Rôle : dessine le labyrinthe sur la sortie standard
        virtual string toString() override {
            ostringstream ss;
            
            for (int i = 0; i < length; i++){
                for (int j = 0; j < width; j++){ 
                    ss << setw(2) << graph::all_block[cord(i,j)]->getValue()<< " " ;
                }
                ss << endl ;
            }
            
            return ss.str();
        }

        //Rôle : retourne l'indice de la cellule
        int cord (int i,int j) const ;

        //Rôle : fusionner 2 cellules
        void fusion(int first_ID,int second_ID) ;

        //Rôle : retourne si labyrinthe est achevé donc si les blocs ont tous la même valeur
        bool is_ready() ;

        //Rôle : nombre de murs ouverts
        int nbwall_opened() ;

        //Rôle : retourne le nombre de murs du labyrinthe
        int nbwall() const;

        //Rôle : retourne la liste des edges de la grille
        vector<pair<int,int>> Edgelist() const;

        //Rôle : retourne la liste des blocs de la grille
        vector<block*> Blocklist() ;

        //Rôle : créer une liste de d'identifiants adjacent à un bloc
        vector<int> adjacent_list_ID(int ID) ;

        //Rôle : Renvoie la liste des cases différentes de celle désignée
        vector<block*> BlockDiff(int ID) ;

        //Rôle : renvoie la matrice des murs verticaux du labyrinthe
        void print_V_wall();

        //Rôle : renvoie la matrice des murs horizontaux du labyrinthe
        void print_H_wall();

        //Rôle : renvoie le nombre de block visité
        int nbVisited();

        //Rôle : génère le labyrinthe à partir de l'algorithme de fusion
        void fusion_labyrinth() ;

        //Rôle : génère le labyrinthe à partir de l'algorithme d'Aldous-Broder
        void aldous_broder_labyrinth() ;

        //Rôle : Opérateur écrivant sur la sortie standard
        friend ostream &operator<<(ostream &f, labyrinthe l){
            return f<<l.toString() ;
        }
        
};