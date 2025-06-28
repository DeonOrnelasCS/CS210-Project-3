# CS210-Project-3

# Corner Grocer

A console-based C++ application that reads a grocery-list text file, tallies item frequencies, and provides an interactive menu for querying or visualizing those frequencies in list or histogram form.

---

## Project Summary
**Corner Grocer** solves the common problem of quickly analyzing a shopping list’s contents: tallying how many times each item appears, backing up the results, and giving the user flexible ways to inspect the data. This is particularly useful in scenarios like inventory management or customer‐order analysis where understanding item frequency at a glance can inform purchasing and stocking decisions.

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

## What Went Well

- **Clear Module Separation:** I split file I/O, menu logic, and user operations into distinct classes (`FileInOut`, `PrintMenu`, `UserOptions`), which made each component easier to write, test, and debug.
- **User Experience:** Input validation and looping logic ensure the program never crashes on bad input and always returns to the menu cleanly.
- **Data Persistence:** Automatic backup to `frequency.dat` guarantees that raw results are saved before any user interaction, safeguarding against data loss.

---

## Areas for Improvement

1. **Performance Optimization**  
   - **Current:** Loads the entire list into memory then writes and processes it each run.  
   - **Improvement:** Stream and process items one-by-one, or use a database for very large input files to reduce memory footprint and speed up repeated queries.

2. **Security & Robustness**  
   - **Current:** Assumes the input file is well-formed and doesn't guard against different file paths or unclean data.  
   - **Improvement:** Validate file paths, handle exceptions more granularly, account for unclean data, and verify user inputs to prevent misuse or crashes on bad data.

3. **Extensibility**  
   - **Current:** Limited to text-file input and simple console output.  
   - **Improvement:** Abstract I/O interfaces to support CSV or JSON inputs, and add an export option (e.g., HTML report or graphical chart) for bettter data presentation.

---

## Challenges & Solutions

- **Parsing and Trimming Lines:** Handling Windows (`\r\n`) vs. Unix (`\n`) line endings correctly was tricky. I solved it by checking and stripping trailing returns before processing.
- **Input Validation Loop:** Preventing infinite loops on non-numeric input required resetting `cin` state and ignoring leftover characters. I referenced C++ I/O documentation and GeeksforGeeks to implement.
- **Resource Network:** To overcome these challenges, I leaned on:
  - **C++ Reference (cppreference.com)** for up-to-date standard library usage  
  - **W3 Schools & GeeksforGeeks** for I/O syntax and examples
  - **zyBooks** For syntax and examples of loops and I/O. 

---

## Transferable Skills

- **Modular Design:** Breaking functionality into classes and methods translates directly to larger C++ projects and other OOP languages.
- ** I/O Handling:** Techniques for safe file and console I/O apply in data-driven applications, systems programming, and scripting.
- **Error Handling & Validation:** Building user-friendly loops and error messages is critical in any interactive software.
- **Documentation & Testing:** Writing clear comments and testing edge cases prepares me for professional code reviews and QA practices.

---

## Maintainability, Readability & Adaptability

- **Consistent Naming Conventions:** Classes, methods, and variables follow a clear, descriptive format (`getItemFrequencies`, `printMenuOptions`), making it easy for new contributors to understand intent and where things go.
- **Single-Responsibility Principle:** Each class has a well-defined role (I/O, menu logic, user actions), simplifying future extensions.
- **Comments:** Inline comments explain the “why” behind non-obvious code blocks. Ensures any developer can get up to speed without diving into implementation details.
- **Scalable Architecture:** The menu dispatcher can be extended with new options without touching existing functionality, and I/O classes can be swapped out for other formats with minimal changes to the rest of the codebase.

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
