#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>

struct Date {
    int day, month, year;
};

Date getUserDateInput(const std::string& prompt);

// Add other declarations if needed

#endif // PROGRAM_H
