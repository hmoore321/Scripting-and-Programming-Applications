#pragma once
#include<string>
#include "student.h"
class NetworkStudent : public Student {

public:

	NetworkStudent();
	NetworkStudent
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

	~NetworkStudent();
};