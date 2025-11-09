#ifndef HOSPITALSERVICE_H
#define HOSPITALSERVICE_H

#include <vector>
#include "doctor.h"
#include "patient.h"

// Does the checking logic for Hospital class
class HospitalService
{
public:
    bool checkDoctor(Doctor *doctor) const;
    bool checkPatient(Patient *patient, const std::vector<Doctor *> &doctors) const;
};

#endif
