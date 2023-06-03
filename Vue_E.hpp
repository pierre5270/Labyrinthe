#pragma once

#include "Vue.hpp"
#include "Vue_G.hpp"

#define X_SCREEN 500
#define Y_SCREEN 250

class Vue_E : public Vue {

    private :

        Gtk::Label *l_label ; //Label de la page
        Gtk::Entry *m_entry ; // Zone d'entrée des données du joueur
        Gtk::ToggleButton *Algo ; // Zone de sélection de l'algo 
        Gtk::Button bBegin ; //Bouton pour commencer la partie
        bool pressed ; //Confirmation de sélection d'un mode

    public :
        Vue_E(int);
        bool getPressed()const;
        void activate();
        void on_game();


};