#include "NetworkStudent.h"
#include "degree.h"
#include "Student.h"
#include<iostream>
#include <string>
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
	dType = NETWORK;
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	dType = NETWORK;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}