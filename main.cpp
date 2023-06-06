#include "labyrinthe.hpp"
#include "Vue.hpp"
#include <gtkmm-3.0/gtkmm.h>

int main (int argc,char *argv[]){

/*
    labyrinthe l = labyrinthe(8,5);
    l.fusion_labyrinth() ;
    //cout << l ;
    //l = new labyrinthe(4,4);
    //l.aldous_broder_labyrinth();
    
    cout << l ;
    //l.print_V_wall();
    //l.print_H_wall();
    //l.astar(0,21) ; //il ne marche pas
    */


    auto app = Gtk::Application::create(argc,argv) ;
    Vue v(0);
    //Vue_G vue(90,55);
    //Vue_R vue(0);
    return app->run(v) ;

    return EXIT_SUCCESS ;
}