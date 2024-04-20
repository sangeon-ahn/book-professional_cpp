#include <iostream>
using namespace std;
int main() 
{
    enum class PieceType { King = 1, Queen, Rook = 11, Pawn };

    PieceType piece { PieceType::Queen };

    /*
    illegal
    if (PieceType::Queen == 2) {

    }
    */

   // it can be co-existent if the name of enum class is different.
    enum class fruit {Unknown, Apple, Banana };
    enum class vehicle {Unknown, Car, motorcycle };  

    // 현대식 enum vs 구식 enum
    // 현대식은 scope resolution 붙여서 사용. 구식은 바로 사용 가능
    // 구식은 변수 중복 문제
    // 구식 enum은 integer로 평가된다 -> 다른 enum간에 비교될 수 있다는 문제. -> type unsafe
    // 타입 세이프 = 컴파일 시점에서 같은 타입끼리 비교되지 않을 때 에러를 반환함
}