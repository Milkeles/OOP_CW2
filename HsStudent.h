
#ifndef HSSTUDENT_H
#define HSSTUDENT_H

#include "Participant.h"
class CHsStudent : public CParticipant {
protected:
	std::string school;
	short grade;

public:
	CHsStudent(void);
	CHsStudent(std::string, std::string, int, std::string, short);
	void setData(void) override;
	void display(void) override;
	short getGrade(void);
};

#endif
