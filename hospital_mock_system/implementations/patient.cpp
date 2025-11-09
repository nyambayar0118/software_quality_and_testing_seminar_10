#include "patient.h"
#include <iostream>
using namespace std;

Patient::Patient(string name, unsigned age, string diagnosis, string needs)
    : Human(name, age), diagnosis(diagnosis), needs(needs) {}

string Patient::getDiagnosis() const { return diagnosis; }
string Patient::getNeeds() const { return needs; }

void Patient::displayInfo() const
{
    cout << "Patient: " << getName()
         << ", Age: " << getAge()
         << ", Diagnosis: " << diagnosis
         << ", Needs: " << needs << endl;
}
