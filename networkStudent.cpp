#include "networkStudent.h"
#include <iostream>
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
	dprogram = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, days)
{
	dprogram = NETWORK;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}		

void NetworkStudent::print()
{
	this->Student::print();  cout << "NETWORK" << "\n";   
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}	 