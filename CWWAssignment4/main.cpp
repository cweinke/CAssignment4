#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

void PrintEmployee(Employee* pEmployee)
{
    
    int weeklyPay = (pEmployee->HoursWorked * pEmployee->HourlyRate);
    cout << pEmployee->ID << ". " << pEmployee->FirstName << " " << pEmployee->LastName << ": $" << weeklyPay << "\n";
    
}

void PrintPayReport(Employee *employees, int size)
{
    cout << "Pay Report \n";
    cout << "======== \n";
    for (int i = 0; i < size; i++)
    {
        PrintEmployee(&employees[i]);
    }
}

Employee* GetEmployeeInfo()
{
    Employee* pE = new Employee;
    cout << "Enter the ID for the Employee " << ": ";
    cin >> pE->ID;
    cout << "Enter the First Name for the Employee " << ": ";
    cin >> pE->FirstName;
    cout << "Enter the Last Name for the Employee " << ": ";
    cin >> pE->LastName;
    cout << "Enter the Hours Worked for the Employee " << ": ";
    cin >> pE->HoursWorked;
    cout << "Enter the Hourly Rate for the Employee " << ": ";
    cin >> pE->HourlyRate;
    cout << "\n";
    return pE;
}

int main()
{
    cout << "Enter the number of employees: ";
    int size = 0;
    cin >> size;
    cout << "\n";

    Employee *employees = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        employees[i] = *GetEmployeeInfo();
    }

    PrintPayReport(employees, size);
    int totalPay = 0;
    for (int i = 0; i < size; i++)
    
    {
        int weeklyPay = (employees[i].HoursWorked * employees[i].HourlyRate);
        totalPay = totalPay + weeklyPay;
    }
    cout << "\n" << "Total Pay: $" << totalPay;
    

    delete[] employees;

    (void)_getch();
    return 0;
}




