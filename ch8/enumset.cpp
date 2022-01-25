#include <iostream>

#include "set.h"		// include Set class
#include "strclass.h"		// we use the String class
using namespace std;
enum Days {Sun,Mon,Tues,Wed,Thurs,Fri,Sat};

// output a Day value
ostream& operator<< (ostream& ostr, const Days& d)
{
	// assign the output string to day
	String day;
	
	// assign the output string
	switch(d)
	{
		case Sun:
			day = (char*)"Sun";
			break;
		case Mon:
			day = (char*)"Mon";
			break;
		case Tues:
			day = (char*)"Tues";
			break;
		case Wed:
			day = (char*)"Wed";
			break;
		case Thurs:
			day = (char*)"Thurs";
			break;
		case Fri:
			day = (char*)"Fri";
			break;
		case Sat:
			day = (char*)"Sat";
			break;
	}
	// output the string
	ostr << day;

	// return a reference to the stream
	return ostr;
}

// input a Day value
istream& operator>> (istream& istr, Days& d)
{
	// read the characters into value
	String value;
	// used to search for ',' or '}'
	int index;
	
	// input a whitespace separated string
	istr >> value;
	
	// if the string ends with ',' or '}', remove
	// it from the string and put it back into the
	// input stream. this anticipates the operator's
	// use with Set input
	if ((index = value.Find(',',0)) != -1)
	{
		value.Remove(index,1);
		istr.putback(',');
	}
	else if ((index = value.Find('}',0)) != -1)
	{
		value.Remove(index,1);
		istr.putback('}');
	} 
	
	// compare value with the enum strings	
	if (value == (char*)"Sun")
		d = Sun;
	else if (value == (char*)"Mon")
		d = Mon;
	else if (value == (char*)"Tues")
		d = Tues;
	else if (value == (char*)"Wed")
		d = Wed;
	else if (value == (char*)"Thurs")
		d = Thurs;
	else if (value == (char*)"Fri")
		d = Fri;
	else if (value == (char*)"Sat")
		d = Sat;
	else
		// flag a stream error
		istr.clear(ios::badbit);
	// return a stream reference
	return istr;
}

int main(void)
{
	Set<Days> weekdays(7), weekend(7), week(7), favorites(7);
	Days wd[] = {Mon,Tues,Wed,Thurs,Fri}, we[] = {Sat,Sun};

	// insert values into the sets
	for(int i=0;i < 5;i++)
		weekdays.Insert(wd[i]);
	for(int i=0;i < 2;i++)
		weekend.Insert(we[i]);
		
	// output the sets
	cout << weekdays << endl;
	cout << weekend << endl;

	// form union of the two sets and print it
	week = weekdays + weekend;
	cout << week << endl;
	
	// prompt for and read a set value. verify correctness
	// by printing the result
	cout << "What are your two favorite days of the week? ";
	cin >> favorites;
	cout << "You selected " << favorites << endl;
}

/*
<Run>

{Mon, Tues, Wed, Thurs, Fri}
{Sun, Sat}
{Sun, Mon, Tues, Wed, Thurs, Fri, Sat}
What are your two favorite days of the week? {Sat, Sun}
You selected {Sun, Sat}
*/

