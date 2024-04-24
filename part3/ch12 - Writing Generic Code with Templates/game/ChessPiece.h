#include <memory>

#ifndef CHESSPIECE
#define CHESSPIECE
#include "GamePiece.h"
using namespace std;

class ChessPiece : public GamePiece
{
    public:
        unique_ptr<GamePiece> clone() const override
        {
            return make_unique<ChessPiece>(*this);
        }
};
#endif