# C-Day-90-Student-Record-Management
# C Day 90 - Student Record Management System

## Description
A menu-driven C project for adding, viewing, and searching student records. Student data is stored in a text file so records can be accessed after the program is closed.

## Features
- Add student records
- View all saved students
- Search by student ID
- Store student data in a file
- Menu-driven interface

## Concepts Used
- Structures
- Functions
- File Handling
- Pointers to FILE
- `fopen()`, `fprintf()`, `fscanf()`, `fclose()`
- Switch Statement and Loops

## Files
- `student_records.c` - Main application
- `students.txt` - Automatically created data file

## How to Run
1. Compile with `gcc student_records.c -o student_records`.
2. Run with `./student_records` on Linux/macOS or `student_records.exe` on Windows.
3. Use the menu to manage student records.

## Current Limitations
- Names must be a single word.
- Duplicate IDs are not prevented.
- Editing and deleting records are not implemented yet.

## Author
Suyash Surve
