#pragma once
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std ;

class way{
    protected :

        int source;
        int destination;
        int length;
        bool free_road;


    public :

        // Rôle : Constructeur de la classe way qui initialise la source, la destination, la longueur de la voie et la disponibilité du chemin
        way(int s ,int dest) :source(s),destination(dest){
            length = 1;                                     // Distance du chemin initialisée à 1
            free_road = false;                              // Disponibilité du chemin initialisée occupé

        }
        // Rôle : Accéder à la valeur de la source du chemin depuis l'extérieur de l'objet sans permettre les modifications
        int getSource()const {
            return source ;
        }

        // Rôle : Accéder à la valeur de la destination du chemin depuis l'extérieur de l'objet sans permettre les modifications
        int getDestination()const{
            return destination ;
        }

        // Rôle : Accéder à la valeur de la longueur du chemin depuis l'extérieur de l'objet sans permettre les modifications
        int getLength()const{
            return length ;
        }

        // Rôle : Vérifier si le chemin est ouvert ou non en retournant la valeur de la variable booléenne "free_road"
        bool isopen()const{
            return free_road ;
        }

        // Rôle : Modifier la valeur de la source du chemin en lui attribuant une nouvelle valeur fournie en paramètre s
        void setSource(int s){
            source = s ;
        }

        // Rôle : Modifier la valeur de la destination du chemin en lui attribuant une nouvelle valeur fournie en paramètre d
        void setDestination(int d) {
            destination = d ;
        }

        // Rôle : Modifier la valeur de la longueur du chemin en lui attribuant une nouvelle valeur fournie en paramètre w
        void setLength(int w){
            length = w ;
        }

        // Rôle : Changer l'état de disponibilité du chemin en la rendant ouvert, en modifiant la valeur de la variable "free_road" par "true"
        void open_wall(){
            free_road = true;
        }

        // Rôle : Obtenir une chaîne de caractères qui représente les différentes valeurs des membres de la classe way
        // source, destination, poids, état de la voie
        string toString() const{
            ostringstream ss ;
            ss << " source_value :"<<to_string(getSource()) << endl ;
            ss << "destination value :"<<to_string(getDestination())<< endl ;
            ss << "weight :"<<to_string(getLength())<< endl ;
            ss << "wall :"<<to_string(isopen())<<endl ;
            return ss.str() ;
        }

        // Rôle : Afficher un objet de la classe way dans un flux de sortie en utilisant son opérateur de flux de sortie surchargé
        friend ostream &operator<<(ostream &f , way e){
            return f << e.toString() ;
        }


};
