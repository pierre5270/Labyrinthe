#pragma once
#include <iostream>
#include "Modele.hpp"
#include "Vue.hpp"

class Controleur {
    private :
        Modele *m_;
        Vue *interface;

    public :

        // Rôle : Constructeur de la classe Controleur qui initialise le modèle, la vue, ...
        Controleur(Modele *m,Vue *V){
            m_ = m;
            interface = V;
            this->on_setting();
            cout << "Lancement du jeu en cours ...." << endl;
        }

        // Rôle : Ouvrir la fenêtre de départ en créant l'initialisation des boutons, des labels, de la mise en forme des blocs, des actions, et de l'affichage
        void on_setting(){
            this->interface->button[0] = Gtk::Button("Commencer");                                          // Création du bouton Commencer de la fenêtre d'ouverture
            this->interface->button[1] = Gtk::Button("Fermer");                                             // Création du bouton Fermer de la fenêtre d'ouverture
            this->interface->Algo[0] = Gtk::ToggleButton("Algorithme de fusion");                           // Création du bouton Algorithme de fusion pouvant être coché et décoché
            this->interface->Algo[1] = Gtk::ToggleButton("Algorithme d'Aldous Bröder");                     // Création du bouton Algorithme d'Aldous Bröder pouvant être coché et décoché
            Gtk::Label *lab_0 = new Gtk::Label("Nom du joueur :");                                          // Création d'une étiquette Nom du joueur
            Gtk::Label *lab_1 = new Gtk::Label("Longueur :");                                               // Création d'une étiquette Longueur
            Gtk::Label *lab_2 = new Gtk::Label ("Largeur :");                                               // Création d'une étiquette Largeur
            Gtk::Label *lab_3 = new Gtk::Label("Algorithme choisi :");                                      // Création d'une étiquette Algorithme choisi
            this->interface->box.pack_start(*lab_0);                                                        // Allocation de l'étiquette lab_0 au début de la boîte (en haut)
            this->interface->box.pack_start(this->interface->entry[0]);                                     // Allocation du champ entré par le joueur pour donner son nom à la suite dans la boîte
            this->interface->box.pack_start(*lab_1);                                                        // Allocation de l'étiquette lab_1 à la suite dans la boîte
            this->interface->box.pack_start(this->interface->entry[1]);                                     // Allocation du champ entré par le joueur pour donner la longueur du labyrinthe à la suite dans la boîte
            this->interface->box.pack_start(*lab_2);                                                        // Allocation de l'étiquette lab_2 à la suite dans la boîte
            this->interface->box.pack_start(this->interface->entry[2]);                                     // Allocation du champ entré par le joueur pour donner la largeur du labyrinthe à la suite dans la boîte
            this->interface->box.pack_start(*lab_3);                                                        // Allocation de l'étiquette lab_3 à la suite dans la boîte
            this->interface->box.pack_start(this->interface->Algo[0]);                                      // Allocation du bouton Algorithme de fusion à la suite dans la boîte
            this->interface->box.pack_start(this->interface->Algo[1]);                                      // Allocation du bouton Aldous Broder à la suite dans la boîte
            this->interface->box.pack_start(this->interface->button[0]);                                    // Allocation du bouton Commencer à la suite dans la boîte
            this->interface->box.pack_start(this->interface->button[1]);                                    // Allocation du bouton Fermer à la suite dans la boîte
            this->interface->button[0].signal_clicked().connect([&](){this->on_game();});                   // Association de la configuration du jeu lorsque l'on clique sur le bouton commencer
            this->interface->button[1].signal_clicked().connect([&](){this->interface->close();});          // Association de la fermeture de la boîte lorsque l'on clique sur le bouton commencer
            this->interface->Algo[0].signal_toggled().connect([&](){this->interface->G_info.setAlgo(0);});  // Association de l'algorithme fusion via un booléen lorsque l'on clique sur le bouton Algorithme de fusion
            this->interface->Algo[1].signal_toggled().connect([&](){this->interface->G_info.setAlgo(1);});  // Association de l'algorithme d'Aldous Bröder via un booléen lorsque l'on clique sur le bouton Algorithme d'Aldous Bröder
            this->interface->add(this->interface->box);                                                     // Intégration de la box que l'on vient de paramétrer à une fenêtre
            this->interface->show_all();                                                                    // Affichage de la fenêtre sur l'interface graphique
        }

