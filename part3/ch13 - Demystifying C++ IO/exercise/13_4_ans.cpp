#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Database.h"

using namespace std;
using namespace std::filesystem;

void Database::add(Person person)
{
    m_persons.push_back(move(person));
}

void Database::clear()
{
    m_persons.clear();
}

void Database::save(const path& folder) const
{
    for (const auto& person : m_persons) {
        path fileName { folder };
        fileName /= person.getInitials();
        fileName += ".person";

        ofstream outFile { fileName, ios_base::trunc };
        
        if (!outFile) {
            cerr << "해당 파일을 열 수 없습니다: " << fileName << endl;
            return;
        }

        outFile << person.getFirstName() << person.getLastName() << person.getInitials() << endl;
    }
}

void Database::load(const path& folder)
{
    directory_iterator begin { folder };
    directory_iterator end {};

    for (auto iter { begin }; iter != end; ++iter) {
        auto& entry {*iter};

        if (!entry.path().has_extension() || entry.path().extension() != ".person") {
            continue;
        }

        loadFile(entry);
    }
}

void Database::loadFile(const std::filesystem::path& file)
{
    ifstream inFile { file.root_path()};
    if (!inFile) {
        cerr << "Cannot open file: " << file.root_path() << endl;
        return;
    }

    while (inFile) {
        string line;
        getline(inFile, line);
        if (line.empty()) {
            continue;
        }

        istringstream iss(line);

        string firstName, lastName, initials;
        iss >> firstName >> lastName >> initials;

        if (iss.bad()) {
            cerr << "Error reading person. Ignoring." << endl;
            continue;
        }

        m_persons.push_back(Person {move(firstName), move(lastName), move(initials)});
    }
}

void Database::outputAll(ostream& output) const
{
    for (const auto& person : m_persons) {
        person.output(output);
    }
}