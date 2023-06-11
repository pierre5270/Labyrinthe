#pragma once
#include "graph.hpp"
#include "character.hpp"
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <random>

class labyrinthe: public graph{
    private:

        int length,width ; // Variables utilis�es pour stocker la longueur et la largeur du labyrinthe
        int size ;

        // R�le : Etablir les connexions entre les blocs de la premi�re rang�e du labyrinthe, en ajoutant les ar�tes appropri�es
        void initFirstRowBlock(int i){
            if(i==0){
                addWay(new way(0,cord(i+1,0))) ;
                addWay(new way(0,cord(i,0+1))) ;
            }
            else if(i>0 && i<length-1){
                addWay(new way(cord(i,0),cord(i+1,0))) ;
                addWay(new way(cord(i,0),cord(i,0+1))) ;
                addWay(new way(cord(i,0),cord(i-1,0))) ;
            }
            else{
                addWay(new way(length-1,cord(i,0+1))) ;
                addWay(new way(length-1,cord(i-1,0))) ;
            }
        }

        // R�le : Etablir les connexions entre les blocs des rang�es du milieu du labyrinthe, en ajoutant les ar�tes appropri�es
        void initMiddleRowsBlock(int i, int j){
            if(i==0){
                addWay(new way(cord(i,j),cord(i,j+1))) ;
                addWay(new way(cord(i,j),cord(i,j-1))) ;
                addWay(new way(cord(i,j),cord(i+1,j))) ;
            }
            else if(i>0 && i<length-1){
                addWay(new way(cord(i,j),cord(i,j+1))) ;
                addWay(new way(cord(i,j),cord(i+1,j))) ;
                addWay(new way(cord(i,j),cord(i,j-1))) ;
                addWay(new way(cord(i,j),cord(i-1,j))) ;
            }
            else{
                addWay(new way(cord(i,j),cord(i,j-1))) ;
                addWay(new way(cord(i,j),cord(i-1,j))) ;
                addWay(new way(cord(i,j),cord(i,j+1)));
            }
        }

        // R�le : Etablir les connexions entre les blocs de la derni�re rang�e du labyrinthe, en ajoutant les ar�tes appropri�es
        void initLastRowBlock(int i, int j){
            if(i==0){
                addWay(new way(cord(i,j),cord(i+1,j)));
                addWay(new way(cord(i,j),cord(i,j-1)));
            }
            else if (i>0 && i<length-1){
                addWay(new way(cord(i,j),cord(i,j-1)));
                addWay(new way(cord(i,j),cord(i-1,j))) ;
                addWay(new way(cord(i,j),cord(i+1,j))) ;
            }
            else{
                addWay(new way(cord(i,j),cord(i-1,j))) ;
                addWay(new way(cord(i,j),cord(i,j-1))) ;
            }
        }

    public:

        // R�le : Constructeur qui initialise un objet labyrinthe avec les dimensions sp�cifi�es et qui cr�e les blocs correspondants
        // en ajoutant les ar�tes n�cessaires pour connecter les blocs adjacents
        // Donne la structure du labyrinthe
        labyrinthe(){}

        labyrinthe (int l,int w):length(l), width(w),size(w*l){
            for(int j =0 ; j< w ;j++){                                  // Initialise chaque bloc du labyrinthe via les for qui parcourent les coordonn�es (i,j) de chaque bloc
                for(int i = 0 ; i<l ;i++){
                    all_block[cord(i,j)] = new block(i,j,cord(i,j)) ;   // Cr�ation � chaque it�ration d'un objet bloc avec les coordonn�es (i,j) dans le tableau all_block
                    if (j==0){
                        initFirstRowBlock(i);                       // Ajoute les ar�tes n�cessaires pour connecter les blocs adjacents de la premi�re rang�e
                    }
                    else if (j>0 && j<width -1){
                        initMiddleRowsBlock(i, j);              // ajoute les ar�tes n�cessaires pour connecter les blocs adjacents des rang�es du milieu
                    }
                    else{
                        initLastRowBlock(i,j);                 // ajoute les ar�tes n�cessaires pour connecter les blocs adjacents de la derni�re rang�e
                    }
                }
            }
        }

        // R�le : Acc�der � la valeur de la longueur du labyrinthe depuis l'ext�rieur de l'objet sans permettre les modifications
        int getLength() const {
            return this->length;
        }

        // R�le : Acc�der � la valeur de la largeur du labyrinthe depuis l'ext�rieur de l'objet sans permettre les modifications
        int getWidth() const {
            return this->width;
        }