        // Rôle : Destructeur de la classe Controleur
        ~Controleur(){}

        // Rôle : Accéder à l'interface graphique du jeu depuis l'extérieur de l'objet sans permettre les modifications
        Vue *VueGraphique(){
            return this->interface;
        }

        // Rôle : Vérifier les informations du jeu, de la création du labyrinthe, de l'enregistrement des paramètres de jeu et de la mise à jour de l'interface graphique et utilisateur
        void on_game(){
                                                                                                            // Vérifier si les champs de l'interface utilisateur sont vides ou pas
                                                                                                            // Si tous les champs sont remplis, info_add est définie sur true, sinon sur false
            bool info_add = !this->interface->entry[0].get_text().empty() && !this->interface->entry[1].get_text().empty() && !this->interface->entry[2].get_text().empty() ;
            bool algo_select = this->interface->Algo[0].get_active()^this->interface->Algo[1].get_active(); // Vérifier si un seul algorithme est sélectionné : true si oui, false sinon
            if(info_add && algo_select){                                                                    // Vérifier si les champs sont saisis par le joueur et si un seul algorithme est sélectionné
                this->interface->G_info.setNom(this->interface->entry[0].get_text());                       // Enregistrer le nom du joueur via SetNom()
                this->m_->setDim_X(stoi(this->interface->entry[1].get_text()));                             // Enregistrer l'abscisse de la position du joueur via setDim_X()
                this->m_->setDim_Y(stoi(this->interface->entry[2].get_text()));                             // Enregistrer l'ordonnée de la position du joueur via setDim_Y()
                                                                                                            // Créer un objet labyrinthe en fonction de l'algorithme sélectionné
                labyrinthe l = (!this->interface->G_info.isAlgo())? labyrinthe(this->m_->getDim_X(),this->m_->getDim_Y()).fusion_labyrinth() : labyrinthe(this->m_->getDim_X(),this->m_->getDim_Y()).aldous_broder_labyrinth();
                this->m_->setLabyrinthe(l);                                                                 // Définir le labyrinthe généré comme labyrinthe du modèle de jeu m_
                //l.printMaze();                                                                              // Afficher la représentation textuelle du labyrinthe dans la console
                //l.print_V_wall();                                                                           // Afficher les murs verticaux du labyrinthe dans la console
                //l.print_H_wall();                                                                           // Afficher les murs horizontaux du labyrinthe dans la console
                this->interface->remove();                                                                  // Supprimer la fenêtre actuelle
                this->interface->grid = new GridGame();                                                     // Création d'une nouvelle grille de jeu
                Gtk::Box *box_two = grid_mode(this->interface->grid);                                       // Afficher la nouvelle grille de jeu
                this->interface->add(*box_two);                                                             // Intégration de la box que l'on vient de paramétrer à une fenêtre
                this->interface->show_all();                                                                // Affichage de la fenêtre sur l'interface graphique
            }
        }


