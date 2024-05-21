*/
#include <iostream>
#include <string>
#include "HsStudent.h"

CHsStudent::CHsStudent(void) : CParticipant() {
	school = "";
	grade = 0;
}

CHsStudent::CHsStudent(
	std::string name,
	std::string EGN,
	int pointsScored,
	std::string school,
	short grade) :
	CParticipant(name, EGN, pointsScored),
	school(school),
	grade(grade) {}

void CHsStudent::setData(void) {
	CParticipant::setData();

	std::cout << "School: ";
	getline(std::cin, school);

	std::cout << "Grade: ";
	std::cin >> grade;
	std::cin.ignore();

	// Cannot be in highschool otherwise.
	while (grade < 8 || grade > 12) {
		std::cerr << "Invalid grade! Please try again: ";
		std::cin >> grade;
		std::cin.ignore();
	}
}

void CHsStudent::display(void) {
	CParticipant::display();

	std::cout << "School: " << school << '\n';
	std::cout << "Grade: " << grade << '\n';
}

short CHsStudent::getGrade(void) {
	return grade;
}
