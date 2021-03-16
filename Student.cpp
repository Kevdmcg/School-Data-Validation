#include "Student.h"
#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
using std::cout;

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; i++)
		this->daysInCourse[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress,int age, int daysInCourse[])
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

//getters
string Student::getStudentId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

// setters

void Student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < numDaysArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

// print method?
void Student::print()
{
	cout << left << setw(10) << getStudentId();
	cout << left << setw(10) << getFirstName();
	cout << left << setw(10) << getLastName();
	cout << left << setw(24) << getEmailAddress();
	cout << left << setw(4) << getAge();
	for (int z = 0; z < 3; z++) 
	{
		cout << left << setw(5) << this->getDaysInCourse()[z];
	}
}

Student::~Student() {}

