#include <iostream>
#include <vector>
using namespace std;

const float probaTourner = 0.1; // 10%
const int dureeSablier = 6;
const float densiteBrindille=0.05;
const int nbcolonies = 2;
const int nbTermites=20;
const int grid_size = 10;
class termites
{
public:
    termites();
    ~termites();
};

vector<vector<char>> init_state()
{
    vector<vector<char>> current_state(grid_size, vector<char>(grid_size, ' '));
    int tirage;
    int termite_place = 0;
    int case_restante = grid_size * grid_size;
    for (int i = 0; i < grid_size; i++)
    {
        for (int j = 0; j < grid_size; j++)
        {
            tirage = rand()%100;
            if (tirage < (float(nbTermites - termite_place)/ float(case_restante)) * 100)
            {
                current_state[i][j] = '|';
                termite_place++;
            }
            tirage = rand()%100;
            if (tirage < (float(nbTermites - termite_place)/ float(case_restante)) * 100)
            {
                current_state[i][j] = '|';
                termite_place++;
            }
            case_restante--;
        }   
    }
    return current_state;
}

void show_grid(vector<vector<char>> grid){
    cout << "s" << endl;
    for (int i = 0; i < grid_size; i++)
    {
        for (int j = 0; j < grid_size; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << "e" << endl;
}

int main() {
    show_grid(init_state());
    return 0;
}

