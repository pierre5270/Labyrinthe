#pragma once
#include "way.hpp"
#include <cassert>
#include <vector>
using namespace std ;

class block{
    protected :
        int x , y ;
        int ID ;
        int value ;
        bool visited ;
        double weight ;
        double estimate ;           // ? int�r�t
        vector<way*> neighboor ;

    public :

        // R�le : Constructeur qui initialise les membres de la classe "block" avec les valeurs fournies,
        // en initialisant �galement certains membres avec des valeurs par d�faut.
        block(int cord_x,int cord_y,int v):x(cord_x),y(cord_y){
            ID = v;                                             // valeur identit� du bloc
            value = ID;
            weight = 0.0;
            visited = false ;                                   // initialisation comme bloc non visit�
            neighboor = {} ;
            estimate = 0.0 ;

        }

        // R�le : Acc�der � la valeur de la coordonn�e abscisse du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        int getX()const{
            return x ;
        }

        // R�le : Acc�der � la valeur de la coordonn�e ordonn�e du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        int getY()const{
            return y ;
        }

        // R�le : Acc�der � la valeur du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        int getValue() const {
            return value ;
        }

        // R�le : Acc�der � la valeur de l'identit� du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        int getID()const {
            return ID ;
        }

        // R�le : V�rifier si le bloc est visit� ou non en retournant la valeur de la variable bool�enne "visited"
        bool getVisited()const {
            return visited ;
        }

        // R�le : Acc�der � la valeur du poids du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        double getWeight()const{
            return weight;
        }

        // R�le : Acc�der � la liste des valeurs ID des blocs voisins du bloc en question depuis l'ext�rieur de l'objet
        // sans permettre les modifications
        vector<way*> getNeighboor() {
            return neighboor ;
        }

        // R�le : Acc�der � la valeur estim� du bloc depuis l'ext�rieur de l'objet sans permettre les modifications
        double getEstimate()const{
            return estimate ;
        }

        // R�le : Modifier la valeur du bloc en lui attribuant une nouvelle valeur fournie en param�tre v
        void setValue(int v){
            value = v ;
        }

        // R�le : Modifier la valeur de l'identit� du bloc en lui attribuant une nouvelle valeur fournie en param�tre i
        void setID(int i){
            ID = i ;
        }

        // R�le : Modifier l'�tat de visite du bloc en lui attribuant l'�tat visit� par true
       void setVisited() {
            visited = true ;
        }

        //R�le : Modifier la liste des blocs voisins du bloc en question en lui attribuant le chemins d'un des blocs voisins fournies en param�tre e
        // L'ajout se fera dans l'ordre suivant :
        //0 : c�t� Est, 1 : c�t� Sud, 2 : c�t� Ouest, 3 : c�t� Nord
        void setNeighboor(way *e){
            neighboor.push_back(e) ;
        }

        // R�le : Modifier la valeur du poids du bloc en lui attribuant une nouvelle valeur fournie en param�tre x
        void setWeight(int x){
            weight = x ;
        }

        // R�le : Modifier la valeur estim� du bloc en lui attribuant une nouvelle valeur fournie en param�tre x
        void setEstimate(double x){
            estimate = x ;
        }

        // R�le : Obtenir une cha�ne de caract�res qui repr�sente certaines valeurs des membres de la classe block
        // valeur du bloc, liste des blocs voisins, son chemin
        string toString()const {
            ostringstream ss ;
            ss << "block value = "<< to_string(getValue())<< endl ;
            ss << "neighboors : " ;
            for(way *x : neighboor) ss << to_string(x->getDestination())<<", " ;
            return ss.str() ;
        }

        // R�le : Afficher un objet de la classe block dans un flux de sortie en utilisant son op�rateur de flux de sortie surcharg�
        friend ostream &operator<<(ostream &f , block b){
            return f << b.toString() ;
        }
} ;
