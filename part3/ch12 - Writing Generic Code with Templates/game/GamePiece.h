#include <memory>
using namespace std;

#ifndef GAMEPIECE
#define GAMEPIECE
class GamePiece
{
    public:
        virtual ~GamePiece() = default;
        virtual std::unique_ptr<GamePiece> clone() const = 0;
};
#endif