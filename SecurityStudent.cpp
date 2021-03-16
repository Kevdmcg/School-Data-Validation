#include "SecurityStudent.h"
#include "degree.h"
#include "Student.h"
#include<iostream>
#include <string>
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	dType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}
SecurityStudent::~SecurityStudent()
{
	Student::~Student() ;
}