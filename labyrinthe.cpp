#include "labyrinthe.hpp"

labyrinthe::labyrinthe (int l,int w):length(l), width(w),size(w*l){

    //Initialisation des blocs
    for(int i =0 ; i< l ;i++){
        for(int j = 0 ; j<w ;j++){
            all_block[cord(i,j)] = new block(i,j,cord(i,j)) ;
            all_block[cord(i,j)]->Setchemin(cord(i,j)) ;

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




int labyrinthe::cord(int i,int j) const {
    assert((i>=0 && i<length) &&(j>=0 && j<width)) ;
    return width*i+j ;
}


void labyrinthe::fusion(int first_ID,int second_ID){

    getEdge(first_ID,second_ID)->open_wall();

    block *b1 = getBlock(first_ID);
    block *b2 = getBlock(second_ID);



    //valeur minimale entre les 2  blocs
    //int x = min(b1->getID(),b2->getID()) ;
    //cout << x << endl ;

    // si les chemins sont différents, on les fusionne
    
    if(b1->getChemin()[0] != b2->getChemin()[0]) {
        // on fusionne les deux chemins
        for (auto x : b2->getChemin()){
            b1->Setchemin(x) ;
            //getBlock(x)->setValue(min(b1->getID(),b2->getID()));
            
        }
    }

    for (auto x : b2->getChemin()){
        Chemins[x] = b1->getChemin() ;
        getBlock(x)->setValue(min(b1->getID(),b2->getID()));
        
    }
    /*
    if(b1->getValue() != b2->getValue()){
        b2->setValue(x);
        b1->setValue(x);
        b2->Setchemin(b1->getID());
        b1->Setchemin(b2->getID());
    
    }
    for(int i :b2->getChemin()){
        b1->Setchemin(i);
    }
    for(int i :b1->getChemin()){
        getBlock(i)->setValue(x);
    }*/
    
}


bool labyrinthe::is_ready() {
    
    for(int i=0 ; i<size-1 ; i++){
        if(getBlock(i)->getValue()!=0) return false ;
    }
    return true ;
}

vector <pair<int,int>> labyrinthe:: Edgelist() const {
    vector <pair<int,int>> edges ;
    for(auto it = road.begin() ; it!=road.end() ; it++)
        edges.push_back(it->first) ;
    return edges ;
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
    for(map<pair<int,int>,edge*>::iterator it = road.begin() ; it!=road.end() ;it++){
        if(it->second->isopen()) n++ ;
    
    }
    
    return n ;
    
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



void labyrinthe::fusion_labyrinth(){
    
    cout << "algorithme de fusion" << endl;
    // Initialise un objet de générateur de nombres aléatoires et une distribution uniforme pour sélectionner une case au hasard

    srand(time(NULL)) ;
    
    // déclaration des identifiants des cellules fusionnées
    pair<int,int> wall ;
    int wall_id ;
    
    //liste des identifiants de tous les murs du labyrinthe
    vector<pair<int,int>> walls = Edgelist() ;
    
    // Continue la fusion tant que le labyrinthe n'est pas complètement connecté
    int taille = length*width ;
    while(nbwall_opened()<taille) {
        //cout << nbwall_opened()<< endl ;
        // sélectionne un mur aléatoirement
        wall_id = rand() % walls.size() ;
        wall = walls[wall_id] ;
        //fuse is the problem
        //cout << "walls :"<<walls.size()<< endl;
        fusion(wall.first,wall.second);
        auto it = find(walls.begin(),walls.end(),pair(wall.first,wall.second));
        walls.erase(it);

    }

}

void labyrinthe::aldous_broder_labyrinth(){

    
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
}

void labyrinthe::print_V_wall(){
    ostringstream ss;
    ss << "V_wall :" << endl;

    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
             if(cord(i,j)>=length){
                string s = (getEdge(cord(i-1,j),cord(i,j))->isopen())?"1":"0" ;
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
                string s = (getEdge(cord(i,j),cord(i,j+1))->isopen())?"1":"0" ;
                ss << setw(2) << s << " " ;
            }
            
        }
        ss << endl ;
    }
    cout << ss.str() ;
}

