#include "hospital.h"
#include <iostream>
using namespace std;

Hospital::Hospital(string name, HospitalService *service)
    : name(name), service(service) {}

void Hospital::addDoctor(Doctor *doctor)
{
    if (service->checkDoctor(doctor))
    {
        doctors.push_back(doctor);
        people.push_back(doctor);
        cout << "Doctor " << doctor->getName()
             << " (" << doctor->getExpertise() << ") added to " << name << endl;
    }
    else
    {
        cout << "Doctor " << doctor->getName()
             << " is too young to join the hospital." << endl;
    }
}

void Hospital::addPatient(Patient *patient)
{
    if (service->checkPatient(patient, doctors))
    {
        people.push_back(patient);
        cout << "Patient " << patient->getName()
             << " (needs: " << patient->getNeeds() << ") added to " << name << endl;
    }
    else
    {
        cout << "Patient " << patient->getName()
             << " could not be added — no doctor with expertise in '"
             << patient->getNeeds() << "' available." << endl;
    }
}

void Hospital::printAll() const
{
    cout << "\n--- People in " << name << " ---" << endl;
    for (auto person : people)
        person->displayInfo();
}

vector<Doctor *> Hospital::getDoctors() const { return doctors; }
