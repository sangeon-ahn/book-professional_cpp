#include <iostream>
#include "Database.h"
using namespace std;
using namespace HR;

int main()
{
    Database myDB;
    Employee& emp1 { myDB.addEmployee("Greg", "Wallis")}; // 직원 생성해 넣고 반환되는 참조값을 emp1에 할당
    emp1.fire();

    Employee& emp2 { myDB.addEmployee("Sangeon", "Ahn")};
    emp2.setSelary(100'000);

    Employee& emp3 { myDB.addEmployee("John", "Doe")};
    emp3.setSelary(10'000);
    emp3.promote();

    cout << "all employees: " << endl << endl;
    myDB.displayAll();

    cout << endl << "current employees: " << endl << endl;
    myDB.displayCurrent(); 

    cout << endl << "former employees: " << endl << endl;
    myDB.displayFormer();
}