// #include "Grid.h"
#include "ChessPiece.h"
#include "GameBoardwithTemplate.h"
using namespace std;

int main()
{
    // Grid<int> myIntGrid;
    // Grid<double> myDoubleGrid { 11, 11 };

    // myIntGrid.at(0, 0) = 10;
    // int x { myIntGrid.at(0, 0).value_or(0)};

    // Grid<int> grid2 { myIntGrid }; // copy constructor
    // Grid<int> anotherIntGrid;
    // anotherIntGrid = grid2; // assign operator
    GameBoard<ChessPiece> chessBoard {8, 8};
    ChessPiece pawn;
    chessBoard.at(0, 0) = pawn;
    chessBoard.move(0, 0, 0, 1);
}