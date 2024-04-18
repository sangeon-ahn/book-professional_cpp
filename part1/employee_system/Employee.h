#include <string>

namespace HR {
    const int DefaultStartingSalary { 30'000 };
    const int DefaultRaiseAndDemeritAmount { 1'000 };
    enum class Title { Manager, Senior_Engineer, Engineer };

    class Employee
    {
        public:
            Employee(const std::string& firstName, const std::string& lastName);
            
            void promote(int raiseAmount = HR::DefaultRaiseAndDemeritAmount);
            void demote(int demeritAmount = HR::DefaultRaiseAndDemeritAmount);
            void hire();
            void fire();
            void display() const;

            void setFirstName(const std::string& firstName);
            void setLastName(const std::string& lastName);
            void setEmployeeNumber(int employeeNumber);
            void setSelary(int newSalary);
            void setTitle(Title title);

            const std::string& getFirstName() const;
            const std::string& getLastName() const;
            int getEmployeeNumber() const;
            int getSalary() const;
            Title getTitle() const;
            
            bool isHired() const;
        private:
            std::string m_firstName;
            std::string m_lastName;
            Title m_title;
            int m_salary { HR::DefaultStartingSalary };
            int m_employeeNumber { -1 };
            bool m_hired { false };
    };    
};

