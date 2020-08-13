#include "securityStudent.h"
#include <iostream>
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	dprogram = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, days)
{
	dprogram = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}	 

void SecurityStudent::print()
{
	this->Student::print(); cout << "SECURITY" << "\n";   
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}	 