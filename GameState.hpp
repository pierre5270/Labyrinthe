#pragma once
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std ;

class Gamestate {
    private :
        string nom;
        int Lab_length,Lab_width;
        bool algo ;// 0 pour fusion et 1 pour aldous Brôder

    public :
        Gamestate(){}
        Gamestate(string n,int l,int w) : nom(n),Lab_length(l),Lab_width(w){}

        // Renvoie le nom de l'utilisateur
        string getNom()const ;

        //Renvoie la longueur de la grille constituant le labyrinthe
        int getLength()const ;

        //Renvoie la largeur de la grille constituant le labyrinthe
        int getWidth()const ;

        //Renvoie le booléen désignant l'algo choisi
        bool isAlgo()const ;

        //Remplie le nom de l'utilisateur
        void SetNom(string n) ;

        // Remplie la longueur de la grille de jeu
        void SetLength(int l) ;

        // Remplie la largeur de la grille de jeu
        void SetWidth(int w) ;

        //modifie l'algorithme choisi
        void SetAlgo(bool a) ;

        //Ecris les statistiques sur la sortie standard
        string toString()const ;

        //Définition de l'oéprateur <<
        friend ostream &operator<<(ostream &f , Gamestate g){
            return f << g.toString() ;
        }

};