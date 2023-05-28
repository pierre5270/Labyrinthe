CFLAGS = -Wall -fconcepts # les options du compilateur
LDFLAGS =  # les options pour l'éditeur de liens

CC = g++ # le compilateur à utiliser

SRC = main.cpp labyrinthe.cpp character.cpp block.cpp edge.cpp # les fichiers sources
PROG = main   # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o    # lien entre les suffixes
all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

main.cpp : labyrinthe.hpp
labyrinthe.cpp : labyrinthe.hpp character.hpp graph.hpp
block.cpp : block.hpp edge.hpp
edge.cpp : edge.hpp
character.cpp : character.hpp

# le lien entre .o et -c
# $< dernière dépendance
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


# pour faire propre
.PHONY: clean
clean:
	rm -f *.o $(PROG)