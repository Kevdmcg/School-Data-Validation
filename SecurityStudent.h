#pragma once
#include "degree.h"
#include "Student.h"
#include<string>
#include <cstring>

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~SecurityStudent();


};

