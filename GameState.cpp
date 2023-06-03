#include "GameState.hpp"

// Renvoie le nom de l'utilisateur
string Gamestate::getNom()const {
    return this->nom ;
}

//Renvoie la longueur de la grille constituant le labyrinthe
int Gamestate::getLength()const {
    return this->Lab_length;
}

//Renvoie la largeur de la grille constituant le labyrinthe
int Gamestate::getWidth()const {
    return this->Lab_width;
}

//Renvoie le booléen désignant l'algo choisi
bool Gamestate::isAlgo()const {
    return algo;
}

//Remplie le nom de l'utilisateur
void Gamestate::SetNom(string n) {
    this->nom = n;
}

// Remplie la longueur de la grille de jeu
void Gamestate::SetLength(int l) {
    this->Lab_length = l;
}

// Remplie la largeur de la grille de jeu
void Gamestate::SetWidth(int w) {
    this->Lab_width = w;
}

//modifie l'algorithme choisi
void Gamestate::SetAlgo(bool a) {
    this->algo = a;
}

string Gamestate::toString()const{
    ostringstream ss ;
    ss << "Nom : " << this->nom << endl;
    ss << "Longueur : " << this->Lab_length << endl;
    ss << "Largeur : " << this->Lab_width << endl;
    ss << "Algorithme : " << ((this->algo)?"Algorithme d'Aldous Bröder":"Algorithme de fusion") << endl;

    return ss.str();
}