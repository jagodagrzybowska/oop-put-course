// oop-lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

using namespace std;

class FinancialInfo {
private:
    double money;
public:
    float Finances() { return this->money; };
    FinancialInfo() { this->money = 0.0; };
    FinancialInfo(double users_finances) { this->money = users_finances; };
    FinancialInfo(int users_finances) : FinancialInfo(static_cast<double>(users_finances)) {};
    FinancialInfo(float users_finances) : FinancialInfo(static_cast<double>(users_finances)) {};
    FinancialInfo(string users_finances) : FinancialInfo(stof(users_finances)) {};


};

int main()
{
    FinancialInfo DefaultBalance;
    FinancialInfo CurrentBalance(1555.89);
    FinancialInfo RecentSalary(666.66f);
    FinancialInfo PreviousSalary("911");
    FinancialInfo RecentSpendings(1000);

    cout << "Default Account Balance\t";
    cout << DefaultBalance.Finances() << endl;
    cout << "Current Account Balance\t";
    cout << CurrentBalance.Finances() << endl;
    cout << "Users Recent Salary\t";
    cout << RecentSalary.Finances() << endl;
    cout << "Users Recent Spendings\t";
    cout << RecentSpendings.Finances() << endl;
    cout << "Users Previous Salary\t";
    cout << PreviousSalary.Finances() << endl;
    cout << "typeid of PreviousSalary.Finances()\t" << typeid(PreviousSalary.Finances()).name();
    return 0;
}

