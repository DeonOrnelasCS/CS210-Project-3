# CS210-Project-3

# Corner Grocer

A console-based C++ application that reads a grocery-list text file, tallies item frequencies, and provides an interactive menu for querying or visualizing those frequencies in list or histogram form.

---

## Features

- **Backup & Data Persistence**  
  - Reads `"CS210_Project_Three_Input_File.txt"`, counts each item, and writes to `frequency.dat`.  
- **Interactive Menu**  
  - **Option 1:** Query frequency of a single item.  
  - **Option 2:** Print all items and counts (list style).  
  - **Option 3:** Print a histogram of counts (asterisks).  
  - **Option 4:** Exit.  
- **Robust Input Validation**  
  - Rejects non-numeric or out-of-range menu selections and re-prompts.  
  - Supports repeated queries until the user chooses to quit. 

---

## Project Structure

- **main.cpp**  
  - Entry point: builds frequency map, writes backup, then launches the menu.  
- **FileInOut**  
  - `readFile()` – opens an input stream (with error reporting).  
  - `getItemFrequencies()` – returns a `map<string,int>` of counts.  
  - `writeFile()` – writes the frequency map to `frequency.dat`.  
- **UserOptions**  
  - `option1()` – prompt & print single-item count.  
  - `option2()` – print all items & counts.  
  - `option3()` – print histogram (asterisks).  
  - `option4()` – exit program.  
- **PrintMenu**  
  - `printMenuOptions()` – displays menu, validates input, and dispatches to `UserOptions`.

---
