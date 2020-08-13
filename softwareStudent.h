#pragma once
#include<string>
#include "student.h"
class SoftwareStudent : public Student {

public:
	
	SoftwareStudent();
	SoftwareStudent
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

	~SoftwareStudent();
};