#ifndef DOCTOR_H
#define DOCTOR_H

#include "Human.h"

class Doctor : public Human
{
private:
    std::string expertise;

public:
    Doctor(const std::string &name, unsigned age, const std::string &expertise);

    std::string getExpertise() const;
    void displayInfo() const override;
};

#endif
