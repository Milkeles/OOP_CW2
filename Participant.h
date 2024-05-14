#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

class CParticipant {
protected:
	std::string name;
	std::string EGN;
	int pointsScored;
	bool isValidEGN(const std::string&);

public:
	CParticipant(void);
	CParticipant(std::string, std::string, int);
	virtual ~CParticipant(void) {}
	virtual void setData(void);
	virtual void display(void);
	std::string getName(void);
	int getPoints(void);
	bool isMale(void);
};

#endif
