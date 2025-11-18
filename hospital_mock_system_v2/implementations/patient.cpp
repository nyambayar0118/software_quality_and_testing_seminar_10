#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string &name, unsigned age,
                 const std::string &diagnosis, const std::string &needs)
    : Human(name, age), diagnosis(diagnosis), needs(needs) {}

std::string Patient::getDiagnosis() const { return diagnosis; }
std::string Patient::getNeeds() const { return needs; }

void Patient::displayInfo() const
{
    std::cout << "Patient: " << name
              << " | Age: " << age
              << " | Diagnosis: " << diagnosis
              << " | Needs: " << needs << "\n";
}
