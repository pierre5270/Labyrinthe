#pragma once
#include "Vue.hpp"
#include "Vue_R.hpp"
#include "GridGame.hpp"

#define X_GAME_SCREEN 800
#define Y_GAME_SCREEN 600

class Vue_G : public Vue {

    private :
        
        Gtk::Button bTips ; //Bouton pour la réponse
        GridGame gg; //Grille de jeu

    public :
        Vue_G(int length,int width);
};