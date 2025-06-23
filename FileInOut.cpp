#include "FileInOut.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>

// Reads a file and returns an input file stream.
// Caller is responsible for checking the returned stream’s state.
ifstream FileInOut::readFile(const string &fileName) {

    ifstream in(fileName); // Attempt to open the file with the provided name.

    // Error handling. Notify user if file cannot be opened.
    if (!in) {
        cerr << "Failed to open " << fileName << endl;
    }
    // Return the input stream (could be in a failed state if opening failed).
    return in;
}

// Iterates through the given frequency map and writes to "frequency.dat".
void FileInOut::writeFile(const map<string, int> &freqData) {
    ofstream out("frequency.dat");
    if (!out) { // Throw error and exit if the file could not be created.
        cout << "Failed to open output file.\n";
        return;
    }

    // Write each item and its count to the file.
    for (auto const& [item, count] : freqData) {
        out << item << " " << count << endl;

        // Check if write failure occurs during the operation.
        if (!out) {
            cout << "Failed to write to output file.\n";
            return;
        }
    }
}
// Opens and reads the specified file line by line, counting occurrences
// of each item. Trims trailing carriage returns and ignores blank lines.
map<string, int> FileInOut::getItemFrequencies(const string &fileName) {
    map<string, int> freqData; // Map that holds results.
    ifstream in = readFile(fileName); // Attempt to open the file.
    if (!in.is_open()) return freqData; // Exit early if file cannot be opened.

    string line;
    while (getline(in, line)) {
        // Remove newline/return character(s).
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        // Skip empty lines.
        if (!line.empty())
            ++freqData[line]; // Increment the count for the current item.
    }
    return freqData; // Return completed frequency map.
}