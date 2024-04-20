#include <iostream>
using namespace std;

class ChessPiece
{

};

class ChessBoard
{
    public:
        // 인터페이스 선언
        void setPieceAt(size_t x, size_t y, ChessPiece* piece);
        ChessPiece* getPieceAt(size_t x, size_t y) const;
        bool isEmpty(size_t x, size_t y) const;
    private:
};

template <typename PieceType>
class GameBoard
{
    public:
        void setPieceAt(size_t x, size_t y, PieceType* piece);
        PieceType* getPieceAt(size_t x, size_t y) const;
        bool isEmpty(size_t x, size_t y) const;
    private:
};

class Rook
{

};

int main()
{
    // 추상화가 이루어지지 않은 경우
    // chessBoard가 1차원으로 구현 바뀔 경우 사용부에서도 변경이 이루어져야 함.
    ChessPiece* chessBoard[8][8] {};
    chessBoard[0][0] = new Rook{};

    // 추상화가 이루어진 경우
    ChessBoard board = new ChessBoard{};
}