        // R�le : Acc�der � la valeur de la taille du labyrinthe depuis l'ext�rieur de l'objet sans permettre les modifications
        int getSize()const {
            return this->size;
        }

        // R�le : Modifier la valeur de la longueur du labyrinthe en lui attribuant une nouvelle valeur fournie en param�tre l
        void setLength(int l) {
            this->length = l ;
        }

        // R�le : Modifier la valeur de la largeur du labyrinthe en lui attribuant une nouvelle valeur fournie en param�tre w
        void setWidth(int w) {
            this->width = w ;
        }

        //R�le : Acc�der au pointeur vers le bloc correspondant � l'identifiant sp�cifi� en param�tre d'entr�e ID
        virtual block *getBlock(int ID) override {
            return all_block[ID] ;
        }

        //R�le : Acc�der au pointeur vers le chemin entre deux blocs sp�cifi�s en param�tre d'entr�e par leurs identifiants source (sID) et destination (dID)
        virtual way *getWay(int sID,int dID) override{
            return road[make_pair(sID,dID)] ; //*
        }

        // R�le : Modifier la liste des chemins du labyrinthe en ajoutant la valeur du chemin du bloc dont la valeur est fournie en param�tre e
        virtual void addWay(way *e) override {
            road.emplace(make_pair(e->getSource(),e->getDestination()),e) ;
            addAdjacentlist(e) ;
        }

// fonction de debugage
        // R�le : Modifier la liste des chemins adjacents au bloc en ajoutant la valeur du chemin du bloc dont la valeur est fournie en param�tre e
        virtual void addAdjacentlist(way *e) override {
            block *b = getBlock(e->getSource()) ;
            b ->setNeighboor(e) ;
        }

        // R�le : Obtenir une cha�ne de caract�res qui repr�sente les valeurs des membres de la classe graph
        virtual string toString() override {
            ostringstream ss;
            for (int j = 0; j < width; j++){
                for (int i = 0; i < width; i++){
                    ss << setw(2) << graph::all_block[cord(i,j)]->getValue()<< " " ;
                }
                ss << endl ;
            }
            return ss.str();
        }

        // R�le : Modifier toutes les tailles des chemins des blocs pour les initialiser � la valeur value donn�e en param�tre d'entr�e
        virtual void set_all_vertex_to_max_value(double value) override {
            for(map < int,block* >::iterator it = all_block.begin(); it!=all_block.end(); it++){
                it->second->setWeight(0.0) ;
            }
        }

        // R�le : Calculer la distance Euclidienne entre deux points de coordonn�es (x,y) diff�rentes
        virtual double heuristic_distance_estimator(int id1_x,int id1_y, int id2_x,int id2_y) override {
            return sqrt(pow((id1_x-id2_x),2)+pow((id1_y-id2_y),2));
        }

