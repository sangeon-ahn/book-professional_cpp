#include <fstream>
#include <vector>
#include <iostream>
#include <string_view>
#include <exception>
#include <sstream>
#include "customException.h"

using namespace std;

[[noreturn]] void myTerminate()
{
    cout << "Uncaught exception!" << endl;
    _Exit(1);
}

vector<int> readIntegerFile(string_view fileName)
{
    ifstream inputStream { fileName.data() };

    // 파일 열기 실패했으면 에러 던지기
    if (inputStream.fail()) {
        // throw runtime_error{ "Unable to open the file." };
        throw FileOpenError {fileName.data()};
    }

    // 잘 열렸으면 진행
    vector<int> integers;
    size_t lineNumber { 0 };

    while (!inputStream.eof()) {
        string line;
        getline(inputStream, line);
        ++lineNumber;

        istringstream lineStream {line};

        int temp;

        while (lineStream >> temp) {
            integers.push_back(temp);
        }

        // 위의 while 빠져나가는 경우는 EOF인 경우, inputStream이 중간에 에러났을 경우 총 2가지다. 후자인 경우 예외처리 해주어야 한다.

        if (!lineStream.eof()) {
            cout << __FILE__ << endl;
            throw FileReadError { fileName.data(), lineNumber };
        }
    }
    
    return integers;
}

int main()
{
    set_terminate(myTerminate);

    vector<int> res;
    const char* fileName = "intFile.txt";

    // try {
    //     /* code */
    //     res = readIntegerFile(fileName);
    // } catch(const invalid_argument& e) {
    //     cerr << e.what() << endl;
    //     return 1;
    // } catch(const runtime_error& e) {
    //     cerr << e.what() << endl;
    //     return 2;
    // } catch(...) {
    //     cerr << "Error reading or opening file " << fileName << endl;
    // }

    try {
        res = readIntegerFile(fileName);
    } catch (const FileError& e) {
        cerr << e.what() << endl;
        return 1;
    }

    for (const auto& i : res) {
        cout << i << endl;
    }

    return 0;
}
