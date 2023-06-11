#include "Controleur.hpp"
#include <gtkmm-3.0/gtkmm.h>

int main (int argc,char *argv[]){

  
  /*labyrinthe l = labyrinthe(3,3);
  l=l.fusion_labyrinth() ;
  //cout << l ;
  cout << "hello"<< endl;
  //cout << l.Edgelist().size() <<endl;
  //l = l.aldous_broder_labyrinth();
  cout << l ;
  l.print_V_wall();
  l.print_H_wall();
  l.astar(0,8) ; //il ne marche pas
  */

  
  auto app = Gtk::Application::create(argc,argv) ;

  Modele *m = new Modele();
  Vue *v = new Vue ();
  Controleur *C = new Controleur(m,v);
    
  return app->run(*v) ;

  delete C ;
  
  return EXIT_SUCCESS ;
}