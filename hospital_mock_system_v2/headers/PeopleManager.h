#ifndef PEOPLE_MANAGER_H
#define PEOPLE_MANAGER_H

#include "Hospital.h"

class PeopleManager
{
public:
    bool addDoctor(Hospital *hospital, Doctor *doctor);
    bool addPatient(Hospital *hospital, Patient *patient);

    bool checkDoctor(Doctor *doctor) const;
    bool checkPatient(Patient *patient, const std::vector<Doctor *> &doctors) const;
};

#endif
