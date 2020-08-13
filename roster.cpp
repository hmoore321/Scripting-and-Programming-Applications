#include "roster.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "student.h"
#include "degree.h"

using std::cout;
using std::cerr;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)	
{
	this->capacity = capacity;
	this->lastIndex = -1;		
	this->classRosterArray = new Student * [capacity];  
}

Student* Roster::getCRArray(int index)   
{
	return classRosterArray[index];
}

void Roster::parseThenAdd(string studRow) 
{
	if (lastIndex < capacity) {
		lastIndex++;  
		Degree dDegree;
		if (studRow[1] == '1') dDegree = SECURITY;
		else if (studRow[1] == '2') dDegree = NETWORK;
		else if (studRow[1] == '3') dDegree = SOFTWARE;
		else if (studRow[1] == '4') dDegree = SECURITY;
		else if (studRow[1] == '5') dDegree = SOFTWARE;
		else {
			cerr << "INVALID TYPE!\n";
			exit(-1);
		}

		int rhs = studRow.find(","); 
		string sID = studRow.substr(0, rhs); 

		int lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		string sFirstName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		string sLastName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		string sEmail = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		int sAge = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		int day1 = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		int day2 = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1; 
		rhs = studRow.find(",", lhs); 
		int day3 = stoi(studRow.substr(lhs, rhs - lhs));

		add(sID, sFirstName, sLastName, sEmail, sAge, day1, day2, day3, dDegree); 
	}
	else {
		cerr << "Capacity exceeded, exiting...\n";
		exit(-1);
	}
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int dp1, int dp2, int dp3, Degree dp)
{
	int daysInCourse[Student::DAYS_ARRAY_SIZE];	
	daysInCourse[0] = dp1;
	daysInCourse[1] = dp2;
	daysInCourse[2] = dp3;
	if (dp == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, dp);
	if (dp == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, dp);
	if (dp == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, dp);
	else;
}

bool Roster::remove(string ID)	
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == ID) {
		found = true;  
		delete this->classRosterArray[i];	
		this->classRosterArray[i] = this->classRosterArray[lastIndex];	
		lastIndex--;	
		}
	}
	return found;
}

void Roster::printAll()	//VERY IMPORTANT!!!!!
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();  //NOTE: run time polymorphism
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID)	{
			found = true;
			int* p = classRosterArray[i]->getDays();
			cout << "Average days in courses for student ID " <<studentID << " is: " << (p[0] + p[1] + p[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()  
{
	cout << "\n" << "Displaying invalid email addresses:\n";  
	for (int i = 0; i < lastIndex; i++) {
		string email = classRosterArray[i]->getEmail();
		if ((email.find('.') == string::npos) || (email.find('@') == string::npos) || (email.find(' ') != string::npos)) {
			cout << "Invalid email address for student " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ": " << email << "\n";
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) 
{
	Degree tempDegree = degreeProgram;   
	cout << "\n" << "Printing roster by specific degree program: SOFTWARE\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (tempDegree == classRosterArray[i]->getDegreeProgram()) { 
			this->classRosterArray[i]->print(); 
		}
	}
}

Roster::~Roster()	
{
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];	
	}
	delete classRosterArray;	//do this one last, can't do it out of order!
}

int main()	
{
	cout << "***************************************************************************************************************\n";
	cout << "WGU C867 - FINAL PROJECT FOR SCRIPTING AND PROGRAMMING APPLICATIONS - REVISION 1 \n";
	cout << "Written in Visual Studio 2019, C++\n";
	cout << "Student ID# 00116877\n";
	cout << "Holly Moore\n";
	cout << "***************************************************************************************************************\n\n";

	int numStudents = 5;
	const string studentData[] = 	
	{	
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Holly,Moore,hmoor79@wgu.edu,43,30,30,14,SOFTWARE",  
	};

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);	
	}
	cout << "Printing the class roster:\n";
	
	classRoster->printAll();
	
	classRoster->printInvalidEmails();	

	cout << "\n" << "Printing average days in courses: \n";		
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getCRArray(i)->getStudentID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "\n" << "Removing student with ID A3:\n";	
	if (classRoster->remove("A3")) {
		cout << "DONE! Student successfully removed! Displaying class roster:\n";
		classRoster->printAll();
		cout << "\n";
		numStudents--;
	}
	else cout << "Student not found!\n\n";

	cout << "Removing student with ID A3:\n";	
	if (classRoster->remove("A3")) classRoster->printAll();	
	else cout << "Error: A student with that ID cannot be found!\n\n";

	system("pause");	
	
	return 0;			

	//Roster::~Roster()  //NO NEED TO CALL THE DESTRUCTOR
}
