#include "PrintMenu.h"
#include "UserOptions.h"
#include <iostream>

using namespace std;

// This method prints the Corner Grocer menu and prompts the user to select an option.
// It validates input and allows repeated use until the user chooses to exit.
void PrintMenu::printMenuOptions() {
    cout << "Welcome to the Corner Grocer app!\n\n";
    char loopAgain = 'n'; // Flag to determine if user wants to make another selection.
    do {
        int menuOption{0}; // Stores the user's selection.

        // Print the menu options.
        cout << "Enter a number to make a selection.\n"
             << "-----------------------------------\n";
             cout << "Enter 1 to print frequency of a specific item\n"
             << "Enter 2 to print all items and their frequency\n"
             << "Enter 3 to print all items and their frequency - Histogram Style\n"
             << "Enter 4 to exit the program\n";
        bool validInput = false; // Flag to determine if user input is valid.

        // Input validation and menu processing loop.
        do {
            cout << "Your selection: ";
            if (!(cin >> menuOption)) { // Handle non-numeric input.
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            UserOptions userOptions; // Create an instance of UserOptions to handle the selected action.

            switch (menuOption) { // Process the user's menu selection.
                case 1:
                    userOptions.option1();
                    validInput = true;
                    break;
                case 2:
                    userOptions.option2();
                    validInput = true;
                    break;
                case 3:
                    userOptions.option3();
                    validInput = true;
                    break;
                case 4:
                    userOptions.option4();
                    validInput = true;
                    break;
                default:
                    // Handle invalid numeric input.
                    cout << "Invalid selection. Please pick an option 1-4.\n";
                    break;
            }
        } while (!validInput); // Repeat until valid option is selected.

        // Prompt user to make another selection or exit.
        cout << "\nWould you like to make another selection? ('Y'/'N'): ";
        cin >> loopAgain;
        cin.ignore(); // Clear the input buffer.
        cout << endl;
    } while (loopAgain == 'Y' || loopAgain == 'y'); // Repeat until user chooses to exit.

    cout << "Exiting the program, goodbye!\n";
}
