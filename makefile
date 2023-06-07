# Compilateur
CC := g++

#Option de compilation
GTKMM_CF = $(shell pkg-config gtkmm-3.0 --cflags)
GTKMM_LD = $(shell pkg-config gtkmm-3.0 --libs)
CFLAGS = $(GTKMM_CF) -Wall -pedantic # les options du compilateur
LDFLAGS = $(GTKMM_LD)      # les options pour l’éditeur de liens

# Répertoires des fichiers sources
SRC_DIR_M := Modele/ # Répertoires des fichiers de type modèle
SRC_DIR_V := /home/pierre/Bureau/ELEC4/C++/Projet_COO/Labyrinthe/Vue # Répertoires des fichiers de type Vue
SRC_DIR_C := Controleur/ # Répertoires des fichiers de type controleur

# Répertoire des fichiers objets
OBJ_DIR := build/ # Répertoires des fichiers objets 

# Répertoire de sortie de l'exécutable
BIN_DIR := bin/

# les fichiers sources
SRC = main.cpp labyrinthe.cpp character.cpp block.cpp edge.cpp GameState.cpp Controleur.cpp

PROG = laby_Gtk   # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o    # lien entre les suffixes
all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

main.cpp : Controleur.hpp
labyrinthe.cpp : labyrinthe.hpp graph.hpp character.hpp
block.cpp : block.hpp edge.hpp
edge.cpp : edge.hpp
character.cpp : character.hpp
GameState.cpp : GameState.hpp
Vue.cpp : Vue.hpp GameState.hpp GridGame.hpp
Controleur.cpp : Controleur.hpp Modele.hpp Vue.hpp

# le lien entre .o et -c
# $< dernière dépendance
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


# pour faire propre
.PHONY: clean
clean:
	rm -f *.o $(PROG)