        // R�le : D�terminer le chemin le plus court entre la source et la destination en fonction des murs ouverts et ferm�s
        virtual deque<int> astar (int bstart, int bend) override {
            deque <int> active_queue ;                                  // File pour notifier les blocs actifs � explorer
            set<int> closed_set ;                                       // Ensemble pour les blocs d�j� visit�s
            map<int,int> parent ;                                       // Map pour notifier les relations parent-enfant entre les blocs
            deque <int> path ;                                          // File pour stocker le chemin final


            set_all_vertex_to_max_value(numeric_limits<double>::max()) ;// Initialisation des poids des blocs � une valeur maximale
            active_queue.push_back(bstart) ;                            // ID du bloc de d�part
            getBlock(bstart)->setWeight(0.00);                          // Initialisation du poids du bloc de d�part � 0
            do{
                auto bcurrent = active_queue.front();                   // R�cup�ration du bloc courant en t�te de la file
                active_queue.pop_front() ;                              // Suppression du bloc courant en t�te de la file pour traiter le suivant
                if(bcurrent==bend) break ;                              // Le bloc courant est le bloc d'arriv�e alors le chemin le plus court est trouv�, on arr�te la boucle
                closed_set.insert(bcurrent) ;                           // Ajouter le bloc courant � l'ensemble des blocs visit�s
                for(way *e : getBlock(bcurrent)->getNeighboor()){
                    int bnext = e->getDestination() ;                   // ID du bloc voisin
                    if (getWay(bcurrent,bnext)->isopen()){              // On v�rifie si le voisin a un chemin ouvert et s'il est non visit�
                        if(closed_set.find(bnext) != closed_set.end()) continue ;
                        auto w = getBlock(bcurrent)->getWeight() + getWay(bcurrent,bnext)->getLength() ; // on calcule le poids de ce bloc voisin
                        auto f = w + heuristic_distance_estimator(getBlock(bnext)->getX(),getBlock(bnext)->getY(),getBlock(bend)->getX(),getBlock(bend)->getY()); // on calcule la valeur estim�e de ce bloc voisin
                        if(find(active_queue.begin(), active_queue.end(), bnext) == active_queue.end()){ // Si le bloc voisin n'est pas d�j� dans la file des blocs actifs � explorer, l'ajouter
                            getBlock(bnext)->setWeight(w) ;             // Ajouter le poids  de ce bloc voisin
                            getBlock(bnext)->setEstimate(f) ;           // Ajouter son estimation mis � jour
                            active_queue.push_back(bnext) ;
                            parent[bnext] = bcurrent;                   // Ajouter sa relation parent-enfant

                        }
                        else if (f < getBlock(bnext)->getEstimate()){   // Le bloc voisin est visit�, on v�rifie si le nouveau chemin offre un poids et une estimation meilleurs
                            getBlock(bnext)->setWeight(w) ;             // Si c'est le cas, on met � jour son poids
                            getBlock(bnext)->setEstimate(f) ;
                            parent[bnext] = bcurrent;                   // On met � jour sa relation parent-enfant

                        }
                    }
                }
                auto sort_function_on_estimate = [this](int a, int b) { // D�fini une fonction lambda pour comparer les blocs via leur estimation
                    return this->getBlock(a)->getEstimate() < this->getBlock(b)->getEstimate() ;
                } ;
                sort(active_queue.begin(), active_queue.end(), sort_function_on_estimate); // trie des �l�ments de la file des blocs actifs en fonction de leurs estimations

            }
            while(!active_queue.empty()) ;                              // Tant que la file active_queue n'est pas vide, faire
            int current = bend ;                                        // D�finir le bloc courant comme �tant le bloc d'arriv�e
            while(current != bstart) {                                  // Tant que le bloc courant n'est pas le bloc de d�part (par s�curit�)
                path.push_front(current) ;                              // Ajouter le bloc courant au d�but de la file du chemin final
                current = parent[current];                              // Mettre � jour le bloc courant en se d�pla�ant vers son parent dans la map
            }
            path.push_front(bstart) ;                                   // On ajoute le bloc de d�part au d�but de la file stockant le chemin final
            
            return path ;
        }

        // R�le : Calculer l'identifiant unique d'un bloc dans le labyrinthe � partir de ses coordonn�es (i,j)
        int cord(int i,int j) const {
            assert((i>=0 && i<length) &&(j>=0 && j<width)) ;
            return length*j+i ;
        }

        // R�le : Fusionner deux blocs dans le labyrinthe
        // Ouvre le mur s�parant les deux blocs, met tous les blocs connect�s dans le m�me ensemble et leur attribue la valeur minimale de l'ensemble
        void fusion(int first_ID,int second_ID){
            getWay(first_ID,second_ID)->open_wall();                                // Ouverture du mur s�parant les 2 blocs
            getWay(second_ID,first_ID)->open_wall();                                // Ouverture du mur s�parant les 2 blocs
            deque<int> active_queue ;                                               // File pour notifier les blocs actifs � explorer
            set<int> closed_set;                                                    // Ensemble pour les blocs d�j� visit�s
            set<int> real_path ;                                                    // Ensemble des blocs faisant partie du chemin final
            active_queue.push_back(first_ID) ;                                      // ID du bloc de d�part ajout� dans le file active_queue
            real_path.insert(first_ID);                                             // ID du bloc de d�part ajout� dans l'ensemble real_path
            do{
                auto b_current = active_queue.front() ;                             // R�cup�ration du bloc courant en t�te de la file
                active_queue.pop_front() ;                                          // On efface le premier bloc de la file active_queue
                closed_set.insert(b_current) ;                                      // On ajoute le bloc courant � l'ensemble des blocs d�j� visit�
                for(way *e : getBlock(b_current)->getNeighboor()){                  // Parcourt tous les voisins du bloc courant
                    int b_next = e->getDestination();                               // Donne au bloc suivant (voisin) sa destination par rapport au bloc courant
                    if(getWay(b_current,b_next)->isopen()){                         // V�rifie que le mur entre le bloc courant et le bloc suivant est ouvert
                        if(closed_set.find(b_next) != closed_set.end()) continue;   // V�rifie si le bloc suivant n'est pas le dernier bloc visit�, sinon, passe au voisin suivant
                            if (find(active_queue.begin(), active_queue.end(), b_next) == active_queue.end()) { // V�rifie si le bloc suivant n'est pas dans la liste d'attente, si oui, on l'ajoute
                                active_queue.push_back(b_next);                     // On ajoute le bloc suivant � la file d'attente pour l'explorer
                                real_path.insert(b_next);                           // On ajoute le bloc suivant � l'ensemble du chemin
                            }
                        }
                    }
            }
            while(!active_queue.empty()) ;                                          // La boucle do continue tant que la file d'attente n'est pas vide, tant que tous les blocs n'ont pas �t� explor�s
            auto minValue = std::min_element(real_path.begin(), real_path.end());   // Recherche de la valeur minimale dans l'ensemble du chemin real_path
            for (auto it = real_path.begin();it!=real_path.end();it++){             // Parcourt la file du chemin real_path
                this->getBlock(*it)->setValue(*minValue);                           // Mise � jour de la valeur des blocs du chemin par la valeur minimale trouv�e
            }
        }

