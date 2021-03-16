#include "roster.h"
#include <string>
#include <cstring>

using namespace std;
using std::cout;
using std::cerr;


Roster::Roster() {

	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;

}

Roster::Roster(int capacity) {

	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];

}

Student* Roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

void Roster::parseThenAdd(string datarow)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degreeType;
		int degreeID = size(datarow);
		if (datarow[degreeID - 1] == 'K') degreeType = NETWORK;
		else if (datarow[degreeID - 1] == 'E') degreeType = SOFTWARE;
		else if (datarow[degreeID - 1] == 'Y') degreeType = SECURITY;
		else {
			cerr << "INVALID INPUT.  EXITING.\n";
			exit(-1);
		}

		int rhs = datarow.find(",");
		string sID = datarow.substr(0, rhs); // While parsing the info in puts the ID into a temp spot

		int lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string sFirst = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string sLast = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string sEmail = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int sDateOne = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int sDateTwo = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int sDateThree = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int sDateFour = stoi(datarow.substr(lhs, rhs - lhs));

		add(sID, sFirst, sLast, sEmail, sDateOne, sDateTwo, sDateThree, sDateFour, degreeType);
	}
	else {
		cerr << "List out of size. Exiting Now.\n";
	}
}

void Roster::add(string sID, string sFirst, string sLast, string sEmail, int sDateOne, int sDateTwo, int sDateThree, int sDateFour, Degree degreeType)
{
	int daysInCourse[Student::numDaysArraySize];
	daysInCourse[0] = sDateTwo;
	daysInCourse[1] = sDateThree;
	daysInCourse[2] = sDateFour;
	if (degreeType == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(sID, sFirst, sLast, sEmail, sDateOne, daysInCourse, degreeType);
	else if (degreeType == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sID, sFirst, sLast, sEmail, sDateOne, daysInCourse, degreeType);
	else classRosterArray[lastIndex] = new SecurityStudent(sID, sFirst, sLast, sEmail, sDateOne, daysInCourse, degreeType);
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::remove(string ID)
{
	bool found = false;
	cout << "\nRemoving " << ID << ": ";
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentId() == ID)
		{
		found = true;
		delete this->classRosterArray[i];
		this->classRosterArray[i] = this->classRosterArray[lastIndex];
		lastIndex--;
		cout << ID << " has been removed.\n";
		}

	}
	if (found == !true) {
		cout <<  "Such a student with this ID was not found.\n";
	}
}

void Roster::printAvgDays(string studentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentId() == studentId)
		{
			found = true;
			int* d = classRosterArray[i]->getDaysInCourse();
			cout << "Average days in course for " << studentId << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not Found.\n";
}

void Roster::printBadEmail()
{
	cout << "\nDisplaying Invalid Email Addresses:\n";
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << '\n';
		}
	}
	cout << '\n';
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	cout << "\nPrinting Students by Degree Type: " << degreeStrings[degreeProgram] << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}




int main()
{
	int numStudents = 5;
	string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kevin,McGhee,dummy@dummy.com,38,10,12,22,SOFTWARE"
	};


	Roster* classRoster = new Roster(numStudents);
	cout << "\nParsing and adding students:\t";
	for (int i = 0; i < numStudents; i++) {

		classRoster->parseThenAdd(studentData[i]);
	}
	cout << "Done.\n";
	cout << "Displaying Student Roster:\n";
	classRoster->print_All();

	classRoster->printBadEmail();

	cout << "Printing Average Days in Course:\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAvgDays(classRoster->getStudentAt(i)->getStudentId());
	}

	classRoster->printByDegreeProgram((Degree)2);

	classRoster->remove("A3");
	classRoster->remove("A3");

	




	classRoster->~Roster();
	return 0;
}
