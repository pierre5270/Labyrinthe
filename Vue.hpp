#pragma once
#include <gtkmm-3.0/gtkmm.h>
#include "GameState.hpp"
#include <iostream>

using namespace std ;


class Vue : public Gtk::Window {

    protected :
        Gtk::Grid grid;
        Gtk::Button bClose;
        Gamestate G_info;

    public :
        Vue(): bClose("Fermer"){
            
        }
        ~Vue () {this->close();};

};