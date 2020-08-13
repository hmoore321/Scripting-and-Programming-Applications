#include "softwareStudent.h"
#include <iostream>
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	dprogram = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, days)
{
	dprogram = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}		 

void SoftwareStudent::print()
{
	this->Student::print(); cout << "SOFTWARE" << "\n";   
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}	