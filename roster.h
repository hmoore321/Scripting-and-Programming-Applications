#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {
private:
	int lastIndex;		
	int capacity;		
	Student** classRosterArray;		

public:
	Roster();	
	Roster(int capacity);	

	Student* getCRArray(int index);
	void parseThenAdd(string datarow);	
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int dp1, int dp2, int dp3, Degree dp);
	void printAll();	
	bool remove(string studentID);	
	void printAverageDaysInCourse(string studentID);	
	void printInvalidEmails();	
	void printByDegreeProgram(Degree degree); 

	~Roster();	
};