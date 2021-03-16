#include "SoftwareStudent.h"
#include "degree.h"
#include "Student.h"
#include<iostream>
#include <string>
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	dType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}