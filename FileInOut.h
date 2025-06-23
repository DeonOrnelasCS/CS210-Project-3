// FileInOut.h
// This header file declares the FileInOut class, which provides methods for reading from and writing to files.

// Header file guards
#ifndef FILEINOUT_H
#define FILEINOUT_H

#include <fstream>
#include <map>
#include <string>

using namespace std;

// FileInOut class handles file input/output operations related to item frequency data.
class FileInOut {
public:
    // Reads a file with the specified file name and returns an input file stream.
    // Note: Caller is responsible for checking if the stream is valid/open.
    static ifstream readFile(const string &fileName);

    // Writes item frequency data to an output file "frequency.dat".
    // Accepts a map where the key is the item name and the value is the frequency count.
    static void writeFile(const map<string,int>& freqData);

    // This method reads each non-empty line from the input file and builds a frequency map.
    // It trims trailing newline/return characters and skips empty lines.
    static map<string, int> getItemFrequencies(const string &fileName);

};

// Header file guard
#endif //FILEINOUT_H
