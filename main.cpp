#include <iostream>
#include <vector>
#include <memory>
#include <type_traits>
#include "Participant.h"
#include "UniStudent.h"
#include "HsStudent.h"
using namespace std;

void displayMenu() {
    cout << "MENU\n";
    cout << "1. Add new participant.\n";
    cout << "2. Display all data.\n";
    cout << "3. Display data of university students in a certain major "
            "with more than 25 points.\n";
    cout << "4. Create an array that contains female highschool students "
            "in a certain grade.\n";
    cout << "0. Cease the execution.\n";
    cout << "Option: ";
}

void addNewParticipant(vector<unique_ptr<CParticipant>>& participants) {
    cout << "\nWhat type of participant would you like to add?" << endl;
    cout << "1. University Student" << endl;
    cout << "2. High School Student" << endl;
    cout << "Choice: ";

    char choice;
    cin >> choice;
    cin.ignore();

    putchar('\n');
    switch (choice) {
        case '1': {
            auto uniStudent = make_unique<CUniStudent>();
            uniStudent->setData();
            participants.push_back(move(uniStudent));
            break;
        }
        case '2': {
            auto hsStudent = make_unique<CHsStudent>();
            hsStudent->setData();
            participants.push_back(move(hsStudent));
            break;
        }
        default: 
            cerr << "Invalid choice!" << endl;
            break;
    }
}

void displayAll(vector<unique_ptr<CParticipant>> & participants) {
    for (const auto& participant : participants) {
        participant->display();
        putchar('\n');
    }
}

void displayStuds(vector<unique_ptr<CParticipant>> & participants, short minPoints) {
    string major;

    cout << "Major: ";
    getline(cin, major);

    for (const auto& participant : participants) {
        // if get() fails -> nullptr -> false
        if (auto uniStudent = dynamic_cast<CUniStudent*>(participant.get())) {
            if (uniStudent->getMajor().compare(major) == 0 && uniStudent->getPoints() > minPoints) {
                participant->display();
                putchar('\n');
            }
        }
    }
}

template <typename ParticipantType,
    typename = std::enable_if_t<std::is_same_v<ParticipantType, CUniStudent> ||
    std::is_same_v<ParticipantType, CHsStudent>>>
    void displayParticipantsVector(const std::vector<ParticipantType>&participants) {
    for (ParticipantType participant : participants) {
        std::cout << participant.getName() << ' ';
    }
    std::cout << std::endl;
}

void getFemaleHSStudsVector(const vector<unique_ptr<CParticipant>>& participants, vector<CHsStudent>& femaleStudents) {
    short grade;

    cout << "Grade: ";
    cin >> grade;
    cin.ignore();

    for (const auto& participant : participants) {
        // if get() fails -> nullptr -> false
        if (auto hsStudent = dynamic_cast<CHsStudent*>(participant.get())) {
            if (hsStudent->getGrade() == grade && hsStudent->isMale() == false) {
                femaleStudents.push_back(*hsStudent);
            }
        }
    }

    // Display the created array for testing purposes.
    if (!femaleStudents.empty()) {
        cout << "\nCreated array: ";
        displayParticipantsVector<CHsStudent>(femaleStudents);
    }
}


int main() {
    vector<unique_ptr<CParticipant>> participants;
    vector<CHsStudent> femaleStuds;

    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': 
                addNewParticipant(participants);
                break;
            case '2':
                displayAll(participants);
                break;
            case '3':
                displayStuds(participants, 25);
                break;
            case '4':
                getFemaleHSStudsVector(participants, femaleStuds);
                break;
            case '0':
                clog << "\nEnd of execution..." << endl;
                break;
            default:
                cerr << "Invalid choice!" << endl;
                break;
        }
        putchar('\n');

    } while (choice != '0');

	return 0;
}
