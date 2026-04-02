# Student Management System

A simple command-line student management system written in C. This program allows you to manage student records, calculate grades, and generate results.

## Features

- **Add Student**: Add new students with their names, student numbers, and grades in three subjects (Math, English, Computer Science)
- **View All Students**: Display all student records stored in the system
- **Search Student**: Search for a specific student by name
- **Calculate Results**: Calculate total scores, averages, and assign letter grades to students
- **Save Results**: Export results to a file for record-keeping
- **User-Friendly Menu**: Interactive menu-driven interface for easy navigation

## Project Structure

```
.
├── README.md
├── student_management_system.c     # Main source code
└── student_management_system       # Compiled executable
```

## Compilation

To compile the project, use the following command:

```bash
gcc -o student_management_system student_management_system.c
```

Or using the provided VS Code build task:
- Press `Ctrl+Shift+B` to build the active file

## Usage

Run the compiled executable:

```bash
./student_management_system
```

### Menu Options

1. **Add Student** - Enter student details (name, student number, and grades for Math, English, Computer)
2. **View Students** - Display all students and their current information
3. **Search Student** - Find a specific student by name
4. **Calculate Results** - Compute totals, averages, and grades for all students
5. **Save Results to File** - Export the results to a file
6. **Exit** - Quit the program

## Grading System

Grades are assigned based on average scores:
- A: 80 and above
- B: 70 to 79
- C: 60 to 69
- D: 50 to 59
- F: Below 50

## Limitations

- Maximum of 100 students can be stored in memory at one time
- Maximum name length is 50 characters
- Data is not persisted between program sessions (unless saved to file using option 5)

## Requirements

- C compiler (gcc, clang, or compatible)
- Standard C library

## Author

Student Management System Project

## License

This project is open source and available for educational purposes.