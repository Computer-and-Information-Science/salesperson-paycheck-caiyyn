
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string filename;
    string firstName, lastName;
    double baseSalary, commissionPercent, totalSales, expenses;
    
    // get file name from user
    cout << "Enter the name of the file: ";
    cin >> filename;
    
    // open the file
    ifstream inputFile(filename);
    
    // input employee information
    inputFile >> firstName >> lastName;
    inputFile >> baseSalary >> commissionPercent;
    inputFile >> totalSales;
    inputFile >> expenses;
    inputFile.close();
    
    // calculate commission and total pay
    double commission = totalSales * (commissionPercent / 100.0);
    double totalPay = baseSalary + commission - expenses;
   
    // output payroll data
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
