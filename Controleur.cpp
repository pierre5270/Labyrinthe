#include "Controleur.hpp"

Controleur::Controleur(Modele *m,Vue *V){

    m_ = m;
	interface = V;

    this->on_setting();

    cout << "Lancement du jeu en cours ...." << endl;

}

Vue *Controleur::VueGraphique(){

    return this->interface;
}

void Controleur:: on_setting(){

    //On crée les boutons de la fenêtre douverture
    this->interface->button[0] = Gtk::Button("Commencer");
    this->interface->button[1] = Gtk::Button("Fermer");
    

    //Création des ToggleButtons
    this->interface->Algo[0] = Gtk::ToggleButton("Algorithme de fusion");
    this->interface->Algo[1] = Gtk::ToggleButton("Algorithme d'Aldous Bröder");


    //On crée les différents labels de tous le programme
    Gtk::Label *lab_0 = new Gtk::Label("Nom du joueur :");
    Gtk::Label *lab_1 = new Gtk::Label("Longueur :");
    Gtk::Label *lab_2 = new Gtk::Label ("Largeur :");
    Gtk::Label *lab_3 = new Gtk::Label("Algorithme choisi :");
    
    //Allocation des widgets dans la box
    this->interface->box.pack_start(*lab_0); 
    this->interface->box.pack_start(this->interface->entry[0]);
    this->interface->box.pack_start(*lab_1);
    this->interface->box.pack_start(this->interface->entry[1]);
    this->interface->box.pack_start(*lab_2);
    this->interface->box.pack_start(this->interface->entry[2]);

    this->interface->box.pack_start(*lab_3);
    this->interface->box.pack_start(this->interface->Algo[0]);
    this->interface->box.pack_start(this->interface->Algo[1]);
    
    this->interface->box.pack_start(this->interface->button[0]);
    this->interface->box.pack_start(this->interface->button[1]);
    

    //Gestion des signaux
    this->interface->button[0].signal_clicked().connect([&](){this->on_game();});
    this->interface->button[1].signal_clicked().connect([&](){this->interface->close();});
    this->interface->Algo[0].signal_toggled().connect([&](){this->on_fusion();});    
    this->interface->Algo[1].signal_toggled().connect([&](){this->on_aldous();});

    //Affichage de la fenêtre
    this->interface->add(this->interface->box);
    this->interface->show_all();

}

void Controleur::on_fusion() {

    this->interface->G_info.SetAlgo(0);
    //cout << "Fusion choisi "<< endl;
}

void Controleur::on_aldous(){
    this->interface->G_info.SetAlgo(1);
    //cout <<"Aldous Bröder choisi " << endl;
}

void Controleur::on_game(){

    //cout << "La suite très bientôt" << endl;

    bool info_add = !this->interface->entry[0].get_text().empty() && !this->interface->entry[1].get_text().empty() && !this->interface->entry[2].get_text().empty() ;
    bool algo_select = this->interface->Algo[0].get_active()^this->interface->Algo[1].get_active() ;

    if(info_add && algo_select){

        //Enregistrement des paramètres de jeu
        this->interface->G_info.SetNom(this->interface->entry[0].get_text());
        this->m_->setDim_X(stoi(this->interface->entry[1].get_text()));
        this->m_->setDim_Y(stoi(this->interface->entry[2].get_text()));
        

        //On efface la fenêtre actuelle et on en affiche une nouvelle

        this->interface->remove();
        this->interface->grid = new GridGame();
        Gtk::Box *box_two = grid_mode(this->interface->grid);
        this->interface->add(*box_two);
        this->interface->show_all();

        
    }
}

Gtk::Box* Controleur::grid_mode(GridGame *g){

    Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    this->interface->set_title("Bonne chance "+this->interface->G_info.getNom());

    //Esthétisme du bloc
    this->interface->set_border_width(5);

    //Bouton de menu
    Gtk::Button *Bclose =new Gtk::Button("Fermer");
    Gtk::Button *Btips = new Gtk::Button("Tips");

    //Affichage de la grille
    box->pack_start(*g);
    box->pack_start(*Bclose);
    box->pack_start(*Btips);


    //Gestion des évènements
    this->interface->grid->signal_draw().connect(sigc::mem_fun(*this,&Controleur::on_draw));
    this->interface->grid->signal_key_press_event().connect(sigc::mem_fun(*this ,&Controleur::on_key_press_event));
    Bclose->signal_clicked().connect([&](){this->interface->close();});
    Btips->signal_clicked().connect([&](){this->solution();});
    g->signal_draw().connect(sigc::mem_fun(*this, &Controleur::on_draw_end));
    //this->game_area = game_area ;

    return box;
}

