#include <iostream>
#include <vector>
#include <random>

std::vector<int> adjacent_list_ID(int id) {
    // ... code pour générer la liste d'adjacence à partir de l'identifiant 'id' ...
}

int main() {
    int id = 0;
    std::vector<int> n = {2 ,3, 57, 10};
    std::vector<double> weights(n.size(), 1.0); // vecteur de poids uniformes
    std::discrete_distribution<int> dist(n.begin(), n.end());
    std::mt19937 rng(std::random_device{}());
    
    // Génération de nombres aléatoires
    for (int i = 0; i < 10; ++i) {
        int random_index = dist(rng);
        std::cout << "Random index: " << random_index << ", value: " << n[random_index] << std::endl;
    }
    
    return 0;
}
