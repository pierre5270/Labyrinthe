#include "labyrinthe.hpp"


void labyrinthe::init_labyrinthe(){
    cout << "Labyrinth initialized !!"<< endl ;
}


int labyrinthe::getGrid(int i, int j)const {
    return grid[width*j+i].getValue() ;
 }


bool labyrinthe::getH_wall(int i, int j) const {
    return h_wall[width*j+i] ;
}


bool labyrinthe::getV_wall(int i, int j) const {
    return v_wall[j*width+i] ;
}

string labyrinthe::v_obstacle(bool b) const{
    return !b ? "|" :"" ;
}

string labyrinthe::h_obstacle(bool b) const{
    return !b ? "-" :"" ;
}

string labyrinthe::toString()const {

    ostringstream ss ;
    ss << "Labyrinthe :"<< endl ;

    // Dessiner la bordure supérieure
    ss<< "+" << std::string(width * 3 - 1, '-') << "+" << endl;

    for (int i =0 ; i<width;i++){
        ss <<h_obstacle(getH_wall(i,0)) ;

        for(int j = 0; j<width ;j++){

            ss << std::setw(2) << getGrid(i,j) << " ";
        }
        ss <<h_obstacle(getH_wall(i,width-1)) ;
    }
    //Bordure inférieure
    ss<< "+" << std::string(width * 3 - 1, '-') << "+" << endl;
    return ss.str() ;
}