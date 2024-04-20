#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include "Database.h"
// #include "Employee.h"

using namespace std;
using namespace HR;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;

    // 잘못된 입력 들어올시 버퍼 초기화
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return selection;
}

void doHire(Database& db)
{
    string firstName;
    string lastName;

    cout << "First name? ";
    cin >> firstName;

    cout << "Last Name? ";
    cin >> lastName;
    auto& employee { db.addEmployee(firstName, lastName) };
    cout << "Hired employee " << firstName << " " << lastName << " " << "with employee number " << employee.getEmployeeNumber() << "." << endl;
}

void doFire(Database& db)
{
    int employeeNumber;
    cout << "Employee number? " << endl;
    cin >> employeeNumber;

    try {
        auto& emp { db.getEmployee(employeeNumber)};
        emp.fire();
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber;
    cout << "Employee number? " << endl;
    cin >> employeeNumber;

    int raiseAmount;
    cout << "How much of a raise? " << endl;
    cin >> raiseAmount;    

    try
    {
        auto& emp {db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unable to promote employee: " << e.what() << '\n' << endl;
    }
    
}

enum class Menu {QUIT, HIRE, FIRE, PROMOTE, DISPLAY_ALL, DISPLAY_CURRENT, DISPLAY_FORMER};

int main()
{
    Database employeeDB;
    bool done { false };
    while (!done) {
        int selection { displayMenu() };
        Menu menu = static_cast<Menu>(selection);

        switch (menu)
        {
        case Menu::QUIT:
            done = true;
            break;
        case Menu::HIRE:
            doHire(employeeDB);
            break;
        case Menu::FIRE:
            doFire(employeeDB);
            break;
        case Menu::PROMOTE:
            doPromote(employeeDB);
            break;
        case Menu::DISPLAY_ALL:
            employeeDB.displayAll();
            break;
        case Menu::DISPLAY_CURRENT:
            employeeDB.displayCurrent();
            break;
        case Menu::DISPLAY_FORMER:
            employeeDB.displayFormer();
            break;
        default:
            cout << "Unknown command." << endl;
            break;
        }
    }
}