        // R�le : V�rifier si tous les blocs du labyrinthe sont pr�ts
        // Retourne true si les blocs ont tous la m�me valeur
        bool is_ready() {
            bool result = true;
            for (auto it = all_block.begin();it!=all_block.end();it++){ // Parcourt tous les blocs du labyrinthe
                if(it->second->getValue()!=0){                          // V�rifie si la valeur du bloc est diff�rente de z�ro
                    result = !result ;                                  // Si la valeur du bloc n'est pas z�ro, alors le labyrinthe n'est pas pr�t, "result" est pass�e � false
                    break;                                              // On interrompt la boucle
                }
            }
            return result ;
        }


        // R�le : Retourner la liste compl�te des murs pr�sents dans le labyrinthe en se basant sur la structure de donn�es road qui les stocke.
        vector <pair<int,int>> WallsList() const {
            vector <pair<int,int>> walls;                           // D�claration d'un vecteur de paires d'entiers pour stocker les murs
            for(auto it = road.begin() ; it!=road.end() ; it++){
                if(find(walls.begin(),walls.end(),make_pair(it->first.second,it->first.first)) != walls.end()) continue ; //*// V�rifie si le mur invers� est pr�sent dans la liste, si oui, on passe � l'it�ration suivante (�viter la redondance)
                walls.push_back(it->first) ;                        // Sinon, on ajoute le mur � la liste des murs
            }
            return walls ;
        }

        // R�le : Retourner la liste des ordonn�es des blocs pr�sents dans la grille du labyrinthe.
        vector<block*> Blocklist() {
            vector<block*> blocks ;                                 // D�claration d'un vecteur de pointeurs de block pour stocker les ordonn�es des blocs
            for(auto it =all_block.begin();it!=all_block.end();it++)// Parcours le tableau des blocs all_block du constructeur
                blocks.push_back(it->second) ;                      // Ajoute chaque ordonn�e de bloc � la liste blocks
            return blocks ;
        }

        // R�le : D�terminer les murs du labyrinthe ouverts
        // Indiquer les murs pouvant �tre effac�s sur l'interface graphique
        vector<pair<int,int>> EraseWall() {
            vector<pair<int,int>> walls = WallsList();                             // R�cup�re la liste de tous les murs du labyrinthe
            vector<pair<int,int>> erasewalls ;                                      // D�claration d'un vecteur pour stocker les murs � effacer
            for(auto it = walls.begin(); it!=walls.end();it++){
                if(getWay(it->first,it->second)->isopen()) erasewalls.push_back(*it);// V�rifie si le mur s�lectionn� est ouvert, si oui, on ajoute le mur dans la liste erasewalls
            }
            return erasewalls ;
        }

        // R�le : D�terminer combien de blocs du labyrinthe ont �t� visit�s
        int nbVisited() {
            int nbbopen = 0 ;                                           // Variable pour compter le nombre de blocs visit�s
            for(auto it = all_block.begin();it!=all_block.end();it++){  // Parcours de la liste des blocs all_block du constructeur
                if (it->second->getVisited()) nbbopen++;                // V�rifie si le bloc a �t� visit�, si oui, incr�mentation
            }
            return nbbopen ;
        }

