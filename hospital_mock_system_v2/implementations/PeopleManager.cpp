#include "PeopleManager.h"
#include <iostream>

bool PeopleManager::checkDoctor(Doctor *doctor) const
{
    return doctor && doctor->getAge() >= 25 && doctor->getAge() <= 70;
}

bool PeopleManager::checkPatient(Patient *patient, const std::vector<Doctor *> &doctors) const
{
    for (auto d : doctors)
        if (d->getExpertise() == patient->getNeeds())
            return true;

    return false;
}

bool PeopleManager::addDoctor(Hospital *hospital, Doctor *doctor)
{
    if (!checkDoctor(doctor))
        return false;

    hospital->doctors.push_back(doctor);
    hospital->humans.push_back(doctor);
    return true;
}

bool PeopleManager::addPatient(Hospital *hospital, Patient *patient)
{
    if (!checkPatient(patient, hospital->doctors))
        return false;

    hospital->patients.push_back(patient);
    hospital->humans.push_back(patient);
    return true;
}
