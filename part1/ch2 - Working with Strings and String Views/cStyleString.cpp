#include <cstring>
#include <iostream>
using namespace std;

char* copyString(const char* str)
{
    char* newStr { new char[strlen(str) + 1] };
    
    strcpy(newStr, str);
    return newStr;
}

char* appendString(const char* str1, const char* str2, const char* str3)
{
    char* newStr { new char[strlen(str1) + strlen(str2) + strlen(str3) + 1] };
    
    strcpy(newStr, str1);
    strcat(newStr, str2);
    strcat(newStr, str3);

    return newStr;

}

int main()
{
    char str[] {'h', 'e', 'l', 'l', 'o'};
    char* copiedStr = copyString(str);
    cout << copiedStr << endl;

    char* appendedStr = appendString("abc", "def", "ghi");
    cout << appendedStr << endl;

    char text1[] {"abcdef"}; // '\0'이 포함되어 있음.
    size_t s1 { sizeof(text1) }; // '\0'를 포함하여 계산함.
    cout << s1 << endl; // 7
    
    size_t s2 { strlen(text1) };
    cout << s2 << endl; // 6

    const char* text2 {"abcdef"};
    size_t s3 { sizeof(text2) };
    cout << s3 << endl; // 8이 나온다. 64bit 아키텍처의 포인터(주소)는 8bytes라서.

    size_t s4 { strlen(text2) };
    cout << s4 << endl; // 6

    const char* str2 {R"(Hello
    World!)"};

    cout << str2 << endl;

    string strHello { "Hello!!aasssss"};
    string strWorld { "The World" };
    
    auto pos = strHello.find("!!");

    if (pos != strHello.npos) {
        strHello.replace(pos, 1, strWorld.substr(3, 6));
        cout << strHello << endl;
    }

    auto s10 {"Hello"};
    auto s20 {"Hello2"s};
    cout << s10 << s20 << endl;

    vector names {"sangeon", "bia", "somin"}; // const char*
    vector names2 {"hey"s, "bye"s}; // string

    
}