#include "Doctor.h"
#include <iostream>

Doctor::Doctor(const std::string &name, unsigned age, const std::string &expertise)
    : Human(name, age), expertise(expertise) {}

std::string Doctor::getExpertise() const { return expertise; }

void Doctor::displayInfo() const
{
    std::cout << "Doctor: " << name
              << " | Age: " << age
              << " | Expertise: " << expertise << "\n";
}
