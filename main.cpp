#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string filename;
    string firstName, lastName;
    double baseSalary, commissionPercent, totalSales, expenses;

    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    inputFile >> firstName >> lastName;
    inputFile >> baseSalary >> commissionPercent;
    inputFile >> totalSales;
    inputFile >> expenses;
    inputFile.close();

    double commission = totalSales * (commissionPercent / 100.0);
    double totalPay = baseSalary + commission - expenses;

    cout << fixed << setprecision(2);
    cout << "Payroll data for " << firstName << " " << lastName << endl << endl;
    cout << "Base Salary:    " << setw(9) << baseSalary << endl;
    cout << "Commission:     " << setw(9) << commission << " ("
         << setprecision(1) << commissionPercent << "% of "
         << setprecision(2) << totalSales << ")" << endl;
    cout << "Expenses:       " << setw(9) << expenses << endl;
    cout << "               --------" << endl;
    cout << "Total:          " << setw(9) << totalPay << endl;

    return 0;
}
