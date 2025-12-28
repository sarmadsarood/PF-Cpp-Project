# PF-Cpp-Project
Programming Fundamentals project in C++ covering basic concepts and logic building.

1. Project Overview
Purpose:
 The project simulates a mini OS with multiple functionalities:
Academic tools (grades, CGPA, results, student info)


Productivity tools (notes, to-do lists, calculator)


Finance tools (expense tracker, EMI, savings)


Fun & learning tools (Tic-Tac-Toe, quizzes)


System operations (exit)


Structure:
Login System → restricts access to authorized users.


Main Menu → lists all modules. User chooses a module by entering a number.


Switch-Case → backend logic that runs the selected module.


Modules → independent mini-programs.



2. Login System
Features:
User enters username and password.


Maximum 3 attempts allowed.


Correct login → main menu.


Incorrect login → program exits after 3 tries.


Purpose:
 Simulates user authentication before accessing any module.

3. Main Menu
Function:
 Displays numbered options (1–15). Users pick a number to access a module.
Example Menu Layout:
Grading System


CGPA Calculator


Result Generator


Student Management System


Attendance Management System


To-Do Manager


Notes App


Reminder Manager


Calculator


Savings Tracker


Expense Tracker


EMI Calculator


Tic-Tac-Toe Game


Quiz Generator


Exit


Backend Logic:
Implemented using a switch-case.


Each case corresponds to a module.


If user selects an invalid number → error message or loop back to menu.



4. Module Explanations
Academic Modules
Grading System:


Input marks for different subjects.


Convert marks into grades (A+, A, B, etc.)


Shows grade points.


CGPA Calculator:


Takes credit hours and grade points.


Calculates CGPA = (Sum of (Credit × Grade Point)) / Total Credits.


Result Generator:


Combines marks, grades, and CGPA.


Generates a report for the student.


Student Management System:


Stores student data (name, roll no, marks).


Can display, add, or modify student info.


Attendance Management System:


Records and tracks attendance.


Calculates attendance percentage.



Productivity Modules
To-Do Manager:


Add, view, delete tasks.


Helps manage daily productivity.


Notes App:


Create, view, delete notes.


Simulates a simple note-taking system.


Reminder Manager:


Set reminders for tasks/events.


Optionally show notifications (console-based).


Calculator:


Simple arithmetic (add, subtract, multiply, divide).


Scientific functions if added (sin, cos, sqrt, etc.)



Finance Modules
Savings Tracker:


Track income and savings goals.


Displays progress towards goals.


Expense Tracker:


Record daily expenses.


Categorizes expenses.


Shows total spending.


EMI Calculator:


Input loan amount, interest rate, and tenure.


Calculates monthly EMI.



Fun & Learning Modules
Tic-Tac-Toe Game:


Two-player game.


Board displayed in console.


Players take turns placing X or O.


Detects win, loss, or draw.


Quiz Generator (optional):


Presents multiple-choice questions.


Checks answers and scores user.


Can be expanded with question database.



System Tools
Exit:


Ends the program.


Optional: confirm before exit.



5. Program Flow (Step by Step)
Start Program → Show welcome message.


Login Screen → Validate username & password.


Main Menu → Display all modules.


User Chooses Module → Input a number.


Switch-Case Executes Module Logic → Run corresponding mini-program.


After Module Completes → Option to return to main menu or exit.



6. How Switch-Case Works for Modules
switch(choice) {
    case 1:
        gradingSystem();
        break;
    case 2:
        calculateCGPA();
        break;
    ...
    case 13:
        ticTacToe();
        break;
    case 15:
        exit(0);
    default:
        cout << "Invalid choice!";
}

choice = number entered by user.


Each case calls a function for that module.


break; ensures program doesn’t fall into the next case.
