#include <memory>
#include "GameBoard.h"
#include "ChessPiece.h"
using namespace std;

int main()
{
    GameBoard chessBoard {8, 8};
    auto pawn { make_unique<ChessPiece>()};

    // at() 반환값이 lvalue라서 대입 가능
    chessBoard.at(0, 0) = std::move(pawn); // rvalue reference로 바꿔서 move assign operator 일어나도록 함.
    chessBoard.at(0, 1) = std::make_unique<ChessPiece>(); // unnamed라서 move assign operator 일어남.
    chessBoard.at(0, 1) = nullptr;
}