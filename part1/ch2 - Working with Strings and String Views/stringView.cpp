#include <iostream>
#include <string_view>
#include <string>

using namespace std;

string_view extractExtension(string_view filename) // pointer과 length
{
    return filename.substr(filename.rfind('.'));
}

int main()
{
    // 1
    string str { R"(c:\temp\my file.ext)" };

    // 2
    const char* str2 { R"(c:\user\document\my_file.ext)" };
    size_t len { strlen(str2) };

    // 1번 방식
    string_view view = extractExtension(str);
    // 2번 방식. 이렇게 써도 된다.
    string_view view2 = extractExtension(string_view(str2, len));
    str.append(view.data(), 3);

    cout << view << endl; // view.data()를 하면 string_view가 consume되었기 때문에 null이라 0이 출력된다. 다 소비되기 전까지는 온전한 string_view를 출력하다가 전체가 다 소비되면 0

    cout << view2 << endl;
    cout << str << endl;

    string s1 { "Hello" };
    string_view sv { s1 + "World" };
    cout << sv << endl;

    auto custom_sv { "this is string_view"sv };
    cout << custom_sv << endl;
}