#ifndef PATIENT_H
#define PATIENT_H

#include "Human.h"
#include <string>

class Patient : public Human
{
private:
    std::string diagnosis;
    std::string needs; // required doctor expertise

public:
    Patient(const std::string &name, unsigned age,
            const std::string &diagnosis, const std::string &needs);

    std::string getDiagnosis() const;
    std::string getNeeds() const;

    void displayInfo() const override;
};

#endif
