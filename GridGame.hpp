#pragma once
#include "labyrinthe.hpp"
#include "character.hpp"
#include <cmath>
#include <gtkmm-3.0/gtkmm.h>

#define X_GRID 600
#define Y_GRID 500


class GridGame : public Gtk::DrawingArea{

    private:


        //Les  coordonnées des cellules du quadrillage
        //vector<pair<int,int>> Coords;

        // Touche directionnelles du clavier
        GdkEventKey *Key_;


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


/*
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override{

            

            //add_events(Gdk::BUTTON_PRESS_MASK) et activation de la focalisation
            add_events(Gdk::KEY_PRESS_MASK);
            this->set_can_focus(true);
            this->set_focus_on_click(true);

            //Dimmensions des cellules
            int cell_x = X_GRID/l.getLength();
            int cell_y = Y_GRID/l.getWidth();


            
            // Dessin du rectangle de la grille de jeu
            cr->set_source_rgb(0.0, 0.0, 0.0); // Couleur noire
            cr->rectangle(0,0,X_GRID,Y_GRID);
            cr->fill();

            //Dessin de la case de départ
            cr->set_source_rgb(0.5, 0.0, 0.5); // Couleur violette
            cr->rectangle(cell_x/4,cell_y/4,cell_x/2,cell_y/2);
            cr->fill();

            //Dessin de la porte d'arrivée
            Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("exit.png");
            Glib::RefPtr<Gdk::Pixbuf> scaledImage = image->scale_simple(cell_x, cell_y, Gdk::INTERP_BILINEAR);
            Gdk::Cairo::set_source_pixbuf(cr,scaledImage, X_GRID-cell_x, Y_GRID-cell_y);
            cr->paint();

            //Dessin du grillage
            cr->set_source_rgb(0.5, 0.5, 0.5);
            for (int x = 0; x < X_GRID; x += cell_x) {
                cr->move_to(x, 0);
                cr->line_to(x, Y_GRID);
                cr->stroke();
            }
            //cr->line_to(X_GRID, Y_GRID);

            for (int y = 0; y < Y_GRID; y += cell_y) {
                cr->move_to(0, y);
                cr->line_to(X_GRID, y);
                cr->stroke();
            }
            cr->line_to(X_GRID, Y_GRID);


            //Création du personnage
            image = Gdk::Pixbuf::create_from_file("link.png");
            scaledImage = image->scale_simple(cell_x, cell_y, Gdk::INTERP_BILINEAR);
            Gdk::Cairo::set_source_pixbuf(cr,scaledImage, cell_x*this->player.getPosition_X(), cell_y*this->player.getPosition_Y());
            cr->paint();


            //Actualise les coordonnées du personnage
            if(this->begin){
                if (Key->keyval == GDK_KEY_Up && this->player.getPosition_Y() != 0) {
                    
                    this->player.setPosition_Y(this->player.getPosition_Y()-1);
                    //cout << "ça marche"<< endl;
                }
                else if (Key->keyval == GDK_KEY_Down && this->player.getPosition_Y() != (l.getWidth()-1)) {

                    this->player.setPosition_Y(this->player.getPosition_Y()+1); 
                    //cout << "ça marche"<< endl;

                }
                else if (Key->keyval == GDK_KEY_Left && this->player.getPosition_X() != 0) {

                    this->player.setPosition_X(this->player.getPosition_X()-1);
                    //cout << "ça marche"<< endl;

                }
                else if (Key->keyval == GDK_KEY_Right && this->player.getPosition_X() != (l.getLength()-1)) {

                    this->player.setPosition_X(this->player.getPosition_X()+1);
                    //cout << "ça marche"<< endl;

                } 
            }

            return true;
        }
*/

        /*

        bool on_key_press_event(GdkEventKey* event) override{

            this->Key = event;
            this->begin = true;


            queue_draw();

            return true ;
        }
        */
       
};