        //R�le : G�n�re le labyrinthe � partir de l'algorithme de fusion
        // Ex�cute l'algorithme de fusion pour connecter les blocs du labyrinthe en supprimant s�lectivement les murs
        // S�lectionne al�atoirement un mur, effectue la fusion des blocs adjacents, puis supprime le mur de la liste.
        // R�p�tition du processus jusqu'� ce que le labyrinthe soit compl�tement connect�
        labyrinthe fusion_labyrinth(){
            cout << "algorithme de fusion" << endl;
            srand(time(NULL));                                  // Initialise le g�n�rateur de nombres al�atoires avec une graine bas�e sur le temps actuel (= s�lection diff�rente � chaque ex�cution)
            pair<int,int> wall;                                 // D�claration d'une variable pour un mur courant form� de deux blocs adjacents
            int wall_id ;                                       // D�claration d'une variable pour identifier le mur en question
            vector<pair<int,int>> walls = WallsList();          // D�claration d'un vecteur pour stocker la liste des murs du labyrinthe form� de deux blocs adjacents
            while(!this->is_ready()){                           // Tant que tous les blocs du labyrinthe n'ont pas la m�me valeur
                wall_id = rand() % walls.size();                // On s�lectionne un mur al�atoire dans la liste des murs disponibles en s�lection un index al�atoire de cette liste
                wall = walls[wall_id] ;                         // On donne les coordonn�es du mur s�lectionn� au mur courant
                fusion(wall.first,wall.second);                 // On fusionne les deux blocs qui forment ce mur
                walls.erase(walls.begin() + wall_id);           // On supprime le mur s�lectionn� de la liste des murs
            }
            return *this ;
        }


        //R�le : G�n�re le labyrinthe � partir de l'algorithme d'Aldous-Broder
        labyrinthe aldous_broder_labyrinth(){
            cout << "algorithme d'Aldous_Br�der" << endl;
            srand(time(NULL)) ;                                                                                // Initialise le g�n�rateur de nombres al�atoires avec une graine bas�e sur le temps actuel (= s�lection diff�rente � chaque ex�cution)
            vector<block*> blocks = Blocklist();                                                               // D�claration d'un vecteur pour stocker la liste des valeurs des blocs du labyrinthe
            vector<way*> neighboor ;                                                                           // D�claration d'une variable qui regroupe les blocs voisins du bloc courant
            int taille = length*width;                                                                         // D�claration d'une variable qui indique la taille du labyrinthe
            block *b_current = blocks[rand()%blocks.size()];                                                   // D�claration d'un bloc courant choisi al�atoirement dans la liste des blocs du labyrinthe
            while((nbVisited()<taille)){                                                                       // Tant que tous les blocs du labyrinthe n'ont pas �t� visit�s
                // s�lectionne un voisin al�atoirement
                neighboor = b_current->getNeighboor();                                                         // R�cup�re la liste des voisins du bloc courant choisi al�atoirement
                int ind_n = rand()%neighboor.size();                                                           // S�lectionne al�atoirement un bloc voisin parmi ceux de la liste en g�n�rant un index al�atoire
                if(!b_current->getVisited()){                                                                  // V�rifie si le bloc courant est visit�, Sinon, on marque sa visite
                    b_current->setVisited();
                }
                if(!neighboor[ind_n]->isopen()){                                                               // V�rifie si le chemin entre le bloc courant et le voisin s�lectionn� est ouvert, sinon, faire la suite
                    if(!getBlock(neighboor[ind_n]->getDestination())->getVisited()){                           // V�rifie si le bloc voisin s�lectionn� est visit�
                        getWay(neighboor[ind_n]->getSource(),neighboor[ind_n]->getDestination())->open_wall(); // Ouvre le mur entre le bloc courant et le bloc voisin s�lectionn�
                        getWay(neighboor[ind_n]->getDestination(),neighboor[ind_n]->getSource())->open_wall(); // Ouvre le mur entre le bloc courant et le bloc voisin s�lectionn�
                    }
                }
                b_current = getBlock(neighboor[ind_n]->getDestination());                                      // Met � jour le bloc courant avec le bloc voisin s�lectionn�
            }
            return *this ;
        }

        // R�le : Afficher un objet de la classe labyrinthe dans un flux de sortie en utilisant son op�rateur de flux de sortie surcharg�
        friend ostream &operator<<(ostream &f, labyrinthe l){
            return f<<l.toString() ;
        }
};
