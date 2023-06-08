#pragma once
#include "gtkmm-3.0/gtkmm.h"
#include "GameState.hpp"
#include "GridGame.hpp"
#include <iostream>
#include <string>

#define X_DEFAUT_SIZE 200
#define Y_DEFAUT_SIZE 200

#define X_RESULT 100
#define Y_RESULT 100

using namespace std ;

class Vue : public Gtk::Window {

    public :
        Gtk::Box box ; // Différentes affiches de notre programme
        Gtk::Button *button; // Différents boutons de notre programme
        Gtk::ToggleButton *Algo; // Toggle bouton de sélection de l'algorithme
        Gtk::Entry *entry; // Les différentes barres d'entrées des informations
        Gamestate G_info ;
        GridGame *grid;

    public :
        Vue() : box(Gtk::ORIENTATION_VERTICAL), button(new Gtk::Button[2]),Algo(new Gtk::ToggleButton[2]), entry(new Gtk::Entry[3]){

            G_info = Gamestate();
            grid = new GridGame();
            //On crée la box d'entrée du programme
            this->set_default_size(X_DEFAUT_SIZE, Y_DEFAUT_SIZE);
            this->set_resizable(true);
            this->set_title("Bienvenue dans le jeu du labyrinthe !!");

            //Esthétisme du bloc
            this->set_border_width(5);


        }

        ~Vue(){ this->close();}



        //Cette fonction retourne le bloc de fin du programme
        Gtk::Box* end_mode(){

            Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
            //box->set_spacing(10);

            //Agancement de la fenêtre
            this->set_title("Félicitations "+this->G_info.getNom()+" !!");
            //this->set_border_width(5);
            this->set_default_size(X_RESULT, Y_RESULT );
            this->set_size_request(X_RESULT, Y_RESULT );
            
    
            //Création des widgets
            Gtk::Label *label = new Gtk::Label("Vous avez gagné");
            Gtk::Button *Bclose =new Gtk::Button("Fermer");
            Gtk::Button *Bagain =new Gtk::Button("Recommencer");

            label->set_halign(Gtk::ALIGN_CENTER);
            label->set_valign(Gtk::ALIGN_CENTER);
            //label->set_hexpand(true);

            //Affichage de la grille
            box->pack_start(*label);
            Gtk::Box *hbox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
            hbox->pack_start(*Bclose);
            hbox->pack_start(*Bagain);
            box->pack_start(*hbox);

            Bclose->signal_clicked().connect([&](){this->close();});
            Bagain->signal_clicked().connect([&](){cout<<"Veuillez redémarer s'il vous plaît"<<endl;});

            return box ;
        }

};