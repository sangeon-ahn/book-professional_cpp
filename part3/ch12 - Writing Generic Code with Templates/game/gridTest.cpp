#include "Grid.h"
using namespace std;

int main()
{
    Grid<int> myIntGrid;
    Grid<double> myDoubleGrid { 11, 11 };

    myIntGrid.at(0, 0) = 10;
    int x { myIntGrid.at(0, 0).value_or(0)};

    Grid<int> grid2 { myIntGrid }; // copy constructor
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2; // assign operator
}