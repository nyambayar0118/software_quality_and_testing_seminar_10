#ifndef PATIENT_H
#define PATIENT_H

#include "human.h"

class Patient : public Human
{
private:
    // Patient has a diagnosis and a needs attribute for which doctor they need
    std::string diagnosis;
    std::string needs; // Example: The patient needs a Neurologist if they have headache

public:
    Patient(std::string name, unsigned age, std::string diagnosis, std::string needs);

    std::string getDiagnosis() const;
    std::string getNeeds() const;

    void displayInfo() const override;
};

#endif
