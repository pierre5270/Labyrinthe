#include "labyrinthe.hpp"

void labyrinthe::init_labyrinthe(){

    for(int i =0 ; i<size+width; i++){
        this->h_wall[i] = false ;
        this->v_wall[i] = false ;
        if (i<size){
            this->grid[i].setValue(rand()%size) ;
            this->grid[i].setID(i) ;
        }
    }

    cout << "Labyrinth initialized !!" << endl;
}

int labyrinthe::getGrid(int i, int j) const
{
    return grid[width * j + i].getValue();
}

bool labyrinthe::getH_wall(int i, int j) const
{
    return h_wall[width * j + i];
}

bool labyrinthe::getV_wall(int i, int j) const
{
    return v_wall[j * width + i];
}

void labyrinthe::adjacent_list() {

}
void labyrinthe::fusion_labyrinth(){
    //écriture de l'algorithme
    //Initialisation des listes d'adjacences (adjacent_list)
}

void labyrinthe::aldous_broder_labyrinth(){
    //écriture de l'algorithme
    //Initialisation des listes d'adjacences   
}


string labyrinthe::toString() const{

    ostringstream ss;
    ss << "Labyrinthe :" << endl;
    ss << endl ;
    for (int i = 0; i < width; i++){
        for (int j = 0; j < width; j++){
            ss << setw(2) << getGrid(i,j) << " ";
        }
        ss << endl ;
    }
    ss << endl ;

    ss << "horizontal wall :"<< endl ;
    draw_check_box(ss,h_wall) ;
    ss << endl ;
    ss << "vertical wall :"<< endl ;
    draw_check_box(ss,v_wall) ;

    return ss.str();
}