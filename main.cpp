#include "labyrinthe.hpp"

int main (){

    labyrinthe l (5) ;
    l.init_labyrinthe() ;
    cout << l << endl ;
    /*
    block b = block(5) ;
    b.setNeighboor(2,1) ;
    cout << b << endl ;*/

    /*edge e = edge(2,6) ;
    cout << e << endl ;*/
    return EXIT_SUCCESS ;
}