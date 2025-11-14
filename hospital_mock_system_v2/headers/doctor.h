#ifndef DOCTOR_H
#define DOCTOR_H

#include "human.h"

class Doctor : public Human
{
private:
    // Doctor has an expertise or a field they specialize in
    std::string expertise;

public:
    Doctor(std::string name, unsigned age, std::string expertise);

    std::string getExpertise() const;
    void displayInfo() const override;
};

#endif
