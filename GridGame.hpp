#pragma once
#include "labyrinthe.hpp"
#include <cmath>
#include <gtkmm-3.0/gtkmm.h>

#define X_GRID 600
#define Y_GRID 500


class GridGame : public Gtk::DrawingArea{

    private:

        labyrinthe *l ; // Le labirynthe généré
        bool mode ; // 0 pour fusion et 1 pour l'Aldous Bröder
        bool begin , end; //Servent à déterminer si le jeu est terminé ou pas

        //Les coordonnées du personnage
        int X_C=0;
        int Y_C=0;

        //Les  coordonnées des cellules du quadrillage
        vector<pair<int,int>> Coords;

        // Touche directionnelles du clavier
        GdkEventKey *Key;


    public :

        GridGame(int length,int width,bool m=true);

        bool getWin();


        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override{

            

            //add_events(Gdk::BUTTON_PRESS_MASK) et activation de la focalisation
            add_events(Gdk::KEY_PRESS_MASK);
            this->set_can_focus(true);
            this->set_focus_on_click(true);

            //Dimmensions des cellules
            int cell_x = X_GRID/l->getLength();
            int cell_y = Y_GRID/l->getWidth();


            //Appliquer un type d'algorithme
            /*
            if(mode){
                l->aldous_broder_labyrinth() ;
                cout << "diag_one" <<endl;
            } else 
            {
                l->fusion_labyrinth();
                cout << "diag_two" <<endl;
            }
            
            cout << *l << endl;
            */
            
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
            Gdk::Cairo::set_source_pixbuf(cr,scaledImage, X_C*cell_x, Y_C*cell_y);
            cr->paint();


            //Actualise les coordonnées du personnage
            if(this->begin){
                if (Key->keyval == GDK_KEY_Up && Y_C != 0) {
                    X_C = X_C;
                    Y_C = Y_C - 1;
                    cout << "ça marche"<< endl;
                }
                else if (Key->keyval == GDK_KEY_Down && Y_C != (l->getWidth()-1)) {
                    X_C = X_C;
                    Y_C = Y_C + 1; 
                    cout << "ça marche"<< endl;
                }
                else if (Key->keyval == GDK_KEY_Left && X_C != 0) {
                    X_C = X_C - 1;
                    Y_C = Y_C; 
                    cout << "ça marche"<< endl;
                }
                else if (Key->keyval == GDK_KEY_Right && X_C != (l->getLength()-1)) {
                    X_C = X_C + 1;
                    Y_C = Y_C;
                    cout << "ça marche"<< endl;
                } 
            }

            return true;
        }


        bool on_key_press_event(GdkEventKey* event) override{

            this->Key = event;
            this->begin = true;
            queue_draw();

            //On marque la fin du jeu
            if(X_C ==l->getLength() && Y_C==l->getWidth()) this->end = true;

            return true ;
        }
        


        
};