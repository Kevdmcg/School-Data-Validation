#pragma once
#include <string>
#include <iostream>
#include "Student.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "SecurityStudent.h"
#include "degree.h"


class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:
	Roster();

	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void print_All();
	void remove(string studentID);
	void printAvgDays(string studentID);
	void printBadEmail();
	void printByDegreeProgram(int degreeProgram);

	~Roster();

};