#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LexiaProject.h"

using namespace std;

void createProject(const string& projectName) {
    ofstream projectFile(projectName + ".lexproj");
    if(projectFile.is_open()) {
        cout << "Project '" << projectName << "' was successfully created." << endl;
        projectFile << "minRandomLimit 1" << endl; // Минимальное значение по умолчанию
        projectFile << "maxRandomLimit 10" << endl; // Максимальное значение по умолчанию
        projectFile.close();
    } else {
        cerr << "Error: failed to create a project file." << endl;
    }
}


void editProject(const string& projectName) {
    LexiaProject project;
    project.loadProject(projectName + ".lexproj");
    bool editing = true;
    while (editing) {
        cout << "\nEditing a project: " << projectName << endl;
        cout << "1. Edit the randomizer limits" << endl;
        cout << "2. Add Action options" << endl;
        cout << "3. Save and exit" << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int minLimit, maxLimit;
                 cout << "Current Randomizer limit: min " << project.getMinRandomLimit() << " and max " << project.getMaxRandomLimit() << endl;
                cout << "New minimum limit: ";
                cin >> minLimit;
                 cout << "New maximum limit: ";
                cin >> maxLimit;
                project.setMinRandomLimit(minLimit);
                project.setMaxRandomLimit(maxLimit);
                 cout << "The randomizer limit is set to: min " << project.getMinRandomLimit() << " and max " << project.getMaxRandomLimit() << endl;
                break;
            }
            case 2: {
                string actionText;
                cout << "Enter an action option: ";
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, actionText);
                project.addAction(actionText);
                 cout << "Option '" << actionText << "' has been added to the list." << endl;
                break;
            }
            case 3: {
                project.saveProject(projectName + ".lexproj");
                cout << "Project '" << projectName << "' saved." << endl;
                editing = false;
                break;
            }
            default: {
                cout << "Wrong choice. Try again." << endl;
                break;
            }
        }
    }
}

int main() {
    string projectName;
    cout << "Enter the name of the project: ";
    cin >> projectName;

    bool projectExists = false;

    ifstream projectFile(projectName + ".lexproj");
    if (projectFile.good()) {
        projectExists = true;
    }
     projectFile.close();

    if(!projectExists) {
       cout << "Project '" << projectName << "' not found. Do you want to create a new one? (y/n): ";
       char createChoice;
        cin >> createChoice;

        if (createChoice == 'y') {
            createProject(projectName);
             editProject(projectName);
            } else {
                cout << "Cancel." << endl;
                return 0;
            }

        } else {
           editProject(projectName);
        }
    
    
    return 0;
}