#pragma once
#include<string>
#include "student.h"
class SecurityStudent : public Student {

public:

	SecurityStudent();
	SecurityStudent
	(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int days[],
		Degree degree
	);

	Degree getDegreeProgram();      
	void print();

	~SecurityStudent();
};