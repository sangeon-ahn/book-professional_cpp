#include <vector> 
#include <string>
#include <string_view>
#include "Person.h"

using namespace std;

class Database
{
    public:
        void add(const Person& person) {
            persons.push_back(std::move(person));
        }

        void save(string_view fileName) {
            // 해당 파일의 모든 사람 정보를 persons에 저장하고 파일 내용 삭제
            ifstream inFile { fileName };

            if (!inFile) return;

            string personData;

            while (getline(inFile, personData)) {
                vector<string> temp;
                istringstream iss(personData);
                string token;

                int idx = 0;
                while (getline(iss, token, ',') && idx < 3) {
                    temp.push_back(std::move(token));
                    ++idx;
                }

                // 파일 형식 맞지 않아 getline에서 오류난 경우,
                if (idx != 3) {
                    continue;
                }

                Person p {std::move(temp[0]), std::move(temp[1]), std::move(temp[2])};

                
                ofstream personOutFile { p.getInitials() + ".person", ios_base::trunc };

                if (!personOutFile) continue;

                personOutFile << p.getFirstName() << "," << p.getLastName() << "," << endl;
                personOutFile.close();

                persons.push_back(std::move(p));
                
                // p는 객체이고, moved되어 더이상 내용물이 없다.
                // cout << "HIHI" << p.getFirstName() << endl;
            }
            inFile.close();

            // 파일 초기화
            ofstream outFile { fileName, ios_base::trunc };
            outFile.close();
        }
        
        // database 내의 모든 사람 정보를 해당 퍄일에 저장
        void load(string_view dirName) {
            for (const auto& p : persons) {
                ifstream inFile { p.getInitials() + ".person" };

                if (!inFile) continue;

                string line;
                while (getline(inFile, line)) {
                    string token;
                    istringstream iss(line);
                    vector<string> temp;

                    int idx = 0;
                    
                    while (getline(iss, token, ',') && idx < 3) {
                        temp.push_back(std::move(token));
                        ++idx;
                    }

                    if (idx != 3) continue;
                    
                    Person p {std::move(temp[0]), std::move(temp[1]), std::move(temp[2])};

                    persons.push_back(std::move(p));
                }
                inFile.close();
                // outFile << p.getFirstName() << "," << p.getLastName() << "," << p.getInitials() << "," << endl;
            }
        }

        void clear() {
            // database 내의 모든 사람 정보 삭제
            persons.clear();
            cout << "db clear called." << endl;
        }

        void outputAll() const {
            // db 내의 모든 사람의 output() 호출

            for (const auto& p : persons) {
                p.output(cout);
            }
        }
    
    private:
        vector<Person> persons;
};

int main()
{
    Database db;
    const string filename = "persons.txt";
    // add 테스트
    Person p1 {"sangeon", "ahn"};
    Person p2 {"jeremy", "jung"};

    db.add(std::move(p1));
    db.add(std::move(p2));
    // db.outputAll();

    db.save(filename);

    // load 테스트
    db.load(filename);
    
    // db 삭제
    // db.clear();

    // save 테스트
    // db.outputAll();
}