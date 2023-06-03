#pragma once
#include "labyrinthe.hpp"
#include <gtkmm-3.0/gtkmm.h>

#define X_GRID 600
#define Y_GRID 500


class GridGame : public Gtk::DrawingArea{

    private:
        labyrinthe l ;

    public :

        GridGame(int length,int width);


        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override{

            // Appeler l'implémentation de base de on_draw()
            bool result = Gtk::DrawingArea::on_draw(cr);

            // Obtenir la taille de la zone de dessin
            Gtk::Allocation allocation = get_allocation();
            int width = allocation.get_width();
            int height = allocation.get_height();

            // Dessiner la grille
            cr->set_source_rgb(0.0, 0.0, 0.0); // Couleur noire

            int cell_x = X_GRID/l.getLength();
            int cell_y = Y_GRID/l.getWidth();
            for (int x = 0; x < width; x += cell_x) {
                cr->move_to(x, 0);
                cr->line_to(x, height);
                cr->stroke();
            }
            for (int y = 0; y < height; y += cell_y) {
                cr->move_to(0, y);
                cr->line_to(width, y);
                cr->stroke();
            }

            return result;
        }
        


        
};