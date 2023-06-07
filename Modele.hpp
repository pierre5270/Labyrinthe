/*Cette classe à pour objectif de réunir les différents composants théoriques du labyrinthe dans un tout appelé graphe
*raison pour laquelle vous y retrouverez peut-être des redondances s'expliquant par la nécéssité de récuperer les informations
*des différentes classes
*/

#pragma once
#include "labyrinthe.hpp"
#include "character.hpp"

class Modele {
    private :

        labyrinthe l ; // labyrinthe de jeu
        character player ; //Coordonnée du jeu

    public :
        Modele(){};

        //Rôle : retourne la longueur du labyrinthe
        int getDim_X() const {

            return l.getLength();
        }

        //Rôle : retourne la largeur du labyrinthe
        int getDim_Y() const {

            return l.getWidth();
        }

        //Rôle : retourne la position en abscisse du joueur
        int getPos_X() const {

            return player.getPosition_X();
        }

        //Rôle : retourne la position en ordonnée du joueur
        int getPos_Y() const {

            return player.getPosition_Y();
        }

        //Rôle : Attribue la longueur du labyrinthe
        void setDim_X(int x){
            l.setLength(x);
        }

        //Rôle : Attribue la largeur du labyrinthe
        void setDim_Y(int y){
            l.setWidth(y);
        }

        //Rôle : Attribue la position en abscisse du joueur
        void setPos_X(int pos_x){
            player.setPosition_X(pos_x);
        }

        //Rôle : Attribue la position en ordonnée du joueur
        void setPos_Y(int pos_y){
            player.setPosition_Y(pos_y);
        }

};