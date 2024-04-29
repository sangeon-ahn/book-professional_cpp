#include <filesystem>
#include <iostream>

using namespace std;

void printDirectoryStructure(const std::filesystem::path& p)
{
    if (!exists(p)) {
        cout << "Invalid Path!" << endl;
        return;
    }   

    int cnt = 0;
    std::filesystem::recursive_directory_iterator begin { p };
    std::filesystem::recursive_directory_iterator end { };

    for (auto iter { begin }; iter != end; ++iter) {
        if (cnt > 1000) {
            break;
        }
    
        // depth()가 뭔지 파악
        const string spacer(iter.depth() * 2, ' ');

        auto& entry { *iter };

        // 파일이면,
        if (entry.is_regular_file()) {
            cout << spacer << "File: " << entry.path().string() << " (" << entry.file_size() << " bytes)" << endl; 
        }
        // 디렉토리면,
        else if (entry.is_directory()) {
            cout << spacer << "Dir: " << entry.path().string() << endl;
        }
        ++cnt;
    }
}

int main()
{
    std::filesystem::path p {R"(/Users/seon/Documents/devel)"};

    printDirectoryStructure(p);
}