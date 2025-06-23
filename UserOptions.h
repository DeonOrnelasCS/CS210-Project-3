// UserOptions.h
// This file defines the class interface for handling user menu options.

// Header file guards
#ifndef USEROPTIONS_H
#define USEROPTIONS_H

#include <iostream>
#include <string>
using namespace std;

// Class declaration
class UserOptions {

private:
    int frequency{0}; // Stores frequency count for an item (Used in Option 1).
    string itemName; // HStores the name of the item entered by the user.

public:
    void option1(); // Handles Option 1: Display frequency of a specific item entered by the user.
    void option2(); // Handles Option 2: Display all items and their frequencies in a list format.
    void option3(); // Handles Option 3: Display all items and their frequencies using a histogram format.
    void option4(); // Handles Option 4: Exits the program.

};


// Header file guard
#endif //USEROPTIONS_H
