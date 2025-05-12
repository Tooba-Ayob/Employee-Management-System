#include <iostream>
#include <string>


using namespace std; 

struct Employee {
    string Fullname, department, address,Emailaddress, gender, position, nationality;
    int age, ID, Experience;
    double salary;
};

const int MAX_EMPLOYEES = 100; 
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

bool authenticUser();
void displayMenu();
void addEmployee();
void displayEmployeeRecord();
void updateEmployee();
void deleteEmployeeRecord();
void calculateEmployeeSalary();
void handleChoice(int choice);

int main() {
    if (authenticUser()) {
        cout << "Access Granted. Welcome to the Employee Management System!" << endl;

        int choice;
        do {
            displayMenu();
            cout << "Please choose the facility you wish to use: ";
            cin >> choice;
            cin.ignore();
            handleChoice(choice);
        } while (choice != 7);  
    } else {
        cout << "Incorrect Password, access denied." << endl;
    }

    return 0;
}


bool authenticUser() {
    string username, password;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter the password to access the program: ";
    cin >> password;

    return password == "9122024"; 
}


void displayMenu() {  // Displays menu
	
    cout << endl;
    cout << "           WELCOME TO EMPLOYEE MANAGEMENT SYSTEM" << endl;
    cout << "           ________________________________________________" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [1]  | ADD NEW EMPLOYEE                     |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [2]  | DISPLAY EMPLOYEE RECORD              |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [3]  | UPDATE EMPLOYEE                      |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [4]  | CALCULATE EMPLOYEE SALARY            |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [5]  | DELETE EMPLOYEE RECORD               |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [6]  | SEARCH EMPLOYEE                      |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << "           |       |                                      |" << endl;
    cout << "           |  [7]  | QUIT THE PROGRAM                     |" << endl;
    cout << "           |_______|______________________________________|" << endl;
    cout << endl;
   
}


void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Employee array is full!" << endl;
        return;
    }

    Employee newEmployee;

    cout << "Enter the following information to register a new employee:" << endl;

    cout << "Your full name: ";
    cin.ignore(); 
    getline(cin, newEmployee.Fullname);

    cout << "Enter your ID: ";
    cin >> newEmployee.ID;

    cout << "Your age: ";
    cin >> newEmployee.age;

    cin.ignore(); 
    cout << "Your department: ";
    getline(cin, newEmployee.department);

    cout << "Your gender: ";
    getline(cin, newEmployee.gender);

    cout << "Your nationality: ";
    getline(cin, newEmployee.nationality);
    cout << endl;
    
    cout << "Your Address: ";
    getline(cin, newEmployee.address);
    
    cout << "Your Accurate Email Address: ";
    getline(cin, newEmployee.Emailaddress);
    cout<<endl;
    
    cout << "Your Work Experience (in months): ";
    cin>>newEmployee.Experience;
    cin.ignore();
 

   
    if ( newEmployee.Experience <=2) {
    cout << "Sorry, Your Working Experience is too brief. You can't register as an employee here." << endl;
} 
    else {
    cout << "Thank you! Your work experience has been recorded." << endl;
    cout << "Choose the Position you want to acquire: " << endl;
    cout<<"1)Intern\n2)Developer\n3)Manager\n4)graphic designer"<<endl;
    getline(cin, newEmployee.position);
    
}

    
    if (newEmployee.position == "Manager") {
        newEmployee.salary = 80000.0;
    } else if (newEmployee.position == "Intern") {
        newEmployee.salary = 20000.0;
    } else if (newEmployee.position == "Developer") {
        newEmployee.salary = 60000.0;
    } else if (newEmployee.position == "graphic designer") {
        newEmployee.salary = 120000.0;
    } else {
        newEmployee.salary = 4000.0; 
    }

    
    employees[employeeCount++] = newEmployee;

    cout << "Employee registered successfully!" << endl;
}

void displayEmployeeRecord() {
    int ID;
    string name;
    cout << "Enter following info to display the employee's record: " << endl;
    cout << "Employee's full name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter Employee's ID: ";
    cin >> ID;
    cin.ignore(); 

    
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].Fullname == name && employees[i].ID == ID) {
            cout << "Employee Found: " << employees[i].Fullname << ", ID: " << employees[i].ID << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee Not Found!" << endl;
    }
}