        // Rôle : Modifier la grille de jeu en fonction du paramètre fourni en entrée g qui indique la taille de la grille choisi par l'utilisateur
        Gtk::Box* grid_mode(GridGame *g){
            Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);                                                        // Création d'une nouvelle boîte verticale
            this->interface->set_title("Bonne chance "+this->interface->G_info.getNom());                                   // Affiche un message d'encouragement avec le nom du joueur
            this->interface->set_border_width(5);                                                                           // Largeur de la bordure de la fenêtre définie sur 5
            Gtk::Button *Bclose =new Gtk::Button("Fermer");                                                                 // Création du bouton Fermer de la boîte
            Gtk::Button *Btips = new Gtk::Button("Tips");                                                                   // Création du bouton Tips donnant des aides sur le chemin à suivre dans le labyrinthe
            box->pack_start(*g);                                                                                            // Allocation de la grille donnée en paramètre au début de la boîte (en haut)
            box->pack_start(*Bclose);                                                                                       // Allocation du bouton Fermer à la suite dans la boîte
            box->pack_start(*Btips);                                                                                        // Allocation du bouton Tips à la suite dans la boîte
            this->interface->grid->signal_draw().connect(sigc::mem_fun(*this,&Controleur::on_draw));                        // Effectuer le dessin de la grille de jeu
            this->interface->grid->signal_key_press_event().connect(sigc::mem_fun(*this ,&Controleur::on_key_press_event)); // Récupérer les informations du clavier
            Bclose->signal_clicked().connect([&](){this->interface->close();});                                             // Association de la fermeture de la boîte lorsque l'on clique sur le bouton Fermer
            Btips->signal_clicked().connect([&](){this->solution();});                           // Association de la solution via l'algorithme Astar du labyrinthe de la boîte lorsque l'on clique sur le bouton Tips
            return box;
        }

        // Rôle : Dessiner la grille de jeu sur l'interface graphique en fonction du paramètre fourni en entrée cr
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr){
            
            //Activation des touches de clavier
            this->interface->grid->add_events(Gdk::KEY_PRESS_MASK);                                                                         // Associer la pression de touche pour se déplacer sur la grille du jeu
            this->interface->grid->set_can_focus(true);                                                                                     // Recevoir le focus sur la grille de jeu et réagir aux événements clavier
            this->interface->grid->set_focus_on_click(true); 

            // Mise au point automatique de de la grille de jeu lors des clics
            int cell_x = X_GRID/this->m_->getDim_X();                                                                                       // Dimension de l'abscisse d'un bloc en fonction des dimensions de la grille
            int cell_y = Y_GRID/this->m_->getDim_Y(); 

            // Dimension de l'ordonnée d'un bloc en fonction des dimensions de la grille
            cr->set_source_rgb(0.0, 0.0, 0.0);                                                                                              // Définir la couleur de dessin actuelle du contexte sur le noir
            cr->rectangle(0,0,X_GRID,Y_GRID);                                                                                               // Dessiner rectangle de grille de jeu rempli : (0,0), coin supérieur gauche du rectangle, dimensions => X_GRID et Y_GRID
            cr->fill();                                                                                                                     // Remplir le rectangle avec la couleur actuelle du contexte
            cr->set_source_rgb(0.5, 0.0, 0.5);                                                                                              // Bloc source rempli par la couleur violette
            cr->rectangle(cell_x/4,cell_y/4,cell_x/2,cell_y/2);                                                                             // Dessiner un rectangle rempli bloc de départ de coordonnées : coin supérieur gauche du rectangle et dimensions
            cr->fill();                                                                                                                     // Remplir le rectangle avec la couleur actuelle du contexte



            cr->set_source_rgb(0.5, 0.5, 0.5);                                                                                              // Lignes de la grille dessinées en couleur grise
            for (int x = 0; x < X_GRID; x += cell_x) {                                                                                      // Lignes verticales dessinées à intervals réguliers en fonction des dimensions des cellules de la grille
                cr->move_to(x, 0);
                cr->line_to(x, Y_GRID);
                cr->stroke();
            }
            for (int y = 0; y < Y_GRID; y += cell_y) {                                                                                      // Lignes horizontales dessinées à intervals réguliers en fonction des dimensions des cellules de la grille
                cr->move_to(0, y);
                cr->line_to(X_GRID, y);
                cr->stroke();
            }
            cr->line_to(X_GRID, Y_GRID);                                                                                                    // Prochaine ligne tracée commence à la position actuelle et se termine à cette destination
            labyrinthe l = this->m_->getLabyrinthe();                                                                                       // Récupère le labyrinthe actuel à partir du modèle du jeu
            vector<pair<int,int>> erasewalls = this->m_->getLabyrinthe().EraseWall();                                                       // Récupère les informations sur les murs à effacer dans le labyrinthe à partir du modèle de jeu
            cr->set_operator(Cairo::OPERATOR_CLEAR);                                                                                        // Les futurs dessins vont effacer plutôt que peindre
        
            block *b1 ;
            
            for( auto it = erasewalls.begin();it!=erasewalls.end();it++){
                b1 = l.getBlock(it->first);                                                                                                   // Premier bloc des deux blocs adjacents d'un mur à effacer                                                                                              // Second bloc des deux blocs adjacents d'un mur à effacer
                if(abs(it->first-it->second)==1){
                    cr->move_to(cell_x*(b1->getX()+1),cell_y*b1->getY());                                                                   // Tracer ligne verticale à effacer entre les blocs b1 et b2 adjacents en horizontal
                    cr->line_to(cell_x*(b1->getX()+1),cell_y*(b1->getY()+1));
                    cr->stroke();
                }
                else{
                    cr->move_to(cell_x*b1->getX(),cell_y*(b1->getY()+1));                                                                   // Tracer ligne horizontale à effacer entre les blocs b1 et b2 adjacents en vertical
                    cr->line_to(cell_x*(b1->getX()+1),cell_y*(b1->getY()+1));
                    cr->stroke();
                }
                
            }
            cr->set_operator(Cairo::OPERATOR_OVER);                                                                                    // Rétablissement des dessins à la normale : superposition des couleurs plutôt qu'effacer lignes

            if(this->interface->G_info.is_activate()){
                deque<int> path = l.astar(0,l.cord(this->m_->getDim_X()-1,this->m_->getDim_Y()-1));     // Solution du labyrinthe astar
                cr->set_source_rgb(0.5, 0.0, 0.5);
                while(path.size()>=2){
                    int id_1 = path.front();
                    int id_2 = path[1];
                    block *b1 = l.getBlock(id_1) ;
                    block *b2 = l.getBlock(id_2) ;
                    cr->move_to(cell_x*(b1->getX()+0.5),cell_y*(b1->getY()+0.5)) ;
                    cr->line_to(cell_x*(b2->getX()+0.5),cell_y*(b2->getY()+0.5)) ;
                    cr->stroke() ;
                    path.pop_front();
                    
                }
            }

            int error_x = (cell_x/10) ;                                                                                                     // Calculer l'erreur en X : max 1/10ème des dimensions des cellules de la grille
            int error_y = (cell_y/10) ;                                                                                                    // Calculer l'erreur en Y : max 1/10ème des dimensions des cellules de la grille

            Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("pictures/link.png");                                                                     // Charger une image du joueur à partir d'un fichier
            Glib::RefPtr<Gdk::Pixbuf> scaledImage = image->scale_simple(cell_x-error_x, cell_y-error_y, Gdk::INTERP_BILINEAR);                                        // Mise à l'échelle en utilisant les dimensions des cellules de la grille
            Gdk::Cairo::set_source_pixbuf(cr,scaledImage, cell_x*this->m_->getPos_X()+error_x/2, cell_y*this->m_->getPos_Y()+error_y/2);    // Dessin à l'emplacement actuel du joueur dans la grille
            cr->paint();

            image = Gdk::Pixbuf::create_from_file("pictures/exit.png");                                           // Charger une image de la porte d'arrivée à partir d'un fichier
            scaledImage = image->scale_simple(cell_x, cell_y, Gdk::INTERP_BILINEAR);                              // Mise à l'échelle de l'image importée
            Gdk::Cairo::set_source_pixbuf(cr,scaledImage, X_GRID-cell_x, Y_GRID-cell_y);                                                    // Dessin à l'emplacement du bloc source dans la grille
            cr->paint();

            return true ;
        }

        // Rôle : Gèrer les déplacements du joueur dans le labyrinthe en fonction des touches clavier pressées,
        // Vérifier si le personnage atteint la sortie et Mettre à jour l'interface graphique en conséquence
        bool on_key_press_event(GdkEventKey* event) {
            this->interface->grid->set_key(event);                                                                                                  // Enregistrer la touche pressée
            this->interface->G_info.can_play();                                                                                                        // Initialiser les informations du jeu
            labyrinthe l = this->m_->getLabyrinthe() ;                                                                                              // Récupération du labyrinthe
            if(this->interface->G_info.can_move()){                                                                                                 // Vérification d'une mise à jour des coordonnées du joueur : si oui faire
                if (this->interface->grid->get_key()->keyval == GDK_KEY_Up && this->m_->getPos_Y()!= 0) {                                           // Vérification de la mises à jour en fonction de la touche pressée
                    if(l.getWay(l.cord(this->m_->getPos_X(),this->m_->getPos_Y()-1),l.cord(this->m_->getPos_X(),this->m_->getPos_Y()))->isopen()){  // Vérification de l'absence d'un mur entre les deux positions
                        this->m_->setPos_Y(this->m_->getPos_Y()-1);
                        
                    }
                }
                else if (this->interface->grid->get_key()->keyval == GDK_KEY_Down && this->m_->getPos_Y() != (this->m_->getDim_Y()-1)) {            // Vérification de la mises à jour en fonction de la touche pressée et que la position en Y du joueur n'est pas à la limite supérieure du labyrinthe
                    if(l.getWay(l.cord(this->m_->getPos_X(),this->m_->getPos_Y()),l.cord(this->m_->getPos_X(),this->m_->getPos_Y()+1))->isopen()){  // Vérification de l'absence d'un mur entre les deux positions
                        this->m_->setPos_Y(this->m_->getPos_Y()+1);                                                                               // Mise à jour de la nouvelle position
                    }
                }
                else if (this->interface->grid->get_key()->keyval == GDK_KEY_Left && this->m_->getPos_X() != 0) {                                   // Vérification de la mises à jour en fonction de la touche pressée et que la position en Y du joueur n'est pas à la limite supérieure du labyrinthe
                    if(l.getWay(l.cord(this->m_->getPos_X()-1,this->m_->getPos_Y()),l.cord(this->m_->getPos_X(),this->m_->getPos_Y()))->isopen()){  // Vérification de l'absence d'un mur entre les deux positions
                        this->m_->setPos_X(this->m_->getPos_X()-1);                                                                                // Mise à jour de la nouvelle position
                    }
                }
                else if (this->interface->grid->get_key()->keyval == GDK_KEY_Right && this->m_->getPos_X() != (this->m_->getDim_X()-1)) {           // Vérification de la mises à jour en fonction de la touche pressée et que la position en Y du joueur n'est pas à la limite supérieure du labyrinthe
                    if(l.getWay(l.cord(this->m_->getPos_X(),this->m_->getPos_Y()),l.cord(this->m_->getPos_X()+1,this->m_->getPos_Y()))->isopen()){  // Vérification de l'absence d'un mur entre les deux positions
                        this->m_->setPos_X(this->m_->getPos_X()+1);                                                                                // Mise à jour de la nouvelle position
                    }
                }
            }
            if(this->m_->getPos_X() ==this->m_->getDim_X()-1 && this->m_->getPos_Y()==this->m_->getDim_Y()-1){                                      // Vérification d'une mise à jour des coordonnées du joueur : si non faire
                this->end_mode();                                                                                                                   // Gérer la fin du jeu
            }
            this->interface->grid->queue_draw();                                                                                                    // Mise à jour de l'interface graphique
            return true ;
        }


        //Cette fonction trace le chemin menant vers la sortie en utilisant l'algorithme d'astar
        bool solution(){
            this->interface->G_info.activate_solution(); // Activation du mode tips à 1 afin de permettre la solution 
            this->interface->grid->queue_draw(); 
            return true ;

        }

        // Rôle : Crée une nouvelle fenêtre de félicitations pour afficher un message de victoire,
        //avec un libellé indiquant que le joueur a gagné et un bouton permettant de fermer la fenêtre.
        void end_mode(){
            Gtk::Box *box = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);                                // Création d'une nouvelle boîte verticale
            this->interface->set_title("Félicitations "+this->interface->G_info.getNom()+" !!");    // Affiche un message de félicitations avec le nom du joueur
            this->interface->set_border_width(10);                                                  // Largeur de la bordure de la fenêtre définie sur 10
            this->interface->resize(X_RESULT, Y_RESULT);                                            // Dimensions de la fenêtre redimensionnées à X_RESULT et Y_RESULT.
            Gtk::Label *label = new Gtk::Label("Vous avez gagné");                                  // Création de l'étiquette "Vous avez gagné" de la boîte de fin
            Gtk::Button *Bclose =new Gtk::Button("Fermer");                                         // Création du bouton Fermer de la boîte de fin
            label->set_halign(Gtk::ALIGN_CENTER);                                                   // Centrage horizontal de l'étiquette
            label->set_valign(Gtk::ALIGN_CENTER);                                                   // Centrage vertical de l'étiquette
            label->set_hexpand(true);                                                               // Développement horizontal de l'étiquette
            box->pack_start(*label);                                                                // Allocation de l'étiquette label au début de la boîte (en haut)
            box->pack_start(*Bclose);                                                               // Allocation du bouton Bclose de fermeture à la suite dans la boîte
            Bclose->signal_clicked().connect([&](){this->interface->close();});                     // Association de la fermeture du jeu lorsque l'on clique sur le bouton Fermer
            this->interface->remove();                                                              // Supprimer la fenêtre actuelle
            this->interface->add(*box);                                                             // Intégration de la box que l'on vient de paramétrer à une fenêtre
            this->interface->show_all();                                                            // Affichage de la fenêtre sur l'interface graphique
        }
};
