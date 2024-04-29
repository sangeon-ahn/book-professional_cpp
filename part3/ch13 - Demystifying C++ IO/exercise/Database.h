#include "Person.h"
#include <vector>
#include <ostream>
#include <filesystem>

class Database
{
    public:
        void add(Person person);
        void clear();
        void save(const std::filesystem::path& folder) const;
        void load(const std::filesystem::path& folder);
        void outputAll(std::ostream& output) const;

    private:
        std::vector<Person> m_persons;
        void loadFile(const std::filesystem::path& file);
};