#include "hospitalService.h"

bool HospitalService::checkDoctor(Doctor *doctor) const
{
    return doctor && doctor->getAge() >= 25;
}

bool HospitalService::checkPatient(Patient *patient, const std::vector<Doctor *> &doctors) const
{
    if (!patient)
        return false;
    for (auto d : doctors)
        if (d->getExpertise() == patient->getNeeds())
            return true;
    return false;
}
