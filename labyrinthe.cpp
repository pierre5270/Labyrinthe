#include "labyrinthe.hpp"
#include <random>

labyrinthe::labyrinthe (int l,int w):length(l), width(w),size(w*l){

    //Initialisation des blocs
    for(int i =0 ; i< l ;i++){
        for(int j = 0 ; j<w ;j++){
            all_block[cord(i,j)] = new block(i,j,cord(i,j)) ;

            if (i==0){
                if(j==0){

                    addEdge(new edge(0,cord(i,j+1))) ;
                    addEdge(new edge(0,cord(i+1,j))) ;

                } else if(j>0 && j<width-1){    

                    addEdge(new edge(cord(i,j),cord(i,j+1))) ;
                    addEdge(new edge(cord(i,j),cord(i+1,j))) ;
                    addEdge(new edge(cord(i,j),cord(i,j-1))) ;
                }
                else{
                        
                    addEdge(new edge(width-1,cord(i+1,j))) ; 
                    addEdge(new edge(width-1,cord(i,j-1))) ;
                }
                     
                }else if (i>0 && i<length -1){
                    if(j==0){
                        
                    addEdge(new edge(cord(i,j),cord(i,j+1))) ;
                    addEdge(new edge(cord(i,j),cord(i-1,j))) ;
                    addEdge(new edge(cord(i,j),cord(i+1,j))) ;

                }else if(j>0 && j<width-1){
                        
                    addEdge(new edge(cord(i,j),cord(i,j+1))) ;
                    addEdge(new edge(cord(i,j),cord(i+1,j))) ;
                    addEdge(new edge(cord(i,j),cord(i,j-1))) ;
                    addEdge(new edge(cord(i,j),cord(i-1,j))) ;
                    
                }
                else{
                        
                    addEdge(new edge(cord(i,j),cord(i-1,j))) ;
                    addEdge(new edge(cord(i,j),cord(i,j-1))) ;
                    addEdge(new edge(cord(i,j),cord(i+1,j)));                        
                }
                   }
                else{
                    if(j==0){
      
                    addEdge(new edge(cord(i,j),cord(i,j+1)));  
                    addEdge(new edge(cord(i,j),cord(i-1,j)));   

                    } else if (j>0 && j<width-1){ 

                    addEdge(new edge(cord(i,j),cord(i-1,j)));
                    addEdge(new edge(cord(i,j),cord(i,j-1))) ; 
                    addEdge(new edge(cord(i,j),cord(i,j+1))) ;   

                    } else{
                    addEdge(new edge(cord(i,j),cord(i-1,j))) ;
                    addEdge(new edge(cord(i,j),cord(width-1,j-1))) ;                        
                }
            }
                   
        }
    }
            
}

//Rôle : retourne la longueur du labyrinthe
int labyrinthe::getLength() const {
    return this->length;
}

//Rôle : retourne la largeur du labyrinthe
int labyrinthe::getWidth() const {
    return this->width;
}

//Rôle : retourne la size du tableau
int labyrinthe::getSize()const {
    return this->size;
}

void labyrinthe::setLength(int l) {
    this->length = l ;
}

void labyrinthe::setWidth(int w) {
    this->width = w ;
}



int labyrinthe::cord(int i,int j) const {
    assert((i>=0 && i<length) &&(j>=0 && j<width)) ;
    return width*i+j ;
}


