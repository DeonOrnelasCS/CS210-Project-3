// PrintMenu.h
// This file prints the main menu that the user interacts with.

// Header file guards.
#ifndef PRINTMENU_H
#define PRINTMENU_H


// PrintMenu class handles displaying a menu of options to the user
// and processing user input to select a desired option.
class PrintMenu {
private:
    int menuOption{0}; // Stores the numeric menu selection entered by the user.
public:
    void printMenuOptions(); // Displays the available menu options and takes the user's selection.

};



#endif //PRINTMENU_H
