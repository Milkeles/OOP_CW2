*/
#include <iostream>
#include <string>
#include "UniStudent.h"

CUniStudent::CUniStudent(void) : CParticipant() {
	university = "";
	major = "";
	facultyNumber = "";
}

CUniStudent::CUniStudent(
    std::string name,
    std::string EGN,
    int pointsScored,
    std::string university,
    std::string major,
    std::string facultyNumber) :
    CParticipant(name, EGN, pointsScored),
    university(university),
    major(major),
    facultyNumber(facultyNumber) {}

void CUniStudent::setData(void) {
    CParticipant::setData();

    std::cout << "University: ";
    getline(std::cin, university);
    std::cout << "Major: ";
    getline(std::cin, major);
    std::cout << "Faculty number: ";
    getline(std::cin, facultyNumber);
}

void CUniStudent::display(void) {
    CParticipant::display();

    std::cout << "University: " << university << '\n';
    std::cout << "Major: " << major << '\n';
    std::cout << "Faculty number: " << facultyNumber << '\n';
}

std::string CUniStudent::getMajor(void) {
    return major;
}
