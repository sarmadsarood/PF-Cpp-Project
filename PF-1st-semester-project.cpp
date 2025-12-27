#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
struct Expense {
    string category;
    float amount;
};

// TIC TAAC TOE
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

// Display board
void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Check winner
char checkWinner() {
    // Rows & columns
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return board[0][i];
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return board[0][2];
    return ' ';
}


int main() {

    // ===== LOGIN SYSTEM =====
    string username, password;
    string correctUsername = "SARMAD SAROOD";
    string correctPassword = "SARMAD";
    int attempts = 3;

    cout << "----- Login System -----\n";

    cin.ignore();  // ensure clean input buffer

    while(attempts > 0) {
        cout << "Enter username: ";
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);

        if(username == correctUsername && password == correctPassword) {
            cout << "Login Successful!\n";
            break;
        } 
        else {
            attempts--;
            cout << "Incorrect username or password. Attempts left: "
                 << attempts << "\n";
        }
    }

    if(attempts == 0) {
        cout << "Access Denied. Exiting...\n";
        return 0;
    }

    // ===== MAIN MENU =====
    int choice;
    do {
        cout << "\n===== OS MAIN MENU =====\n\n";
        cout << "A. Academic Tools (5 modules)\n\n";
        cout << "1. Grading System\n";
        cout << "2. CGPA Calculator\n";
        cout << "3. Result Generator\n";
        cout << "4. Student Management System\n";
        cout << "5. Attendance Management System\n\n";
        cout << "B. Productivity Tools (4 modules)\n\n";
        cout << "6. To-Do Manager\n";
        cout << "7. Notes App\n";
        cout << "8. Reminder Manager\n";
        cout << "9. Calculator\n\n";
        cout << "C. Finance Tools (3 modules)\n\n";
        cout << "10. Savings Tracker\n";
        cout << "11. Expense Tracker\n";
        cout << "12. EMI Calculator\n\n";
        cout << "D. Fun & Learning Tools (2 modules)\n\n";
        cout << "13. Tic-Tac-Toe Game\n";
        cout << "14. Quiz Generator\n\n";
        cout << "E. System Tools (1 module)\n\n";
        cout << "15. Exit OS\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Grading System Module\n";
			   {
			   int n;
    cout << "Enter the number of subjects: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of subjects must be positive!";
        return 0;
    }

    float totalMarks = 0, obtainedMarks = 0, mark;
    for (int i = 1; i <= n; i++) {
        cout << "Enter total marks for subject " << i << ": ";
        cin >> mark;
        if (mark < 0) {
            cout << "Marks cannot be negative!" << endl;
            i--; // Repeat this subject input
            continue;
        }
        totalMarks += mark;

        cout << "Enter obtained marks for subject " << i << ": ";
        cin >> mark;
        if (mark < 0) {
            cout << "Marks cannot be negative!" << endl;
            i--; // Repeat this subject input
            continue;
        }
        obtainedMarks += mark;
    }

    float percentage = (obtainedMarks / totalMarks) * 100;
    char grade;

    if (percentage >= 85 && percentage <= 100)
        grade = 'A';
    else if (percentage >= 75 && percentage < 85)
        grade = 'B';
    else if (percentage >= 65 && percentage < 75)
        grade = 'C';
    else if (percentage >= 50 && percentage < 65)
        grade = 'D';
    else
        grade = 'F';

    cout << "\n-----Final Result-----\n";
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Obtained Marks: " << obtainedMarks << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;

			 }break;
            case 2: cout << "CGPA Calculator Module\n"; 
			{
				    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of subjects must be positive!";
        return 0;
    }

    float credit, marks, totalCredit = 0, totalPoints = 0, percentage, gradePoint;

    for (int i = 1; i <= n; i++) {
        cout << "\nSubject " << i << endl;

        cout << "Enter credit hours: ";
        cin >> credit;
        if (credit < 0) {
            cout << "Credit hours cannot be negative!" << endl;
            i--; 
            continue;
        }

        cout << "Enter marks obtained: ";
        cin >> marks;
        if (marks < 0) {
            cout << "Marks cannot be negative!" << endl;
            i--; 
            continue;
        }

        cout << "Enter total marks for this subject: ";
        float totalMarks;
        cin >> totalMarks;
        if (totalMarks <= 0) {
            cout << "Total marks must be positive!" << endl;
            i--; 
            continue;
        }

        percentage = (marks / totalMarks) * 100;

        if (percentage >= 85)
            gradePoint = 4.0; // A+
        else if (percentage >= 75)
            gradePoint = 3.5; // A
        else if (percentage >= 65)
            gradePoint = 3.0; // B
        else if (percentage >= 50)
            gradePoint = 2.5; // C
        else if (percentage >= 40)
            gradePoint = 2.0; // D
        else
            gradePoint = 0.0; // F

        totalCredit += credit;
        totalPoints += (gradePoint * credit);
    }

    float CGPA = totalPoints / totalCredit;

    cout << "\n-----Final Result-----\n";
    cout << "Total Credit Hours: " << totalCredit << endl;
    cout << "Total Grade Points: " << totalPoints << endl;
    cout << "CGPA: " << CGPA << endl;

			}
			break;
            case 3: cout << "Result Generator Module\n";
			{
				  int n;
    cout << "Enter the number of subjects: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of subjects must be positive!";
        return 0;
    }

    float totalMarks = 0, obtainedMarks = 0;
    float totalCredit = 0, totalPoints = 0;

    float marks, subjectTotal, credit, percentage, gradePoint;
    char grade;

    cout << "\n-----Subject-wise Input-----\n";

    for (int i = 1; i <= n; i++) {
        cout << "\nSubject " << i << endl;

        cout << "Enter total marks: ";
        cin >> subjectTotal;
        if (subjectTotal <= 0) {
            cout << "Total marks must be positive!" << endl;
            i--;
            continue;
        }

        cout << "Enter obtained marks: ";
        cin >> marks;
        if (marks < 0) {
            cout << "Obtained marks cannot be negative!" << endl;
            i--;
            continue;
        }

        cout << "Enter credit hours: ";
        cin >> credit;
        if (credit < 0) {
            cout << "Credit hours cannot be negative!" << endl;
            i--;
            continue;
        }

        percentage = (marks / subjectTotal) * 100;

        // Determine grade
        if (percentage >= 85)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 65)
            grade = 'C';
        else if (percentage >= 50)
            grade = 'D';
        else
            grade = 'F';

        // Determine grade point for CGPA
        if (percentage >= 85)
            gradePoint = 4.0; // A+
        else if (percentage >= 75)
            gradePoint = 3.5; // A
        else if (percentage >= 65)
            gradePoint = 3.0; // B
        else if (percentage >= 50)
            gradePoint = 2.5; // C
        else if (percentage >= 40)
            gradePoint = 2.0; // D
        else
            gradePoint = 0.0; // F

        totalMarks += subjectTotal;
        obtainedMarks += marks;
        totalCredit += credit;
        totalPoints += gradePoint * credit;

        cout << fixed << setprecision(2);
        cout << "Subject " << i << " -> Percentage: " << percentage << "%, Grade: " << grade << endl;
    }

    float percentageOverall = (obtainedMarks / totalMarks) * 100;
    float CGPA = totalPoints / totalCredit;

    cout << "\n-----Final Result-----\n";
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Obtained Marks: " << obtainedMarks << endl;
    cout << "Overall Percentage: " << percentageOverall << "%" << endl;
    cout << "Total Credit Hours: " << totalCredit << endl;
    cout << "Total Grade Points: " << totalPoints << endl;
    cout << "CGPA: " << CGPA << endl;

    // Optional remarks based on CGPA
    if (CGPA >= 3.5)
        cout << "Remarks: Excellent (A+)" << endl;
    else if (CGPA >= 3.0)
        cout << "Remarks: Very Good (A)" << endl;
    else if (CGPA >= 2.5)
        cout << "Remarks: Good (C)" << endl;
    else if (CGPA >= 2.0)
        cout << "Remarks: Satisfactory (D)" << endl;
    else if (CGPA >= 1.5)
        cout << "Remarks: Probation" << endl;
    else
        cout << "Remarks: Fail (F)" << endl;


			}
			 break;
            case 4: cout << "Student Management System Module\n"; 
			{
				    int totalStudents;

    cout << "Enter total number of students: ";
    cin >> totalStudents;

    // Arrays
    string names[100];
    int ages[100];
    int roll[100];

    int count = 0;
    int choice;

    cin.ignore(); // fix input buffer issue

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clean buffer after numeric input

        if (choice == 1) {
            if (count >= totalStudents) {
                cout << "Limit reached! Cannot add more students.\n";
            } else {
                cout << "Enter name: ";
                getline(cin, names[count]);

                cout << "Enter age: ";
                cin >> ages[count];

                cout << "Enter roll number: ";
                cin >> roll[count];

                cin.ignore(); // clear buffer
                count++;

                cout << "Student added successfully!\n";
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No students added yet.\n";
            } else {
                cout << "\n----- All Students -----\n";
                for (int i = 0; i < count; i++) {
                    cout << "Name: " << names[i]
                         << " | Age: " << ages[i]
                         << " | Roll: " << roll[i] << endl;
                }
            }
        }

        else if (choice == 3) {
            int r;
            cout << "Enter roll number to search: ";
            cin >> r;

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (roll[i] == r) {
                    cout << "\nStudent Found:\n";
                    cout << "Name: " << names[i] << endl;
                    cout << "Age: " << ages[i] << endl;
                    cout << "Roll: " << roll[i] << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found!\n";
            }

            cin.ignore();
        }

    } while (choice != 4);

    cout << "Exiting program...\n";

			}
			break;
            case 5: cout << "Attendance Management System Module\n"
            ;{
                 int totalStudents;
    cout << "Enter total number of students: ";
    cin >> totalStudents;

    string names[100];
    int roll[100];
    int attendance[100]; // 1 = present, 0 = absent

    int count = 0;
    int choice;

    cin.ignore();

    do {
        cout << "\n===== ATTENDANCE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance (Present/Absent)\n";
        cout << "3. View Attendance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= totalStudents) {
                cout << "Limit reached! Cannot add more students.\n";
            } else {
                cout << "Enter student name: ";
                getline(cin, names[count]);

                cout << "Enter roll number: ";
                cin >> roll[count];

                attendance[count] = -1; // not marked yet

                cin.ignore();
                count++;

                cout << "Student added successfully!\n";
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No students to mark attendance.\n";
            } else {
                cout << "\nMark attendance for each student (1 = Present, 0 = Absent)\n\n";
                for (int i = 0; i < count; i++) {
                    cout << "Name: " << names[i] << " | Roll: " << roll[i] << " => ";
                    cin >> attendance[i];

                    // No negative or invalid values
                    while (attendance[i] != 0 && attendance[i] != 1) {
                        cout << "Invalid! Enter 1 for Present or 0 for Absent: ";
                        cin >> attendance[i];
                    }
                }
                cin.ignore();
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "No students added yet.\n";
            } else {
                cout << "\n----- ATTENDANCE RECORD -----\n";
                for (int i = 0; i < count; i++) {
                    cout << "Name: " << names[i]
                         << " | Roll: " << roll[i]
                         << " | Attendance: "
                         << (attendance[i] == 1 ? "Present" : attendance[i] == 0 ? "Absent" : "Not Marked")
                         << endl;
                }
            }
        }

    } while (choice != 4);

    cout << "Exiting program...\n";

            }
             break;
            case 6: cout << "To-Do Manager Module\n";
            {
                  int totalTasks;

    cout << "Enter total number of tasks you want to manage: ";
    cin >> totalTasks;

    string tasks[100];
    bool done[100];

    int count = 0;
    int choice;

    cin.ignore();

    do {
        cout << "\n===== TO-DO MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= totalTasks) {
                cout << "Task limit reached!\n";
            } else {
                cout << "Enter task: ";
                getline(cin, tasks[count]);
                done[count] = false;
                count++;
                cout << "Task added!\n";
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No tasks added yet.\n";
            } else {
                cout << "\n----- ALL TASKS -----\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " 
                         << tasks[i] 
                         << " [" << (done[i] ? "Done" : "Pending") << "]\n";
                }
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter task number to mark as done: ";
            cin >> num;

            if (num < 1 || num > count) {
                cout << "Invalid task number!\n";
            } else {
                done[num - 1] = true;
                cout << "Task marked as done!\n";
            }
        }

        else if (choice == 4) {
            int num;
            cout << "Enter task number to delete: ";
            cin >> num;

            if (num < 1 || num > count) {
                cout << "Invalid task number!\n";
            } else {
                for (int i = num - 1; i < count - 1; i++) {
                    tasks[i] = tasks[i + 1];
                    done[i] = done[i + 1];
                }
                count--;
                cout << "Task deleted!\n";
            }
        }

    } while (choice != 5);

    cout << "Exiting program...\n";

            }break;
            case 7: cout << "Notes App Module\n";
            {
                   int totalNotes;

    cout << "Enter total number of notes you want to manage: ";
    cin >> totalNotes;

    string notes[100];
    int count = 0;
    int choice;

    cin.ignore(); // clear buffer

    do {
        cout << "\n===== NOTES APP =====\n";
        cout << "1. Add Note\n";
        cout << "2. View All Notes\n";
        cout << "3. Edit Note\n";
        cout << "4. Delete Note\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= totalNotes) {
                cout << "Limit reached! Cannot add more notes.\n";
            } else {
                cout << "Write your note: ";
                getline(cin, notes[count]);
                count++;
                cout << "Note saved!\n";
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No notes available.\n";
            } else {
                cout << "\n----- ALL NOTES -----\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << notes[i] << endl;
                }
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter note number to edit: ";
            cin >> num;
            cin.ignore();

            if (num < 1 || num > count) {
                cout << "Invalid note number!\n";
            } else {
                cout << "Enter new text: ";
                getline(cin, notes[num - 1]);
                cout << "Note updated!\n";
            }
        }

        else if (choice == 4) {
            int num;
            cout << "Enter note number to delete: ";
            cin >> num;

            if (num < 1 || num > count) {
                cout << "Invalid note number!\n";
            } else {
                for (int i = num - 1; i < count - 1; i++) {
                    notes[i] = notes[i + 1];
                }
                count--;
                cout << "Note deleted!\n";
            }
        }

    } while (choice != 5);

    cout << "Exiting Notes App...\n";

            }break;
            case 8: cout << "Reminder Manager Module\n";
            {
                    int maxReminders;

    cout << "Enter how many reminders you want to store: ";
    cin >> maxReminders;

    string reminders[100];
    bool done[100];
    int count = 0;
    int choice;

    cin.ignore();

    do {
        cout << "\n===== REMINDER MANAGER =====\n";
        cout << "1. Add Reminder\n";
        cout << "2. View Reminders\n";
        cout << "3. Mark Reminder as Done\n";
        cout << "4. Delete Reminder\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= maxReminders) {
                cout << "Limit reached! Can't add more.\n";
            } else {
                cout << "Enter reminder text: ";
                getline(cin, reminders[count]);
                done[count] = false;
                count++;
                cout << "Reminder added!\n";
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No reminders created yet.\n";
            } else {
                cout << "\n----- ALL REMINDERS -----\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " 
                         << reminders[i]
                         << " [" << (done[i] ? "Done" : "Pending") << "]\n";
                }
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter reminder number to mark as done: ";
            cin >> num;

            if (num < 1 || num > count) {
                cout << "Invalid reminder number!\n";
            } else {
                done[num - 1] = true;
                cout << "Marked as done!\n";
            }
        }

        else if (choice == 4) {
            int num;
            cout << "Enter reminder number to delete: ";
            cin >> num;

            if (num < 1 || num > count) {
                cout << "Invalid reminder number!\n";
            } else {
                for (int i = num - 1; i < count - 1; i++) {
                    reminders[i] = reminders[i + 1];
                    done[i] = done[i + 1];
                }
                count--;
                cout << "Reminder deleted!\n";
            }
        }

    } while (choice != 5);

    cout << "Exiting Reminder Manager...\n";

            }break;
            case 9: cout << "Calculator Module\n";
            {
                  int choice;

    do {
        cout << "\n=========== CALCULATOR ===========\n";
        cout << "1. Simple Calculator\n";
        cout << "2. Scientific Calculator\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int op;
            double a, b;

            cout << "\n--- SIMPLE CALCULATOR ---\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "Enter operation: ";
            cin >> op;

            cout << "Enter first number: ";
            cin >> a;

            cout << "Enter second number: ";
            cin >> b;

            if (op == 1) cout << "Result: " << a + b << endl;
            else if (op == 2) cout << "Result: " << a - b << endl;
            else if (op == 3) cout << "Result: " << a * b << endl;
            else if (op == 4) {
                if (b == 0) cout << "Error: Division by zero not allowed!\n";
                else cout << "Result: " << a / b << endl;
            } else {
                cout << "Invalid choice!\n";
            }
        }

        else if (choice == 2) {
            int op;
            double x;

            cout << "\n--- SCIENTIFIC CALCULATOR ---\n";
            cout << "1. Square root\n";
            cout << "2. Power (x^y)\n";
            cout << "3. Log (base 10)\n";
            cout << "4. Natural log (ln)\n";
            cout << "5. Sin\n";
            cout << "6. Cos\n";
            cout << "7. Tan\n";
            cout << "Enter operation: ";
            cin >> op;

            if (op == 2) {
                double y;
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter y: ";
                cin >> y;
                cout << "Result: " << pow(x, y) << endl;
            } 
            else {
                cout << "Enter number: ";
                cin >> x;

                if (op == 1) cout << "Result: " << sqrt(x) << endl;
                else if (op == 3) cout << "Result: " << log10(x) << endl;
                else if (op == 4) cout << "Result: " << log(x) << endl;
                else if (op == 5) cout << "Result: " << sin(x) << endl;
                else if (op == 6) cout << "Result: " << cos(x) << endl;
                else if (op == 7) cout << "Result: " << tan(x) << endl;
                else cout << "Invalid choice!\n";
            }
        }

    } while (choice != 3);

    cout << "Exiting Calculator...\n";

            }break;
            case 10: cout << "Savings Tracker Module\n";
            {
                  float income = 0, expense = 0, amount;
    int choice;

    cout << "----- Savings Tracker -----\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Show Savings Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter income amount: ";
                cin >> amount;
                if(amount < 0){
                    cout << "Amount cannot be negative!\n";
                    break;
                }
                income += amount;
                cout << "Income added successfully.\n";
                break;

            case 2:
                cout << "Enter expense amount: ";
                cin >> amount;
                if(amount < 0){
                    cout << "Amount cannot be negative!\n";
                    break;
                }
                expense += amount;
                cout << "Expense added successfully.\n";
                break;

            case 3:
                cout << "\n----- Savings Summary -----\n";
                cout << "Total Income: " << income << endl;
                cout << "Total Expenses: " << expense << endl;
                cout << "Net Savings: " << (income - expense) << endl;
                break;

            case 4:
                cout << "Exiting Savings Tracker. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 4);
            }break;
            case 11: cout << "Expense Tracker Module\n";
            {
                
                 vector<Expense> expenses;
    int choice;
    string category;
    float amount;

    cout << "----- Expense Tracker -----\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Expense\n";
        cout << "2. Show Expenses Summary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // <-- Important: ignore leftover newline

        switch(choice) {
            case 1:
                cout << "Enter expense category: ";
                getline(cin, category); // Works fine after cin.ignore()
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore(); // Ignore newline after amount input
                if(amount < 0){
                    cout << "Amount cannot be negative!\n";
                    break;
                }
                expenses.push_back({category, amount});
                cout << "Expense added successfully.\n";
                break;

            case 2:
                if(expenses.empty()){
                    cout << "No expenses recorded yet.\n";
                    break;
                }
                float total;
                total = 0;
                cout << "\n----- Expense Summary -----\n";
                for (int i = 0; i < expenses.size(); i++) {
                   cout << "Category: " << expenses[i].category
         << ", Amount: " << expenses[i].amount << endl;
    total += expenses[i].amount;
                }
                cout << "Total Expenses: " << total << endl;
                break;

            case 3:
                cout << "Exiting Expense Tracker. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 3);

            }break;
            case 12: cout << "EMI Calculator Module\n"; 
            {
                  double principal, annualRate, tenureMonths, monthlyRate, EMI;

    cout << "----- EMI Calculator -----\n";

    cout << "Enter Principal Amount: ";
    cin >> principal;
    if(principal < 0){
        cout << "Principal cannot be negative!";
        return 0;
    }

    cout << "Enter Annual Interest Rate (in %): ";
    cin >> annualRate;
    if(annualRate < 0){
        cout << "Interest rate cannot be negative!";
        return 0;
    }

    cout << "Enter Loan Tenure (in months): ";
    cin >> tenureMonths;
    if(tenureMonths <= 0){
        cout << "Tenure must be positive!";
        return 0;
    }

    // Convert annual rate to monthly rate
    monthlyRate = (annualRate / 12) / 100;

    // EMI formula
    EMI = (principal * monthlyRate * pow(1 + monthlyRate, tenureMonths)) / (pow(1 + monthlyRate, tenureMonths) - 1);

    cout << "\nYour Monthly EMI is: " << EMI << endl;

                }break;
            case 13: cout << "Tic-Tac-Toe Game Module\n";
            {
                 int move;
    char player = 'X';
    char winner = ' ';
    int movesMade = 0;

    cout << "----- Tic-Tac-Toe -----\n";
    displayBoard();

    while(winner==' ' && movesMade<9){
        cout << "Player " << player << ", enter cell number (1-9): ";
        cin >> move;

        if(move<1 || move>9){
            cout << "Invalid input! Try again.\n";
            continue;
        }

        int row = (move-1)/3;
        int col = (move-1)%3;

        if(board[row][col]=='X' || board[row][col]=='O'){
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = player;
        movesMade++;
        displayBoard();

        winner = checkWinner();
        if(winner != ' ') break;

        player = (player=='X') ? 'O' : 'X';
    }

    if(winner != ' ')
        cout << "Player " << winner << " wins!\n";
    else
        cout << "It's a draw!\n";

                }break;
            case 14: cout << "Quiz Generator Module\n";{
                 char answer;
    int score = 0;

    cout << "----- Quiz -----\n";

    // Question 1
    cout << "1. What is the capital of Pakistan?\n";
    cout << "a) Karachi\nb) Lahore\nc) Islamabad\nd) Peshawar\n";
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'c' || answer == 'C') score++;

    // Question 2
    cout << "\n2. Which language is used for web development?\n";
    cout << "a) Python\nb) C++\nc) HTML\nd) Java\n";
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'c' || answer == 'C') score++;

    // Question 3
    cout << "\n3. What is 5 + 7?\n";
    cout << "a) 10\nb) 12\nc) 13\nd) 14\n";
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'b' || answer == 'B') score++;

    // Final score
    cout << "\n----- Quiz Finished -----\n";
    cout << "Your Score: " << score << "/3" << endl;

            } break;
            case 15: cout << "Exiting OS. Goodbye!\n"; break;

            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 15);

    return 0;
}

