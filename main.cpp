#include "FileInOut.h"
#include "PrintMenu.h"

// Main function: Entry point for the Corner Grocer application.
// Performs a backup operation before user interaction, then launches the interactive menu.
int main() {

    // Generate frequency data from the input file:
    // Reads all items from "CS210_Project_Three_Input_File.txt" and tallies occurrences.
    map<string, int> freqData = FileInOut::getItemFrequencies("CS210_Project_Three_Input_File.txt");

    // Write the frequency data to a backup file "frequency.dat".
    FileInOut::writeFile(freqData);

    // Create an instance of the PrintMenu class and display the user menu.
    PrintMenu printMenu;
    printMenu.printMenuOptions();

    return 0; // Successful program termination.
}
