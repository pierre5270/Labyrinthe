/*Cette classe à pour objectif de réunir les différents composants théoriques du labyrinthe dans un tout appelé graphe
*raison pour laquelle vous y retrouverez peut-être des redondances s'expliquant par la nécéssité de récuperer les informations
*des différentes classes
*/

#pragma once
#include "labyrinthe.hpp"
#include "character.hpp"

class Modele {
    private :

        labyrinthe l ;              // Labyrinthe de jeu
        character player ;          // Coordonnées du joueur

    public :

        // Rôle : Constructeur de la classe "Modele"
        Modele(){}

        // Rôle : Accéder à la valeur de la longueur du labyrinthe depuis l'extérieur de l'objet sans permettre les modifications
        int getDim_X() const {
            return l.getLength();
        }

        // Rôle : Accéder à la valeur de la largeur du labyrinthe depuis l'extérieur de l'objet sans permettre les modifications
        int getDim_Y() const {

            return l.getWidth();
        }

        // Rôle : Accéder à la valeur de l'abscisse de la position du joueur depuis l'extérieur de l'objet sans permettre les modifications
        int getPos_X() const {

            return player.getPosition_X();
        }

        // Rôle : Accéder à la valeur de l'ordonnée de la position du joueur depuis l'extérieur de l'objet sans permettre les modifications
        int getPos_Y() const {

            return player.getPosition_Y();
        }

        // Rôle : Modifier la valeur de la longueur du labyrinthe en lui attribuant une nouvelle valeur fournie en paramètre x
        void setDim_X(int x){
            l.setLength(x);
        }

        // Rôle : Modifier la valeur de la largeur du labyrinthe en lui attribuant une nouvelle valeur fournie en paramètre y
        void setDim_Y(int y){
            l.setWidth(y);
        }

        // Rôle : Modifier la valeur de l'abscisse de la position du joueur en lui attribuant une nouvelle valeur fournie en paramètre pos_x
        void setPos_X(int pos_x){
            player.setPosition_X(pos_x);
        }

        // Rôle : Modifier la valeur de l'ordonnée de la position du joueur en lui attribuant une nouvelle valeur fournie en paramètre pos_y
        void setPos_Y(int pos_y){
            player.setPosition_Y(pos_y);
        }

        // Rôle : Accéder au labyrinthe depuis l'extérieur de l'objet sans permettre les modifications
        labyrinthe getLabyrinthe() {
            return this-> l ;
        }

        // Rôle : Accéder au pion joueur depuis l'extérieur de l'objet sans permettre les modifications
        character getCharacter() {
            return this->player ;
        }

        // Rôle : Modifier le labyrinthe en lui attribuant un nouveau labyrinthe fourni en paramètre lab
        void setLabyrinthe(labyrinthe lab){
            this->l = lab;
        }
};
