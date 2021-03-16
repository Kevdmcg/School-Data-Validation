#pragma once
#include <string>
#include "degree.h"
#include <cstring>

using namespace std;



class Student
{
public:
	const static int numDaysArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[numDaysArraySize];
	Degree dType;


public:

	Student(); //empty constructor

	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]); // full constructor

	//getters

	Student(string studentID, string firstName, string lastName, string emailAddress, int daysInCourse[]);

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	virtual Degree getDegreeProgram() = 0;


	//setters

	void setFirstName(string firstName);
	void setStudentId(string studentId);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);

	virtual void print() = 0;


	// destructor
	~Student();












};

