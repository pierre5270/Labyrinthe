#include "GridGame.hpp"

GridGame::GridGame(int length,int width,bool m) : l(new labyrinthe(length,width)),mode(m),begin(false),end(false){
    this->set_size_request(X_GRID, Y_GRID);

    //Gestion des évènements
    this->signal_draw().connect(sigc::mem_fun(*this,&GridGame::on_draw));
    this->signal_key_press_event().connect(sigc::mem_fun(*this ,&GridGame::on_key_press_event));

    //Sauvegarde des coordonnées des blocs du labyrinthe
    for (int i=0; i<length; i++) {
        for (int j=0; j<width; j++) {
            Coords.push_back(make_pair(j,i));
        }
    }
}

bool GridGame::getWin(){ 
    return this->end;
}

