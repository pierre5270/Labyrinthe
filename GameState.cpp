#include "GameState.hpp"

// Renvoie le nom de l'utilisateur
string Gamestate::getNom()const {
    return this->nom ;
}


//Renvoie le booléen désignant l'algo choisi
bool Gamestate::isAlgo()const {
    return algo;
}

//Remplie le nom de l'utilisateur
void Gamestate::SetNom(string n) {
    this->nom = n;
}

//modifie l'algorithme choisi
void Gamestate::SetAlgo(bool a) {
    this->algo = a;
}

bool Gamestate::can_move()const{
    return this->begin_ ;
}

void Gamestate::begin(){
    begin_ = true ;
}

bool Gamestate::is_end() const{
    return this->end_ ;
}

void Gamestate::end(){
    end_ = true ;
}

string Gamestate::toString()const{
    ostringstream ss ;
    ss << "Nom : " << this->nom << endl;
    ss << "Algorithme : " << ((this->algo)?"Algorithme d'Aldous Bröder":"Algorithme de fusion") << endl;

    return ss.str();
}