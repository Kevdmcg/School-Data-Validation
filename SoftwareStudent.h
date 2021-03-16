#pragma once
#include "degree.h"
#include "Student.h"
#include<string>
#include <cstring>

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
		string studentId, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		int daysInCourse[], 
		Degree degreeType
	);

	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();


};