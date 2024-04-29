#include <memory>
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void funcOne();
void funcTwo();

int main()
{
    try {
        funcOne();
    } catch (const exception& e) {
        cerr << "Exception caught!" << endl;
        return 1;
    }
}

void funcOne()
{
    string str1;

    // funcTwo에서 예외 발생 -> delete 호출 안됨 -> 메모리릭 
        // string* str2 { new string {}};

    // 스마트 포인터 사용시, 해당 포인터 변수 해제되면 연결된 동적객체도 해제됨
    auto str2 {make_unique<string>("hello")};
    funcTwo();
}

void funcTwo()
{
    ifstream inFile;
    inFile.open("filename");
    throw exception{};
    inFile.close(); // throw에 의해 호출 안됨 -> inFile은 지역변수라 어차피 자동 메모리 해제됨.
}