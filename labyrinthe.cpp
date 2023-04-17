#include "labyrinthe.hpp"

void labyrinthe::init_labyrinthe()
{
    cout << "Labyrinth initialized !!" << endl;
}

int labyrinthe::getGrid(int i, int j) const
{
    return grid[width * j + i].getValue();
}

bool labyrinthe::getH_wall(int i, int j) const
{
    return h_wall[width * j + i];
}

bool labyrinthe::getV_wall(int i, int j) const
{
    return v_wall[j * width + i];
}

string labyrinthe::v_obstacle(bool b) const
{
    return !b ? "|" : "";
}

string labyrinthe::h_obstacle(bool b) const
{
    return !b ? "_" : "";
}

string labyrinthe::toString() const{

    ostringstream ss;
    ss << "Labyrinthe :" << endl;
    ss << endl ;
    for (int i = 0; i < width; i++)
    {

        for (int j = 0; j < width; j++)
        {
            ss << setw(2) << getGrid(i, j) << " ";
        }
        ss << endl ;
    }

    return ss.str();
}