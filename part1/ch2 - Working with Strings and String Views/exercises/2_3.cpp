#include <string>
#include <iostream>
#include <string_view>
using namespace std;

string getReplacedString(string_view src, string_view from, string_view to)
{
    size_t pos;
    pos = src.find(from);
    
    string srcStr = src.data();

    while (pos != src.npos) {
        srcStr.replace(pos, from.length(), to);
        pos += from.length();

        pos = src.find(from, pos);
    }
    return srcStr;
}

int main()
{
    string haystack, needle, reple;
    cin >> haystack >> needle >> reple;

    string newStr = getReplacedString(haystack, needle, reple);
    cout << newStr;
    return 0;
}

#include <string>
#include <iostream>
#include <string_view>
using namespace std;

string getReplacedString(string_view src, string_view from, string_view to)
{
    string result; // 정답 string 하나 생성
    size_t pos = 0; // 위치 추적할 포인터 생성.
    while (pos != src.npos) { // 끝에 다다를 때까지 계속 수행.
        size_t foundPos = src.find(from, pos); // src에서 from을 pos부터 확인해가며 있는지 확인
        if (foundPos == src.npos) { // 여기서 또 마지막에 이르렀는지 체크
            result.append(src.substr(pos)); // 마지막이면 src 나머지 부분 전부 복사.
            break; // 끝
        }
        result.append(src.substr(pos, foundPos - pos)); // 마지막 아니면 같은거 존재 -> pos에서 시작해서 저 차이만큼의 substr을 붙여넣기
        result.append(to); // 그리고 나서 to 붙여넣기
        pos = foundPos + from.length(); // pos를 갱신
    }
    return result;
}

string getReplacedString(string_view src, string_view from, string_view to)
{
    string result;
    size_t pos = 0;

    while (pos != src.npos) {
        size_t nextPos = src.find(from, pos);

        if (nextPos == src.npos) {
            result.append(src.substr(pos));
            break;
        }
        result.append(src.substr(pos, nextPos - pos));
        result.append(to);
        pos = nextPos + from.length();
    }
    return result;
}

int main()
{
    string haystack, needle, reple;
    cin >> haystack >> needle >> reple;

    string newStr = getReplacedString(haystack, needle, reple);
    cout << newStr;
    return 0;
}
