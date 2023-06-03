#include "GridGame.hpp"

GridGame::GridGame(int length,int width) : l(length,width){
    this->signal_draw().connect(sigc::mem_fun(*this,&GridGame::on_draw));
    this->set_size_request(X_GRID, Y_GRID);
}

