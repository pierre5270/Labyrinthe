#include "Vue_E.hpp"

Vue_E::Vue_E(int):l_label(new Gtk::Label [3]),m_entry(new Gtk::Entry[3]),Algo(new Gtk::ToggleButton[2]),bBegin("Commencer"),pressed(0){

    // Création de la vue
    this->set_title("Bienvenue dans le Jeu Labyrinthe_Gtk !");
    this->set_border_width(5);
    this->set_default_size(X_SCREEN, Y_SCREEN);
    this->set_size_request(X_SCREEN, Y_SCREEN);

    //Remplissage de la fenêtre

    //Définition des labels
    this->l_label[0] = Gtk::Label ("Nom du joueur:");
    this->l_label[1] = Gtk::Label ("Dimension :");
    this->l_label[2] = Gtk::Label ("Algorithme :");

    //Classement des blocs dans la grille
    grid.set_column_spacing(10);
    grid.set_row_spacing(10);

    //Rangement des widgets dans la grille
    grid.attach(this->l_label[0],0,0,1,1);//Nom Joueur
    grid.attach(this->l_label[1],0,1,1,1);//Dimension
    grid.attach(this->l_label[2],0,2,1,1); //Algo

    grid.attach(this->m_entry[0],1,0,1,1); //nom du joueur
    grid.attach(this->m_entry[1],1,1,1,1); //Dimension_one
    grid.attach(this->m_entry[2],2,1,1,1); //Dimension_two

    this->Algo[0] = Gtk::ToggleButton("Algorithme_fusion");
    this->Algo[1] = Gtk::ToggleButton("Algorithme_aldous_Brôder");

    grid.attach(this->Algo[0],1,2,1,1);
    grid.attach(this->Algo[1],2,2,1,1);

    grid.attach(this->Vue::bClose,0,3,1,1);
    grid.attach(bBegin,1,4,1,1);
    grid.attach(bClose,2,4,1,1);

    //Ajout des éléments dans la fenêtre
    this->add(grid);
    this->show_all();

    //Gestion des évènements de la fenêtre
    //this->signal_delete_event().connect(sigc::mem_fun(*this, &Vue_E::delete_window));
    this->bBegin.signal_clicked().connect([this](){this->on_game();});
    this->bClose.signal_clicked().connect([this](){this->close();});
    this->m_entry[0].signal_changed().connect([this](){this->Vue::G_info.SetNom(this->m_entry[0].get_text());}); //Récupère le nom du joueur
    this->m_entry[1].signal_changed().connect([this](){this->Vue::G_info.SetLength(stoi(this->m_entry[1].get_text()));});
    this->m_entry[2].signal_changed().connect([this](){this->Vue::G_info.SetWidth(stoi(this->m_entry[2].get_text()));});
    this->Algo[0].signal_toggled().connect([this](){this->Vue::G_info.SetAlgo(0),this->activate();});
    this->Algo[1].signal_toggled().connect([this](){this->Vue::G_info.SetAlgo(1),this->activate();});
            
}

bool Vue_E:: getPressed()const{
    return this->pressed;
}

void Vue_E::activate(){
    pressed = !pressed ;
}

void Vue_E::on_game(){

    //cout <<this->Vue::G_info<< endl ;
    
    if(!this->m_entry[0].get_text().empty() && !this->m_entry[1].get_text().empty() && this->getPressed() ){
        //this->~Vue();
        //auto app = Gtk::Application::create() ;
       //Vue_G VueG (G_info.getLength(),G_info.getWidth());

        //app->run(VueG);
        
        
    }
    //this->on_button_clicked();
}