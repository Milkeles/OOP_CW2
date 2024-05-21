#include <iostream>
#include <string>
#include "Participant.h"

CParticipant::CParticipant(void) {
	name = "";
	EGN = "";
	pointsScored = 0;
}

CParticipant::CParticipant(std::string name, std::string EGN, int pointsScored) {
	this->name = name;
	this->EGN = EGN;
	this->pointsScored = pointsScored;
}

bool CParticipant::isValidEGN(const std::string& EGN) {
    // Validate length
    if (EGN.length() != 10)
        return false;

    // Validate symbols
    for (char symbol : EGN) {
        if (!isdigit(symbol))
            return false;
    }

    // Validate birthdate
    short year = stoi(EGN.substr(0, 2));
    short month = stoi(EGN.substr(2, 2));
    short day = stoi(EGN.substr(4, 2));

    if (month > 40) {
        year += 2000;
        month -= 40;
    }
    else {
        year += 1900;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Validate last digit
    short weights[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };
    short sum = 0;

    for (int i = 0; i < 9; ++i) {
        sum += (EGN[i] - '0') * weights[i];
    }

    if (sum % 11 != EGN[9] - '0')
        return false;

    return true;
}

bool CParticipant::isMale(void) {
    // Even 9th digit -> Male
    if (EGN[8] % 2 == 0) {
        return true;
    }

    return false;
}

void CParticipant::setData(void) {
	std::cout << "Name: ";
	getline(std::cin, name);

    std::cout << "EGN: ";
    getline(std::cin, EGN);

    while (!isValidEGN(EGN)) {
        std::cerr << "Invalid EGN! Please try again: ";
        getline(std::cin, EGN);
    }

	std::cout << "Scored points: ";
	std::cin >> pointsScored;
    std::cin.ignore();
}

void CParticipant::display(void) {
	std::cout << "Name: " << name << '\n';
	std::cout << "EGN: " << EGN << '\n';
	std::cout << "Scored points: " << pointsScored << '\n';
}

std::string CParticipant::getName(void) {
    return name;
}

int CParticipant::getPoints(void) {
	return pointsScored;
}
