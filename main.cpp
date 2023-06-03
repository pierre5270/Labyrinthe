#include "labyrinthe.hpp"
#include "Vue_E.hpp"
#include <gtkmm-3.0/gtkmm.h>

int main (int argc,char *argv[]){
/*
    labyrinthe l = labyrinthe(5,5);
    l.fusion_labyrinth() ;
    //cout << l ;
    //l = new labyrinthe(4,4);
    //l.aldous_broder_labyrinth();
    
    cout << l ;
    l.print_V_wall();
    l.print_H_wall();
    //l.astar(0,21) ; il ne marche pas
    
*/
    auto app = Gtk::Application::create(argc,argv) ;
    //Vue_E vue(0) ;
    Vue_G vue(8,7);
    return app->run(vue) ;

    return EXIT_SUCCESS ;
}