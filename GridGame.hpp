#pragma once
#include "labyrinthe.hpp"
#include "character.hpp"
#include <cmath>
#include <gtkmm-3.0/gtkmm.h>

#define X_GRID 600
#define Y_GRID 500


class GridGame : public Gtk::DrawingArea{

    private:

        GdkEventKey *Key_;
    public :
        bool move_up = true;
        bool move_down = true;
        bool move_left = true;
        bool move_right = true;


    public :

        //Constructeur
        GridGame(){
            this->set_size_request(X_GRID, Y_GRID);
        }

        GdkEventKey *get_key(){
            return Key_ ;
        }

        void set_key(GdkEventKey *Key){
            this->Key_ = Key ;
        }

       
};