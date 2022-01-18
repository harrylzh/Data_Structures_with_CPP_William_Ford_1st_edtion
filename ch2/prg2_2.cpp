#include <iostream>
#include <fstream>
// #include <strstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    // input text file containing names and values
    ifstream fin;

    // read identifiers into name and write results to outputstr
    char name[30];
    // char outputstr[256];
    // ostrstream outs(outputstr, sizeof(outputstr));

    // declare an array-based output stream that uses outputstr
    std::ostringstream outs;
    
    double value;

    // open 'names.dat' for input. make sure it exists.
    fin.open("names.dat", ios::in);
    if (!fin)
    {
        cerr << "Could not open 'names.dat'" << endl;
        exit(1);
    }

    // read names and values. write to outs as 'name = value   '
    while (fin >> name)
    {
        fin >> value;
        outs << name << " = " << value << "   ";
    }
    // null-terminate the output string
    outs << ends;

    // cout << outputstr << endl;
    cout << outs.str() << endl;
    fin.close();
    return 0;
}

/*
<File "names.dat">

start   55
breakloop   225.39
stop    23

<Run of Program 2.2>

start = 55   breakloop = 225.39   stop = 23
*/
