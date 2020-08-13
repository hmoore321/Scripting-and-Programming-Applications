#include "student.h"
#include<iostream>
#include<iomanip>

using std::cout;
using std::left;
using std::setw;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) this->days[i] = 0;     
}

Student::Student(string ID, string firstName, string lastName, string email, int age, int days[]) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) this->days[i] = days[i];
}

string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getDays() {
	return days;
}

void Student::setStudentID(string ID) {
	this->studentID = ID; 
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;         
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDays(int days[]) {

	for (int i = 0; i < DAYS_ARRAY_SIZE; i++)
		this->days[i] = days[i];
}

void Student::print() 
{   
	/////////REVISION/////////
	int* courseDays = this->getDays();
	cout << this->getStudentID() << "\t" << "First Name: " << this->getFirstName() << "\t" << "Last Name: " << this->getLastName() 
		<< "\t" << "Age: " << this->getAge() << "  \t" << "Days in course: {" << *courseDays << ", " << *(courseDays + 1) << ", " << 
		*(courseDays + 2) << "}" << "\t" << "Degree Program: ";
}

Student::~Student() {}