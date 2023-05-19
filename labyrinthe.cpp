#include "labyrinthe.hpp"

labyrinthe::labyrinthe (int l,int w):length(l), width(w),size(w*l){

    //Initialisation des blocs
    for(int i =0 ; i< l ;i++){
        for(int j = 0 ; j<w ;j++){
            all_block[cord(i,j)] = new block(cord(i,j),cord(i,j)) ;

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




int labyrinthe::cord(int i,int j) const {
    assert((i>=0 && i<length) &&(j>=0 && j<width)) ;
    return width*i+j ;
}

void labyrinthe::merge(int first_ID,int second_ID){

    assert(getBlock(first_ID)->getID() != getBlock(second_ID)->getID()) ;

    int neighboor ;
    int neighboor_size ;
    int id, n_id ;
    vector<edge> neighboor_list ;
    
    if(getBlock(first_ID)->getValue() <= getBlock(second_ID)->getValue()){
        id =first_ID;
        n_id =second_ID ;
    }else id =second_ID ,n_id =first_ID ;
     
    getBlock(n_id)->setValue(getBlock(id)->getValue()) ;
    //getBlock(second_ID)->setValue(25) ;
    neighboor_size = getBlock(n_id)->getNeighboor().size();
    neighboor_list = getBlock(n_id)->getNeighboor();
    for(int i=0 ; i<neighboor_size;i++){
        if(!neighboor_list[i].isopen()){
            neighboor = neighboor_list[i].getDestination() ;
            merge(getBlock(n_id)->getValue(),neighboor);
        }
    }
    road[pair(id,n_id)]->open_wall() ;
    
    /*
    if(getBlock(first_ID)->getValue() <= getBlock(second_ID)->getValue()){
        getBlock(second_ID)->setValue(getBlock(first_ID)->getValue()) ;
        //getBlock(second_ID)->setValue(25) ;
        neighboor_size = getBlock(second_ID)->getNeighboor().size();
        neighboor_list = getBlock(second_ID)->getNeighboor();
        for(int i=0 ; i<neighboor_size;i++){
            if(!neighboor_list[i].isopen()){
                neighboor = neighboor_list[i].getDestination() ;
                merge(getBlock(second_ID)->getValue(),neighboor);
            }
        }
    } else {
        getBlock(first_ID)->setValue(getBlock(second_ID)->getValue()) ;
        
        neighboor_size = getBlock(first_ID)->getNeighboor().size();
        neighboor_list = getBlock(first_ID)->getNeighboor();
        for(int i=0 ; i<neighboor_size;i++){
            if(!neighboor_list[i].isopen()){
                neighboor = neighboor_list[i].getDestination() ;
                merge(getBlock(first_ID)->getValue(),neighboor);
            }
        }
    }
    //cout << "first_ID :"<< getBlock(first_ID)->getValue() << " second_ID :"<< getBlock(second_ID)->getValue() << endl ;
    road[pair(id,n_id)]->open_wall() ;
    */
}

bool labyrinthe::is_ready() {
    int v = getBlock(0)->getValue();
    for(int i=0 ; i<size-1 ; i++){
        if(v != getBlock(i+1)->getValue()) return false ;
    }
    return true ;
}

vector <pair<int,int>> labyrinthe:: Edgelist() const {
    vector <pair<int,int>> edges ;
    for(auto it = road.begin() ; it!=road.end() ; it++)
        edges.push_back(it->first) ;
    return edges ;
}

vector<int> labyrinthe::Blocklist() const {
    vector<int> blocks ;
    for(auto it =all_block.begin();it!=all_block.end();it++)
        blocks.push_back(it->first) ;
    return blocks ;
}

int labyrinthe::nbwall() const {
    return width*(2*length-1)-length ;
}



int labyrinthe::nbwall_opened(){
    int n = 0 ;
    for(map<pair<int,int>,edge*>::iterator it = road.begin() ; it!=road.end() ;it++){
        if(!it->second->isopen()) n++ ;
    }
    cout << n << endl ;
    return n ;
    
}

vector<int> labyrinthe::adjacent_list_ID(int ID) {
    vector<int> adjacent_list ;
    int n = getBlock(ID)->getNeighboor().size() ;
    for(int i =0 ; i< n;i++){
        adjacent_list.push_back(getBlock(ID)->getNeighboor()[i].getDestination()) ;
    }

    return adjacent_list ;
}



void labyrinthe::fusion_labyrinth(){
    
    // Initialise un objet de générateur de nombres aléatoires et une distribution uniforme pour sélectionner une case au hasard

    srand(time(NULL)) ;
    // déclaration des identifiants des cellules fusionnées
    pair<int,int> wall ;
    
    
    //liste des identifiants de tous les murs du labyrinthe
    vector<pair<int,int>> walls = Edgelist() ;    
    
    // Continue la fusion tant que le labyrinthe n'est pas complètement connecté
    while(!is_ready() && (nbwall_opened()!=(width*length-1))){
        
        wall = walls[rand()%walls.size()];
        
        // Fusionne les deux cases actuelles
        merge(wall.first, wall.second);
        
        //Retirer le mur ouvert de la liste des murs
        auto it = find(walls.begin(), walls.end(), pair(wall.first, wall.second));
        walls.erase(it) ;
        
    }

}

void labyrinthe::aldous_broder_labyrinth(){
    //écriture de l'algorithme
    //Initialisation des listes d'adjacences   
}

