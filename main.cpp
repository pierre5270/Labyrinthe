#include "labyrinthe.hpp"

int main (){

    labyrinthe l = labyrinthe(5,5);
    l.fusion_labyrinth() ;
    //cout << l ;
    //l = new labyrinthe(4,4);
    //l.aldous_broder_labyrinth();
    cout << "first"<< endl;
    cout << l ;
    l.print_V_wall();
    l.print_H_wall();
    


    return EXIT_SUCCESS ;
}