#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name, position;
    int id, daysWorked;
    double salaryPerDay;
    bool exists = false;
};

bool askContinue() {
    char again;
    cout << "\nDo you want to return to the menu? (Y/N): ";
    cin >> again;

    if (again == 'Y' || again == 'y') {
        return true; 
    } else {
        cout << "\nThank you for using WOAH System!\n";
        exit(0);
    }
}

int main() {
    const int MAX = 100;           
    Employee emp[MAX];             
    int count = 0;   

    
    string storedNames[5]  = {"Pauleen", "Jhon Mark", "Mark", "Jiro", "Jhared"};
    int storedIDs[5]       = {1001, 1002, 1003, 1004, 1005};
    string storedPos[5]    = {"IT Support", "Network Administrator", "Cloud Engineer", "IT Manager", "Software Developer"};
    double storedSalary[5] = {900, 1200, 1500, 2500, 1700};
    int storedDays[5]      = {20, 18, 22, 25, 19};

    for (int i = 0; i < 5; i++) {
        emp[count].name          = storedNames[i];
        emp[count].id            = storedIDs[i];
        emp[count].position      = storedPos[i];
        emp[count].salaryPerDay  = storedSalary[i];
        emp[count].daysWorked    = storedDays[i];
        emp[count].exists        = true;
        count++;
    }

    int choice;
    
    while (true) {
        cout << "____________________________" << endl;
        cout << "\n==== EMPLOYEE PAYROLL SYSTEM ====\n";
        cout << "____________________________" << endl;
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Print Payslip\n";
        cout << "4. Search Employee by ID\n";
        cout << "5. List Employees\n";
        cout << "6. Exit\n";
        cout << "____________________________" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "\n-------------------"<<endl;
            cout << "| Invalid Option! |"<<endl;
            cout << "-------------------"<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        if (choice == 1) { 
            if (count >= MAX) {
                cout << "\nEmployee list is full!\n";
                continue;
            }
            cout << "____________________________" << endl;
            cout << "\n=== ADD EMPLOYEE ===\n";

            cout << "Enter Employee Name: ";
            cin >> emp[count].name;

            cout << "Enter Employee ID: ";
            cin >> emp[count].id;

            cout << "\n===Choose Position===\n";
            cout << "1. IT Support\n";
            cout << "2. Network Administrator\n";
            cout << "3. Cloud Engineer\n";
            cout << "4. IT Manager\n";
            cout << "5. Cybersecurity Specialist\n";
            cout << "6. Software Developer\n";
            cout << "7. Data Analyst\n";

            int pos;
            cout << "____________________________" << endl;
            cout << "Enter choice: ";
            cin >> pos;

            switch (pos) {
                case 1: emp[count].position = "IT Support"; emp[count].salaryPerDay = 900; break;
                case 2: emp[count].position = "Network Administrator"; emp[count].salaryPerDay = 1200; break;
                case 3: emp[count].position = "Cloud Engineer"; emp[count].salaryPerDay = 1500; break;
                case 4: emp[count].position = "IT Manager"; emp[count].salaryPerDay = 2500; break;
                case 5: emp[count].position = "Cybersecurity Specialist"; emp[count].salaryPerDay = 2000; break;
                case 6: emp[count].position = "Software Developer"; emp[count].salaryPerDay = 1700; break;
                case 7: emp[count].position = "Data Analyst"; emp[count].salaryPerDay = 1300; break;
                default: cout << "Invalid position!\n"; continue;
            }

            cout << "____________________________" << endl;
            cout << "Enter Days Worked: ";
            cin >> emp[count].daysWorked;

            emp[count].exists = true;
            count++;

            cout << "\nEmployee added successfully!\n";

            askContinue();
        }

        else if (choice == 2) { 

            if (count == 0) {
                cout << "\nNo employees to remove!\n";
                askContinue();
            }

            int id;
            cout << "____________________________" << endl;
            cout << "Enter Employee ID to remove: " << endl;
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (emp[i].exists && emp[i].id == id) {
                    emp[i].exists = false;
                    cout << "Employee removed successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nEmployee not found!\n";

            askContinue();
        }

        else if (choice == 3) { 

            int id;
            cout << "\nEnter Employee ID: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++) {

                if (emp[i].exists && emp[i].id == id) {
                    found = true;

                    double gross = emp[i].salaryPerDay * emp[i].daysWorked;
                    double sss = gross * 0.045;
                    double phil = gross * 0.035;
                    double totalDed = sss + phil;
                    double net = gross - totalDed;

                    cout << "____________________________" << endl;
                    cout << "\n=========== PAYSLIP ===========\n";
                    cout << "*****************************************" << endl;
                    cout << "INFORMATION             LIST" << endl;
                    cout << "* Employee Name:           " << emp[i].name << endl;
                    cout << "* Employee ID:             " << emp[i].id << endl;
                    cout << "* Position:                " << emp[i].position << endl;
                    cout << "* Daily Rate:              ₱" << emp[i].salaryPerDay << endl;
                    cout << "* Days Worked:             " << emp[i].daysWorked << endl;
                    cout << "*****************************************" << endl;
                    cout << "DEDUCTION               PRICE" << endl;
                    cout << "* Gross Salary:              ₱" << gross << endl;
                    cout << "* SSS Deduction:             ₱" << sss << endl;
                    cout << "* PhilHealth Deduction:      ₱" << phil << endl;
                    cout << "*****************************************" << endl;
                    cout << "TOTAL DEDUCTION         PRICE" << endl;
                    cout << "* Total Deductions:        ₱" << totalDed << endl;
                    cout << "*****************************************" << endl;
                    cout << "TOTAL                   PRICE" << endl;
                    cout << "* NET SALARY:              ₱" << net << endl;
                    cout << "=============================================\n";

                    askContinue();
                }
            }

            if (!found)
                cout << "\nEmployee not found!\n";

            askContinue();
        }

        else if (choice == 4) { 

            int id;
            cout << "\nEnter ID to search: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (emp[i].exists && emp[i].id == id) {
                    cout << "\nEmployee Found!\n";
                    cout << "Name: " << emp[i].name << endl;
                    cout << "ID: " << emp[i].id << endl;
                    cout << "Position: " << emp[i].position << endl;
                    cout << "Daily Rate: ₱" << emp[i].salaryPerDay << endl;
                    cout << "Days Worked: " << emp[i].daysWorked << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "\nEmployee not found!\n";

            askContinue();
        }

        else if (choice == 5) {

            if (count == 0) {
                cout << "\nNo employees stored!\n";
                askContinue();
            }

            cout << "\n=== EMPLOYEE LIST ===\n";

            for (int i = 0; i < count; i++) {
                if (emp[i].exists) {
                    cout << "\nEmployee " << i + 1 << ":\n";
                    cout << "Name: " << emp[i].name << endl;
                    cout << "ID: " << emp[i].id << endl;
                    cout << "Position: " << emp[i].position << endl;
                    cout << "Daily Rate: ₱" << emp[i].salaryPerDay << endl;
                    cout << "Days Worked: " << emp[i].daysWorked << endl;
                }
            }

            askContinue();
        }

        else if (choice == 6) {
            cout << "\nThank you for using WOAH System";
            return 0;
        }

        else {
            cout << "\nInvalid Option!\n";
        }
    }

    return 0;
}