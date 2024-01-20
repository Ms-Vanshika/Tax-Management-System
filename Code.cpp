#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string id;
    string password;

public:
    string name;
    long long int acc_no;
    double salary;

    Employee(const string &empName, long long int accountNo, double empSalary) : name(empName), acc_no(accountNo), salary(empSalary) {}

    void employeeRegister() {
        cout << "Enter Registration ID: ";
        cin >> id;
        cout << "Enter your password (KEEP IT AS UNIQUE AS YOUR EARLOBE): ";
        cin >> password;
    }
};

class Registration {
public:
    string id;
    string password;
    long long int acc_no;

    Registration(const string &regID, const string &regPassword, long long int accountNo) : id(regID), password(regPassword), acc_no(accountNo) {}
};

class Payslip {
public:
    int payslipno;
    double taxable_income;
    double tax_deduction;
    long long int acc_no;

    Payslip(int pNo, double income, double taxDeduction, long long int accountNo) : payslipno(pNo), taxable_income(income), tax_deduction(tax_deduction), acc_no(accountNo) {}

    double calculateTax() {
        double taxRate = 0.15;
        tax_deduction = taxable_income * taxRate;
        return tax_deduction;
    }

    void displayPayslip() {
        cout << "Payslip Number: " << payslipno << endl;
        cout << "Employee Account No: " << acc_no << endl;
        cout << "Taxable Income: $" << taxable_income << endl;
        cout << "Tax Deduction: $" << tax_deduction << endl;
    }
};

class Payment {
public:
    long long int acc_no;
    double amount;

    Payment(long long int accountNo, double paymentAmount) : acc_no(accountNo), amount(paymentAmount) {}
};

class Employer {
public:
    string name;
    long int id;
    long long int acc_no;

    Employer(const string& empName, long int employerID, long long int accountNo) : name(empName), id(employerID), acc_no(accountNo) {}
};

int main() {
    vector<Employee> employees;
    vector<Registration> registrations;
    vector<Payslip> payslips;
    vector<Payment> payments;
    vector<Employer> employers;

    while (true) {
        cout << endl;
        cout << "1. Register Employee" << endl;
        cout << "2. Make Payment" << endl;
        cout << "3. Generate Payslip" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                long long int acc_no;
                double salary;

                cout << "Enter Employee Name: ";
                cin >> name;
                cout << "Enter Employee Account No: ";
                cin >> acc_no;
                cout << "Enter Salary: $";
                cin >> salary;

                employees.push_back(Employee(name, acc_no, salary));
                registrations.push_back(Registration("", "", acc_no));
                cout << "Employee Registered Successfully!" << endl;
                break;
            }

            case 2: {
                if (employees.empty()) {
                    cout << "No registered employees to make payments to." << endl;
                    break;
                }

                long long int acc_no;
                double paymentAmount;

                cout << "Select Employee to Make Payment To:" << endl;
                for (size_t i = 0; i < employees.size(); ++i) {
                    cout << i + 1 << ". " << employees[i].name << " (Account No: " << employees[i].acc_no << ")" << endl;
                }

                int empChoice;
                cin >> empChoice;

                if (empChoice >= 1 && empChoice <= employees.size()) {
                    cout << "Enter Payment Amount: $";
                    cin >> paymentAmount;
                    payments.push_back(Payment(employees[empChoice - 1].acc_no, paymentAmount));
                    cout << "Payment Made Successfully!" << endl;
                } else {
                    cout << "Invalid selection." << endl;
                }
                break;
            }

            case 3: {
                if (payments.empty()) {
                    cout << "No payments have been made yet." << endl;
                    break;
                }

                long long int acc_no;
                double taxableIncome;
                int payslipNo;

                cout << "Select Payment to Generate Payslip For:" << endl;
                for (size_t i = 0; i < payments.size(); ++i) {
                    cout << i + 1 << ". Employee Account No: " << payments[i].acc_no << " - Amount: $" << payments[i].amount << endl;
                }

                int payChoice;
                cin >> payChoice;

                if (payChoice >= 1 && payChoice <= payments.size()) {
                    cout << "Enter Payslip Number: ";
                    cin >> payslipNo;
                    taxableIncome = payments[payChoice - 1].amount;
                    payslips.push_back(Payslip(payslipNo, taxableIncome, 0, payments[payChoice - 1].acc_no));
                    cout << "Payslip Generated Successfully!" << endl;
                    cout << "Tax generated: $" << payslips.back().calculateTax() << endl;
                } else {
                    cout << "Invalid selection." << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