void Controleur::solution(){}

bool Controleur::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){

    //add_events(Gdk::BUTTON_PRESS_MASK) et activation de la focalisation
    this->interface->grid->add_events(Gdk::KEY_PRESS_MASK);
    this->interface->grid->set_can_focus(true);
    this->interface->grid->set_focus_on_click(true);

    //Dimmensions des cellules
    int cell_x = X_GRID/this->m_->getDim_X();
    int cell_y = Y_GRID/this->m_->getDim_Y();


            
    // Dessin du rectangle de la grille de jeu
    cr->set_source_rgb(0.0, 0.0, 0.0); // Couleur noire
    cr->rectangle(0,0,X_GRID,Y_GRID);
    cr->fill();

    //Dessin de la case de départ
    cr->set_source_rgb(0.5, 0.0, 0.5); // Couleur violette
    cr->rectangle(cell_x/4,cell_y/4,cell_x/2,cell_y/2);
    cr->fill();

    //Dessin de la porte d'arrivée
    Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("exit.png");
    Glib::RefPtr<Gdk::Pixbuf> scaledImage = image->scale_simple(cell_x, cell_y, Gdk::INTERP_BILINEAR);
    Gdk::Cairo::set_source_pixbuf(cr,scaledImage, X_GRID-cell_x, Y_GRID-cell_y);
    cr->paint();

    //Dessin du grillage
    cr->set_source_rgb(0.5, 0.5, 0.5);
    for (int x = 0; x < X_GRID; x += cell_x) {
        cr->move_to(x, 0);
        cr->line_to(x, Y_GRID);
        cr->stroke();
    }
    //cr->line_to(X_GRID, Y_GRID);

    for (int y = 0; y < Y_GRID; y += cell_y) {
        cr->move_to(0, y);
        cr->line_to(X_GRID, y);
        cr->stroke();
    }
    cr->line_to(X_GRID, Y_GRID);


    //Création du personnage
    image = Gdk::Pixbuf::create_from_file("link.png");
    scaledImage = image->scale_simple(cell_x, cell_y, Gdk::INTERP_BILINEAR);
    Gdk::Cairo::set_source_pixbuf(cr,scaledImage, cell_x*this->m_->getPos_X(), cell_y*this->m_->getPos_Y());
    cr->paint();


    //Actualise les coordonnées du personnage
    if(this->interface->G_info.can_move()){
        if (this->interface->grid->get_key()->keyval == GDK_KEY_Up && this->m_->getPos_Y()!= 0) {
                    
            this->m_->setPos_Y(this->m_->getPos_Y()-1);
            //cout << "ça marche"<< endl;
        }
        else if (this->interface->grid->get_key()->keyval == GDK_KEY_Down && this->m_->getPos_Y() != (this->m_->getDim_Y()-1)) {

            this->m_->setPos_Y(this->m_->getPos_Y()+1); 
            //cout << "ça marche"<< endl;

        }
        else if (this->interface->grid->get_key()->keyval == GDK_KEY_Left && this->m_->getPos_X() != 0) {

            this->m_->setPos_X(this->m_->getPos_X()-1);
            //cout << "ça marche"<< endl;

        }
        else if (this->interface->grid->get_key()->keyval == GDK_KEY_Right && this->m_->getPos_X() != (this->m_->getDim_X()-1)) {

            this->m_->setPos_X(this->m_->getPos_X()+1);
            //cout << "ça marche"<< endl;

        } 
    }

    return true ;
}


bool Controleur::on_key_press_event(GdkEventKey* event) {

    this->interface->grid->set_key(event);
    this->interface->G_info.begin();


    this->interface->grid->queue_draw();

    return true ;
}

bool Controleur::on_draw_end(const Cairo::RefPtr<Cairo::Context>& cr){

    if(this->m_->getPos_X() ==this->m_->getDim_X()-1 && this->m_->getPos_Y()==this->m_->getDim_Y()-1){
        this->interface->remove();
        Gtk::Box *box_end = this->interface->end_mode() ;
        this->interface->add(*box_end);
        this->interface->show_all();
    }
    return true ;
}