#ifndef JOBREQUEST
#define JOBREQUEST

// employee priority level (Manager=0, etc)
enum Staff
{
    Manager,
    Supervisor,
    Worker
};

// record defining a job request
struct JobRequest
{
    Staff staffPerson;
    int jobid;
    int jobTime;
};

// overload "<" to compare two JobRequests
int operator<(const JobRequest &a, const JobRequest &b)
{
    return a.staffPerson < b.staffPerson;
}

// print a JobRequest record
void PrintJobInfo(JobRequest PR)
{
    switch (PR.staffPerson)
    {
    case Manager:
        std::cout << "Manager        ";
        break;
    case Supervisor:
        std::cout << "Supervisor     ";
        break;
    case Worker:
        std::cout << "Worker         ";
        break;
    }
    std::cout << PR.jobid << "        " << PR.jobTime << std::endl;
}

#include <iomanip> // use manipulator std::setw

// print total job time allocated to each employee category
void PrintJobSummary(int jobServicesUse[])
{
    std::cout << "\nTotal Support Usage\n";
    std::cout << "   Manager     " << std::setw(3)
              << jobServicesUse[0] << std::endl;
    std::cout << "   Supervisor  " << std::setw(3)
              << jobServicesUse[1] << std::endl;
    std::cout << "   Worker      " << std::setw(3)
              << jobServicesUse[2] << std::endl;
}

#endif // JOBREQUEST
