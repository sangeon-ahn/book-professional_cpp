#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream inFile { "input.txt" };
    ofstream outFile { "output.txt" };

    inFile.tie(&outFile);
    outFile << "Hello there!"; // 아직 flush는 안 된 상태.(endl 안해서)

    string nextToken;
    inFile >> nextToken; // inFile에서 읽기 시도 -> inFile과 tied된 outFile의 버퍼에 있는 데이터를 끌어와서 nextToken에 할당
    
    ofstream outFile2 { "output2.txt" };

    outFile.tie(&outFile2);

    outFile2 << "aa";
    outFile << "abcde";
}