void labyrinthe::fusion(int first_ID,int second_ID){

    //On ouvre le mur séparant les 2 blocs
    getEdge(first_ID,second_ID)->open_wall();
    getEdge(second_ID,first_ID)->open_wall();
    

    //Chemin de tous les blocs relés
    deque<int> active_queue ;
    set<int> closed_set;
    //map<int,int> path;
    set<int> real_path ;
    
    //ID du bloc de départ
    active_queue.push_back(first_ID) ;
    real_path.insert(first_ID);
    
    do{

        auto b_current = active_queue.front() ;

        //On retire le bloc courant de la file d'attente
        active_queue.pop_front() ;

        //On ajoute le bloc courant à la liste de chemin
        closed_set.insert(b_current) ;

        for(edge *e : getBlock(b_current)->getNeighboor()){

            
            int b_next = e->getDestination();
            if(getEdge(b_current,b_next)->isopen()){

                if(closed_set.find(b_next) != closed_set.end()) continue;

                if (find(active_queue.begin(), active_queue.end(), b_next) == active_queue.end()) {
                    active_queue.push_back(b_next);
                    real_path.insert(b_next);        
                }
            }      
        }

    }while(!active_queue.empty()) ;

    //cout <<"real_path :"<<real_path.size()<<endl;

    //La valeur minimale du chemin généré
    auto minValue = std::min_element(real_path.begin(), real_path.end());
    for (auto it = real_path.begin();it!=real_path.end();it++){
        this->getBlock(*it)->setValue(*minValue);
    }
 
}


bool labyrinthe::is_ready() {
    
    bool result = true;

    for (auto it = all_block.begin();it!=all_block.end();it++){
        if(it->second->getValue()!=0){
            result = !result ;
            break;
        }
    }
    return result ;
}

vector <pair<int,int>> labyrinthe:: Edgelist() const {
    vector <pair<int,int>> edges ;
    for(auto it = road.begin() ; it!=road.end() ; it++){
        if(find(edges.begin(),edges.end(),pair(it->first.second,it->first.first)) != edges.end()) continue ;
        edges.push_back(it->first) ;
    }
    return edges ;
}

vector<pair<int,int>> labyrinthe:: EraseWall() {
    vector<pair<int,int>> walls = Edgelist();
    vector<pair<int,int>> erasewalls ;
    for(auto it = walls.begin(); it!=walls.end();it++){
        if(getEdge(it->first,it->second)->isopen()) erasewalls.push_back(*it);
    }
    return erasewalls ;
}

vector<pair<int,int>> labyrinthe:: H_walls(){
    vector<pair<int,int>> walls = EraseWall();
    vector<pair<int,int>> v_walls ;

    for(auto it = walls.begin();it!=walls.end();it++){
        if((it->first -it->second)==1){
            v_walls.push_back(*it);
        }
    }
    return v_walls ;
}

vector<pair<int,int>> labyrinthe::V_walls(){
    vector<pair<int,int>> walls = EraseWall();
    vector<pair<int,int>> h_walls ;

    for(auto it = walls.begin();it!=walls.end();it++){
        if((it->first -it->second)==this->getLength()){
            h_walls.push_back(*it);
        }
    }
    return h_walls ;
}

vector<block*> labyrinthe::Blocklist() {
    vector<block*> blocks ;
    for(auto it =all_block.begin();it!=all_block.end();it++)
        blocks.push_back(it->second) ;
    return blocks ;
}


int labyrinthe :: nbVisited() {
    int nbbopen = 0 ;
    for(auto it = all_block.begin();it!=all_block.end();it++){
        if (it->second->getVisited()) nbbopen++ ;
        
    }
    
    return nbbopen ;
}


int labyrinthe::nbwall() const {
    return width*(2*length-1)-length ;
}



int labyrinthe::nbwall_opened(){
    int n = 0 ;
    vector<pair<int,int>> edges = this->Edgelist() ;
    for(auto it = edges.begin();it!=edges.end();it++){
        if(getEdge(it->first,it->second)->isopen()) n++ ;
    }
    return n;
    
}
vector<block*> labyrinthe::BlockDiff(int ID) {
    int v = getBlock(ID)->getValue() ;
    vector<block*> diff_list ;
    for(map<int,block*>::iterator it=all_block.begin();it!=all_block.end();it++){
        if(it->second->getValue()!=v) diff_list.push_back(it->second);
    }
    return diff_list ;
}

vector<int> labyrinthe::adjacent_list_ID(int ID) {
    vector<int> adjacent_list ;
    int n = getBlock(ID)->getNeighboor().size() ;
    for(int i =0 ; i< n;i++){
        adjacent_list.push_back(getBlock(ID)->getNeighboor()[i]->getDestination()) ;
    }

    return adjacent_list ;
}



