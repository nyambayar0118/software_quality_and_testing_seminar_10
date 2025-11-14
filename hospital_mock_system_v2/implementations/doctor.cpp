#include "doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor(string name, unsigned age, string expertise)
    : Human(name, age), expertise(expertise) {}

string Doctor::getExpertise() const { return expertise; }

void Doctor::displayInfo() const
{
    cout << "Doctor: " << getName()
         << ", Age: " << getAge()
         << ", Expertise: " << expertise << endl;
}
