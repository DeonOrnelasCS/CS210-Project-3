#include "UserOptions.h"
#include "FileInOut.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Option 1: Prompts user to enter an item name and outputs its frequency in the input file.
void UserOptions::option1() {

    cout << "\nEnter an item name: (Ex. 'Spinach')" << endl;
    cin >> itemName;

    // Capitalize the first character to match file format.
    if (!itemName.empty()) {
        itemName[0] = toupper(itemName[0]);
    }

    // Attempt to open the input file using the FileInOut class.
    FileInOut fileInOut;
    ifstream groceryList = fileInOut.readFile("CS210_Project_Three_Input_File.txt");

    // Exit early if file cannot be opened.
    if (!groceryList.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return;
    }

    frequency = 0; // Reset frequency counter to ensure clean count.
    string line;

    // Read the file line by line and search for matches with the item name.
    while (getline(groceryList, line)) {
        size_t foundItem = line.find(itemName); // Check if the item name appears in the current line.
        if (foundItem != string::npos) {
            frequency++; // Increment frequency counter if the item name is found.
        }
    }
    groceryList.close(); // Close file after use.

    cout << itemName << " " << frequency << endl; // Output frequency results.
}

// Option 2: Prints all items and their corresponding frequency counts.
void UserOptions::option2() {
    cout << "\nPrinting all items and their frequency - List Style.\n" << endl;

    FileInOut fileInOut;

    // Map to retrieve item-frequency data from file.
    map<string, int> itemFrequency = fileInOut.getItemFrequencies("CS210_Project_Three_Input_File.txt");
    
    // Print the item name and frequency count for each item.
    for (auto const &item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

// Option 3: Prints a histogram for each item where the frequency is shown as asterisks.
void UserOptions::option3() {
    cout << "\nPrinting all items and their frequency - Histogram Style.\n" << endl;

    FileInOut fileInOut;

    // Map to retrieve item-frequency data from file.
    map<string, int> itemFrequency = fileInOut.getItemFrequencies("CS210_Project_Three_Input_File.txt");

    // Output the histogram for each item.
    for (auto const &item : itemFrequency) {
        cout << item.first << " ";
        // Print asterisks for each item occurrence.
        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Option 4: Exits the application.
void UserOptions::option4() {
    cout << "Exiting the program, goodbye!" << endl;
    exit(0); // Terminates program.
}