labyrinthe labyrinthe::fusion_labyrinth(){
    
    cout << "algorithme de fusion" << endl;
    // Initialise un objet de générateur de nombres aléatoires et une distribution uniforme pour sélectionner une case au hasard

    srand(time(NULL)) ;
    //cout << "taille des chemins :"<< road.size()<< endl;
    // déclaration des identifiants des cellules fusionnées
    pair<int,int> wall ;
    int wall_id ;
    
    //liste des identifiants de tous les murs du labyrinthe
    vector<pair<int,int>> walls = Edgelist() ;
    cout << "nombre de chemin" << walls.size()<< endl;
    //int i = 0;
    
    // Continue la fusion tant que le labyrinthe n'est pas complètement connecté
    //while(this->nbwall_opened()<this->getSize()){
    while(!this->is_ready()){

        // sélectionne un mur aléatoirement
        wall_id = rand() % walls.size() ;
        wall = walls[wall_id] ;

        //fusion des cellules
        fusion(wall.first,wall.second);

        // Supprime le mur de la liste
        walls.erase(walls.begin() + wall_id);

        //cout << "j'ai  :"<<nbwall_opened() << endl;
    }

    cout << "j'ai ouvert :"<<nbwall_opened() << endl;

    return *this ;
}




labyrinthe labyrinthe::aldous_broder_labyrinth(){

    
    cout << "algorithme d'Aldous_Bröder" << endl;
    // Initialise un objet de générateur de nombres aléatoires et une distribution uniforme pour sélectionner une case au hasard
    srand(time(NULL)) ;

    vector<block*> blocks = Blocklist(); //déclaration des cellules du labyrinthe
    vector<edge*> neighboor ; //L'ensemble des voisins de la cellules sélectionnées
    int ind_n ; // Indice de la cellule adjacente dans la liste des blocks adjacents
    int taille = length*width;
    block *b_current = blocks[rand()%blocks.size()];

    while((nbVisited()<taille)){

        // sélectionne un voisin aléatoirement
        neighboor = b_current->getNeighboor();
        ind_n = rand()%neighboor.size();

        if(!b_current->getVisited()){
            b_current->setVisited();
            
        }
            //Si le chemin avec le voisin n'est pas ouvert
            if(!neighboor[ind_n]->isopen()){
                // si la case n'a pas encore été visitée
                if(!getBlock(neighboor[ind_n]->getDestination())->getVisited()){
                    getEdge(neighboor[ind_n]->getSource(),neighboor[ind_n]->getDestination())->open_wall();
                    getEdge(neighboor[ind_n]->getDestination(),neighboor[ind_n]->getSource())->open_wall();
                }
            }
            b_current = getBlock(neighboor[ind_n]->getDestination());
    }   
    cout <<"Done"<<endl;
    cout << "j'ai ouvert :"<<nbwall_opened() << endl;

    return *this ;
}

void labyrinthe::print_V_wall(){
    ostringstream ss;
    ss << "V_wall :" << endl;

    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
             if(cord(i,j)>=length){
                string s = (getEdge(cord(i-1,j),cord(i,j))->isopen()&&getEdge(cord(i,j),cord(i-1,j))->isopen())?"1":"0" ;
                ss << setw(2) << s << " " ;
            }  
        }
        ss << endl ;
    }
    cout << ss.str() ;
}

void labyrinthe::print_H_wall(){
    ostringstream ss;
    ss << "H_wall :" << endl;

    for (int i = 0; i < length; i++){
        for (int j = 0; j < width-1; j++){
             if(1){
                string s = (getEdge(cord(i,j),cord(i,j+1))->isopen()&&getEdge(cord(i,j+1),cord(i,j))->isopen())?"1":"0" ;
                ss << setw(2) << s << " " ;
            }  
        }
        ss << endl ;
    }
    cout << ss.str() ;
}
