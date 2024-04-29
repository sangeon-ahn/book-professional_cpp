#include <fstream>
#include <iostream>
#include <string_view>
using namespace std;


bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
    cout << filename << endl;
    fstream ioData { filename.data() };

    if (!ioData) {
        cerr << "Error while opening " << filename << endl;
        return false;
    }

    bool isChanged = false;

    while (ioData) {
        int tempId;
        ioData >> tempId;

        if (!ioData) {
            break;
        }

        // 해당 id 찾았으면 position 옮긴 후 write 해야 함.
        // seekp: 포지션 옮기기
        // tellp: 위치 찾기
        if (tempId == id) {
            cout << "현재 put 위치: " << ioData.tellp() << endl;
            cout << "현재 get 위치: " << ioData.tellg() << endl;

            ioData.seekp(ioData.tellg()); // tellp() == tellg() 이지만, 혹시나 모를 오류를 방지하려고 명확하게 하는 것 같다.

            ioData << " " << newNumber;
            isChanged = true;
            break;
        }

        // 해당하는 id 아니면 번호 consume하고 다음 id 확인하러 감.
        string number;
        ioData >> number;
    }
    if (isChanged) {
        return true;
    }
    return false;
}

int main()
{
    if (changeNumberForID("phones.txt", 263, "123-456-7890")) {
        cout << "Done!" << endl;
    } else {
        cout << "Doesn't changed!" << endl;
    }

    return 0;
}