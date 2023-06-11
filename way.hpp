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

        // R�le : Constructeur de la classe way qui initialise la source, la destination, la longueur de la voie et la disponibilit� du chemin
        way(int s ,int dest) :source(s),destination(dest){
            length = 1;                                     // Distance du chemin initialis�e � 1
            free_road = false;                              // Disponibilit� du chemin initialis�e occup�

        }
        // R�le : Acc�der � la valeur de la source du chemin depuis l'ext�rieur de l'objet sans permettre les modifications
        int getSource()const {
            return source ;
        }

        // R�le : Acc�der � la valeur de la destination du chemin depuis l'ext�rieur de l'objet sans permettre les modifications
        int getDestination()const{
            return destination ;
        }

        // R�le : Acc�der � la valeur de la longueur du chemin depuis l'ext�rieur de l'objet sans permettre les modifications
        int getLength()const{
            return length ;
        }

        // R�le : V�rifier si le chemin est ouvert ou non en retournant la valeur de la variable bool�enne "free_road"
        bool isopen()const{
            return free_road ;
        }

        // R�le : Modifier la valeur de la source du chemin en lui attribuant une nouvelle valeur fournie en param�tre s
        void setSource(int s){
            source = s ;
        }

        // R�le : Modifier la valeur de la destination du chemin en lui attribuant une nouvelle valeur fournie en param�tre d
        void setDestination(int d) {
            destination = d ;
        }

        // R�le : Modifier la valeur de la longueur du chemin en lui attribuant une nouvelle valeur fournie en param�tre w
        void setLength(int w){
            length = w ;
        }

        // R�le : Changer l'�tat de disponibilit� du chemin en la rendant ouvert, en modifiant la valeur de la variable "free_road" par "true"
        void open_wall(){
            free_road = true;
        }

        // R�le : Obtenir une cha�ne de caract�res qui repr�sente les diff�rentes valeurs des membres de la classe way
        // source, destination, poids, �tat de la voie
        string toString() const{
            ostringstream ss ;
            ss << " source_value :"<<to_string(getSource()) << endl ;
            ss << "destination value :"<<to_string(getDestination())<< endl ;
            ss << "weight :"<<to_string(getLength())<< endl ;
            ss << "wall :"<<to_string(isopen())<<endl ;
            return ss.str() ;
        }

        // R�le : Afficher un objet de la classe way dans un flux de sortie en utilisant son op�rateur de flux de sortie surcharg�
        friend ostream &operator<<(ostream &f , way e){
            return f << e.toString() ;
        }


};
