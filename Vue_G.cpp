#include "Vue_G.hpp"

Vue_G::Vue_G(int length,int width):bTips("Solution"),gg(length,width){
            
    // Création de la vue
    this->set_title("A vous de joueur !!");
    this->set_border_width(5);
    this->set_default_size(X_GAME_SCREEN, Y_GAME_SCREEN );
    this->set_size_request(X_GAME_SCREEN, Y_GAME_SCREEN );


    grid.set_row_spacing(10);
    grid.set_column_spacing(10);

    //Remplissage de la fenêtre
    grid.attach(gg,0,0,1,1);
    grid.attach(bTips,0,1,1,1);
    grid.attach(this->Vue::bClose,0,2,1,1);
            
        
    //Ajout des éléments dans la fenêtre
    this->add(grid);
    this->show_all();

    //Gestion des évènements de la fenêtre
    this->bClose.signal_clicked().connect([this](){this->close();});
    //this->bTips.signal_clicked().connect([this](){this->on_button_clicked();}); // immplémenter la fonction traçant le chemin en utilisant l'algo d'astar

}
