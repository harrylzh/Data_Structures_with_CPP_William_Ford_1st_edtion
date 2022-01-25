#include "strclass.h"

struct StudentRecord
{
	String name;
	float gpa;
};

int operator!= (const StudentRecord& s,
				const StudentRecord& t)
{
	return s.name != t.name;
}

std::istream& operator>> (std::istream& istr, StudentRecord& srec)
{
	srec.name.ReadString(istr);	
	istr >> srec.gpa;
	istr.get();	// read and discard end of line
	return istr;
}

std::ostream& operator<< (std::ostream& ostr, const StudentRecord& srec)
{
	ostr << srec.name << "  " <<  srec.gpa;
	return ostr;
}
