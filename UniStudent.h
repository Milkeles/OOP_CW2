
#ifndef UNISTUDENT_H
#define UNISTUDENT_H

#include "Participant.h"

class CUniStudent : public CParticipant {
protected:
	std::string university;
	std::string major;
	std::string facultyNumber;

public:
	CUniStudent(void);
	CUniStudent(std::string, std::string, int, std::string, std::string, std::string);
	void setData(void) override;
	void display(void) override;
	std::string getMajor(void);
};

#endif
