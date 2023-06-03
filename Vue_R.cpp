#include "Vue_R.hpp"

Vue_R::Vue_R(int) : label("Bravo !! Vous avez gagné !!"){

    grid.set_row_spacing(10);
    grid.set_column_spacing(10);

    label.set_halign(Gtk::ALIGN_CENTER);
    label.set_valign(Gtk::ALIGN_CENTER);
    label.set_hexpand(true);
            
    grid.attach(label,0,0,1,1);

    //Gestion des évènements
    this->bClose.signal_clicked().connect([this](){this->close();});

    //Ajout des éléments dans la fenêtre
    this->add(grid);
    this->show_all();

}