void updateEmployee() {
    int ID;
    string fullName;
    cout << "Enter the employee's full name whose record you want to update: ";
    cin.ignore(); 
    getline(cin, fullName);
    cout << "Enter the employee's ID number: ";
    cin >> ID;
    cin.ignore(); 


    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].Fullname == fullName && employees[i].ID == ID) {
            cout << "Employee Found: " << employees[i].Fullname << ", ID: " << employees[i].ID << endl;

            cout << "Enter new department: ";
            getline(cin, employees[i].department);
            cout << "Enter new position: ";
            getline(cin, employees[i].position);
            cout << "Update successful!" << endl;
            return;
        }
    }

    cout << "Employee not Found." << endl;
}

void deleteEmployeeRecord() {
    string name, code;
    int ID;
    cout << "Enter employee's full name whose record you want to delete: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << endl;
    cout << "Enter employee's ID: ";
    cin >> ID;
    cin.ignore(); 
    cout << "You need to enter the confirmation code to modify employee info: ";
    cin >> code;

   
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].Fullname == name && employees[i].ID == ID) {
           
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Employee record deleted successfully!" << endl;
            return;
        }
    }

    cout << "Employee not Found." << endl;
}

void searchEmployee() {
    int searchChoice;
    cout << "Search Employee by: "<<endl;
    cout << "[1] Full Name"<<endl;
    cout << "[2] Employee ID"<<endl;
    cout << "Enter your choice: ";
    cin >> searchChoice;
    cin.ignore(); 

    bool found = false;

    if (searchChoice == 1) {
        string searchName;
        cout << "Enter the full name of the employee: ";
        getline(cin, searchName);

        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].Fullname == searchName) {
                cout << "Employee Found:"<<endl;
                cout << "Name: " << employees[i].Fullname << ", ID: " << employees[i].ID << ", Age: " << employees[i].age <<endl;
                cout << "Department: " << employees[i].department << ", Position: " << employees[i].position <<endl;
                cout << "Gender: " << employees[i].gender << ", Nationality: " << employees[i].nationality << ", Salary: $" << employees[i].salary <<endl;
                found = true;
                break;
            }
        }
    } else if (searchChoice == 2) {
        int searchID;
        cout << "Enter the employee ID: ";
        cin >> searchID;

        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].ID == searchID) {
                cout << "Employee Found: "<<endl;
                cout << "Name: " << employees[i].Fullname << ", ID: " << employees[i].ID << ", Age: " << employees[i].age <<endl;
                cout << "Department: " << employees[i].department << ", Position: " << employees[i].position <<endl;
                cout << "Gender: " << employees[i].gender << ", Nationality: " << employees[i].nationality << ", Salary: $" << employees[i].salary <<endl;
                found = true;
                break;
            }
        }
    } else {
        cout << "Invalid choice! Please select 1 or 2.\n";
        return;
    }

    if (!found) {
        cout << "Employee Not Found.\n";
    }
}

void calculateEmployeeSalary() {
    double incomeTax;
    double netSalary;
    int grossSalary;

    cout << "Please enter the gross salary: ";
    cin >> grossSalary;

  
    if (grossSalary <= 50000) {
        incomeTax = grossSalary * 0.10; // 10 tax for salaries <= 50000
    } else if (grossSalary <= 100000) {
        incomeTax = grossSalary * 0.20; // 20% tax for salaries <= 100000
    } else {
        incomeTax = grossSalary * 0.30; // 30% tax for salaries > 100000
    }

    netSalary = grossSalary - incomeTax;

    cout << "Income Tax: " << incomeTax << endl;
    cout << "Net Salary: " << netSalary << endl;
}

// Function to handle the user's choice
void handleChoice(int choice) {
    switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployeeRecord();
            break;
        case 3:
            updateEmployee();
            break;
        case 4:
            calculateEmployeeSalary();
            break;
        case 5:
            deleteEmployeeRecord();
            break;
        case 6:
           searchEmployee();
            break;
        case 7: 
        cout<<"Exiting the program. Thanks For Using Our Services! "<<endl;
        break;
        
        default:
        	cout<<"Invalid choice. Please enter a number between (1-7). "<<endl;
    }
}
    