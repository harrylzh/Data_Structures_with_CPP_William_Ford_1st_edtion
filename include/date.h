#ifndef DATE_CLASS
#define DATE_CLASS

#include <cstring>
#include <string>
// #include <strstream>          // array based I/O stream methods
#include <sstream>

class Date
{
private:
    // private members that specify the date
    int month, day, year;

public:
    // constructors. default date is January 1, 1900
    Date(int m = 1, int d = 1, int y = 0);
    Date(char *dstr);

    // output the date in the format "month day, year"
    void PrintDate(void);
};

// constructor. month, day, year given as integer values mm dd yy
Date::Date(int m, int d, int y) : month(m), day(d)
{
    year = 1900 + y; // y is a year in the 20th century
}

// constructor. month, day, year given as string "mm/dd/yy"
Date::Date(char *dstr)
{
    char inputBuffer[16];
    char ch;

    // copy string to inputBuffer and declare an array based input stream
    strcpy(inputBuffer, dstr);
    // std::istrstream input(inputBuffer, sizeof(inputBuffer));
    std::istringstream input;

    // read from input stream. use ch to read the '/' characters
    input >> month >> ch >> day >> ch >> year;
    year += 1900;
}

// print date with full month name.
void Date::PrintDate(void)
{
    // allocate static array of month names. Index 0 is NULL string.
    static const char *Months[] = {(char *)"", (char *)"January", (char *)"February", (char *)"March", (char *)"April",
                                   (char *)"May", (char *)"June", (char *)"July", (char *)"August", (char *)"September",
                                   (char *)"October", (char *)"November", (char *)"December"};

    std::cout << Months[month] << " " << day << ", " << year;
}

#endif // DATE_CLASS