#include "Vue.hpp"

Vue::Vue(int) : box(Gtk::ORIENTATION_VERTICAL), button(new Gtk::Button[2]), entry(new Gtk::Entry[3]), label(new Gtk::Label[4]),Algo(new Gtk::ToggleButton[2]){


    //On crée la box d'entrée du programme
    this->set_default_size(X_DEFAUT_SIZE, Y_DEFAUT_SIZE);
    this->set_title("Bienvenue dans le jeu du labyrinthe !!");

    //Esthétisme du bloc
    this->set_border_width(5);
    

            
    //On crée les boutons de la fenêtre douverture
    this->button[0] = Gtk::Button("Commencer");
    this->button[1] = Gtk::Button("Fermer");
    

    //Création des ToggleButtons
    this->Algo[0] = Gtk::ToggleButton("Algorithme de fusion");
    this->Algo[1] = Gtk::ToggleButton("Algorithme d'Aldous Bröder");


    //On crée les différents labels de tous le programme
    this->label[0] = Gtk::Label("Nom du joueur :");
    this->label[1] = Gtk::Label("Longueur :");
    this->label[2] = Gtk::Label("Largeur :");
    this->label[3] = Gtk::Label("Algorithme choisi :");
    
    //Allocation des widgets dans la box
    box.pack_start(this->label[0]); 
    box.pack_start(this->entry[0]);
    box.pack_start(this->label[1]);
    box.pack_start(this->entry[1]);
    box.pack_start(this->label[2]);
    box.pack_start(this->entry[2]);

    box.pack_start(this->label[3]);
    box.pack_start(this->Algo[0]);
    box.pack_start(this->Algo[1]);
    
    box.pack_start(this->button[0]);
    box.pack_start(this->button[1]);
    

    //Gestion des signaux
    this->button[0].signal_clicked().connect([&](){this->on_game();});
    this->button[1].signal_clicked().connect([&](){this->close();});
    this->Algo[0].signal_toggled().connect([&](){this->on_fusion();});    
    this->Algo[1].signal_toggled().connect([&](){this->on_aldous();});

    //Affichage de la fenêtre
    this->add(box);
    this->show_all();
}

void Vue::on_fusion() {

    this->G_info.SetAlgo(0);
    cout << "Fusion choisi "<< endl;
}

void Vue::on_aldous(){
    this->G_info.SetAlgo(1);
    cout <<"Aldous Bröder choisi " << endl;
}

void Vue::on_game(){

    //cout << "La suite très bientôt" << endl;

    bool info_add = !this->entry[0].get_text().empty() && !this->entry[1].get_text().empty() && !this->entry[2].get_text().empty() ;
    bool algo_select = this->Algo[0].get_active()^this->Algo[1].get_active() ;

    if(info_add && algo_select){

        //Enregistrement des paramètres de jeu
        this->G_info.SetNom(this->entry[0].get_text());
        this->G_info.SetLength(stoi(this->entry[1].get_text()));
        this->G_info.SetWidth(stoi(this->entry[2].get_text()));

        //On efface la fenêtre actuelle et on en affiche une nouvelle
        this->remove();
        this->add(*grid_mode(this->G_info.getLength(),this->G_info.getWidth(),this->G_info.isAlgo()));
        this->show_all();
        
    }


}

Gtk::Box* Vue::grid_mode(int l, int w, bool m){

    Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    this->set_size_request(X_GRID, Y_GRID);
    this->set_title("Bonne chance "+this->G_info.getNom());

    //Esthétisme du bloc
    this->set_border_width(5);

    //Génération de la grille de jeu
    GridGame *gg = new GridGame(l,w,m);

    //Bouton de menu
    Gtk::Button *Bclose =new Gtk::Button("Fermer");
    Gtk::Button *Btips = new Gtk::Button("Tips");

    //Affichage de la grille
    box->pack_start(*gg);
    box->pack_start(*Bclose);
    box->pack_start(*Btips);

    Bclose->signal_clicked().connect([&](){this->close();});
    Btips->signal_clicked().connect([&](){this->solution();});

    if(gg->getWin()){
        //On efface la fenêtre actuelle et on en affiche une nouvelle
        this->remove();
        this->add(*end_mode());
        this->show_all();
    }

    return box;
}

void Vue::solution(){}

Gtk::Box* Vue::end_mode(){

    Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

    //Agancement de la fenêtre
    this->set_title("Félicitations "+this->G_info.getNom()+" !!");
    this->set_border_width(5);
    this->set_size_request(X_RESULT, Y_RESULT );
    
    //Création des widgets
    Gtk::Label *label = new Gtk::Label("Vous avez gagné");
    Gtk::Button *Bclose =new Gtk::Button("Fermer");
    Gtk::Button *Bagain =new Gtk::Button("Recommencer");

    //Affichage de la grille
    box->pack_start(*label);
    box->pack_start(*Bclose);
    box->pack_start(*Bagain);

    Bclose->signal_clicked().connect([&](){this->close();});
    Bagain->signal_clicked().connect([&](){cout<<"Veuillez redémarer s'il vous plaît"<<endl;});

    return box ;



}