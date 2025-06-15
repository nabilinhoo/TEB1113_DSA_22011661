#include <iostream>
#include <string>
using namespace std;

// Define structure for Student
struct Student {
    string name;
    string studentID;
    string contact;
    string email;
};

int main() {
    const int MAX_STUDENTS = 5;
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n===== Student Database Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                cout << "Student limit reached (5 students only).\n";
                continue;
            }

            Student* s = &students[count];  // Use pointer to access array element

            cout << "Enter name: ";
            getline(cin, s->name);

            cout << "Enter student ID: ";
            getline(cin, s->studentID);

            cout << "Enter contact number: ";
            getline(cin, s->contact);

            cout << "Enter email: ";
            getline(cin, s->email);

            count++;
            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No students to display.\n";
            } else {
                cout << "\n--- Student Records ---\n";
                for (int i = 0; i < count; i++) {
                    Student* s = &students[i];
                    cout << "\nStudent #" << i + 1 << endl;
                    cout << "Name      : " << s->name << endl;
                    cout << "ID        : " << s->studentID << endl;
                    cout << "Contact   : " << s->contact << endl;
                    cout << "Email     : " << s->email << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}