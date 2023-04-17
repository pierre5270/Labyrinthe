#include "block.hpp"
#include "edge.hpp"

int main (){

    block b = block(5) ;
    b.setNeighboor(2,1) ;
    cout << b << endl ;

    edge e = edge(2,6) ;
    cout << e << endl ;
    return EXIT_SUCCESS ;
}