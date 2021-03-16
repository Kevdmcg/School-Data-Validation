#pragma once
#include "degree.h"
#include "Student.h"
#include<string>
#include <cstring>

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();


};