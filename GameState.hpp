#pragma once
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std ;

class Gamestate {
    private :
        string nom;

        bool algo ;             // Déclaration d'un booléen pour déterminer le choix de l'algorithme créant le labyrinthr : 0 pour fusion et 1 pour Aldous Brôder
        bool begin_ , tips ;    // Déclaration de booléens pour déterminer si le joueur a commencé et fini la partie ou non : 0 pour non, 1 pour oui
        
    public :

        // Rôle : Constructeur de la classe Gamestate qui initialise le nom du joueur et l'état du jeu tel que non commencé et non terminé
        Gamestate(string n="Joueur") : nom(n),begin_(false),tips(false){}

        // Rôle : Accéder au nom de l'utilisateur depuis l'extérieur de l'objet sans permettre les modifications
        string getNom()const {
            return this->nom ;
        }

        // Rôle : Vérifier si l'algorithme choisi est celui de fusion en retournant 0 ou bien d'Aldous Bröder en retournant 1
        bool isAlgo()const {
            return algo;
        }

        // Rôle : Statuer si la partie a commencé depuis l'extérieur de l'objet en renvoyant 1 si oui et 0 sinon
        void can_play(){
            begin_ = true ;
        }

        // Rôle : Vérifier si l'utilisateur a activé la solution ou pas
        bool is_activate() const{
            return this->tips ;
        }

        // Rôle : activenum class  solution de jeu=
        void activate_solution(){
            tips = true ;
        }

        // Rôle : Modifier la chaîne de caractère du nom de l'utilisateur en lui attribuant une nouvelle chaîne de caractère fournie en paramètre n
        void setNom(string n) {
            this->nom = n;
        }

        // Rôle : Modifier l'algorithme choisi pour créer le labyrinthe en lui attribuant un booléen fournie en paramètre a
        void setAlgo(bool a) {
            this->algo = a;
        }

        // Rôle : Vérifier si la partie a commencé depuis l'extérieur de l'objet sans permettre les modifications en renvoyant 1 si oui et 0 sinon
        bool can_move()const{
            return this->begin_ ;
        }

        // Rôle : Obtenir une chaîne de caractères qui représente les différentes valeurs des membres de la classe GameState
        // nom du joueur, nom de l'algorithme choisi pour créer le labyrinthe
        string toString()const{
            ostringstream ss ;
            ss << "Nom : " << this->nom << endl;
            ss << "Algorithme : " << ((this->algo)?"Algorithme d'Aldous Bröder":"Algorithme de fusion") << endl;
            return ss.str();
        }

        // Rôle : Afficher un objet de la classe GameState dans un flux de sortie en utilisant son opérateur de flux de sortie surchargé
        friend ostream &operator<<(ostream &f , Gamestate g){
            return f << g.toString() ;
        }
};