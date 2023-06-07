#pragma once
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std ;

class Gamestate {
    private :
        string nom;

        bool algo ;// 0 pour fusion et 1 pour aldous Brôder
        bool begin_ , end_ ; // Déterminent si joueur à fini la partie ou non

    public :
        
        Gamestate(string n="Joueur") : nom(n),begin_(false),end_(false){}

        // Renvoie le nom de l'utilisateur
        string getNom()const ;

        //Renvoie le booléen désignant l'algo choisi
        bool isAlgo()const ;

        bool can_move()const ;

        void begin() ;

        bool is_end() const ;

        void end() ;

        //Remplie le nom de l'utilisateur
        void SetNom(string n) ;

        //modifie l'algorithme choisi
        void SetAlgo(bool a) ;

        //Ecris les statistiques sur la sortie standard
        string toString()const ;

        //Définition de l'oéprateur <<
        friend ostream &operator<<(ostream &f , Gamestate g){
            return f << g.toString() ;
        }

};