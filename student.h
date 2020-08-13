#pragma once                    
#include <string>
#include "degree.h"
using std::string;

class Student {

public:   
	const static int DAYS_ARRAY_SIZE = 3;  

protected:   
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[DAYS_ARRAY_SIZE];   
	Degree dprogram;    

public:  
	Student();   
	Student(string ID, string firstName, string lastName, string email, int age, int days[]);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();    
	virtual Degree getDegreeProgram() = 0;    

	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);

	virtual void print() = 0;

	~Student();
};