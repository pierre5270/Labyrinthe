#pragma once
#include "graph.hpp"
#include "character.hpp"
#include <iomanip>
#include <algorithm>
#include <cmath>

class labyrinthe: public graph{

    private :

        int length,width ; // M, N
        int size ;


    public :

        labyrinthe(){}

        labyrinthe(int l,int w)  ;

        //Rôle : retourne la longueur du labyrinthe
        int getLength() const ;

        //Rôle : retourne la largeur du labyrinthe
        int getWidth() const ;

        //Rôle : retourne la size du tableau
        int getSize()const ;

        //Rôle : entrer la longueur du labyrinthe
        void setLength(int l) ;

        //Rôle : entrer la largeur du labyrinthe
        void setWidth(int w) ;

        //Rôle : retourne un bloc présent dans notre labyrinthe
        virtual block *getBlock(int ID) override {
            return all_block[ID] ;
        }

        //Rôle : retourne le chemin entre 2 cellules
        virtual edge *getEdge(int sID,int dID) override{
            return road[pair(sID,dID)] ;
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

        virtual void set_all_vertex_to_max_value(double value) override {
            for(map < int,block* >::iterator it = all_block.begin(); it!=all_block.end(); it++){
                it->second->SetWeight(0.0) ;
            }
        }

        virtual double heuristic_distance_estimator(int id1_x,int id1_y, int id2_x,int id2_y) override {
            return sqrt(pow((id1_x-id2_x),2)+pow((id1_y-id2_y),2)) ;
        }


        // astar algorithm 
        virtual void astar (int bstart, int bend) override {
 
            deque <int> active_queue ;
            set<int> closed_set ;
            map<int,int> parent ;
            deque <int> path ;
            ostringstream end_result;
            int path_counter ;
            set_all_vertex_to_max_value(numeric_limits<double>::max()) ;
            
            //ID of the start vertex
            active_queue.push_back(bstart) ;

            // Set start vertex weight to 0
            getBlock(bstart)->SetWeight(0.00);
            
            do{

                // from the current vertex in the front of the queue
                // compute all vertices reachable in 1 step
                auto bcurrent = active_queue.front();
                active_queue.pop_front() ;

                if(bcurrent==bend) break ;

                closed_set.insert(bcurrent) ;
                //cout << "ok"<<endl;
                for(edge *e : getBlock(bcurrent)->getNeighboor()){
                
                    int bnext = e->getDestination() ;
                    if (getEdge(bcurrent,bnext)->isopen()){
                        if(closed_set.find(bnext) != closed_set.end()) continue ; 

                        auto w = getBlock(bcurrent)->getWeight() + getEdge(bcurrent,bnext)->getLength() ;
                        auto f = w + heuristic_distance_estimator(getBlock(bcurrent)->getX(),getBlock(bcurrent)->getY(),getBlock(bnext)->getX(),getBlock(bnext)->getY());
                
                        if(find(active_queue.begin(), active_queue.end(), bnext) == active_queue.end()){
                            getBlock(bnext)->SetWeight(w) ;
                            getBlock(bnext)->SetEstimate(f) ;
                            active_queue.push_back(bnext) ;
                            parent[bnext] = bcurrent;
                            cout <<"taille de l'arbre :"<< parent.size() << endl;
                        } 
                        else if (f < getBlock(bnext)->getEstimate()){
                            getBlock(bnext)->SetWeight(w) ;
                            getBlock(bnext)->SetEstimate(f) ;
                            parent[bnext] = bcurrent;
                            cout <<"taille de l'arbre :"<< parent.size() << endl;
                        }
                    }
                }
                
                auto sort_function_on_estimate = [this](int a, int b) { 
                return this->getBlock(a)->getEstimate() < this->getBlock(b)->getEstimate() ; 
                } ;
                
                sort(active_queue.begin(), active_queue.end(), sort_function_on_estimate);
                cout << "queue :"<<active_queue.size()<< endl;

            } while(!active_queue.empty()) ;

            
            int current = bend ;
            
            while(current != bstart) {
                path.push_front(current) ;
                current = parent[current];
                //cout << "hello"<<endl;
            }
            path.push_front(bstart) ;
            path_counter = path.size() ;

            int compt = 1 ;
            double length = 0.0 ;
            while(!path.empty()){
                end_result << "Vertex ["<<to_string(compt)<<"] = "<<
                to_string(path.front())<< " ,length = "<< to_string(length) <<endl ;
                compt++ ;
                length +=getEdge(path.front(),path[1])->getLength() ;
                path.pop_front() ;
            }

            
            cout << "\nAstar's Algorithm "<< endl ;
            cout << "Total visited vertex :" << to_string(closed_set.size()) << endl;
            cout << "Length of the path :" << to_string(path_counter) << endl;
            cout <<end_result.str()<< endl  ;
            
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